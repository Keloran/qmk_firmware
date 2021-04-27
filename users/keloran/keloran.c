#include QMK_KEYBOARD_H
#include <stdio.h>
#include "timer.h"
#include "print.h"

#include "keloran.h"
#include "tap_dance.h"
#include "rgb.h"
#include "rotary.h"
#include "bitc.h"
#include "oled.h"

// OS
int8_t myOperatingSys = _macOS;
void set_current_os(void) {
    switch (myOperatingSys) {
        case _WindowsOS:
            myOperatingSys = _LinuxOS;
            break;
        case _LinuxOS:
            myOperatingSys = _macOS;
            break;

        case _macOS:
        default:
            myOperatingSys = _WindowsOS;
            break;
    }
}
void lock_screen(void) {
    switch (myOperatingSys) {
        case _WindowsOS:
            tap_code16(G(KC_L));
            break;

        case _macOS:
        default:
            SEND_STRING(SS_DOWN(X_LCTRL) SS_DOWN(X_LGUI) SS_TAP(X_Q) SS_DELAY(100) SS_UP(X_LGUI) SS_UP(X_LCTRL));
            break;
    }
}

// Layers
int8_t myCurrentLayer = 0;
void set_layer(layer_state_t layer) {
    layer_off(myCurrentLayer);
    layer_on(layer);

    myCurrentLayer = layer;
}
void switch_layer(uint16_t keycode) {
    switch (keycode) {
        // Layers
        case BASE_LAYER:
            set_layer(_BASE);
            break;
        case WORKMAN_LAYER:
            set_layer(_WORKMAN);
            break;
        case CIV_LAYER:
            set_layer(_CIV);
            break;
        case OLDFPS_LAYER:
            set_layer(_OLDFPS);
            break;
        case MISC_GAME_LAYER:
            set_layer(_MISC_GAME);
            break;
        case MISC_LAYER:
            set_layer(_MISC);
            break;
    }
}

layer_state_t layer_state_set_user(layer_state_t state) {
#ifdef RGBLIGHT_LAYERS
    rgb_layer_colors(state);
#endif

    return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

// Macros
void coding_macro(uint16_t keycode) {
    switch (keycode) {
        case CODE_NOT_EQUAL:
            send_not_equal();
            break;
        case CODE_GO_ASSIGN:
            send_go_assign();
            break;
        case CODE_FAT_ARROW:
            send_fat_arrow();
            break;
        case CODE_ARROW_OPERATOR:
            send_arrow_operator();
            break;
        case CODE_GO_CHANNEL:
            send_go_channel();
            break;
    }
}
void custom_funcs(uint16_t keycode) {
    switch (keycode) {
        // Operating System
        case MAC_EXPOSE:
            tap_code16(C(KC_UP));
            break;
        case SET_OS:
            set_current_os();
            break;
        case LOCK_SCREEN:
            lock_screen();
            break;
        case POUND_SIGN:
            send_pound_sign(99);
            break;
        case POUND_SIGN_WIN:
            send_pound_sign(_WindowsOS);
            break;
        case MEET_MUTE:
            send_meet_mute();
            break;
        case MEET_CAMERA:
            send_meet_camera();
            break;
    }
}
void send_not_equal(void) {
    SEND_STRING("!=");
}
void send_go_assign(void) {
    SEND_STRING(":=");
}
void send_fat_arrow(void) {
    SEND_STRING("=>");
}
void send_arrow_operator(void) {
    SEND_STRING("->");
}
void send_go_channel(void) {
    SEND_STRING("<-");
}
void send_pound_sign(int OS) {
    int useOS = myOperatingSys;
    if (OS != 99) {
        useOS = OS;
    }

    if (useOS == _macOS) {
        tap_code16(A(KC_3));
    }

    if (useOS == _WindowsOS) {
        register_code(KC_LALT);
        register_code(KC_P0);
        unregister_code(KC_P0);
        register_code(KC_P1);
        unregister_code(KC_P1);
        register_code(KC_P6);
        unregister_code(KC_P6);
        register_code(KC_P3);
        unregister_code(KC_P3);
        unregister_code(KC_LALT);
    }
}
void send_meet_mute(void) {
    if (myOperatingSys == _macOS) {
        tap_code16(G(KC_D));
    }
}
void send_meet_camera(void) {
    if (myOperatingSys == _macOS) {
        tap_code16(G(KC_E));
    }
}

bool led_update_user(led_t led_state) {
    static uint8_t caps_state = 0;
    if (caps_state != led_state.caps_lock) {
#ifdef OLED_SCREENS
        oled_led_state(caps_state);
#endif
#ifdef BIT_C
        bitc_led_state(caps_state);
#endif
#ifdef RGBLIGHT_LAYERS
        rgb_led_state(caps_state);
#endif

        caps_state = led_state.caps_lock;
    }

    return true;
}

// Leader
#ifdef LEADER_ENABLE
#define LEADER_TIMEOUT 300
LEADER_EXTERNS();
void matrix_scan_user() {
    LEADER_DICTIONARY() {
        leading = false;
        leader_end();

        // Go Assign
        SEQ_ONE_KEY(KC_A) { send_go_assign(); }

        // Not Equal
        SEQ_ONE_KEY(KC_S) { send_not_equal(); }

        // Go Channel
        SEQ_ONE_KEY(KC_Z) { send_go_channel(); }
    }
}
#endif
