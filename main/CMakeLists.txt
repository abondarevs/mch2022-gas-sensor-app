idf_component_register(
    SRCS
        "gas_sensor.c"
        "main.c"
        "screens.c"
        "wifi_connect.c"
        "wifi_connection.c"
        "screens/live.c"
        "screens/settings_heat_setpoint.c"
        "screens/settings_heat_wait.c"
    INCLUDE_DIRS
        "." "include"
)