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

static pax_buf_t buf_main;
static xQueueHandle buttonQueue;

static const char *TAG = "mch2022-gas-sensor-app";

void app_main() {
    // Init HW.
    bsp_init();
    bsp_rp2040_init();
    bsp_bme680_init();
    gas_sensor_init();
    buttonQueue = get_rp2040()->queue;

    // Init GFX.
    pax_buf_init(&buf_main, NULL, 320, 240, PAX_BUF_16_565RGB);
    screens_init(buttonQueue, &buf_main, get_ili9341());

    while (1) {
        screens_show_next();
    }
}
