#include QMK_KEYBOARD_H
#include <stdio.h>
#include "timer.h"

#include "oled.h"
#include "keloran.h"
#include "print.h"

// OLED
#ifdef OLED_DRIVER_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
#ifndef OLED_SCREENS
    #define OLED_SCREENS 1
#endif

    if (OLED_SCREENS > 1) {
        if (!is_keyboard_master()) {
            return OLED_ROTATION_180;  // flips the display 180 degrees if offhand
        }
        return rotation;
    } else {
        return OLED_ROTATION_180;
    }

    return rotation;
}
void oled_task_user(void) {
    if (OLED_SCREENS > 1) {
        if (is_keyboard_master()) {
            render_master();
        } else {
            render_follower();
        }
    } else {
        render_master();
    }
}

// words per minute
char wpm_str[10];
char wpm_stats[30];
static uint16_t wpm_graph_timer = 0;
static uint8_t highest_wpm = 0;

void draw_wpm_stats(void) {
    uint8_t latest_wpm = get_current_wpm();
    if (latest_wpm > highest_wpm) {
        highest_wpm = latest_wpm;
    }

    char highIcon[] = { 0x15, 0x3e, 0x00 };
    char wpm_b[7];
    oled_set_cursor(9, 1);
    snprintf(wpm_b, sizeof(wpm_b), "%s%03d", highIcon, highest_wpm);
    oled_write(wpm_b, false);

    char wpmIcon[] = { 0x14, 0x3e, 0x00 };
    char wpm_c[7];
    oled_set_cursor(3, 1);
    snprintf(wpm_c, sizeof(wpm_c), "%s%03d", wpmIcon, latest_wpm);
    oled_write(wpm_c, false);
}

void render_wpm_graph(void) {
    uint8_t latest_wpm = get_current_wpm();
    int wpm_bar_point = 31;
    float max_wpm = 110.0f;

    //check if it's been long enough before refreshing graph
    if (latest_wpm == 0) {
        oled_write(read_logo(), false);
        return;
    }

    if (timer_elapsed(wpm_graph_timer) > 80) {
        // main calculation to plot graph line
        wpm_bar_point = 32 - ((latest_wpm / max_wpm) * 32);

        // first draw actual value line
        for (int i = 0; i <= 3 - 1; i++) {
            oled_write_pixel(1, wpm_bar_point + i, true);
        }

        for (int i = 32; i > wpm_bar_point; i--) {
            if (i % 3 == 0) {
                oled_write_pixel(1, i, true);
            }
        }

        // then move the entire graph one pixel to the right
        oled_pan(false);
        wpm_graph_timer = timer_read();
    }

    if (latest_wpm > 0) {
        oled_set_cursor(12, 3);
        char wpm_readout[11];
        snprintf(wpm_readout, sizeof(wpm_readout), " WPM: %03d", latest_wpm);
        oled_write(wpm_readout, false);
    }
}

// Operating System
void draw_os(void) {
    static char top_macOS[] = { 0x95, 0x96, 0x00 };
    static char bottom_macOS[] = { 0xb5, 0xb6, 0x00 };

    static char top_Linux[] = { 0x99, 0x9a, 0x00 };
    static char bottom_Linux[] = { 0xb9, 0xba, 0x00 };

    static char top_Windows[] = { 0x97, 0x98, 0x00 };
    static char bottom_Windows[] = { 0xb7, 0xb8, 0x00 };

    switch (myOperatingSys) {
        case _LinuxOS:
            oled_set_cursor(0, 0);
            oled_write(top_Linux, false);
            oled_set_cursor(0, 1);
            oled_write(bottom_Linux, false);
            break;

        case _WindowsOS:
            oled_set_cursor(0, 0);
            oled_write(top_Windows, false);
            oled_set_cursor(0, 1);
            oled_write(bottom_Windows, false);
            break;

        case _macOS:
        default:
            oled_set_cursor(0, 0);
            oled_write(top_macOS, false);
            oled_set_cursor(0, 1);
            oled_write(bottom_macOS, false);
            break;
    }
}

// Standard Layer code
void draw_current_layer(void) {
    char currentLayerLabel[16];

    uint8_t layerID = biton32(layer_state);
    switch (myCurrentLayer) {
        case _QWERTY:
            snprintf(currentLayerLabel, sizeof(currentLayerLabel), "Layer:%s   ", "qwerty");
            break;
        case _WORKMAN:
            snprintf(currentLayerLabel, sizeof(currentLayerLabel), "Layer:%s  ", "workman");
            break;
        case _CIV:
            snprintf(currentLayerLabel, sizeof(currentLayerLabel), "Layer:%s      ", "civ");
            break;
        case _OLDFPS:
            snprintf(currentLayerLabel, sizeof(currentLayerLabel), "Layer:%s      ", "old");
            break;
        case _FKEYS:
            snprintf(currentLayerLabel, sizeof(currentLayerLabel), "Layer:%s", "functions");
            break;
        default:
            snprintf(currentLayerLabel, sizeof(currentLayerLabel), "Layer:%d      ", layerID);
            break;
    }

    oled_set_cursor(3, 0);
    oled_write(currentLayerLabel, false);
}

// OLED
bool oled_cleared;
void render_follower(void) {
    uint8_t latest_wpm = get_current_wpm();
    if (latest_wpm > 0) {
        render_wpm_graph();
        oled_cleared = false;
    } else {
        if (!oled_cleared) {
            oled_clear();
            oled_cleared = true;
            return;
        }
        oled_write(read_logo(), false);
    }
}

void draw_super_layer(void) {
    oled_set_cursor(19, 0);
    const char lower[] = { 0x19, 0x00 };
    const char raise[] = { 0x18, 0x00 };
    const char adjust[] = { 0x12, 0x00 };
    const char none[] = { 0xbe, 0x00 };

    uint8_t layerID = biton32(layer_state);
    switch (layerID) {
        case _LOWER:
            oled_write(lower, false);
            break;
        case _RAISE:
            oled_write(raise, false);
            break;
        case _ADJUST:
            oled_write(adjust, false);
            break;
        default:
            oled_write(none, false);
            break;
    }
}

void draw_mods(void) {
    uint8_t mods = get_mods();
    char noMod[] = { 0xbe, 0x00 };

    if (mods & MOD_MASK_SHIFT) {
        char shift[] = { 0x53, 0x00 };
        oled_set_cursor(15, 1);
        oled_write(shift, true);
    } else {
        oled_set_cursor(15, 1);
        oled_write(noMod, false);
    }

    if (mods & MOD_MASK_CTRL) {
        char ctrl[] = { 0x43, 0x00 };
        oled_set_cursor(16, 1);
        oled_write(ctrl, true);
    } else {
        oled_set_cursor(16, 1);
        oled_write(noMod, false);
    }

    if (mods & MOD_MASK_ALT) {
        char alt[] = { 0x41, 0x00 };
        oled_set_cursor(17, 1);
        oled_write(alt, true);
    } else {
        oled_set_cursor(17, 1);
        oled_write(noMod, false);
    }

    if (mods & MOD_MASK_GUI) {
        char gui[] = { 0x47, 0x00 };
        oled_set_cursor(18, 1);
        oled_write(gui, true);
    } else {
        oled_set_cursor(18, 1);
        oled_write(noMod, false);
    }

    if (IS_HOST_LED_ON(USB_LED_CAPS_LOCK)) {
        char capsON[] = { 0x7f, 0x00 };
        oled_set_cursor(20, 0);
        oled_write(capsON, false);
    } else {
        oled_set_cursor(20, 0);
        oled_write(noMod, false);
    }
}

void oled_led_state(uint8_t caps_state) {
    const char blank[]  = {0xbe, 0x00};
    const char capsON[] = {0x7f, 0x00};
    oled_set_cursor(20, 0);
    caps_state ? oled_write(capsON, false) : oled_write(blank, false);
}

static int animationFrame;
void render_master(void) {
    // OS Logo
    draw_os();

    // Current Layer
    draw_current_layer();

    // Mods
    draw_mods();

    // Super Layer
    draw_super_layer();

    // Words per Minute
    draw_wpm_stats();

    // pacman
    if (animationFrame >= 2161) {
        animationFrame = 0;
    }
    animate_pacman();
    animationFrame += 1;
}

// Pacman
void pacman(int col, int row) {
    static char top[] = { 0xd4, 0xd5, 0x00 };
    static char bottom[] = { 0xd6, 0xd7, 0x00 };
    oled_set_cursor(col, row);
    oled_write(top, false);
    oled_set_cursor(col, row + 1);
    oled_write(bottom, false);
}

void ghost(int col, int row) {
    static char top_ghost[] = { 0xbb, 0xbc, 0x00 };
    static char bottom_ghost[] = { 0xdb, 0xdc, 0x00 };

    oled_set_cursor(col, row);
    oled_write(top_ghost, false);
    oled_set_cursor(col, row + 1);
    oled_write(bottom_ghost, false);
}

bool finished_render;
void animate_pacman() {
    uint8_t latest_wpm = get_current_wpm();
    if (latest_wpm < 10) {
        if (finished_render) {
            animationFrame = 0;
        }
    }

    // Start Ghost
    static char frame1_top[]     = { 0xbb, 0xbc, 0xbd, 0xbe, 0xbd, 0xbe, 0xbd, 0xbe, 0xbd, 0xbe, 0xbd, 0xbe, 0xbd, 0xbe, 0xbd, 0xbe, 0xbd, 0xbe, 0xbd, 0xbe, 0x00};
    static char frame1_bottom[]  = { 0xdb, 0xdc, 0xdd, 0xbe, 0xdd, 0xbe, 0xdd, 0xbe, 0xdd, 0xbe, 0xdd, 0xbe, 0xdd, 0xbe, 0xdd, 0xbe, 0xdd, 0xbe, 0xdd, 0xbe, 0x00};

    static char frame2_top[]     = { 0xbd, 0xbe, 0xbb, 0xbc, 0xbd, 0xbe, 0xbd, 0xbe, 0xbd, 0xbe, 0xbd, 0xbe, 0xbd, 0xbe, 0xbd, 0xbe, 0xbd, 0xbe, 0xbd, 0xbe, 0x00};
    static char frame2_bottom[]  = { 0xdd, 0xbe, 0xdb, 0xdc, 0xdd, 0xbe, 0xdd, 0xbe, 0xdd, 0xbe, 0xdd, 0xbe, 0xdd, 0xbe, 0xdd, 0xbe, 0xdd, 0xbe, 0xdd, 0xbe, 0x00};

    static char frame3_top[]     = { 0xbd, 0xbe, 0xbd, 0xbe, 0xbb, 0xbc, 0xbd, 0xbe, 0xbd, 0xbe, 0xbd, 0xbe, 0xbd, 0xbe, 0xbd, 0xbe, 0xbd, 0xbe, 0xbd, 0xbe, 0x00};
    static char frame3_bottom[]  = { 0xdd, 0xbe, 0xdd, 0xbe, 0xdb, 0xdc, 0xdd, 0xbe, 0xdd, 0xbe, 0xdd, 0xbe, 0xdd, 0xbe, 0xdd, 0xbe, 0xdd, 0xbe, 0xdd, 0xbe, 0x00};

    static char frame4_top[]     = { 0xbd, 0xbe, 0xbd, 0xbe, 0xbd, 0xbe, 0xbb, 0xbc, 0xbd, 0xbe, 0xbd, 0xbe, 0xbd, 0xbe, 0xbd, 0xbe, 0xbd, 0xbe, 0xbd, 0xbe, 0x00};
    static char frame4_bottom[]  = { 0xdd, 0xbe, 0xdd, 0xbe, 0xdd, 0xbe, 0xdb, 0xdc, 0xdd, 0xbe, 0xdd, 0xbe, 0xdd, 0xbe, 0xdd, 0xbe, 0xdd, 0xbe, 0xdd, 0xbe, 0x00};

    static char frame5_top[]     = { 0xbd, 0xbe, 0xbd, 0xbe, 0xbd, 0xbe, 0xbd, 0xbe, 0xbb, 0xbc, 0xbd, 0xbe, 0xbd, 0xbe, 0xbd, 0xbe, 0xbd, 0xbe, 0xbd, 0xbe, 0x00};
    static char frame5_bottom[]  = { 0xdd, 0xbe, 0xdd, 0xbe, 0xdd, 0xbe, 0xdd, 0xbe, 0xdb, 0xdc, 0xdd, 0xbe, 0xdd, 0xbe, 0xdd, 0xbe, 0xdd, 0xbe, 0xdd, 0xbe, 0x00};

    // Start Pacman
    static char frame6_top[]     = { 0xd4, 0xd5, 0xbd, 0xbe, 0xbd, 0xbe, 0xbd, 0xbe, 0xbd, 0xbe, 0xbb, 0xbc, 0xbd, 0xbe, 0xbd, 0xbe, 0xbd, 0xbe, 0xbd, 0xbe, 0x00};
    static char frame6_bottom[]  = { 0xd6, 0xd7, 0xdd, 0xbe, 0xdd, 0xbe, 0xdd, 0xbe, 0xdd, 0xbe, 0xdb, 0xdc, 0xdd, 0xbe, 0xdd, 0xbe, 0xdd, 0xbe, 0xdd, 0xbe, 0x00};

    static char frame7_top[]     = { 0xbe, 0xbe, 0x93, 0x94, 0xbd, 0xbe, 0xbd, 0xbe, 0xbd, 0xbe, 0xbd, 0xbe, 0xbb, 0xbc, 0xbd, 0xbe, 0xbd, 0xbe, 0xbd, 0xbe, 0x00};
    static char frame7_bottom[]  = { 0xbe, 0xbe, 0xb3, 0xb4, 0xdd, 0xbe, 0xdd, 0xbe, 0xdd, 0xbe, 0xdd, 0xbe, 0xdb, 0xdc, 0xdd, 0xbe, 0xdd, 0xbe, 0xdd, 0xbe, 0x00};

    static char frame8_top[]     = { 0xbe, 0xbe, 0xbe, 0xbe, 0xd4, 0xd5, 0xbd, 0xbe, 0xbd, 0xbe, 0xbd, 0xbe, 0xbd, 0xbe, 0xbb, 0xbc, 0xbd, 0xbe, 0xbd, 0xbe, 0x00};
    static char frame8_bottom[]  = { 0xbe, 0xbe, 0xbe, 0xbe, 0xd6, 0xd7, 0xdd, 0xbe, 0xdd, 0xbe, 0xdd, 0xbe, 0xdd, 0xbe, 0xdb, 0xdc, 0xdd, 0xbe, 0xdd, 0xbe, 0x00};

    static char frame9_top[]     = { 0xbe, 0xbe, 0xbe, 0xbe, 0xbe, 0xbe, 0x93, 0x94, 0xbd, 0xbe, 0xbd, 0xbe, 0xbd, 0xbe, 0xbd, 0xbe, 0xbb, 0xbc, 0xbd, 0xbe, 0x00};
    static char frame9_bottom[]  = { 0xbe, 0xbe, 0xbe, 0xbe, 0xbe, 0xbe, 0xb3, 0xb4, 0xdd, 0xbe, 0xdd, 0xbe, 0xdd, 0xbe, 0xdd, 0xbe, 0xdb, 0xdc, 0xdd, 0xde, 0x00};

    // End Ghost
    static char frame10_top[]    = { 0xbe, 0xbe, 0xbe, 0xbe, 0xbe, 0xbe, 0xbe, 0xbe, 0xd4, 0xd5, 0xbd, 0xbe, 0xbd, 0xbe, 0xbd, 0xbe, 0xbd, 0xbe, 0xbd, 0xbb, 0x00};
    static char frame10_bottom[] = { 0xbe, 0xbe, 0xbe, 0xbe, 0xbe, 0xbe, 0xbe, 0xbe, 0xd6, 0xd7, 0xdd, 0xbe, 0xdd, 0xbe, 0xdd, 0xbe, 0xdd, 0xbe, 0xdd, 0xdb, 0x00};

    static char frame11_top[]    = { 0xbe, 0xbe, 0xbe, 0xbe, 0xbe, 0xbe, 0xbe, 0xbe, 0xbe, 0xbe, 0x93, 0x94, 0xbd, 0xbe, 0xbd, 0xbe, 0xbd, 0xbe, 0xbd, 0xbe, 0x00};
    static char frame11_bottom[] = { 0xbe, 0xbe, 0xbe, 0xbe, 0xbe, 0xbe, 0xbe, 0xbe, 0xbe, 0xbe, 0xb3, 0xb4, 0xdd, 0xbe, 0xdd, 0xbe, 0xdd, 0xbe, 0xdd, 0xbe, 0x00};

    static char frame12_top[]    = { 0xbe, 0xbe, 0xbe, 0xbe, 0xbe, 0xbe, 0xbe, 0xbe, 0xbe, 0xbe, 0xbe, 0xbe, 0xd4, 0xd5, 0xbd, 0xbe, 0xbd, 0xbe, 0xbd, 0xbe, 0x00};
    static char frame12_bottom[] = { 0xbe, 0xbe, 0xbe, 0xbe, 0xbe, 0xbe, 0xbe, 0xbe, 0xbe, 0xbe, 0xbe, 0xbe, 0xd6, 0xd7, 0xdd, 0xbe, 0xdd, 0xbe, 0xdd, 0xbe, 0x00};

    static char frame13_top[]    = { 0xbe, 0xbe, 0xbe, 0xbe, 0xbe, 0xbe, 0xbe, 0xbe, 0xbe, 0xbe, 0xbe, 0xbe, 0xbe, 0xbe, 0x93, 0x94, 0xbd, 0xbe, 0xbd, 0xbe, 0x00};
    static char frame13_bottom[] = { 0xbe, 0xbe, 0xbe, 0xbe, 0xbe, 0xbe, 0xbe, 0xbe, 0xbe, 0xbe, 0xbe, 0xbe, 0xbe, 0xbe, 0xb3, 0xb4, 0xdd, 0xbe, 0xdd, 0xbe, 0x00};

    static char frame14_top[]    = { 0xbe, 0xbe, 0xbe, 0xbe, 0xbe, 0xbe, 0xbe, 0xbe, 0xbe, 0xbe, 0xbe, 0xbe, 0xbe, 0xbe, 0xbe, 0xbe, 0xd4, 0xd5, 0xbd, 0xbe, 0x00};
    static char frame14_bottom[] = { 0xbe, 0xbe, 0xbe, 0xbe, 0xbe, 0xbe, 0xbe, 0xbe, 0xbe, 0xbe, 0xbe, 0xbe, 0xbe, 0xbe, 0xbe, 0xbe, 0xd6, 0xd7, 0xdd, 0xbe, 0x00};

    // End Pacman
    static char frame15_top[]    = { 0xbe, 0xbe, 0xbe, 0xbe, 0xbe, 0xbe, 0xbe, 0xbe, 0xbe, 0xbe, 0xbe, 0xbe, 0xbe, 0xbe, 0xbe, 0xbe, 0xbe, 0xbe, 0xbe, 0x93, 0x00};
    static char frame15_bottom[] = { 0xbe, 0xbe, 0xbe, 0xbe, 0xbe, 0xbe, 0xbe, 0xbe, 0xbe, 0xbe, 0xbe, 0xbe, 0xbe, 0xbe, 0xbe, 0xbe, 0xbe, 0xbe, 0xbe, 0xb3, 0x00};

    static char blank_top[]      = { 0xbe, 0xbe, 0xbe, 0xbe, 0xbe, 0xbe, 0xbe, 0xbe, 0xbe, 0xbe, 0xbe, 0xbe, 0xbe, 0xbe, 0xbe, 0xbe, 0xbe, 0xbe, 0xbe, 0xbe, 0x00};
    static char blank_bottom[]   = { 0xbe, 0xbe, 0xbe, 0xbe, 0xbe, 0xbe, 0xbe, 0xbe, 0xbe, 0xbe, 0xbe, 0xbe, 0xbe, 0xbe, 0xbe, 0xbe, 0xbe, 0xbe, 0xbe, 0xbe, 0x00};

    static int row = 2;
    static int col = 1;

    switch (animationFrame) {
        case 120:
            oled_set_cursor(col, row);
            oled_write(frame1_top, false);
            oled_set_cursor(col, row + 1);
            oled_write(frame1_bottom, false);
            finished_render = false;
            break;
        case 240:
            oled_set_cursor(col, row);
            oled_write(frame2_top, false);
            oled_set_cursor(col, row + 1);
            oled_write(frame2_bottom, false);
            break;
        case 360:
            oled_set_cursor(col, row);
            oled_write(frame3_top, false);
            oled_set_cursor(col, row + 1);
            oled_write(frame3_bottom, false);
            break;
        case 480:
            oled_set_cursor(col, row);
            oled_write(frame4_top, false);
            oled_set_cursor(col, row + 1);
            oled_write(frame4_bottom, false);
            break;
        case 600:
            oled_set_cursor(col, row);
            oled_write(frame5_top, false);
            oled_set_cursor(col, row + 1);
            oled_write(frame5_bottom, false);
            break;
        case 720:
            oled_set_cursor(col, row);
            oled_write(frame6_top, false);
            oled_set_cursor(col, row + 1);
            oled_write(frame6_bottom, false);
            break;
        case 840:
            oled_set_cursor(col, row);
            oled_write(frame7_top, false);
            oled_set_cursor(col, row + 1);
            oled_write(frame7_bottom, false);
            break;
        case 960:
            oled_set_cursor(col, row);
            oled_write(frame8_top, false);
            oled_set_cursor(col, row + 1);
            oled_write(frame8_bottom, false);
            break;
        case 1080:
            oled_set_cursor(col, row);
            oled_write(frame9_top, false);
            oled_set_cursor(col, row + 1);
            oled_write(frame9_bottom, false);
            break;
        case 1200:
            oled_set_cursor(col, row);
            oled_write(frame10_top, false);
            oled_set_cursor(col, row + 1);
            oled_write(frame10_bottom, false);
            break;
        case 1320:
            oled_set_cursor(col, row);
            oled_write(frame11_top, false);
            oled_set_cursor(col, row + 1);
            oled_write(frame11_bottom, false);
            break;
        case 1440:
            oled_set_cursor(col, row);
            oled_write(frame12_top, false);
            oled_set_cursor(col, row + 1);
            oled_write(frame12_bottom, false);
            break;
        case 1560:
            oled_set_cursor(col, row);
            oled_write(frame13_top, false);
            oled_set_cursor(col, row + 1);
            oled_write(frame13_bottom, false);
            break;
        case 1680:
            oled_set_cursor(col, row);
            oled_write(frame14_top, false);
            oled_set_cursor(col, row + 1);
            oled_write(frame14_bottom, false);
            break;

        case 1800:
            oled_set_cursor(col, row);
            oled_write(frame15_top, false);
            oled_set_cursor(col, row + 1);
            oled_write(frame15_bottom, false);
            finished_render = true;
            break;

        case 0:
        case 1920:
        case 2040:
        case 2160:
            oled_set_cursor(col, row);
            oled_write(blank_top, false);
            oled_set_cursor(col, row + 1);
            oled_write(blank_bottom, false);
            break;
        default:
            return;
    }
}

void draw_blank(int col, int row) {
    static char blank[] = { 0xbe, 0x00 };

    oled_set_cursor(col, row);
    oled_write(blank, false);
    oled_set_cursor(col, row + 1);
    oled_write(blank, false);
}

const char *read_logo(void) {
    static char logo[] = {
        0xbe, 0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8a, 0x8b, 0x8c, 0x8d, 0x8e, 0x8f, 0x90, 0x91, 0x92, 0xbe,
        0xbe, 0xa0, 0xa1, 0xa2, 0xa3, 0xa4, 0xa5, 0xa6, 0xa7, 0xa8, 0xa9, 0xaa, 0xab, 0xac, 0xad, 0xae, 0xaf, 0xb0, 0xb1, 0xb2, 0xbe,
        0xbe, 0xc0, 0xc1, 0xc2, 0xc3, 0xc4, 0xc5, 0xc6, 0xc7, 0xc8, 0xc9, 0xca, 0xcb, 0xcc, 0xcd, 0xce, 0xcf, 0xd0, 0xd1, 0xd2, 0xbe,
        0x00};

    return logo;
}
#endif
