#include <freertos/FreeRTOS.h>
#include <freertos/semphr.h>
#include <freertos/task.h>
#include <esp_log.h>
#include "gas_sensor.h"
#include "bme680.h"
#include "hardware.h"

#define MEASUREMENT_WAIT_TIMEOUT_MS 2000U
#define MEASUREMENT_WAIT_STEP_MS 5U

static BME680* bme680_inst;

esp_err_t gas_sensor_init(void) {
    bme680_inst = get_bme680();
    bme680_reset(bme680_inst);
    bme680_set_oversampling(bme680_inst, BME680_OVERSAMPLING_X4,
                                            BME680_OVERSAMPLING_X4,
                                            BME680_OVERSAMPLING_X4);

    bme680_set_gas_wait(bme680_inst, BME680_HEATER_PROFILE_0, BME680_GAS_WAIT_FACTOR_4, 37);
    bme680_set_heater_target(bme680_inst, BME680_HEATER_PROFILE_0, 320.0, 25.0);
    bme680_set_heater_profile(bme680_inst, BME680_HEATER_PROFILE_0);
    bme680_run_gas(bme680_inst);

    return ESP_OK;
}

esp_err_t gas_sensor_get_meas(gas_sensor_meas_t* meas) {
    esp_err_t res;
    bme680_status_t bme680_status;
    uint16_t timeout = MEASUREMENT_WAIT_TIMEOUT_MS;

    bme680_set_mode(bme680_inst, BME680_MEAS_FORCED);

    while (timeout > 0) {
        vTaskDelay(MEASUREMENT_WAIT_STEP_MS / portTICK_PERIOD_MS);
        timeout -= MEASUREMENT_WAIT_STEP_MS;
        bme680_get_status(bme680_inst, &bme680_status);
        if ((bme680_status.measuring == false) &&
            (bme680_status.new_data == true) &&
            (bme680_status.gas_valid == true)) {
            break;
        }
    }

    res = bme680_get_temperature(bme680_inst, &meas->temperature);

    if (res == ESP_OK) {
        res = bme680_get_humidity(bme680_inst, &meas->humidity, meas->temperature);
    }

    if (res == ESP_OK) {
        res = bme680_get_pressure(bme680_inst, &meas->pressure, meas->temperature);
    }

    if (res == ESP_OK) {
        res = bme680_get_gas_resistance(bme680_inst, &meas->gas_resistance);
    }

    return res;
}