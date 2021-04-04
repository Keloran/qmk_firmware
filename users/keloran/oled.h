#pragma once

#ifdef OLED_DRIVER_ENABLE
#undef OLED_FONT_H
#define OLED_FONT_H "users/keloran/custom_font.h"

// WPM
void render_wpm_graph(void);
void draw_wpm_stats(void);

// OLED
void render_master(void);
void render_follower(void);
const char *read_logo(void);
void oled_led_state(uint8_t caps_state);

// OS
void draw_mods(void);
void draw_os(void);

// Layers
void draw_super_layer(void);
void draw_current_layer(void);

// Pacman
void ghost(int col, int row);
void pacman(int col, int row);
void animate_pacman(void);
void draw_blank(int col, int row);
#endif