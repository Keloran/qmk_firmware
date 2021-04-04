#include QMK_KEYBOARD_H

#include "keloran.h"
#include "print.h"

enum sixty_custom {
    SUPERCAPS = SAFE_RANGE
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_QWERTY] = LAYOUT_all(
        KC_GESC,   KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,       KC_0,    KC_MINS,      KC_EQL,  KC_NO,   KC_BSPC,
        KC_TAB,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,       KC_P,    KC_LBRC,      KC_RBRC, KC_BSLS,
        SUPERCAPS, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,       KC_SCLN, KC_QUOT,               KC_ENT,
        KC_LSFT,   KC_NO,   KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM,    KC_DOT,  KC_SLSH,      KC_RSFT, KC_UP,   KC_NO,
        KC_LCTL,   KC_LALT, KC_LGUI,                   KC_NO,   KC_SPC,  KC_NO,            MO(_LOWER),          TD(MISC_TAP), KC_LEFT, KC_DOWN, KC_RIGHT
    ),

    [_LOWER] = LAYOUT_all(
        KC_GRV, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,       KC_F10, KC_F11, KC_F12, KC_NO, KC_DEL,
        KC_NO,  RGB_TOG, RGB_MOD, RGB_HUI, RGB_HUD, RGB_SAI, RGB_SAD, RGB_VAI, RGB_VAD, KC_NO,       KC_NO,          KC_NO,  KC_NO, KC_NO,
        KC_NO,  KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   LOCK_SCREEN, KC_NO,          KC_NO,         KC_NO,
        KC_NO,  KC_NO,   KC_NO,   KC_NO,   BL_DEC,  BL_TOGG, BL_INC,  BL_STEP, KC_NO,   KC_NO,       KC_NO,  KC_NO,  KC_NO,  KC_NO, RESET,
        KC_NO,  KC_NO,   KC_NO,                     KC_NO,   KC_NO,   KC_NO,            KC_TRNS,             KC_NO,  KC_NO,  KC_NO, KC_NO
    )
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    //uprintf("KL: kc: 0x%04X, col: %u, row: %u\n", keycode, record->event.key.col, record->event.key.row);

    if (record->event.pressed) {
        update_wpm(keycode);
        coding_macro(keycode);
        switch_layer(keycode);
        custom_funcs(keycode);
    }

    static uint16_t caps_timer;
    switch(keycode) {
        case SUPERCAPS:
            if (record->event.pressed) {
                caps_timer = timer_read();
                unregister_code(KC_ESC);
                unregister_code(KC_CAPS);
            } else {
                if (timer_elapsed(caps_timer) < CAPS_TIMER) {
                    tap_code(KC_ESC);
                } else {
                    tap_code(KC_CAPS);
                }
            }

            return false;
    }

    return true;
}
