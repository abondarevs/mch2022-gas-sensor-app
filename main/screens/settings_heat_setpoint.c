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

#define HEATER_TEMP_MAX     500
#define HEATER_TEMP_MIN     30

static void s_update_heater_setpoint(screen_t* screen, double setpoint) {
    static pax_vec1_t dims_last;
    char str_setpoint[30];
    const pax_font_t *font = pax_get_font("saira regular");
    float x0 = (screen->pax_buffer->width / 2.0 - dims_last.x / 2.0);

    sprintf(str_setpoint, "%.0fC", setpoint);
    pax_draw_rect(screen->pax_buffer, 0xffffffff, x0, 30.0, dims_last.x, dims_last.y);
    dims_last = pax_text_size(font, 24, str_setpoint);
    x0 = (screen->pax_buffer->width / 2.0 - dims_last.x / 2.0);
    pax_draw_text(screen->pax_buffer, 0xff000000, font, 24, x0, 30.0, str_setpoint);
}

void screen_settings_heater_setpoint(screen_t* screen) {
    double heater_setpoint;
    char str_setpoint_lbl[30];

    pax_vec1_t dims;
    rp2040_input_message_t message;

    pax_col_t bg_color = pax_col_hsv(0, 0 /*saturation*/, 255 /*brighness*/);

    heater_setpoint = gas_sensor_get_heater_setpoint();

    sprintf(str_setpoint_lbl, "Heater set-point");

    pax_background(screen->pax_buffer, bg_color);
    const pax_font_t *font = pax_get_font("saira regular");

    dims = pax_text_size(font, 24, str_setpoint_lbl);
    pax_draw_text(screen->pax_buffer, 0xff000000, font, 24, (screen->pax_buffer->width / 2) - dims.x / 2, 5, str_setpoint_lbl);

    s_update_heater_setpoint(screen, heater_setpoint);

    screens_flush(screen);

    while (true) {
        xQueueReceive(screen->buttonQueue, &message, portTICK_PERIOD_MS);

        if (message.state == true) {
            if (message.input == RP2040_INPUT_JOYSTICK_UP) {
                if (heater_setpoint < HEATER_TEMP_MAX) {
                    heater_setpoint += 10;
                    s_update_heater_setpoint(screen, heater_setpoint);
                    screens_flush(screen);
                }
            } else if (message.input == RP2040_INPUT_JOYSTICK_DOWN) {
                if (heater_setpoint > HEATER_TEMP_MIN) {
                    heater_setpoint -= 10;
                    s_update_heater_setpoint(screen, heater_setpoint);
                    screens_flush(screen);
                }
            } else if (message.input == RP2040_INPUT_BUTTON_ACCEPT) {
                gas_sensor_set_heater_setpoint(heater_setpoint);
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