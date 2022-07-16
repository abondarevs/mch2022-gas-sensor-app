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

#define HEATER_TEMP_MAX     500
#define HEATER_TEMP_MIN     30

void screen_settings_heater_setpoint(screen_t* screen) {
    double heater_setpoint;
    char str_setpoint_val[10] = "0";
    char str_setpoint_lbl[] = "Heater set-point";
    char str_setpoint_unit[] = "C";
    char str_setpoint_val_fmt[] = "%.0f";
    char str_info[] =   "The gas sensor is made of SnO2 mate-\n"
                        "rial. The material electrical resistance\n"
                        "changes when in contact with an air\n"
                        "pollutant. The resistance response\n"
                        "dependends on the material tempera-\n"
                        "ture, which can be set from 30 to 500C.\n"
                        "Use joystick to change and A to apply.";

    rp2040_input_message_t message;

    pax_col_t bg_color = pax_col_hsv(0, 0 /*saturation*/, 255 /*brighness*/);
    pax_col_t fg_color = pax_col_hsv(0, 0 /*saturation*/, 0   /*brighness*/);
    pax_col_t fg_color_val_changing = pax_col_hsv(0, 0 /*saturation*/, 100   /*brighness*/);
    pax_col_t fg_color_val_applied = pax_col_hsv(50, 200 /*saturation*/, 150   /*brighness*/);

    pax_font_t* font_text = (pax_font_t*)pax_get_font("saira condensed");
    pax_font_t* font_lbl = (pax_font_t*)pax_get_font("sky mono");

    heater_setpoint = gas_sensor_get_heater_setpoint();
    sprintf(str_setpoint_val, str_setpoint_val_fmt, heater_setpoint);

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

    // Heater set-point label

    gui_txt_p_t txt_heat_set_point_lbl_p = {
        .font = font_lbl,
        .font_size = font_lbl->default_size,
        .offset = 0,
        .text = str_setpoint_lbl,
        .bg_color = bg_color,
        .fg_color = fg_color,
    };

    gui_txt_t txt_heat_set_point_lbl = {
        .x = 0,
        .y = 165,
        .width = 320,
        .height = 0,
        .bg_color = bg_color,
        .txt = &txt_heat_set_point_lbl_p,
        .txt_num = 1,
        .halign = GUI_TEXT_ALIGN_CENTER,
    };

    // Heater set-point value

    gui_txt_p_t txt_heat_set_point_val_p[] = {
        {
            .font = font_text,
            .font_size = font_text->default_size,
            .offset = 0,
            .text = str_setpoint_val,
            .bg_color = bg_color,
            .fg_color = fg_color_val_applied,
        },
        {
            .font = font_text,
            .font_size = font_text->default_size / 2.0,
            .offset = -7,
            .text = str_setpoint_unit,
            .bg_color = bg_color,
            .fg_color = fg_color_val_applied,
        }
    };

    gui_txt_t txt_heat_set_point_val = {
        .x = 0,
        .y = 180,
        .width = 320,
        .height = 0,
        .bg_color = bg_color,
        .txt = txt_heat_set_point_val_p,
        .txt_num = 2,
        .halign = GUI_TEXT_ALIGN_CENTER,
    };

    pax_background(screen->pax_buffer, bg_color);

    gui_txt_draw(screen->pax_buffer, &txt_info);
    gui_txt_draw(screen->pax_buffer, &txt_heat_set_point_lbl);
    gui_txt_draw(screen->pax_buffer, &txt_heat_set_point_val);

    screens_flush(screen);

    while (true) {
        xQueueReceive(screen->buttonQueue, &message, portTICK_PERIOD_MS);

        if (message.state == true) {
            if (message.input == RP2040_INPUT_JOYSTICK_UP) {
                if (heater_setpoint < HEATER_TEMP_MAX) {
                    heater_setpoint += 10;
                    sprintf(str_setpoint_val, str_setpoint_val_fmt, heater_setpoint);
                    txt_heat_set_point_val_p[0].fg_color = fg_color_val_changing;
                    txt_heat_set_point_val_p[1].fg_color = fg_color_val_changing;
                    gui_txt_draw(screen->pax_buffer, &txt_heat_set_point_val);
                    screens_flush(screen);
                }
            } else if (message.input == RP2040_INPUT_JOYSTICK_DOWN) {
                if (heater_setpoint > HEATER_TEMP_MIN) {
                    heater_setpoint -= 10;
                    sprintf(str_setpoint_val, str_setpoint_val_fmt, heater_setpoint);
                    txt_heat_set_point_val_p[0].fg_color = fg_color_val_changing;
                    txt_heat_set_point_val_p[1].fg_color = fg_color_val_changing;
                    gui_txt_draw(screen->pax_buffer, &txt_heat_set_point_val);
                    screens_flush(screen);
                }
            } else if (message.input == RP2040_INPUT_BUTTON_ACCEPT) {
                gas_sensor_set_heater_setpoint(heater_setpoint);
                txt_heat_set_point_val_p[0].fg_color = fg_color_val_applied;
                txt_heat_set_point_val_p[1].fg_color = fg_color_val_applied;
                gui_txt_draw(screen->pax_buffer, &txt_heat_set_point_val);
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