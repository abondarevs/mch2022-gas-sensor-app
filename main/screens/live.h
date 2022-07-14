#include <sdkconfig.h>
#include <freertos/FreeRTOS.h>
#include <freertos/task.h>
#include <freertos/queue.h>
#include "pax_gfx.h"
#include "ili9341.h"

void screen_live(screen_t* screen);