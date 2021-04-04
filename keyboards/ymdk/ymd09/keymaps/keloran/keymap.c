#include QMK_KEYBOARD_H

#include "keloran.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_QWERTY] = LAYOUT(
        KC_KP_7, LT(_RAISE, KC_KP_8), KC_KP_9,
        KC_KP_4, LT(_LOWER, KC_KP_5), KC_KP_6,
        KC_KP_1, KC_KP_2,             KC_KP_3
    ),

    [_LOWER] = LAYOUT(
        RGB_RMOD, RGB_VAI, RGB_MOD,
        RGB_HUI,  KC_TRNS, RGB_SAI,
        RGB_HUD,  RGB_VAD, RGB_SAD
    ),

    [_RAISE] = LAYOUT(
        KC_NO, KC_NO, RESET,
        KC_NO, KC_NO, KC_NO,
        KC_NO, KC_NO, KC_NO
    )
};
