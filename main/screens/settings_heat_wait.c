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

#define HEATER_WAIT_MS_MAX     4096
#define HEATER_WAIT_MS_MIN     0

static void s_update_heater_wait(screen_t* screen, uint32_t wait_ms) {
    static pax_vec1_t dims_last;
    char str_wait_ms[30];
    const pax_font_t *font = pax_get_font("saira regular");
    float x0 = (screen->pax_buffer->width / 2.0 - dims_last.x / 2.0);

    sprintf(str_wait_ms, "%ums", wait_ms);
    pax_draw_rect(screen->pax_buffer, 0xffffffff, x0, 30.0, dims_last.x, dims_last.y);
    dims_last = pax_text_size(font, 24, str_wait_ms);
    x0 = (screen->pax_buffer->width / 2.0 - dims_last.x / 2.0);
    pax_draw_text(screen->pax_buffer, 0xff000000, font, 24, x0, 30.0, str_wait_ms);
}

void screen_settings_heater_wait(screen_t* screen)  {
    uint32_t heater_wait_ms;
    char str_setpoint_lbl[30];

    pax_vec1_t dims;
    rp2040_input_message_t message;

    pax_col_t bg_color = pax_col_hsv(0, 0 /*saturation*/, 255 /*brighness*/);

    heater_wait_ms = gas_sensor_get_heater_wait();

    sprintf(str_setpoint_lbl, "Heater on-time");

    pax_background(screen->pax_buffer, bg_color);
    const pax_font_t *font = pax_get_font("saira regular");

    dims = pax_text_size(font, 24, str_setpoint_lbl);
    pax_draw_text(screen->pax_buffer, 0xff000000, font, 24, (screen->pax_buffer->width / 2) - dims.x / 2, 5, str_setpoint_lbl);

    s_update_heater_wait(screen, heater_wait_ms);

    screens_flush(screen);

    while (true) {
        xQueueReceive(screen->buttonQueue, &message, portTICK_PERIOD_MS);

        if (message.state == true) {
            if (message.input == RP2040_INPUT_JOYSTICK_UP) {
                if (heater_wait_ms < HEATER_WAIT_MS_MAX) {
                    heater_wait_ms += 10;
                    s_update_heater_wait(screen, heater_wait_ms);
                    screens_flush(screen);
                }
            } else if (message.input == RP2040_INPUT_JOYSTICK_DOWN) {
                if (heater_wait_ms > HEATER_WAIT_MS_MIN) {
                    heater_wait_ms -= 10;
                    s_update_heater_wait(screen, heater_wait_ms);
                    screens_flush(screen);
                }
            } else if (message.input == RP2040_INPUT_BUTTON_ACCEPT) {
                gas_sensor_set_heater_wait(heater_wait_ms);
                break;
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