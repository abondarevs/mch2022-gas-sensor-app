#pragma once

#include <esp_err.h>
#include <stdint.h>

typedef struct gas_sensor_meas_t {
    double temperature;
    double humidity;
    double pressure;
    double gas_resistance;
} gas_sensor_meas_t;

esp_err_t gas_sensor_init(void);
esp_err_t gas_sensor_get_meas(gas_sensor_meas_t* meas);