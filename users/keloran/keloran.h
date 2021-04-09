#pragma once

#include "bitc.h"
#include "tap_dance.h"
#include "rgb.h"
#include "rotary.h"
#include "oled.h"

// Words Per Minute
void update_wpm(uint16_t keycode);

// KeyCodes
enum keyCodes {
    MACRO_SAFE = SAFE_RANGE,
    SAFE_LED_LEVEL,
    SAFE_LAYER_COLOR,
    RGB_SLD,

    // Operating System
    SET_OS,
    LOCK_SCREEN,
    MAC_EXPOSE,
    LINUX_TERM1,
    LINUX_TERM2,
    LINUX_GUI,

    // Layers
    QWERTY_LAYER,
    WORKMAN_LAYER,
    OLDFPS_LAYER,
    CIV_LAYER,
    MISC_GAME_LAYER,

    // Coding
    CODE_GO_ASSIGN,
    CODE_NOT_EQUAL,
    CODE_GO_CHANNEL,
    CODE_FAT_ARROW,
    CODE_ARROW_OPERATOR,

    // General
    POUND_SIGN,
    POUND_SIGN_WIN,

    // Google Meet
    MEET_MUTE,
    MEET_CAMERA,
};

// Layers
extern int8_t myCurrentLayer;
const char *read_layer_state(void);
void set_layer(layer_state_t layer);
void switch_layer(uint16_t keycode);
void layer_color(layer_state_t layer);
layer_state_t layer_state_set_user(layer_state_t state);
enum layer_number {
    // Typing
    _QWERTY = 0,
    _WORKMAN,

    // Game
    _CIV,
    _OLDFPS,
    _MISC_GAME,

    // FKeys
    _FKEYS,
    _MISC,
    _EXTRA,

    // Super Layers
    _LOWER,
    _RAISE,
    _ADJUST,
};

// OS
extern int8_t myOperatingSys;
void lock_screen(void);
const char *read_host_led_state(void);
void set_current_os(void);
enum operatingSysDef {
    _macOS = 0,
    _WindowsOS,
    _LinuxOS,
};

// Macros
void coding_macro(uint16_t keycode);
void custom_funcs(uint16_t keycode);
void send_not_equal(void);
void send_go_assign(void);
void send_fat_arrow(void);
void send_arrow_operator(void);
void send_go_channel(void);


// General
void send_pound_sign(int OS);
void send_meet_mute(void);
void send_meet_camera(void);