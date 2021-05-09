#include QMK_KEYBOARD_H

#include "rgb_matrix.h"

#include "keloran.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Base
* ,----------------------------------------------------------------------------------------------------------------------.
* |  Esc  |   1   |   2   |   3   |   4   |   5   |   6   |   7   |   8   |   9   |   0   |   -   |   =   |   Backspace  |
* |----------------------------------------------------------------------------------------------------------------------|
* |    Tab    |   Q   |   W   |   E   |   R   |   T   |   Y   |   U   |   I   |   O   |   P   |   [   |   ]   |     \    |
* |----------------------------------------------------------------------------------------------------------------------|
* |    Caps    |   A   |   S   |   D   |   F   |   G   |   H   |   J   |   K   |   L   |   ;   |   '   |      Enter      |
* |----------------------------------------------------------------------------------------------------------------------|
* |     Shift      |   Z   |   X   |   C   |   V   |   B   |   N   |   M   |   ,   |   .   |   /   |       Shift         |
* |----------------------------------------------------------------------------------------------------------------------|
* |   Ctrl  |   Alt   |   GUI   |                     Space                       |  Lower  |   Alt   |  Ctrl  |  Raise  |
* `----------------------------------------------------------------------------------------------------------------------'
*/
	[_BASE] = LAYOUT_60_ansi(
        KC_ESC,     KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,       KC_0,    KC_MINS, KC_EQL,  KC_BSPC,
        KC_TAB,     KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,       KC_P,    KC_LBRC, KC_RBRC, KC_BSLS,
        SUPERCAPS,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,       KC_SCLN, KC_QUOT,          KC_ENT,
        KC_LSFT,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,     KC_SLSH,                   KC_RSFT,
        KC_LCTL,    KC_LALT, KC_LGUI,                   KC_SPC,                             MO(_LOWER), KC_RALT,          KC_RCTL, MO(_RAISE)
    ),

/* Raise
* ,----------------------------------------------------------------------------------------------------------------------.
* |  Esc  |  F1   |  F2   |  F3   |  F4   |  F5   |  F6   |  F7   |  F8   |  F9   |  F10  |  F11  |  F12  |   Delete     |
* |----------------------------------------------------------------------------------------------------------------------|
* |    Tab    |       |       |       |       |       |       |       |       |       |       |       |       |     `    |
* |----------------------------------------------------------------------------------------------------------------------|
* |            |       |       |       |       |       |       |       |       |  Lock |       |       |      Enter      |
* |----------------------------------------------------------------------------------------------------------------------|
* |     Shift      |       |       |       |       |       |       |       |       |       |       |       Shift         |
* |----------------------------------------------------------------------------------------------------------------------|
* |   Ctrl  |   Alt   |   GUI   |                     Space                       |  Lower  |   Alt   |  Ctrl  |  Raise  |
* `----------------------------------------------------------------------------------------------------------------------'
*/
    [_RAISE] = LAYOUT_60_ansi(
        KC_TRNS, KC_F1,   KC_F2,   KC_F3, KC_F4, KC_F5,   KC_F6, KC_F7, KC_F8, KC_F9,       KC_F10,  KC_F11, KC_F12,  KC_DEL,
        KC_TRNS, KC_NO,   KC_NO,   KC_NO, KC_NO, KC_NO,   KC_NO, KC_NO, KC_NO, KC_NO,       KC_NO,   KC_NO,  KC_NO,   KC_GRV,
        KC_NO,   KC_NO,   KC_NO,   KC_NO, KC_NO, KC_NO,   KC_NO, KC_NO, KC_NO, LOCK_SCREEN, KC_NO,   KC_NO,           KC_TRNS,
        KC_TRNS, KC_NO,   KC_NO,   KC_NO, KC_NO, KC_NO,   KC_NO, KC_NO, KC_NO, KC_NO,       KC_NO,                    KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS,               KC_TRNS,                      KC_TRNS,     KC_TRNS,         KC_TRNS, KC_TRNS
    ),

/* Lower
* ,----------------------------------------------------------------------------------------------------------------------.
* |  Esc  |       |       |       |       |      |       |       |       |       |       |       |       |   Delete      |
* |----------------------------------------------------------------------------------------------------------------------|
* |    Tab    |       |  Up   |       |       |       |       |       |       |       |       |       |       |          |
* |----------------------------------------------------------------------------------------------------------------------|
* |            |  Left |  Down | Right |       |       |       |       |       |       |       |       |      Enter      |
* |----------------------------------------------------------------------------------------------------------------------|
* |     Shift      |       |       |       |       |       |       |       |       |       |       |       Shift         |
* |----------------------------------------------------------------------------------------------------------------------|
* |   Ctrl  |   Alt   |   GUI   |                     Space                       |  Lower  |   Alt   |  Ctrl  |  Raise  |
* `----------------------------------------------------------------------------------------------------------------------'
*/
    [_LOWER] = LAYOUT_60_ansi(
        KC_TRNS, KC_NO,   KC_NO,   KC_NO, KC_NO, KC_NO,   KC_NO, KC_NO, KC_NO, KC_NO,   KC_NO,   KC_NO, KC_NO,   KC_DEL,
        KC_TRNS, KC_NO,   KC_UP,   KC_NO,      KC_NO, KC_NO,   KC_NO, KC_NO, KC_NO, KC_NO,   KC_NO,   KC_NO, KC_NO,   KC_NO,
        KC_NO,   KC_LEFT, KC_DOWN, KC_RGHT,    KC_NO, KC_NO,   KC_NO, KC_NO, KC_NO, KC_NO,   KC_NO,   KC_NO,          KC_TRNS,
        KC_TRNS, KC_NO,   KC_NO,   KC_NO,      KC_NO, KC_NO,   KC_NO, KC_NO, KC_NO, KC_NO,   KC_NO,                   KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS,                    KC_TRNS,                      KC_TRNS, KC_TRNS,        KC_TRNS, KC_TRNS
    ),

/* Adjust
* ,----------------------------------------------------------------------------------------------------------------------.
* | Reset |       |       |       |       |      |       |       |       |       |       |       |       |   Delete      |
* |----------------------------------------------------------------------------------------------------------------------|
* |    Tab    |       |       |       |       |       |       |       |       |       |       |       |       |          |
* |----------------------------------------------------------------------------------------------------------------------|
* |            |       |       |       |       |       |       |       |       |       |       |       |      Enter      |
* |----------------------------------------------------------------------------------------------------------------------|
* |     Shift      |       |       |       |       |       |       |       |       |       |       |       Shift         |
* |----------------------------------------------------------------------------------------------------------------------|
* |   RGB   |   Alt   |   GUI   |                     Space                       |  Lower  |   Alt   |  Ctrl  |  Raise  |
* `----------------------------------------------------------------------------------------------------------------------'
*/
    [_ADJUST] = LAYOUT_60_ansi(
        RESET,   KC_NO,   KC_NO,   KC_NO, KC_NO, KC_NO,   KC_NO, KC_NO, KC_NO, KC_NO,   KC_NO,   KC_NO, KC_NO,   KC_TRNS,
        KC_TRNS, KC_NO,   KC_NO,   KC_NO, KC_NO, KC_NO,   KC_NO, KC_NO, KC_NO, KC_NO,   KC_NO,   KC_NO, KC_NO,   KC_NO,
        KC_NO,   KC_NO,   KC_NO,   KC_NO, KC_NO, KC_NO,   KC_NO, KC_NO, KC_NO, KC_NO,   KC_NO,   KC_NO,          KC_TRNS,
        KC_TRNS, KC_NO,   KC_NO,   KC_NO, KC_NO, KC_NO,   KC_NO, KC_NO, KC_NO, KC_NO,   KC_NO,                   KC_TRNS,
        RGB_TOG, KC_TRNS, KC_TRNS,               KC_TRNS,                      KC_TRNS, KC_TRNS,        KC_TRNS, KC_TRNS
    ),
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
        update_wpm(keycode);
        coding_macro(keycode);
        switch_layer(keycode);
        custom_funcs(keycode);
    }

    return true;
}

const rgblight_segment_t PROGMEM rgb_base_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 16, HSV_PURPLE}
);
const rgblight_segment_t PROGMEM rgb_lower_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 16, HSV_GREEN}
);
const rgblight_segment_t PROGMEM rgb_raise_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 16, HSV_GOLD}
);
const rgblight_segment_t PROGMEM rgb_caps_lock[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 16, HSV_WHITE}
);
const rgblight_segment_t* const PROGMEM rgb_layers[] = RGBLIGHT_LAYERS_LIST(
    rgb_caps_lock,
    rgb_raise_layer,
    rgb_lower_layer,
    rgb_base_layer
);

void keyboard_post_init_user(void) {
    rgblight_layers = rgb_layers;
    rgblight_set_layer_state(3, true);
}
