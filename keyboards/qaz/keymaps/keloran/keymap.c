#include QMK_KEYBOARD_H

#include "keloran.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Base
* ,---------------------------------------------------------------------------------.
* |   Q   |   W   |   E   |   R   |   T   |   Y   |   U   |   I   |   O   |    P    |
* |---------------------------------------------------------------------------------|
* |     A   |   S   |   D   |   F   |   G   |   H   |   J   |   K   |   L   |  Bspc |
* |------+--------------------------------------------------------------------------|
* |       Z     |   X   |   C   |   V   |   B   |   N   |   M   | Shift |   Tab     |
* |---------------------------------------------------------------------------------|
* |  Alt  |  GUI  | Lower |      Space      |     Enter     | Raise |  Misc |  Ctrl |
* `---------------------------------------------------------------------------------'
*/
    [_BASE] = LAYOUT_split_space(
        KC_Q,    KC_W,    KC_E,       KC_R,   KC_T,   KC_Y,       KC_U,         KC_I,    KC_O,   KC_P,
        KC_A,    KC_S,    KC_D,       KC_F,   KC_G,   KC_H,       KC_J,         KC_K,    KC_L,   KC_BSPC,
        KC_Z,    KC_X,    KC_C,       KC_V,   KC_B,   KC_N,       KC_M,         KC_LSFT, KC_TAB,
        KC_LALT, KC_LGUI, MO(_LOWER), KC_SPC, KC_ENT, MO(_RAISE), TD(MISC_TAP), KC_LCTL
    ),

/* Lower
* ,---------------------------------------------------------------------------------.
* |  Del  |       |   :=  |   !=  |   <-  |   =>  |       |       |       |     "   |
* |---------------------------------------------------------------------------------|
* |   Esc   |       |   ->  |   (   |   )   |       |       |       |       |       |
* |------+--------------------------------------------------------------------------|
* |    Shift    |       |   [   |   ]   |   #   |       |       |       |   Tab     |
* |---------------------------------------------------------------------------------|
* |  Alt  |  GUI  | Lower |      Space      |     Enter     | Raise |  Misc |  Ctrl |
* `---------------------------------------------------------------------------------'
*/
    [_LOWER] = LAYOUT_split_space(
        KC_DEL,  KC_NO,   CODE_GO_ASSIGN,      CODE_NOT_EQUAL, CODE_GO_CHANNEL, CODE_FAT_ARROW,   KC_NO,   KC_NO,   KC_NO,   KC_BSPC,
        KC_ESC,  KC_NO,   CODE_ARROW_OPERATOR, KC_LPRN,        KC_RPRN,         KC_NO,            KC_NO,   KC_NO,   KC_NO,   KC_NO,
        KC_LSFT, KC_NO,   KC_LBRC,             KC_RBRC,        KC_HASH,         KC_NO,            KC_NO,   KC_NO,   KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS,             KC_NO,          KC_NO,           KC_TRNS,          KC_TRNS, KC_TRNS
    ),

/* Raise
* ,---------------------------------------------------------------------------------.
* |   1   |   2   |   3   |   4   |   5   |   6   |   7   |   8   |   9   |    0    |
* |---------------------------------------------------------------------------------|
* |         |   _   |   $   |   /   |   '   |   =   |       |       |       |       |
* |------+--------------------------------------------------------------------------|
* |   Shift     |       |   -   |   \   |   +   |   ,   |   .   |       |           |
* |---------------------------------------------------------------------------------|
* |  Alt  |  GUI  | Lower |      Space      |     Enter     | Raise |  Misc |  Ctrl |
* `---------------------------------------------------------------------------------'
*/
    [_RAISE] = LAYOUT_split_space(
        KC_1,    KC_2,    KC_3,    KC_4,      KC_5,    KC_6,     KC_7,    KC_8,    KC_9,  KC_0,
        KC_NO,   KC_UNDS, KC_DLR,  KC_SLASH,  KC_QUOT, KC_EQL,   KC_NO,   KC_NO,   KC_NO, KC_NO,
        KC_LSFT, KC_NO,   KC_MINS, KC_BSLASH, KC_PLUS, KC_COMMA, KC_DOT,  KC_NO,   KC_NO,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_NO,     KC_NO,   KC_TRNS,  KC_TRNS, KC_TRNS
    ),

/* Adjust
* ,---------------------------------------------------------------------------------.
* | Reset |       |       |       |       |       |       |       |   Up  |         |
* |---------------------------------------------------------------------------------|
* |         |       |       |  Game |       |       |Qwerty | Left  |  Down | Right |
* |------+--------------------------------------------------------------------------|
* |     Caps    |       |       |       |       |       |       |       |           |
* |---------------------------------------------------------------------------------|
* |  Alt  |  GUI  | Lower |      Space      |     Enter     | Raise |  Misc |  Ctrl |
* `---------------------------------------------------------------------------------'
*/
    [_ADJUST] = LAYOUT_split_space(
        RESET,       KC_NO,   KC_NO,   KC_NO,           KC_NO, KC_NO,   KC_NO,        KC_NO,   KC_UP,    KC_NO,
        KC_NO,       KC_NO,   KC_NO,   MISC_GAME_LAYER, KC_NO, KC_NO,   BASE_LAYER, KC_LEFT, KC_DOWN,  KC_RIGHT,
        KC_CAPS,     KC_NO,   KC_NO,   KC_NO,           KC_NO, KC_NO,   KC_NO,        KC_NO,   KC_NO,
        KC_TRNS,     KC_TRNS, KC_TRNS, KC_NO,           KC_NO, KC_TRNS, KC_TRNS,      KC_TRNS
    ),

/* Misc Game
* ,---------------------------------------------------------------------------------.
* |   Q   |   W   |   E   |   R   |   T   |   Y   |   U   |   I   |   O   |    P    |
* |---------------------------------------------------------------------------------|
* |     A   |   S   |   D   |   F   |   G   |   H   |   J   |   K   |   L   |       |
* |------+--------------------------------------------------------------------------|
* |     Shift   |   Z   |   X   |   C   |   V   |   B   |   N   |   M   |   Tab     |
* |---------------------------------------------------------------------------------|
* |  Ctrl |  Alt  | Lower |      Space      |     Enter     | Raise |  Misc |  GUI  |
* `---------------------------------------------------------------------------------'
*/
    [_MISC_GAME] = LAYOUT_split_space(
        KC_Q,      KC_W,    KC_E,       KC_R,   KC_T,   KC_Y,       KC_U,         KC_I,  KC_O,   KC_P,
        KC_A,      KC_S,    KC_D,       KC_F,   KC_G,   KC_H,       KC_J,         KC_K,  KC_L,   KC_NO,
        KC_LSHIFT, KC_Z,    KC_X,       KC_C,   KC_V,   KC_B,       KC_N,         KC_M,  KC_TAB,
        KC_LCTL,   KC_LALT, MO(_LOWER), KC_SPC, KC_ENT, MO(_RAISE), TD(MISC_TAP), KC_LGUI
    )
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
        switch_layer(keycode);
    }

    return true;
}
