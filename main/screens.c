#include <sdkconfig.h>
#include <freertos/FreeRTOS.h>
#include <freertos/task.h>
#include <freertos/queue.h>
#include "pax_gfx.h"
#include "ili9341.h"
#include "screens.h"
#include "screens/live.h"
#include "screens/settings_heat_setpoint.h"
#include "screens/settings_heat_wait.h"

#define FOOTER_HEIGHT_PX 20.0
#define FOOTER_MARGIN_PX 2

static screen_id_t s_next_screen = 0;
static screen_id_t s_current_screen = 0;

static screen_t s_screens[SCREEN_ID_NUM] = {
    [SCREEN_ID_LIVE] = {
        .handler = screen_live,
    },
    [SCREEN_ID_SETTINGS_HEAT_SETPOINT] = {
        .handler = screen_settings_heater_setpoint,
    },
    [SCREEN_ID_SETTINGS_HEAT_WAIT] = {
        .handler = screen_settings_heater_wait,
    }
};

void screens_init(xQueueHandle buttonQueue, pax_buf_t* pax_buffer, ILI9341* ili9341) {
    for (screen_id_t it_scr = 0; it_scr < SCREEN_ID_NUM; it_scr++) {
        s_screens[it_scr].pax_buffer = pax_buffer;
        s_screens[it_scr].ili9341 = ili9341;
        s_screens[it_scr].buttonQueue = buttonQueue;
    }
}

void screens_next_left(void) {
    if (s_next_screen == 0) {
        s_next_screen = SCREEN_ID_NUM - 1;
    } else {
        s_next_screen--;
    }
}

void screens_next_right(void) {
    s_next_screen++;
    if (s_next_screen >= SCREEN_ID_NUM) {
        s_next_screen = (screen_id_t)0;
    }
}

void screens_show_next(void) {
    s_current_screen = s_next_screen;
    (s_screens[s_next_screen].handler)(&s_screens[s_next_screen]);
}

void screens_flush(screen_t* screen) {
    screens_update_footer(screen);
    ili9341_write(screen->ili9341, screen->pax_buffer->buf);
}

void screens_update_footer(screen_t* screen) {
    pax_vec1_t dims;
    char str_wait_ms[30];
    const pax_font_t *font = pax_get_font("saira regular");
    float x0;
    float y0 = screen->pax_buffer->height - FOOTER_HEIGHT_PX;
    pax_col_t footer_bg_color = pax_col_hsv(0, 0 /*saturation*/, 100 /*brighness*/);
    pax_col_t footer_text_color = pax_col_hsv(0, 0 /*saturation*/, 255 /*brighness*/);

    sprintf(str_wait_ms, "%u/%u    <- Joystick ->", s_current_screen+1, SCREEN_ID_NUM);

    pax_draw_rect(screen->pax_buffer, footer_bg_color, 0, y0, screen->pax_buffer->width, FOOTER_HEIGHT_PX);
    dims = pax_text_size(font, 18, str_wait_ms);
    x0 = (screen->pax_buffer->width / 2.0 - dims.x / 2.0) + FOOTER_MARGIN_PX;
    y0 += FOOTER_MARGIN_PX;
    pax_draw_text(screen->pax_buffer, footer_text_color, font, 18, x0, y0, str_wait_ms);
}