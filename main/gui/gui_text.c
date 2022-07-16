#include "pax_gfx.h"
#include "gui_text.h"

void gui_txt_draw(pax_buf_t* pax_buffer, gui_txt_t * txt)
{
    pax_vec1_t dims;
    float text_width = 0.0;
    float text_max_height = 0.0;
    float x = 0.0;
    float box_height = txt->height;

    // Calculate the total width of the text and the maximum height of a line
    for (uint32_t i = 0; i < txt->txt_num; i++)
    {
        dims = pax_text_size(txt->txt[i].font, txt->txt[i].font_size, txt->txt[i].text);
        text_width += dims.x;
        if (dims.y > text_max_height) {
            text_max_height = dims.y;
        }
    }

    // Calculate starting point
    if (txt->halign == GUI_TEXT_ALIGN_LEFT) {
        x = txt->x;
    } else if (txt->halign == GUI_TEXT_ALIGN_RIGHT) {
        x = txt->x + txt->width - text_width;
    } else if (txt->halign == GUI_TEXT_ALIGN_CENTER) {
        x = txt->x + txt->width / 2 - text_width / 2;
    }

    if (txt->height == 0.0) {
        box_height = text_max_height;
    }

    pax_draw_rect(pax_buffer, txt->bg_color, txt->x, txt->y, txt->width, box_height);

    // Draw the text to the buffer
    for (uint32_t i = 0; i < txt->txt_num; i++)
    {
        dims = pax_text_size(txt->txt[i].font, txt->txt[i].font_size, txt->txt[i].text);
        pax_draw_rect(pax_buffer, txt->txt[i].bg_color, x, txt->y, dims.x, text_max_height);
        pax_draw_text(pax_buffer, txt->txt[i].fg_color, txt->txt[i].font, txt->txt[i].font_size, x, txt->y + (text_max_height - dims.y + txt->txt[i].offset), txt->txt[i].text);
        x =  x + dims.x + 1;
    }
}