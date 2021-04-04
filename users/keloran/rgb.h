#pragma once

#define RGB_BLACK 0x00, 0x00, 0x00
#define RGB_ROMAN_LEAF 0x55, 0xCB, 0x9E
#define RGB_LIGHT_RED 0x00, 0xB7, 0xEE
#define RGB_SUPER_LIGHT_PURPLE 0xF9, 0xE4, 0xFF
#define RGB_LIGHT_BLUE 0x8D, 0xFF, 0xE9

#ifdef RGBLIGHT_LAYERS
void rgb_led_state(uint8_t caps_state);
void rgb_layer_colors(layer_state_t state);
#endif