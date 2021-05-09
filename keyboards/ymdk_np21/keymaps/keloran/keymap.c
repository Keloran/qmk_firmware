#include QMK_KEYBOARD_H

#include "keloran.h"

enum numpadLayers {
    _NUMPAD = 0,
    _NUMPAD_MACROS,
    _NUMPAD_NAV,
    _NUMPAD_EXTRA,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Numpad
* ,-------------------------------.
* |Macros | Misc  | Extra | Bspc  |
* |-------------------------------|
* |-------------------------------|
* |  Nav  |   /   |   *   |   -   |
* |-------+-------+-------+-------|
* |   7   |   8   |   9   |       |
* |-------+-------+-------|   +   |
* |   4   |   5   |   6   |       |
* |-------+-------+-------+-------|
* |   1   |   2   |   3   |       |
* |---------------+-------| Enter |
* |       0       |   .   |       |
* `-------------------------------'
*/
    [_NUMPAD] = LAYOUT_numpad_6x4(
        OSL(_NUMPAD_MACROS), TD(MISC_TAP), OSL(_NUMPAD_EXTRA), KC_BSPC,

        TG(_NUMPAD_NAV),     KC_PSLS,      KC_PAST,            KC_PMNS,
        KC_P7,               KC_P8,        KC_P9,
        KC_P4,               KC_P5,        KC_P6,              KC_PPLS,
        KC_P1,               KC_P2,        KC_P3,
        KC_P0,                             KC_PDOT,            KC_PENT
    ),

/* Numpad
* ,-------------------------------.
* |Macros | Misc  | Extra | Bspc  |
* |-------------------------------|
* |-------------------------------|
* |  Nav  |       |       |       |
* |-------+-------+-------+-------|
* |  Home |   Up  |  End  |       |
* |-------+-------+-------|       |
* | Right |       | Left  |       |
* |-------+-------+-------+-------|
* |       |  Down |       |       |
* |---------------+-------| Enter |
* |               |       |       |
* `-------------------------------'
*/
    [_NUMPAD_NAV] = LAYOUT_numpad_6x4(
        KC_TRNS,  KC_TRNS, KC_TRNS,  KC_TRNS,

        KC_TRNS,  KC_NO,    KC_NO,   KC_DEL,
        KC_HOME,  KC_UP,    KC_END,
        KC_LEFT,  KC_NO,    KC_RGHT, KC_NO,
        KC_NO,    KC_DOWN,  KC_NO,
        KC_NO,              KC_NO,   KC_TRNS
    ),

/* Numpad Macros
* ,-------------------------------.
* |Macros | Misc  | Extra | Bspc  |
* |-------------------------------|
* |-------------------------------|
* |  Nav  |       |       |       |
* |-------+-------+-------+-------|
* |       |   £   |       |       |
* |-------+-------+-------|       |
* |       |   £   |       |       |
* |-------+-------+-------+-------|
* |MeetMic|       |MeetCam|       |
* |---------------+-------|       |
* |    Expose     |       |       |
* `-------------------------------'
*/
    [_NUMPAD_MACROS] = LAYOUT_numpad_6x4(
        KC_TRNS,   KC_TRNS,    KC_TRNS,     KC_TRNS,

        KC_TRNS,   KC_NO,          KC_NO,       KC_DEL,
        KC_NO,     POUND_SIGN,     KC_NO,
        KC_LEFT,   POUND_SIGN_WIN, KC_NO,       KC_NO,
        MEET_MUTE, KC_DOWN,        MEET_CAMERA,
        MAC_EXPOSE,                KC_NO,       KC_TRNS
    ),

/* Numpad Extra
* ,-------------------------------.
* |  Esc  | Misc  |       | Bspc  |
* |-------------------------------|
* |-------------------------------|
* |  Nav  |       |       |       |
* |-------+-------+-------+-------|
* |       |       | Reset |       |
* |-------+-------+-------|       |
* |       |       |       |       |
* |-------+-------+-------+-------|
* |       |       |       |       |
* |---------------+-------|       |
* |      SetOS    |       |       |
* `-------------------------------'
*/
    [_NUMPAD_EXTRA] = LAYOUT_numpad_6x4(
        KC_TRNS, KC_TRNS, KC_NO, KC_TRNS,

        KC_TRNS, KC_NO,   KC_NO, KC_NO,
        KC_NO,   KC_NO,   RESET,
        KC_NO,   KC_NO,   KC_NO, KC_NO,
        KC_NO,   KC_NO,   KC_NO,
        SET_OS,           KC_NO, KC_NO
    )
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
        switch_layer(keycode);
        custom_funcs(keycode, record);
        coding_macro(keycode);
    }

    return true;
}
