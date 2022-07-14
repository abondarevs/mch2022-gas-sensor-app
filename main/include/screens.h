#pragma once

#include <sdkconfig.h>
#include <freertos/FreeRTOS.h>
#include <freertos/task.h>
#include <freertos/queue.h>
#include "pax_gfx.h"
#include "ili9341.h"

typedef struct screen screen_t;

typedef void (*screen_handler_func_t)(screen_t*);

typedef struct screen {
    pax_buf_t* pax_buffer;
    ILI9341* ili9341;
    xQueueHandle buttonQueue;
    screen_handler_func_t handler;
} screen_t;

typedef enum  {
    SCREEN_ID_LIVE = 0,
    SCREEN_ID_SETTINGS_HEAT_SETPOINT = 1,
    SCREEN_ID_SETTINGS_HEAT_WAIT = 2,
    SCREEN_ID_NUM = 3,
} screen_id_t;

void screens_init(xQueueHandle buttonQueue, pax_buf_t* pax_buffer, ILI9341* ili9341) ;
void screens_next_left(void);
void screens_next_right(void);
void screens_show_next(void);
void screens_flush(screen_t* screen);
void screens_update_footer(screen_t* screen);