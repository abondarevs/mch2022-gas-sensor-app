#pragma once

#include "pax_gfx.h"

typedef struct {
    pax_font_t* font;
    float font_size;
    float offset;
    char* text;
    pax_col_t bg_color;
    pax_col_t fg_color;
} gui_txt_p_t;

typedef enum {
    GUI_TEXT_ALIGN_LEFT = 0,
    GUI_TEXT_ALIGN_RIGHT = 1,
    GUI_TEXT_ALIGN_CENTER = 2
} gui_text_align_t;

typedef struct {
    float x;
    float y;
    float width;
    float height;
    gui_txt_p_t* txt;
    uint8_t txt_num;
    gui_text_align_t halign;
} gui_txt_t;

void gui_txt_draw(pax_buf_t* pax_buffer, gui_txt_t * txt);
