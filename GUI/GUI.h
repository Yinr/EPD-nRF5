#ifndef __GUI_H
#define __GUI_H

#include "Adafruit_GFX.h"

#ifndef PAGE_HEIGHT
#define PAGE_HEIGHT ((__HEAP_SIZE / 50) - 8)
#endif

typedef enum {
    MODE_PICTURE = 0,
    MODE_CALENDAR = 1,
    MODE_CLOCK = 2,
} display_mode_t;

typedef struct {
    uint16_t color;
    uint16_t width;
    uint16_t height;
    uint32_t timestamp;
    uint8_t week_start; // 0: Sunday, 1: Monday
    int8_t temperature;
    float voltage;
    char ssid[13];
} gui_data_t;

void DrawGUI(gui_data_t *data, buffer_callback draw, display_mode_t mode);

#endif
