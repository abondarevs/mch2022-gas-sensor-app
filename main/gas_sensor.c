#include <freertos/FreeRTOS.h>
#include <freertos/semphr.h>
#include <freertos/task.h>
#include <esp_log.h>
#include "gas_sensor.h"
#include "bme680.h"
#include "hardware.h"

#define MEASUREMENT_WAIT_TIMEOUT_MS 2000U
#define MEASUREMENT_WAIT_STEP_MS 5U

static BME680* s_bme680_inst;
static double s_heater_setpoint = 320.0;
static uint32_t s_heater_wait_ms = 150;
static double s_last_temperature = 25.0;

esp_err_t gas_sensor_init(void) {
    s_bme680_inst = get_bme680();
    bme680_reset(s_bme680_inst);
    bme680_set_oversampling(s_bme680_inst, BME680_OVERSAMPLING_X4,
                                            BME680_OVERSAMPLING_X4,
                                            BME680_OVERSAMPLING_X4);

    gas_sensor_set_heater_wait(s_heater_wait_ms);
    gas_sensor_set_heater_setpoint(s_heater_setpoint);
    bme680_set_heater_profile(s_bme680_inst, BME680_HEATER_PROFILE_0);
    bme680_run_gas(s_bme680_inst);

    return ESP_OK;
}

esp_err_t gas_sensor_get_meas(gas_sensor_meas_t* meas) {
    esp_err_t res;
    bme680_status_t bme680_status;
    uint16_t timeout = MEASUREMENT_WAIT_TIMEOUT_MS;

    bme680_set_mode(s_bme680_inst, BME680_MEAS_FORCED);

    while (timeout > 0) {
        vTaskDelay(MEASUREMENT_WAIT_STEP_MS / portTICK_PERIOD_MS);
        timeout -= MEASUREMENT_WAIT_STEP_MS;
        bme680_get_status(s_bme680_inst, &bme680_status);
        if ((bme680_status.measuring == false) &&
            (bme680_status.new_data == true) &&
            (bme680_status.gas_valid == true)) {
            break;
        }
    }

    res = bme680_get_temperature(s_bme680_inst, &meas->temperature);

    if (res == ESP_OK) {
        s_last_temperature = meas->temperature;
        bme680_set_heater_target(s_bme680_inst, BME680_HEATER_PROFILE_0, s_heater_setpoint, meas->temperature);
    }

    if (res == ESP_OK) {
        res = bme680_get_humidity(s_bme680_inst, &meas->humidity, meas->temperature);
    }

    if (res == ESP_OK) {
        res = bme680_get_pressure(s_bme680_inst, &meas->pressure, meas->temperature);
    }

    if (res == ESP_OK) {
        res = bme680_get_gas_resistance(s_bme680_inst, &meas->gas_resistance);
    }

    return res;
}

double gas_sensor_get_heater_setpoint(void) {
    return s_heater_setpoint;
}

esp_err_t gas_sensor_set_heater_setpoint(double temperature) {
    esp_err_t res;
    s_heater_setpoint = temperature;
    res = bme680_set_heater_target(s_bme680_inst, BME680_HEATER_PROFILE_0, s_heater_setpoint, s_last_temperature);
    return res;
}

esp_err_t gas_sensor_set_heater_wait(uint32_t wait_ms) {
    esp_err_t res;
    s_heater_wait_ms = wait_ms;
    bme680_gas_wait_factor_t wait_factor = BME680_GAS_WAIT_FACTOR_1;

    if (wait_ms <= 64) {
        wait_factor = BME680_GAS_WAIT_FACTOR_1;
    } else if ((wait_ms > 64) && (wait_ms <= 256)) {
        wait_factor = BME680_GAS_WAIT_FACTOR_4;
        wait_ms /= 4;
    } else if ((wait_ms > 256) && (wait_ms <= 1024)) {
        wait_factor = BME680_GAS_WAIT_FACTOR_16;
        wait_ms /= 16;
    } else if ((wait_ms > 1024) && (wait_ms <= 4096)) {
        wait_factor = BME680_GAS_WAIT_FACTOR_64;
        wait_ms /= 64;
    } else {
        wait_factor = BME680_GAS_WAIT_FACTOR_64;
        wait_ms = 64;
    }

    res = bme680_set_gas_wait(s_bme680_inst, BME680_HEATER_PROFILE_0, wait_factor, wait_ms);

    return res;
}

uint32_t gas_sensor_get_heater_wait(void) {
    return s_heater_wait_ms;
}

