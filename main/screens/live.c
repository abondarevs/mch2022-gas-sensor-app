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

#define MEASUREMENT_UPDATE_PERIOD_MS 5000

void screen_live(screen_t* screen) {
    gas_sensor_meas_t meas;
    char str_temp_val[15];
    char str_hum_val[15];
    char str_pres_val[15];
    char str_gas_val[15];
    char str_lbl_temp[] = "Temperature";
    char str_lbl_hum[] = "Relative Humidity";
    char str_lbl_pres[] = "Pressure";
    char str_lbl_gas[] = "Gas Resistance";
    char str_temp_unit[]= "C";
    char str_hum_unit[] = "%";
    char str_pres_unit[] = "hPa";
    char str_gas_unit[] = "kOhm";
    rp2040_input_message_t message;

    pax_col_t bg_color = pax_col_hsv(0, 0 /*saturation*/, 255 /*brighness*/);
    pax_col_t fg_color = pax_col_hsv(0, 0 /*saturation*/, 0 /*brighness*/);

    pax_font_t* font_values = (pax_font_t*)pax_get_font("saira condensed");
    pax_font_t* font_lbl = (pax_font_t*)pax_get_font("sky mono");

    // Temperature label

    gui_txt_p_t txt_temp_lbl_p = {
        .font = font_lbl,
        .font_size = font_lbl->default_size,
        .offset = 0,
        .text = str_lbl_temp,
        .bg_color = bg_color,
        .fg_color = fg_color,
    };

    gui_txt_t txt_temp_lbl = {
        .x = 0,
        .y = 5,
        .width = 160,
        .txt = &txt_temp_lbl_p,
        .txt_num = 1,
        .halign = GUI_TEXT_ALIGN_CENTER,
    };

    // Relative humidity label

    gui_txt_p_t txt_hum_lbl_p = {
        .font = font_lbl,
        .font_size = font_lbl->default_size,
        .offset = 0,
        .text = str_lbl_hum,
        .bg_color = bg_color,
        .fg_color = fg_color,
    };

    gui_txt_t txt_hum_lbl = {
        .x = 160,
        .y = 5,
        .width = 160,
        .txt = &txt_hum_lbl_p,
        .txt_num = 1,
        .halign = GUI_TEXT_ALIGN_CENTER,
    };

    // Pressure label

    gui_txt_p_t txt_pres_lbl_p = {
        .font = font_lbl,
        .font_size = font_lbl->default_size,
        .offset = 0,
        .text = str_lbl_pres,
        .bg_color = bg_color,
        .fg_color = fg_color,
    };

    gui_txt_t txt_pres_lbl = {
        .x = 0,
        .y = 70,
        .width = 320,
        .txt = &txt_pres_lbl_p,
        .txt_num = 1,
        .halign = GUI_TEXT_ALIGN_CENTER,
    };

    // Gas resistance label

    gui_txt_p_t txt_gas_lbl_p = {
        .font = font_lbl,
        .font_size = font_lbl->default_size,
        .offset = 0,
        .text = str_lbl_gas,
        .bg_color = bg_color,
        .fg_color = fg_color,
    };

    gui_txt_t txt_gas_lbl = {
        .x = 0,
        .y = 140,
        .width = 320,
        .txt = &txt_gas_lbl_p,
        .txt_num = 1,
        .halign = GUI_TEXT_ALIGN_CENTER,
    };

    // Temperature value

    gui_txt_p_t txt_temp_p[] = {
        {
            .font = font_values,
            .font_size = 48,
            .offset = 0,
            .text = str_temp_val,
            .bg_color = bg_color,
            .fg_color = fg_color,
        },
        {
            .font = font_values,
            .font_size = 24,
            .offset = -7,
            .text = str_temp_unit,
            .bg_color = bg_color,
            .fg_color = fg_color,
        }
    };

    gui_txt_t txt_temp = {
        .x = 0,
        .y = 20,
        .width = 160,
        .txt = txt_temp_p,
        .txt_num = 2,
        .halign = GUI_TEXT_ALIGN_CENTER,
    };

    // Relative humidity value

    gui_txt_p_t txt_hum_p[] = {
        {
            .font = font_values,
            .font_size = 48,
            .offset = 0,
            .text = str_hum_val,
            .bg_color = bg_color,
            .fg_color = fg_color,
        },
        {
            .font = font_values,
            .font_size = 24,
            .offset = -7,
            .text = str_hum_unit,
            .bg_color = bg_color,
            .fg_color = fg_color,
        }
    };

    gui_txt_t txt_hum = {
        .x = 160,
        .y = 20,
        .width = 160,
        .txt = txt_hum_p,
        .txt_num = 2,
        .halign = GUI_TEXT_ALIGN_CENTER,
    };

    // Pressure value

    gui_txt_p_t txt_pres_p[] = {
        {
            .font = font_values,
            .font_size = 48,
            .offset = 0,
            .text = str_pres_val,
            .bg_color = bg_color,
            .fg_color = fg_color,
        },
        {
            .font = font_values,
            .font_size = 24,
            .offset = -7,
            .text = str_pres_unit,
            .bg_color = bg_color,
            .fg_color = fg_color,
        }
    };

    gui_txt_t txt_pres = {
        .x = 0,
        .y = 85,
        .width = 320,
        .txt = txt_pres_p,
        .txt_num = 2,
        .halign = GUI_TEXT_ALIGN_CENTER,
    };

    // Gas ressitance value

    gui_txt_p_t txt_gas_p[] = {
        {
            .font = font_values,
            .font_size = 48,
            .offset = 0,
            .text = str_gas_val,
            .bg_color = bg_color,
            .fg_color = fg_color,
        },
        {
            .font = font_values,
            .font_size = 24,
            .offset = -7,
            .text = str_gas_unit,
            .bg_color = bg_color,
            .fg_color = fg_color,
        }
    };

    gui_txt_t txt_gas = {
        .x = 0,
        .y = 155,
        .width = 320,
        .txt = txt_gas_p,
        .txt_num = 2,
        .halign = GUI_TEXT_ALIGN_CENTER,
    };

    while (true) {
        gas_sensor_get_meas(&meas);
        sprintf(str_temp_val, "%.1f", meas.temperature);
        sprintf(str_hum_val, "%.0f", meas.humidity);
        sprintf(str_pres_val, "%.0f", meas.pressure / 100.0);
        sprintf(str_gas_val, "%.1f", meas.gas_resistance / 1000.0);

        pax_background(screen->pax_buffer, bg_color);

        // Temperature
        gui_txt_draw(screen->pax_buffer, &txt_temp_lbl);
        gui_txt_draw(screen->pax_buffer, &txt_temp);

        // Relative humidity
        gui_txt_draw(screen->pax_buffer, &txt_hum_lbl);
        gui_txt_draw(screen->pax_buffer, &txt_hum);

        // Pressure
        gui_txt_draw(screen->pax_buffer, &txt_pres_lbl);
        gui_txt_draw(screen->pax_buffer, &txt_pres);

        // Gas resistance
        gui_txt_draw(screen->pax_buffer, &txt_gas_lbl);
        gui_txt_draw(screen->pax_buffer, &txt_gas);

        screens_flush(screen);

        xQueueReceive(screen->buttonQueue, &message, MEASUREMENT_UPDATE_PERIOD_MS / portTICK_PERIOD_MS);

        if (message.state == true) {
            if (message.input == RP2040_INPUT_JOYSTICK_LEFT) {
                screens_next_left();
                break;
            } else if (message.input == RP2040_INPUT_JOYSTICK_RIGHT) {
                screens_next_right();
                break;
            }
        }
    }
}
