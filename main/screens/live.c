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

void screen_live(screen_t* screen) {
    gas_sensor_meas_t meas;
    char str_temp[20];
    char str_hum[20];
    char str_pres[20];
    char str_gas[20];
    pax_vec1_t dims;
    rp2040_input_message_t message;

    pax_col_t bg_color = pax_col_hsv(0, 0 /*saturation*/, 255 /*brighness*/);

    while (true) {
        gas_sensor_get_meas(&meas);
        sprintf(str_temp, "%.0fC", meas.temperature);
        sprintf(str_hum, "%.0f%%", meas.humidity);
        sprintf(str_pres, "%.0fkPa", meas.pressure / 1000.0);
        sprintf(str_gas, "%.0fkOhm", meas.gas_resistance / 1000.0);

        pax_background(screen->pax_buffer, bg_color);
        const pax_font_t *font = pax_get_font("saira regular");

        dims = pax_text_size(font, 48, str_temp);
        pax_draw_text(screen->pax_buffer, 0xff000000, font, 48, (screen->pax_buffer->width / 4.0) - dims.x / 2.0, 5.0, str_temp);

        dims = pax_text_size(font, 48, str_hum);
        pax_draw_text(screen->pax_buffer, 0xff000000, font, 48, (screen->pax_buffer->width / 4.0)*3.0 - dims.x / 2.0, 5.0, str_hum);

        dims = pax_text_size(font, 48, str_pres);
        pax_draw_text(screen->pax_buffer, 0xff000000, font, 48, (screen->pax_buffer->width / 2.0) - dims.x/2.0, 80.0, str_pres);

        dims = pax_text_size(font, 48, str_gas);
        pax_draw_text(screen->pax_buffer, 0xff000000, font, 48, (screen->pax_buffer->width / 2.0) - dims.x/2.0, 150.0, str_gas);

        screens_flush(screen);

        xQueueReceive(screen->buttonQueue, &message, 5000 / portTICK_PERIOD_MS);

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
