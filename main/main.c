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

static pax_buf_t buf;
xQueueHandle buttonQueue;

static const char *TAG = "mch2022-gas-sensor-app";

void disp_flush() {
    ili9341_write(get_ili9341(), buf.buf);
}

void app_main() {
    gas_sensor_meas_t meas;
    char text1[30];
    char text2[30];
    char text3[30];
    char text4[30];
    pax_vec1_t dims;
    uint8_t y_pos = 0;

    // Init HW.
    bsp_init();
    bsp_rp2040_init();
    bsp_bme680_init();
    gas_sensor_init();
    buttonQueue = get_rp2040()->queue;

    // Init GFX.
    pax_buf_init(&buf, NULL, 320, 240, PAX_BUF_16_565RGB);

    while (1) {
        pax_col_t bg_color = pax_col_hsv(0, 0 /*saturation*/, 255 /*brighness*/);

        gas_sensor_get_meas(&meas);
        sprintf(text1, "Temperature: %.1f", meas.temperature);
        sprintf(text2, "Humidity: %.1f", meas.humidity);
        sprintf(text3, "Pressure: %.0f", meas.pressure);
        sprintf(text4, "Gas res: %.0f", meas.gas_resistance);

        pax_background(&buf, bg_color);
        const pax_font_t *font = pax_get_font("saira regular");

        dims = pax_text_size(font, font->default_size, text1);
        y_pos = 5;
        pax_draw_text(&buf, 0xff000000, font, 24, 5, y_pos, text1);

        dims = pax_text_size(font, font->default_size, text2);
        y_pos += dims.y + 5;
        pax_draw_text(&buf, 0xff000000, font, 24, 5, y_pos, text2);

        dims = pax_text_size(font, font->default_size, text3);
        y_pos += dims.y + 5;
        pax_draw_text(&buf, 0xff000000, font, 24, 5, y_pos, text3);

        dims = pax_text_size(font, font->default_size, text4);
        y_pos += dims.y + 5;
        pax_draw_text(&buf, 0xff000000, font, 24, 5, y_pos, text4);

        disp_flush();

        vTaskDelay(1000 / portTICK_PERIOD_MS);
    }
}
