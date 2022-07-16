#include "main.h"
#include "hardware.h"
#include "pax_gfx.h"
#include "pax_codecs.h"
#include "ili9341.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/queue.h"
#include "esp_system.h"
#include "gas_sensor.h"
#include "screens.h"
#include "gui_text.h"

#define HEATER_WAIT_MS_MAX     4096
#define HEATER_WAIT_MS_MIN     0

void screen_settings_heater_wait(screen_t* screen)  {
    double heater_wait_ms;
    char str_wait_val[10] = "0";
    char str_wait_lbl[] = "Heater wait time";
    char str_wait_unit[] = "ms";
    char str_wait_val_fmt[] = "%.0f";
    char str_info[] =   "The material resistance response also\n"
                        "dependends on the time duration it is\n"
                        "kept at the target temperature.\n"
                        "It can be set from 0ms to 4096ms.\n"
                        "Zero means heater is always on. Use \n"
                        "joystick to change, press A to apply.\n";

    rp2040_input_message_t message;

    pax_col_t bg_color = pax_col_hsv(0, 0 /*saturation*/, 255 /*brighness*/);
    pax_col_t fg_color = pax_col_hsv(0, 0 /*saturation*/, 0   /*brighness*/);
    pax_col_t fg_color_val_changing = pax_col_hsv(0, 0 /*saturation*/, 100   /*brighness*/);
    pax_col_t fg_color_val_applied = pax_col_hsv(50, 200 /*saturation*/, 150   /*brighness*/);

    pax_font_t* font_text = (pax_font_t*)pax_get_font("saira condensed");
    pax_font_t* font_lbl = (pax_font_t*)pax_get_font("sky mono");

    heater_wait_ms = gas_sensor_get_heater_wait();
    sprintf(str_wait_val, str_wait_val_fmt, heater_wait_ms);

    // Info text

    gui_txt_p_t txt_info_p = {
        .font = font_text,
        .font_size = font_text->default_size / 2.0,
        .offset = 0,
        .text = str_info,
        .bg_color = bg_color,
        .fg_color = fg_color,
    };

    gui_txt_t txt_info = {
        .x = 5,
        .y = 5,
        .width = 320,
        .height = 160,
        .bg_color = bg_color,
        .txt = &txt_info_p,
        .txt_num = 1,
        .halign = GUI_TEXT_ALIGN_LEFT,
    };

    // Heater wait time label

    gui_txt_p_t txt_wait_lbl_p = {
        .font = font_lbl,
        .font_size = font_lbl->default_size,
        .offset = 0,
        .text = str_wait_lbl,
        .bg_color = bg_color,
        .fg_color = fg_color,
    };

    gui_txt_t txt_wait_lbl = {
        .x = 0,
        .y = 165,
        .width = 320,
        .height = 0,
        .bg_color = bg_color,
        .txt = &txt_wait_lbl_p,
        .txt_num = 1,
        .halign = GUI_TEXT_ALIGN_CENTER,
    };

    // Heater wait time value

    gui_txt_p_t txt_wait_val_p[] = {
        {
            .font = font_text,
            .font_size = font_text->default_size,
            .offset = 0,
            .text = str_wait_val,
            .bg_color = bg_color,
            .fg_color = fg_color_val_applied,
        },
        {
            .font = font_text,
            .font_size = font_text->default_size / 2.0,
            .offset = -7,
            .text = str_wait_unit,
            .bg_color = bg_color,
            .fg_color = fg_color_val_applied,
        }
    };

    gui_txt_t txt_wait_val = {
        .x = 0,
        .y = 180,
        .width = 320,
        .height = 0,
        .bg_color = bg_color,
        .txt = txt_wait_val_p,
        .txt_num = 2,
        .halign = GUI_TEXT_ALIGN_CENTER,
    };

    pax_background(screen->pax_buffer, bg_color);

    gui_txt_draw(screen->pax_buffer, &txt_info);
    gui_txt_draw(screen->pax_buffer, &txt_wait_lbl);
    gui_txt_draw(screen->pax_buffer, &txt_wait_val);

    screens_flush(screen);

    while (true) {
        xQueueReceive(screen->buttonQueue, &message, portTICK_PERIOD_MS);

        if (message.state == true) {
            if (message.input == RP2040_INPUT_JOYSTICK_UP) {
                if (heater_wait_ms < HEATER_WAIT_MS_MAX) {
                    heater_wait_ms += 10;
                    sprintf(str_wait_val, str_wait_val_fmt, heater_wait_ms);
                    txt_wait_val_p[0].fg_color = fg_color_val_changing;
                    txt_wait_val_p[1].fg_color = fg_color_val_changing;
                    gui_txt_draw(screen->pax_buffer, &txt_wait_val);
                    screens_flush(screen);
                }
            } else if (message.input == RP2040_INPUT_JOYSTICK_DOWN) {
                if (heater_wait_ms > HEATER_WAIT_MS_MIN) {
                    heater_wait_ms -= 10;
                    sprintf(str_wait_val, str_wait_val_fmt, heater_wait_ms);
                    txt_wait_val_p[0].fg_color = fg_color_val_changing;
                    txt_wait_val_p[1].fg_color = fg_color_val_changing;
                    gui_txt_draw(screen->pax_buffer, &txt_wait_val);
                    screens_flush(screen);
                }
            } else if (message.input == RP2040_INPUT_BUTTON_ACCEPT) {
                gas_sensor_set_heater_wait(heater_wait_ms);
                txt_wait_val_p[0].fg_color = fg_color_val_applied;
                txt_wait_val_p[1].fg_color = fg_color_val_applied;
                gui_txt_draw(screen->pax_buffer, &txt_wait_val);
                screens_flush(screen);
            } else if (message.input == RP2040_INPUT_JOYSTICK_LEFT) {
                screens_next_left();
                break;
            } else if (message.input == RP2040_INPUT_JOYSTICK_RIGHT) {
                screens_next_right();
                break;
            }
        }
    }
}