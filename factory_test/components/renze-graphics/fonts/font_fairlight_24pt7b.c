#include "../include/driver_framebuffer.h"
const uint8_t fairlight_24pt7bBitmaps[] = {
  0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
  0x1F, 0x03, 0xE0, 0x00, 0x00, 0x00, 0x00, 0x3E, 0x07, 0xC0, 0xF8, 0x1F,
  0x03, 0xE0, 0xF8, 0x39, 0xF0, 0x73, 0xE0, 0xFF, 0xC1, 0xFF, 0x83, 0xE0,
  0x1F, 0x3E, 0x07, 0xCF, 0x81, 0xF3, 0xE0, 0x7C, 0xF8, 0x1F, 0x3E, 0x3F,
  0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x1F, 0x3E, 0x07, 0xCF, 0x8F, 0xFF,
  0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xC7, 0xCF, 0x81, 0xF3, 0xE0, 0x7C, 0xF8,
  0x1F, 0x3E, 0x07, 0xCF, 0x80, 0x07, 0xC0, 0x0F, 0x80, 0x1F, 0x01, 0xFF,
  0xF3, 0xFF, 0xE7, 0xFF, 0xFE, 0x00, 0x7C, 0x00, 0xF8, 0x00, 0x7F, 0xF0,
  0xFF, 0xE1, 0xFF, 0xCF, 0xFF, 0xDF, 0xFF, 0x3F, 0xFE, 0x03, 0xE0, 0x07,
  0xC0, 0x0F, 0x80, 0xF8, 0x07, 0xF0, 0x0F, 0xE0, 0x1F, 0xC1, 0xFF, 0x83,
  0xE0, 0x1F, 0x00, 0x3E, 0x00, 0x7C, 0x07, 0xC0, 0x0F, 0x80, 0x7C, 0x00,
  0xF8, 0x01, 0xF0, 0x1F, 0x07, 0xFE, 0x0F, 0xF0, 0x1F, 0xE0, 0x3F, 0xC0,
  0x7C, 0x1F, 0xF8, 0x0F, 0xFC, 0x07, 0xFE, 0x1F, 0x07, 0xCF, 0x83, 0xE7,
  0xC1, 0xF0, 0x7F, 0xE0, 0x3F, 0xF0, 0x1F, 0xF8, 0x0F, 0xE0, 0x3E, 0x0F,
  0xFF, 0x07, 0xFF, 0x83, 0xFF, 0xC1, 0xF3, 0xE0, 0xF8, 0x3F, 0xFF, 0x1F,
  0xFF, 0x8F, 0xFF, 0xC0, 0x07, 0xC1, 0xF0, 0x7C, 0x7C, 0x1F, 0x3E, 0x0F,
  0x83, 0xE0, 0x07, 0xC1, 0xF0, 0x7C, 0x7C, 0x1F, 0x07, 0xC1, 0xF0, 0x7C,
  0xF8, 0x3E, 0x0F, 0x83, 0xE0, 0xF8, 0x07, 0xC1, 0xF0, 0x7C, 0x1F, 0x07,
  0xC0, 0x7C, 0x1F, 0x07, 0xC0, 0xF8, 0x3E, 0x0F, 0x80, 0x7C, 0x1F, 0x07,
  0xC1, 0xF0, 0x7C, 0x07, 0xC1, 0xF0, 0x7C, 0x1F, 0x07, 0xC7, 0xC1, 0xF0,
  0x7C, 0x1F, 0x07, 0xCF, 0x83, 0xE0, 0xF8, 0x00, 0x1F, 0x3E, 0x07, 0xCF,
  0x81, 0xF3, 0xE0, 0x1F, 0xC0, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFC,
  0x1F, 0xC0, 0x07, 0xF0, 0x07, 0xCF, 0x81, 0xF3, 0xE0, 0x7C, 0xF8, 0x07,
  0xC0, 0x0F, 0x80, 0x1F, 0x00, 0x3E, 0x0F, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
  0x83, 0xE0, 0x07, 0xC0, 0x0F, 0x80, 0x1F, 0x00, 0x3E, 0x00, 0x1F, 0x1F,
  0x1F, 0x1F, 0x1F, 0xF8, 0xF8, 0xF8, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
  0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xC0, 0xFF, 0xFF, 0xFF, 0x80, 0x00, 0x07,
  0xC0, 0x01, 0xF0, 0x00, 0x7C, 0x00, 0xF8, 0x00, 0x3E, 0x00, 0x3E, 0x00,
  0x0F, 0x80, 0x1F, 0x00, 0x07, 0xC0, 0x01, 0xF0, 0x01, 0xF0, 0x00, 0x7C,
  0x00, 0xF8, 0x00, 0x3E, 0x00, 0x0F, 0x80, 0x00, 0x1F, 0xFE, 0x07, 0xFF,
  0x81, 0xFF, 0xE3, 0xF8, 0x1F, 0xF8, 0x1F, 0xFE, 0x07, 0xFF, 0x81, 0xFF,
  0xFF, 0x9F, 0xFF, 0xE7, 0xFF, 0xF9, 0xFF, 0xE0, 0x7F, 0xF8, 0x1F, 0xF8,
  0x1F, 0xFE, 0x07, 0xFF, 0x81, 0xFC, 0x7F, 0xF8, 0x1F, 0xFE, 0x07, 0xFF,
  0x80, 0x1F, 0xC1, 0xFC, 0x1F, 0xCF, 0x80, 0xF8, 0x0F, 0x80, 0x07, 0xC0,
  0x7C, 0x07, 0xC0, 0x7C, 0x07, 0xC0, 0x7C, 0x07, 0xC0, 0x7C, 0x07, 0xC0,
  0x7F, 0x07, 0xF0, 0x7F, 0x1F, 0xF1, 0xF0, 0x03, 0xE0, 0x07, 0xC0, 0x00,
  0x03, 0xE0, 0x07, 0xC0, 0x0F, 0x83, 0xF8, 0x07, 0xF0, 0x0F, 0xE0, 0x7C,
  0x00, 0xF8, 0x0F, 0x83, 0xFF, 0x07, 0xFE, 0x0F, 0xFF, 0xF8, 0xFF, 0xF1,
  0xFF, 0xE0, 0xFF, 0xF1, 0xFF, 0xE3, 0xFF, 0xC0, 0x00, 0x00, 0x00, 0x00,
  0x07, 0xC0, 0x0F, 0x80, 0x1F, 0x07, 0xF0, 0x0F, 0xE0, 0x1F, 0xC0, 0x01,
  0xFF, 0x83, 0xFF, 0x07, 0xFE, 0x0F, 0x8F, 0xF8, 0x1F, 0xF0, 0x3F, 0xE0,
  0x00, 0xFE, 0x00, 0x7F, 0x00, 0x3F, 0x80, 0xE0, 0x00, 0x70, 0x00, 0xF9,
  0xF0, 0x7C, 0xF8, 0x3E, 0x7C, 0xF8, 0x3E, 0x7C, 0x1F, 0x3F, 0xFF, 0xFF,
  0xFF, 0xFF, 0xFF, 0xF8, 0x01, 0xF0, 0x00, 0xF8, 0x00, 0x7F, 0x00, 0x3F,
  0x80, 0x1F, 0xC0, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFC, 0x00, 0x00,
  0x00, 0x00, 0x3E, 0x00, 0x0F, 0x80, 0x03, 0xFF, 0xF8, 0xFF, 0xFE, 0x3F,
  0xFF, 0x80, 0x00, 0x7C, 0x00, 0x1F, 0xF8, 0x1F, 0xFE, 0x07, 0xFF, 0x81,
  0xFC, 0x7F, 0xF8, 0x1F, 0xFE, 0x07, 0xFF, 0x80, 0x07, 0xFE, 0x01, 0xFF,
  0x80, 0x7F, 0xE0, 0x7C, 0x1F, 0x1F, 0x07, 0xC7, 0xC1, 0xFF, 0x80, 0x03,
  0xFF, 0xF8, 0xFF, 0xFE, 0x3F, 0xFF, 0x8F, 0x80, 0x7F, 0xE0, 0x1F, 0xF8,
  0x07, 0xFE, 0x07, 0xFF, 0x81, 0xFC, 0x7F, 0xF8, 0x1F, 0xFE, 0x07, 0xFF,
  0x80, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xF8, 0x00, 0x00, 0x00, 0x00, 0x1F,
  0x00, 0x3E, 0x00, 0x7C, 0x00, 0xF8, 0x01, 0xF0, 0x1F, 0x00, 0x3E, 0x00,
  0x7C, 0x00, 0xF8, 0x01, 0xF0, 0x03, 0xE0, 0x07, 0xC0, 0x0F, 0x80, 0x1F,
  0xFE, 0x07, 0xFF, 0x81, 0xFF, 0xE3, 0xF8, 0x00, 0xF8, 0x07, 0xFE, 0x01,
  0xFF, 0x80, 0x7C, 0x7F, 0xF8, 0x1F, 0xFE, 0x07, 0xFF, 0x8F, 0x80, 0x7F,
  0xE0, 0x1F, 0xF8, 0x07, 0xFE, 0x07, 0xFF, 0x81, 0xFC, 0x7F, 0xF8, 0x1F,
  0xFE, 0x07, 0xFF, 0x80, 0x1F, 0xFE, 0x07, 0xFF, 0x81, 0xFF, 0xE3, 0xF8,
  0x00, 0xFE, 0x00, 0x3E, 0x01, 0xFF, 0x80, 0x7C, 0x7F, 0xFF, 0x1F, 0xFF,
  0xC7, 0xFF, 0xF0, 0x00, 0x7C, 0x00, 0x1F, 0xF8, 0x1F, 0xFE, 0x07, 0xFF,
  0x81, 0xFC, 0x7F, 0xF8, 0x1F, 0xFE, 0x07, 0xFF, 0x80, 0xFF, 0xFE, 0x00,
  0x00, 0x1F, 0xFF, 0xC0, 0x1F, 0x1F, 0x1F, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x1F, 0x1F, 0x1F, 0x1F, 0x1F, 0xF8, 0xF8, 0xF8, 0x00, 0xFE, 0x01, 0xFC,
  0x03, 0xF8, 0x3E, 0x00, 0x7C, 0x03, 0xE0, 0x07, 0xC0, 0x7C, 0x00, 0xF8,
  0x01, 0xF0, 0x00, 0x7C, 0x00, 0xF8, 0x01, 0xF0, 0x00, 0xF8, 0x01, 0xF0,
  0x00, 0x7F, 0x00, 0xFE, 0x01, 0xFC, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xF8,
  0x00, 0x00, 0x00, 0x1F, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFE, 0x03, 0xF8,
  0x0F, 0xE0, 0x03, 0xE0, 0x0F, 0x80, 0x07, 0xC0, 0x1F, 0x00, 0x1F, 0x00,
  0x7C, 0x01, 0xF0, 0x1F, 0x00, 0x7C, 0x01, 0xF0, 0x3E, 0x00, 0xF8, 0x3F,
  0x80, 0xFE, 0x03, 0xF8, 0x00, 0x3F, 0xF8, 0x7F, 0xF0, 0xFF, 0xE7, 0xC1,
  0xFF, 0x83, 0xFF, 0x07, 0xC0, 0x0F, 0x80, 0x1F, 0x00, 0xF8, 0x01, 0xF0,
  0x1F, 0x00, 0x3E, 0x00, 0x7C, 0x00, 0x00, 0x00, 0x00, 0x03, 0xE0, 0x07,
  0xC0, 0x0F, 0x80, 0x1F, 0xF0, 0x3F, 0xE0, 0x7F, 0xC7, 0xC1, 0xFF, 0x83,
  0xFF, 0x1F, 0xFE, 0x3F, 0xFC, 0x7F, 0xF8, 0xFF, 0xF1, 0xFF, 0xE0, 0x07,
  0xC0, 0x0F, 0x80, 0xFF, 0x01, 0xFE, 0x03, 0x8F, 0xF8, 0x1F, 0xF0, 0x3F,
  0xE0, 0x07, 0xFF, 0xC1, 0xFF, 0xF0, 0x7F, 0xFC, 0x7C, 0x00, 0x1F, 0x00,
  0x3E, 0x01, 0xFF, 0x80, 0x7F, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
  0x80, 0x7F, 0xE0, 0x1F, 0xF8, 0x07, 0xFE, 0x01, 0xFF, 0x80, 0x7C, 0x7C,
  0x1F, 0x1F, 0x07, 0xC7, 0xC1, 0xF0, 0xFF, 0xFE, 0x3F, 0xFF, 0x8F, 0xFF,
  0xE0, 0x00, 0x1F, 0x00, 0x07, 0xFE, 0x07, 0xFF, 0x81, 0xFF, 0xFF, 0xF8,
  0xFF, 0xFE, 0x3F, 0xFF, 0x8F, 0x80, 0x7F, 0xE0, 0x1F, 0xF8, 0x07, 0xFE,
  0x07, 0xFF, 0x81, 0xFF, 0xFF, 0xF8, 0xFF, 0xFE, 0x3F, 0xFF, 0x80, 0x07,
  0xFE, 0x0F, 0xFC, 0x1F, 0xF8, 0xF8, 0x01, 0xF0, 0x1F, 0x00, 0x3E, 0x00,
  0x7C, 0x00, 0xF8, 0x01, 0xF0, 0x03, 0xE0, 0x07, 0xC0, 0x0F, 0x83, 0xFF,
  0x07, 0xFE, 0x0F, 0x8F, 0xFC, 0x1F, 0xF8, 0x3F, 0xF0, 0xFF, 0xFE, 0x3F,
  0xFF, 0x8F, 0xFF, 0xE0, 0x00, 0x1F, 0x00, 0x07, 0xFE, 0x01, 0xFF, 0x80,
  0x7F, 0xE0, 0x1F, 0xF8, 0x07, 0xFE, 0x01, 0xFF, 0x83, 0xE3, 0xE0, 0xF8,
  0xF8, 0x3E, 0x3E, 0x3F, 0x8F, 0x8F, 0xE3, 0xFF, 0x00, 0xFF, 0xC0, 0x3F,
  0xF0, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFC, 0x00, 0x00, 0x00,
  0x00, 0x3E, 0x00, 0x0F, 0x80, 0x03, 0xFF, 0xE0, 0xFF, 0xF8, 0x3F, 0xFE,
  0x0F, 0x80, 0x03, 0xE0, 0x00, 0xFE, 0x07, 0xFF, 0x81, 0xFF, 0xE0, 0x7C,
  0x7F, 0xF8, 0x1F, 0xFE, 0x07, 0xFF, 0x80, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
  0xFF, 0xFC, 0x00, 0x00, 0x00, 0x00, 0x3E, 0x00, 0x0F, 0x80, 0x03, 0xFF,
  0xE0, 0xFF, 0xF8, 0x3F, 0xFE, 0x0F, 0x80, 0x03, 0xE0, 0x00, 0xF8, 0x00,
  0x3E, 0x00, 0x0F, 0x80, 0x00, 0x7C, 0x00, 0x1F, 0x00, 0x07, 0xC0, 0x00,
  0x1F, 0xFE, 0x07, 0xFF, 0x81, 0xFF, 0xE3, 0xF8, 0x1F, 0xFE, 0x07, 0xFF,
  0x81, 0xFF, 0x80, 0x03, 0xE0, 0x7F, 0xF8, 0x1F, 0xFE, 0x07, 0xFF, 0x80,
  0x7F, 0xE0, 0x1F, 0xF8, 0x07, 0xFE, 0x07, 0xFF, 0x81, 0xFC, 0x7F, 0xF8,
  0x1F, 0xFE, 0x07, 0xFF, 0x80, 0xF8, 0x07, 0xFE, 0x01, 0xFF, 0x80, 0x7C,
  0x00, 0x1F, 0x00, 0x07, 0xFE, 0x01, 0xFF, 0x80, 0x7F, 0xFF, 0xFF, 0xFF,
  0xFF, 0xFF, 0xFF, 0xFF, 0x80, 0x7F, 0xE0, 0x1F, 0xF8, 0x07, 0xFE, 0x01,
  0xFF, 0x80, 0x7C, 0x7C, 0x1F, 0x1F, 0x07, 0xC7, 0xC1, 0xF0, 0xFF, 0xFF,
  0xFF, 0xFF, 0xFF, 0xF8, 0x00, 0x00, 0x00, 0x00, 0xF8, 0x01, 0xF0, 0x03,
  0xE0, 0x07, 0xC0, 0x0F, 0x80, 0x1F, 0x00, 0x3E, 0x00, 0x7C, 0x00, 0xF8,
  0x01, 0xF0, 0x0F, 0xFF, 0x1F, 0xFE, 0x3F, 0xFC, 0x1F, 0xFF, 0xC7, 0xFF,
  0xF1, 0xFF, 0xFC, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3E, 0x00, 0x0F, 0x80,
  0x03, 0xE0, 0x00, 0xF8, 0x00, 0x3E, 0x0E, 0x0F, 0x83, 0x83, 0xE0, 0xE0,
  0xF8, 0x3E, 0x3E, 0x0F, 0x8F, 0x80, 0x7F, 0x00, 0x1F, 0xC0, 0x07, 0xF0,
  0x00, 0xF8, 0x07, 0xFE, 0x01, 0xFF, 0x80, 0x7C, 0x00, 0xF8, 0x00, 0x3E,
  0x3E, 0x3E, 0x0F, 0x8F, 0x83, 0xFF, 0x00, 0xFF, 0xC0, 0x3F, 0xF0, 0x0F,
  0x8F, 0x83, 0xE3, 0xE0, 0xF8, 0xF8, 0x3E, 0x0F, 0x8F, 0x83, 0xE0, 0xE0,
  0x1F, 0x38, 0x07, 0xCE, 0x01, 0xF0, 0xF8, 0x00, 0x3E, 0x00, 0x0F, 0x80,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x3E, 0x00, 0x0F, 0x80, 0x03, 0xE0, 0x00,
  0xF8, 0x00, 0x3E, 0x00, 0x0F, 0x80, 0x03, 0xE0, 0x00, 0xF8, 0x1F, 0xFE,
  0x07, 0xFF, 0x81, 0xFF, 0xFF, 0xF8, 0xFF, 0xFE, 0x3F, 0xFF, 0x80, 0x07,
  0x07, 0xC1, 0xC1, 0xF0, 0x70, 0x7C, 0x7F, 0x80, 0x1F, 0xE0, 0x3F, 0xFF,
  0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xF8, 0xE7, 0xFE, 0x39, 0xFF, 0x8E, 0x7F,
  0xE3, 0x9F, 0xF8, 0xE7, 0xFE, 0x01, 0xFF, 0x80, 0x7C, 0x7C, 0x1F, 0x1F,
  0x07, 0xC7, 0xC1, 0xF0, 0x1F, 0x07, 0xC7, 0xC1, 0xF1, 0xF0, 0x7F, 0xFC,
  0x00, 0xFF, 0x00, 0x3F, 0xF9, 0xFF, 0xFE, 0x7F, 0xFF, 0x9F, 0xFF, 0xFF,
  0xFF, 0xFF, 0xFF, 0x81, 0xFF, 0xE0, 0x7F, 0xF8, 0x1F, 0xFE, 0x01, 0xFF,
  0x80, 0x7C, 0x7C, 0x1F, 0x1F, 0x07, 0xC7, 0xC1, 0xF0, 0x1F, 0xFE, 0x07,
  0xFF, 0x81, 0xFF, 0xE3, 0xF8, 0x1F, 0xFE, 0x07, 0xFE, 0x01, 0xFF, 0x80,
  0x7F, 0xE0, 0x1F, 0xF8, 0x07, 0xFE, 0x01, 0xFF, 0x80, 0x7F, 0xE0, 0x1F,
  0xF8, 0x07, 0xFE, 0x07, 0xFF, 0x81, 0xFC, 0x7F, 0xF8, 0x1F, 0xFE, 0x07,
  0xFF, 0x80, 0xFF, 0xFE, 0x3F, 0xFF, 0x8F, 0xFF, 0xE0, 0x00, 0x1F, 0x00,
  0x07, 0xFE, 0x01, 0xFF, 0x80, 0x7F, 0xFF, 0xF8, 0xFF, 0xFE, 0x3F, 0xFF,
  0x8F, 0x80, 0x03, 0xE0, 0x00, 0xF8, 0x00, 0x3E, 0x00, 0x0F, 0x80, 0x00,
  0x7C, 0x00, 0x1F, 0x00, 0x07, 0xC0, 0x00, 0x0F, 0xFE, 0x03, 0xFF, 0x80,
  0xFF, 0xE3, 0xF8, 0x1F, 0xFE, 0x07, 0xFE, 0x01, 0xFF, 0x80, 0x7F, 0xE0,
  0x1F, 0xF8, 0x07, 0xFE, 0x01, 0xFF, 0x81, 0xFF, 0xE0, 0x7F, 0xF8, 0x1F,
  0xFF, 0xFF, 0xFF, 0xFF, 0xFC, 0x3F, 0x9F, 0x0F, 0xE7, 0xC3, 0xF9, 0xF0,
  0xFF, 0xFE, 0x3F, 0xFF, 0x8F, 0xFF, 0xE0, 0x00, 0x1F, 0xF8, 0x07, 0xFE,
  0x01, 0xFF, 0x80, 0x7F, 0xFF, 0xF8, 0xFF, 0xFE, 0x3F, 0xFF, 0x8F, 0x8F,
  0x83, 0xE3, 0xE0, 0xF8, 0x3E, 0x3E, 0x0F, 0x8F, 0x83, 0xE0, 0x7C, 0x1F,
  0x1F, 0x07, 0xC7, 0xC1, 0xF0, 0x1F, 0xFE, 0x07, 0xFF, 0x81, 0xFF, 0xE3,
  0xF8, 0x1F, 0xFE, 0x07, 0xFF, 0x81, 0xFF, 0x80, 0x00, 0x7F, 0xF8, 0x1F,
  0xFE, 0x07, 0xFF, 0x80, 0x00, 0x7C, 0x00, 0x1F, 0xF8, 0x1F, 0xFE, 0x07,
  0xFF, 0x81, 0xFC, 0x7F, 0xF8, 0x1F, 0xFE, 0x07, 0xFF, 0x80, 0xFF, 0xFF,
  0xFF, 0xFF, 0xFF, 0xFF, 0xFC, 0x00, 0x00, 0x00, 0x00, 0x01, 0xFC, 0x00,
  0x7F, 0x00, 0x1F, 0xC0, 0x07, 0xF0, 0x01, 0xFC, 0x00, 0x7F, 0x00, 0x1F,
  0xC0, 0x07, 0xF0, 0x01, 0xFC, 0x00, 0x7F, 0x00, 0x03, 0xF8, 0x00, 0xFE,
  0x00, 0x3F, 0x80, 0xF8, 0x07, 0xFE, 0x01, 0xFF, 0x80, 0x7F, 0xE0, 0x00,
  0xF8, 0x00, 0x3E, 0x01, 0xFF, 0x80, 0x7F, 0xE0, 0x1F, 0xF8, 0x07, 0xFE,
  0x01, 0xFF, 0x80, 0x7F, 0xE0, 0x1F, 0xF8, 0x07, 0xC7, 0xC7, 0xF1, 0xF1,
  0xFC, 0x1F, 0xFF, 0x07, 0xFF, 0xC1, 0xFF, 0xF0, 0xF8, 0x07, 0xFE, 0x01,
  0xFF, 0x80, 0x7F, 0xE0, 0x00, 0xF8, 0x00, 0x3E, 0x01, 0xFF, 0x80, 0x7F,
  0xE0, 0x1F, 0xF8, 0x07, 0xFE, 0x01, 0xF1, 0xF0, 0x7C, 0x7C, 0x1F, 0x1F,
  0x07, 0xC1, 0xF1, 0xF0, 0x7C, 0x7C, 0x03, 0xF8, 0x00, 0xFE, 0x00, 0x3F,
  0x80, 0x1F, 0x07, 0xC7, 0xC1, 0xF1, 0xF0, 0x7F, 0xE0, 0x00, 0xF8, 0x00,
  0x3E, 0x39, 0xFF, 0x8E, 0x7F, 0xE3, 0x9F, 0xF8, 0xE7, 0xFE, 0x39, 0xFF,
  0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xC7, 0xC7, 0xF1, 0xF1, 0xFC, 0x1C,
  0x1F, 0x07, 0x07, 0xC1, 0xC1, 0xF0, 0x3E, 0x0F, 0x9F, 0x07, 0xFF, 0x80,
  0x1F, 0xC0, 0x0F, 0xE0, 0x01, 0xFF, 0xE0, 0xFF, 0xF0, 0x7F, 0xF8, 0x01,
  0xF0, 0x1F, 0xFE, 0x0F, 0xFF, 0x07, 0xFF, 0x8F, 0xE3, 0xFF, 0xF1, 0xFF,
  0xF8, 0xFE, 0x7C, 0x1F, 0x3E, 0x0F, 0x9F, 0x07, 0xC0, 0xF8, 0x07, 0xFE,
  0x01, 0xFF, 0x80, 0x7F, 0xE0, 0x00, 0xF8, 0x00, 0x3E, 0x01, 0xFF, 0x80,
  0x7F, 0xE0, 0x1F, 0x1F, 0x3E, 0x07, 0xCF, 0x80, 0x7F, 0x80, 0x1F, 0xE0,
  0x07, 0xF8, 0x01, 0xFE, 0x00, 0x7F, 0x80, 0x1F, 0xE0, 0x07, 0xF8, 0x01,
  0xFE, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x01, 0xFE, 0x03, 0xE0,
  0x1F, 0x00, 0x3E, 0x03, 0xE0, 0x07, 0xC0, 0x0F, 0x80, 0x7C, 0x00, 0xF8,
  0x0F, 0x83, 0xFF, 0x07, 0xFE, 0x0F, 0xFF, 0xFC, 0xFF, 0xF9, 0xFF, 0xF0,
  0xFF, 0xFF, 0xFF, 0xFF, 0xE0, 0xF8, 0x3E, 0x0F, 0x83, 0xE0, 0xF8, 0x3E,
  0x0F, 0x83, 0xE0, 0xF8, 0x3E, 0x0F, 0x83, 0xFF, 0xFF, 0xFF, 0xF0, 0xF8,
  0x00, 0x3E, 0x00, 0x0F, 0x80, 0x00, 0x7C, 0x00, 0x1F, 0x00, 0x01, 0xF0,
  0x00, 0x7C, 0x00, 0x1F, 0x00, 0x00, 0xF8, 0x00, 0x3E, 0x00, 0x03, 0xE0,
  0x00, 0xF8, 0x00, 0x07, 0xC0, 0x01, 0xF0, 0x00, 0x7C, 0xFF, 0xFF, 0xFF,
  0xFC, 0x1F, 0x07, 0xC1, 0xF0, 0x7C, 0x1F, 0x07, 0xC1, 0xF0, 0x7C, 0x1F,
  0x07, 0xC1, 0xF0, 0x7F, 0xFF, 0xFF, 0xFF, 0xF0, 0x07, 0xC0, 0x0F, 0x80,
  0x1F, 0x01, 0xFF, 0xC3, 0xFF, 0x9F, 0x07, 0xFE, 0x0F, 0xFC, 0x1F, 0xFF,
  0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xF0, 0xF8, 0xF8, 0xF8, 0x1F, 0x1F,
  0x1F, 0x07, 0xFF, 0xC1, 0xFF, 0xF0, 0x7F, 0xFC, 0x7C, 0x00, 0x1F, 0x00,
  0x3E, 0x01, 0xFF, 0x80, 0x7F, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
  0x80, 0x7F, 0xE0, 0x1F, 0xF8, 0x07, 0xFE, 0x01, 0xFF, 0x80, 0x7C, 0x7C,
  0x1F, 0x1F, 0x07, 0xC7, 0xC1, 0xF0, 0xFF, 0xFE, 0x3F, 0xFF, 0x8F, 0xFF,
  0xE0, 0x00, 0x1F, 0x00, 0x07, 0xFE, 0x07, 0xFF, 0x81, 0xFF, 0xFF, 0xF8,
  0xFF, 0xFE, 0x3F, 0xFF, 0x8F, 0x80, 0x7F, 0xE0, 0x1F, 0xF8, 0x07, 0xFE,
  0x07, 0xFF, 0x81, 0xFF, 0xFF, 0xF8, 0xFF, 0xFE, 0x3F, 0xFF, 0x80, 0x07,
  0xFE, 0x0F, 0xFC, 0x1F, 0xF8, 0xF8, 0x01, 0xF0, 0x1F, 0x00, 0x3E, 0x00,
  0x7C, 0x00, 0xF8, 0x01, 0xF0, 0x03, 0xE0, 0x07, 0xC0, 0x0F, 0x83, 0xFF,
  0x07, 0xFE, 0x0F, 0x8F, 0xFC, 0x1F, 0xF8, 0x3F, 0xF0, 0xFF, 0xFE, 0x3F,
  0xFF, 0x8F, 0xFF, 0xE0, 0x00, 0x1F, 0x00, 0x07, 0xFE, 0x01, 0xFF, 0x80,
  0x7F, 0xE0, 0x1F, 0xF8, 0x07, 0xFE, 0x01, 0xFF, 0x83, 0xE3, 0xE0, 0xF8,
  0xF8, 0x3E, 0x3E, 0x3F, 0x8F, 0x8F, 0xE3, 0xFF, 0x00, 0xFF, 0xC0, 0x3F,
  0xF0, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFC, 0x00, 0x00, 0x00,
  0x00, 0x3E, 0x00, 0x0F, 0x80, 0x03, 0xFF, 0xE0, 0xFF, 0xF8, 0x3F, 0xFE,
  0x0F, 0x80, 0x03, 0xE0, 0x00, 0xFE, 0x07, 0xFF, 0x81, 0xFF, 0xE0, 0x7C,
  0x7F, 0xF8, 0x1F, 0xFE, 0x07, 0xFF, 0x80, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
  0xFF, 0xFC, 0x00, 0x00, 0x00, 0x00, 0x3E, 0x00, 0x0F, 0x80, 0x03, 0xFF,
  0xE0, 0xFF, 0xF8, 0x3F, 0xFE, 0x0F, 0x80, 0x03, 0xE0, 0x00, 0xF8, 0x00,
  0x3E, 0x00, 0x0F, 0x80, 0x00, 0x7C, 0x00, 0x1F, 0x00, 0x07, 0xC0, 0x00,
  0x1F, 0xFE, 0x07, 0xFF, 0x81, 0xFF, 0xE3, 0xF8, 0x1F, 0xFE, 0x07, 0xFF,
  0x81, 0xFF, 0x80, 0x03, 0xE0, 0x7F, 0xF8, 0x1F, 0xFE, 0x07, 0xFF, 0x80,
  0x7F, 0xE0, 0x1F, 0xF8, 0x07, 0xFE, 0x07, 0xFF, 0x81, 0xFC, 0x7F, 0xF8,
  0x1F, 0xFE, 0x07, 0xFF, 0x80, 0xF8, 0x07, 0xFE, 0x01, 0xFF, 0x80, 0x7C,
  0x00, 0x1F, 0x00, 0x07, 0xFE, 0x01, 0xFF, 0x80, 0x7F, 0xFF, 0xFF, 0xFF,
  0xFF, 0xFF, 0xFF, 0xFF, 0x80, 0x7F, 0xE0, 0x1F, 0xF8, 0x07, 0xFE, 0x01,
  0xFF, 0x80, 0x7C, 0x7C, 0x1F, 0x1F, 0x07, 0xC7, 0xC1, 0xF0, 0xFF, 0xFF,
  0xFF, 0xFF, 0xFF, 0xF8, 0x00, 0x00, 0x00, 0x00, 0xF8, 0x01, 0xF0, 0x03,
  0xE0, 0x07, 0xC0, 0x0F, 0x80, 0x1F, 0x00, 0x3E, 0x00, 0x7C, 0x00, 0xF8,
  0x01, 0xF0, 0x0F, 0xFF, 0x1F, 0xFE, 0x3F, 0xFC, 0x1F, 0xFF, 0xC7, 0xFF,
  0xF1, 0xFF, 0xFC, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3E, 0x00, 0x0F, 0x80,
  0x03, 0xE0, 0x00, 0xF8, 0x00, 0x3E, 0x0E, 0x0F, 0x83, 0x83, 0xE0, 0xE0,
  0xF8, 0x3E, 0x3E, 0x0F, 0x8F, 0x80, 0x7F, 0x00, 0x1F, 0xC0, 0x07, 0xF0,
  0x00, 0xF8, 0x07, 0xFE, 0x01, 0xFF, 0x80, 0x7C, 0x00, 0xF8, 0x00, 0x3E,
  0x3E, 0x3E, 0x0F, 0x8F, 0x83, 0xFF, 0x00, 0xFF, 0xC0, 0x3F, 0xF0, 0x0F,
  0x8F, 0x83, 0xE3, 0xE0, 0xF8, 0xF8, 0x3E, 0x0F, 0x8F, 0x83, 0xE0, 0xE0,
  0x1F, 0x38, 0x07, 0xCE, 0x01, 0xF0, 0xF8, 0x00, 0x3E, 0x00, 0x0F, 0x80,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x3E, 0x00, 0x0F, 0x80, 0x03, 0xE0, 0x00,
  0xF8, 0x00, 0x3E, 0x00, 0x0F, 0x80, 0x03, 0xE0, 0x00, 0xF8, 0x1F, 0xFE,
  0x07, 0xFF, 0x81, 0xFF, 0xFF, 0xF8, 0xFF, 0xFE, 0x3F, 0xFF, 0x80, 0x07,
  0x07, 0xC1, 0xC1, 0xF0, 0x70, 0x7C, 0x7F, 0x80, 0x1F, 0xE0, 0x3F, 0xFF,
  0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xF8, 0xE7, 0xFE, 0x39, 0xFF, 0x8E, 0x7F,
  0xE3, 0x9F, 0xF8, 0xE7, 0xFE, 0x01, 0xFF, 0x80, 0x7C, 0x7C, 0x1F, 0x1F,
  0x07, 0xC7, 0xC1, 0xF0, 0x1F, 0x07, 0xC7, 0xC1, 0xF1, 0xF0, 0x7F, 0xFC,
  0x00, 0xFF, 0x00, 0x3F, 0xF9, 0xFF, 0xFE, 0x7F, 0xFF, 0x9F, 0xFF, 0xFF,
  0xFF, 0xFF, 0xFF, 0x81, 0xFF, 0xE0, 0x7F, 0xF8, 0x1F, 0xFE, 0x01, 0xFF,
  0x80, 0x7C, 0x7C, 0x1F, 0x1F, 0x07, 0xC7, 0xC1, 0xF0, 0x1F, 0xFE, 0x07,
  0xFF, 0x81, 0xFF, 0xE3, 0xF8, 0x1F, 0xFE, 0x07, 0xFE, 0x01, 0xFF, 0x80,
  0x7F, 0xE0, 0x1F, 0xF8, 0x07, 0xFE, 0x01, 0xFF, 0x80, 0x7F, 0xE0, 0x1F,
  0xF8, 0x07, 0xFE, 0x07, 0xFF, 0x81, 0xFC, 0x7F, 0xF8, 0x1F, 0xFE, 0x07,
  0xFF, 0x80, 0xFF, 0xFE, 0x3F, 0xFF, 0x8F, 0xFF, 0xE0, 0x00, 0x1F, 0x00,
  0x07, 0xFE, 0x01, 0xFF, 0x80, 0x7F, 0xFF, 0xF8, 0xFF, 0xFE, 0x3F, 0xFF,
  0x8F, 0x80, 0x03, 0xE0, 0x00, 0xF8, 0x00, 0x3E, 0x00, 0x0F, 0x80, 0x00,
  0x7C, 0x00, 0x1F, 0x00, 0x07, 0xC0, 0x00, 0x0F, 0xFE, 0x03, 0xFF, 0x80,
  0xFF, 0xE3, 0xF8, 0x1F, 0xFE, 0x07, 0xFE, 0x01, 0xFF, 0x80, 0x7F, 0xE0,
  0x1F, 0xF8, 0x07, 0xFE, 0x01, 0xFF, 0x81, 0xFF, 0xE0, 0x7F, 0xF8, 0x1F,
  0xFF, 0xFF, 0xFF, 0xFF, 0xFC, 0x3F, 0x9F, 0x0F, 0xE7, 0xC3, 0xF9, 0xF0,
  0xFF, 0xFE, 0x3F, 0xFF, 0x8F, 0xFF, 0xE0, 0x00, 0x1F, 0xF8, 0x07, 0xFE,
  0x01, 0xFF, 0x80, 0x7F, 0xFF, 0xF8, 0xFF, 0xFE, 0x3F, 0xFF, 0x8F, 0x8F,
  0x83, 0xE3, 0xE0, 0xF8, 0x3E, 0x3E, 0x0F, 0x8F, 0x83, 0xE0, 0x7C, 0x1F,
  0x1F, 0x07, 0xC7, 0xC1, 0xF0, 0x1F, 0xFE, 0x07, 0xFF, 0x81, 0xFF, 0xE3,
  0xF8, 0x1F, 0xFE, 0x07, 0xFF, 0x81, 0xFF, 0x80, 0x00, 0x7F, 0xF8, 0x1F,
  0xFE, 0x07, 0xFF, 0x80, 0x00, 0x7C, 0x00, 0x1F, 0xF8, 0x1F, 0xFE, 0x07,
  0xFF, 0x81, 0xFC, 0x7F, 0xF8, 0x1F, 0xFE, 0x07, 0xFF, 0x80, 0xFF, 0xFF,
  0xFF, 0xFF, 0xFF, 0xFF, 0xFC, 0x00, 0x00, 0x00, 0x00, 0x01, 0xFC, 0x00,
  0x7F, 0x00, 0x1F, 0xC0, 0x07, 0xF0, 0x01, 0xFC, 0x00, 0x7F, 0x00, 0x1F,
  0xC0, 0x07, 0xF0, 0x01, 0xFC, 0x00, 0x7F, 0x00, 0x03, 0xF8, 0x00, 0xFE,
  0x00, 0x3F, 0x80, 0xF8, 0x07, 0xFE, 0x01, 0xFF, 0x80, 0x7F, 0xE0, 0x00,
  0xF8, 0x00, 0x3E, 0x01, 0xFF, 0x80, 0x7F, 0xE0, 0x1F, 0xF8, 0x07, 0xFE,
  0x01, 0xFF, 0x80, 0x7F, 0xE0, 0x1F, 0xF8, 0x07, 0xC7, 0xC7, 0xF1, 0xF1,
  0xFC, 0x1F, 0xFF, 0x07, 0xFF, 0xC1, 0xFF, 0xF0, 0xF8, 0x07, 0xFE, 0x01,
  0xFF, 0x80, 0x7F, 0xE0, 0x00, 0xF8, 0x00, 0x3E, 0x01, 0xFF, 0x80, 0x7F,
  0xE0, 0x1F, 0xF8, 0x07, 0xFE, 0x01, 0xF1, 0xF0, 0x7C, 0x7C, 0x1F, 0x1F,
  0x07, 0xC1, 0xF1, 0xF0, 0x7C, 0x7C, 0x03, 0xF8, 0x00, 0xFE, 0x00, 0x3F,
  0x80, 0x1F, 0x07, 0xC7, 0xC1, 0xF1, 0xF0, 0x7F, 0xE0, 0x00, 0xF8, 0x00,
  0x3E, 0x39, 0xFF, 0x8E, 0x7F, 0xE3, 0x9F, 0xF8, 0xE7, 0xFE, 0x39, 0xFF,
  0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xC7, 0xC7, 0xF1, 0xF1, 0xFC, 0x1C,
  0x1F, 0x07, 0x07, 0xC1, 0xC1, 0xF0, 0x3E, 0x0F, 0x9F, 0x07, 0xFF, 0x80,
  0x1F, 0xC0, 0x0F, 0xE0, 0x01, 0xFF, 0xE0, 0xFF, 0xF0, 0x7F, 0xF8, 0x01,
  0xF0, 0x1F, 0xFE, 0x0F, 0xFF, 0x07, 0xFF, 0x8F, 0xE3, 0xFF, 0xF1, 0xFF,
  0xF8, 0xFE, 0x7C, 0x1F, 0x3E, 0x0F, 0x9F, 0x07, 0xC0, 0xF8, 0x07, 0xFE,
  0x01, 0xFF, 0x80, 0x7F, 0xE0, 0x00, 0xF8, 0x00, 0x3E, 0x01, 0xFF, 0x80,
  0x7F, 0xE0, 0x1F, 0x1F, 0x3E, 0x07, 0xCF, 0x80, 0x7F, 0x80, 0x1F, 0xE0,
  0x07, 0xF8, 0x01, 0xFE, 0x00, 0x7F, 0x80, 0x1F, 0xE0, 0x07, 0xF8, 0x01,
  0xFE, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x01, 0xFE, 0x03, 0xE0,
  0x1F, 0x00, 0x3E, 0x03, 0xE0, 0x07, 0xC0, 0x0F, 0x80, 0x7C, 0x00, 0xF8,
  0x0F, 0x83, 0xFF, 0x07, 0xFE, 0x0F, 0xFF, 0xFC, 0xFF, 0xF9, 0xFF, 0xF0,
  0x3F, 0xF3, 0xFF, 0x3F, 0xF3, 0xE0, 0x3E, 0x03, 0xE0, 0x3E, 0x0F, 0xE0,
  0xFE, 0x0F, 0xE0, 0x3E, 0x03, 0xE0, 0x3E, 0x03, 0xE0, 0x3E, 0x03, 0xFF,
  0x3F, 0xF3, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x3F, 0xFF, 0xFF,
  0xFF, 0xFF, 0xC0, 0xFF, 0xCF, 0xFC, 0xFF, 0xC0, 0x7C, 0x07, 0xC0, 0x7C,
  0x07, 0xC0, 0x7F, 0x07, 0xF0, 0x7F, 0x07, 0xC0, 0x7C, 0x07, 0xC0, 0x7C,
  0x07, 0xCF, 0xFC, 0xFF, 0xCF, 0xFC, 0x1F, 0x3E, 0x3E, 0x7F, 0xE3, 0xE7,
  0xC7, 0xCF, 0x8F, 0x80 };

const GFXglyph fairlight_24pt7bGlyphs[] = {
  {     0,   1,   1,  20,    0,    0 },   // 0x20 ' '
  {     1,  11,  18,  20,    5,  -17 },   // 0x21 '!'
  {    26,  15,   5,  20,    2,  -17 },   // 0x22 '"'
  {    36,  18,  18,  20,    2,  -17 },   // 0x23 '#'
  {    77,  15,  18,  20,    2,  -17 },   // 0x24 '$'
  {   111,  15,  18,  20,    2,  -17 },   // 0x25 '%'
  {   145,  17,  18,  20,    2,  -17 },   // 0x26 '&'
  {   184,  10,   8,  20,    5,  -17 },   // 0x27 '''
  {   194,  10,  21,  20,    5,  -17 },   // 0x28 '('
  {   221,  10,  21,  20,    5,  -17 },   // 0x29 ')'
  {   248,  18,  12,  20,    2,  -14 },   // 0x2A '*'
  {   275,  15,  12,  20,    2,  -14 },   // 0x2B '+'
  {   298,   8,   8,  20,    6,   -4 },   // 0x2C ','
  {   306,  18,   5,  20,    2,   -9 },   // 0x2D '-'
  {   318,   5,   5,  20,    7,   -4 },   // 0x2E '.'
  {   322,  18,  15,  20,    2,  -14 },   // 0x2F '/'
  {   356,  18,  18,  20,    2,  -17 },   // 0x30 '0'
  {   397,  12,  18,  20,    5,  -17 },   // 0x31 '1'
  {   424,  15,  18,  20,    5,  -17 },   // 0x32 '2'
  {   458,  15,  18,  20,    2,  -17 },   // 0x33 '3'
  {   492,  17,  18,  20,    2,  -17 },   // 0x34 '4'
  {   531,  18,  18,  20,    2,  -17 },   // 0x35 '5'
  {   572,  18,  18,  20,    2,  -17 },   // 0x36 '6'
  {   613,  15,  18,  20,    2,  -17 },   // 0x37 '7'
  {   647,  18,  18,  20,    2,  -17 },   // 0x38 '8'
  {   688,  18,  18,  20,    2,  -17 },   // 0x39 '9'
  {   729,   5,  10,  20,    7,  -12 },   // 0x3A ':'
  {   736,   8,  16,  20,    6,  -12 },   // 0x3B ';'
  {   752,  15,  18,  20,    2,  -17 },   // 0x3C '<'
  {   786,  15,   8,  20,    2,  -12 },   // 0x3D '='
  {   801,  14,  18,  20,    3,  -17 },   // 0x3E '>'
  {   833,  15,  18,  20,    2,  -17 },   // 0x3F '?'
  {   867,  15,  18,  20,    2,  -17 },   // 0x40 '@'
  {   901,  18,  18,  20,    2,  -17 },   // 0x41 'A'
  {   942,  18,  18,  20,    2,  -17 },   // 0x42 'B'
  {   983,  15,  18,  20,    5,  -17 },   // 0x43 'C'
  {  1017,  18,  18,  20,    2,  -17 },   // 0x44 'D'
  {  1058,  18,  18,  20,    2,  -17 },   // 0x45 'E'
  {  1099,  18,  18,  20,    2,  -17 },   // 0x46 'F'
  {  1140,  18,  18,  20,    2,  -17 },   // 0x47 'G'
  {  1181,  18,  18,  20,    2,  -17 },   // 0x48 'H'
  {  1222,  15,  18,  20,    2,  -17 },   // 0x49 'I'
  {  1256,  18,  18,  20,    2,  -17 },   // 0x4A 'J'
  {  1297,  18,  18,  20,    2,  -17 },   // 0x4B 'K'
  {  1338,  18,  18,  20,    2,  -17 },   // 0x4C 'L'
  {  1379,  18,  18,  20,    2,  -17 },   // 0x4D 'M'
  {  1420,  18,  18,  20,    2,  -17 },   // 0x4E 'N'
  {  1461,  18,  18,  20,    2,  -17 },   // 0x4F 'O'
  {  1502,  18,  18,  20,    2,  -17 },   // 0x50 'P'
  {  1543,  18,  18,  20,    2,  -17 },   // 0x51 'Q'
  {  1584,  18,  18,  20,    2,  -17 },   // 0x52 'R'
  {  1625,  18,  18,  20,    2,  -17 },   // 0x53 'S'
  {  1666,  18,  18,  20,    2,  -17 },   // 0x54 'T'
  {  1707,  18,  18,  20,    2,  -17 },   // 0x55 'U'
  {  1748,  18,  18,  20,    2,  -17 },   // 0x56 'V'
  {  1789,  18,  18,  20,    2,  -17 },   // 0x57 'W'
  {  1830,  17,  18,  20,    3,  -17 },   // 0x58 'X'
  {  1869,  18,  18,  20,    2,  -17 },   // 0x59 'Y'
  {  1910,  15,  18,  20,    5,  -17 },   // 0x5A 'Z'
  {  1944,  10,  18,  20,    5,  -17 },   // 0x5B '['
  {  1967,  18,  15,  20,    2,  -14 },   // 0x5C '\'
  {  2001,  10,  18,  20,    7,  -17 },   // 0x5D ']'
  {  2024,  15,   8,  20,    2,  -25 },   // 0x5E '^'
  {  2039,  20,   3,  20,    0,    1 },   // 0x5F '_'
  {  2047,   8,   6,  20,    6,  -25 },   // 0x60 '`'
  {  2053,  18,  18,  20,    2,  -17 },   // 0x61 'a'
  {  2094,  18,  18,  20,    2,  -17 },   // 0x62 'b'
  {  2135,  15,  18,  20,    5,  -17 },   // 0x63 'c'
  {  2169,  18,  18,  20,    2,  -17 },   // 0x64 'd'
  {  2210,  18,  18,  20,    2,  -17 },   // 0x65 'e'
  {  2251,  18,  18,  20,    2,  -17 },   // 0x66 'f'
  {  2292,  18,  18,  20,    2,  -17 },   // 0x67 'g'
  {  2333,  18,  18,  20,    2,  -17 },   // 0x68 'h'
  {  2374,  15,  18,  20,    2,  -17 },   // 0x69 'i'
  {  2408,  18,  18,  20,    2,  -17 },   // 0x6A 'j'
  {  2449,  18,  18,  20,    2,  -17 },   // 0x6B 'k'
  {  2490,  18,  18,  20,    2,  -17 },   // 0x6C 'l'
  {  2531,  18,  18,  20,    2,  -17 },   // 0x6D 'm'
  {  2572,  18,  18,  20,    2,  -17 },   // 0x6E 'n'
  {  2613,  18,  18,  20,    2,  -17 },   // 0x6F 'o'
  {  2654,  18,  18,  20,    2,  -17 },   // 0x70 'p'
  {  2695,  18,  18,  20,    2,  -17 },   // 0x71 'q'
  {  2736,  18,  18,  20,    2,  -17 },   // 0x72 'r'
  {  2777,  18,  18,  20,    2,  -17 },   // 0x73 's'
  {  2818,  18,  18,  20,    2,  -17 },   // 0x74 't'
  {  2859,  18,  18,  20,    2,  -17 },   // 0x75 'u'
  {  2900,  18,  18,  20,    2,  -17 },   // 0x76 'v'
  {  2941,  18,  18,  20,    2,  -17 },   // 0x77 'w'
  {  2982,  17,  18,  20,    3,  -17 },   // 0x78 'x'
  {  3021,  18,  18,  20,    2,  -17 },   // 0x79 'y'
  {  3062,  15,  18,  20,    5,  -17 },   // 0x7A 'z'
  {  3096,  12,  18,  20,    4,  -17 },   // 0x7B '{'
  {  3123,   5,  18,  20,    7,  -17 },   // 0x7C '|'
  {  3135,  12,  18,  20,    5,  -17 },   // 0x7D '}'
  {  3162,  15,   5,  20,    2,  -17 } }; // 0x7E '~'

const GFXfont fairlight_24pt7b = {
  (uint8_t  *)fairlight_24pt7bBitmaps,
  (GFXglyph *)fairlight_24pt7bGlyphs,
  0x20, 0x7E, 24 };//B

// Approx. 3844 bytes