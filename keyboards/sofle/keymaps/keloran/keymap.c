#include QMK_KEYBOARD_H

#include "keloran.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/*
 * Base
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |                    |   Y  |   U  |   I  |   O  |   P  |BckSpc|
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | ESC  |   A  |   S  |   D  |   F  |   G  |                    |   H  |   J  |   K  |   L  |   ;  |  '   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |LShift|   Z  |   X  |   C  |   V  |   B  |-------.    ,-------|   N  |   M  |   ,  |   .  |   /  |  -   |
 * |------+------+------+------+------+------|  Mute |    | SetOS |------+------+------+------+------+------|
 * |LCtrl |   1  |   2  |   3  |   4  |   5  |-------|    |-------|   6  |   7  |   8  |   9  |   0  |Delete|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            | LAlt |   [  | LGUI |LOWER | /Space  /       \Enter \  |RAISE |  ]   |  `   | Misc |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */

[_BASE] = LAYOUT( \
  KC_TAB,   KC_Q, KC_W, KC_E, KC_R, KC_T,                      KC_Y, KC_U, KC_I,    KC_O,   KC_P,    KC_BSPC,
  KC_ESC,   KC_A, KC_S, KC_D, KC_F, KC_G,                      KC_H, KC_J, KC_K,    KC_L,   KC_SCLN, KC_QUOT,
  KC_LSFT,  KC_Z, KC_X, KC_C, KC_V, KC_B,                      KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_MINS,
  KC_LCTRL, KC_1, KC_2, KC_3, KC_4, KC_5, KC_MUTE,     SET_OS, KC_6, KC_7, KC_8,    KC_9,   KC_0,    KC_DELETE,
    KC_LALT, KC_LBRC, KC_LGUI, MO(_LOWER), KC_SPC,      KC_ENT, MO(_RAISE), KC_RBRC, KC_GRV, TD(MISC_TAP)
),
/* Lower
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |HYPER | MEH  |      |      |      |                    |      |      |      |      |      |  ⇩  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |  ⇩  |   !  |   @  |   #  |   $  |   %  |-------.    ,-------|   ^  |   &  |   *  |   (  |   )  |   ~  |
 * |------+------+------+------+------+------|   ⇩   |    |  ⇩   |------+------+------+------+------+------|
 * |  ⇩  |      |      | ALT_3 |      |      |-------|    |-------|     |   _  |  +  |   {  |  }    |   |  |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            |  ⇩  |   ⇩  |  ⇩  |  ⇩  | /   ⇩   /       \  ⇩  \  |  ⇩  |   ⇩  |   ⇩ |  ⇩  |
 *            |      |      |      |      |/       /         \      \ |      |      |      |     |
 *            `----------------------------------'            '------''--------------------------'
 */
[_LOWER] = LAYOUT( \
  KC_NO,   KC_HYPR, KC_MEH, KC_NO,      KC_F4,  KC_F5,                           KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_TRNS,
  KC_NO,   KC_NO,   KC_NO,  KC_NO,      KC_NO,  KC_NO,                           KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
  KC_TRNS, KC_EXLM, KC_AT,  KC_HASH,    KC_DLR, KC_PERC,                         KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_TILD,
  KC_TRNS, KC_NO,   KC_NO,  LALT(KC_3), KC_NO,  KC_NO,   KC_TRNS,       KC_TRNS, KC_NO,   KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_PIPE,
                     KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
),
/* Raise
 * ,----------------------------------------.                     ,-----------------------------------------.
 * |      |  (   |   )  |      |      |      |                    |   +  |  -   |   =  |      |  \   | ⇩   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |  `   |      |      |      |  F1  |  F2  |                    |  :=  |      |     |   Up  |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |  ⇩  |      |      |      |      |      |-------.    ,-------|  !=  |      | Left | Down |Right |      |
 * |------+------+------+------+------+------|  ⇩   |    |   ⇩   |------+------+------+------+------+------|
 * |  ⇩  |      |  <-  |  =>  |  ->  |      |-------|    |-------|      |      |      |      |      | Delete|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            |  ⇩  |  ⇩  |  ⇩   |  ⇩  | /  ⇩    /       \  ⇩  \  |  ⇩  |  ⇩   |  ⇩  |  ⇩   |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'            '------''---------------------------'
 */
[_RAISE] = LAYOUT( \
  KC_NO,   KC_LPRN, KC_RPRN,         KC_NO,          KC_NO,               KC_NO,                           KC_KP_PLUS,     KC_MINS, KC_EQL,  KC_NO,   KC_BSLS,  KC_TRNS,
  KC_GRV,  KC_NO,   KC_NO,           KC_NO,          KC_NO,               KC_NO,                           CODE_GO_ASSIGN, KC_NO,   KC_NO,   KC_UP,   KC_NO,    KC_NO,
  KC_TRNS, KC_NO,   KC_NO,           KC_NO,          KC_NO,               KC_NO,                           CODE_NOT_EQUAL, KC_NO,   KC_LEFT, KC_DOWN, KC_RIGHT, KC_NO,
  KC_TRNS, KC_NO,   CODE_GO_CHANNEL, CODE_FAT_ARROW, CODE_ARROW_OPERATOR, KC_NO,  KC_TRNS,       KC_TRNS,  KC_NO,          KC_NO,   KC_NO,   KC_NO,   KC_NO,    KC_DELETE,
                                              KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
),
/* Adjust
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | RESET|      |QWERTY|      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------.    ,-------|      |      |      |      |      |      |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * | CAPS |      |      |      |      |      |-------|    |-------|      |      |      |      |      |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            |      |      |      |  ⇩  | /       /       \      \  |  ⇩   |      |      |      |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */
  [_ADJUST] = LAYOUT( \
    KC_NO,       KC_NO, KC_NO ,       KC_NO, KC_NO, KC_NO,                   KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
    RESET,       KC_NO, BASE_LAYER, KC_NO, KC_NO, KC_NO,                   KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
    KC_NO,       KC_NO, KC_NO,        KC_NO, KC_NO, KC_NO,                   KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
    KC_CAPSLOCK, KC_NO, KC_NO,        KC_NO, KC_NO, KC_NO, KC_NO,     KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
                             KC_NO, KC_NO, KC_NO, KC_TRNS, KC_NO,     KC_NO, KC_TRNS, KC_NO, KC_NO, KC_NO
  )
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
        update_wpm(keycode);
        coding_macro(keycode);
        switch_layer(keycode);
        custom_funcs(keycode, record);
    }

    return true;
}
