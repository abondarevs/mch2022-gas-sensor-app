#pragma once

#include "pax_gfx.h"

/* Holds a part of text */
typedef struct {
    /* Text font */
    pax_font_t* font;
    /* Text size */
    float font_size;
    /* Vertical offset in pixels */
    float offset;
    /* Text string */
    char* text;
    /* Text background color */
    pax_col_t bg_color;
    /* Text foreground color*/
    pax_col_t fg_color;
} gui_txt_p_t;

/* Alignment inside of the text box */
typedef enum {
    GUI_TEXT_ALIGN_LEFT = 0,
    GUI_TEXT_ALIGN_RIGHT = 1,
    GUI_TEXT_ALIGN_CENTER = 2
} gui_text_align_t;

/* Holds information necessary for the text box draw */
typedef struct {
    /* Position of the text box along horizontal axis */
    float x;
    /* Position of the text box along vertical axis */
    float y;
    /* Width of the text box */
    float width;
    /* height of the text box */
    float height;
    /* Text box background color */
    pax_col_t bg_color;
    /* Pointer to array of text parts */
    gui_txt_p_t* txt;
    /* Number of elements in the text parts array */
    uint8_t txt_num;
    /* Horizontal align mode */
    gui_text_align_t halign;
} gui_txt_t;


void gui_txt_draw(pax_buf_t* pax_buffer, gui_txt_t * txt);
