#ifndef __GUI_H
#define __GUI_H

#include "Adafruit_GFX.h"

typedef enum {
    MODE_PICTURE = 0,
    MODE_CALENDAR = 1,
    MODE_CLOCK = 2,
} display_mode_t;

typedef struct {
    display_mode_t mode;
    uint16_t color;
    uint16_t width;
    uint16_t height;
    uint32_t timestamp;
    uint8_t week_start; // 0: Sunday, 1: Monday
    int8_t temperature;
    float voltage;
    char ssid[20];
    uint8_t partial_update; // 1: use partial refresh update window, 0: full
} gui_data_t;

void DrawGUI(gui_data_t *data, buffer_callback callback, void *callback_data);

#endif
