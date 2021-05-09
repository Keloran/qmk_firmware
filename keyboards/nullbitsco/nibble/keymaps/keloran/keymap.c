/* Copyright 2020 Jay Greco
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include QMK_KEYBOARD_H
#include "keloran.h"


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Base
* ,--------------------------------------------------------------------------------------------------------------------------------------.
* |       |  Esc  |   1   |   2   |   3   |   4   |   5   |   6   |   7   |   8   |   9   |   0   |   -   |   =   |   Backspace  |   `   |
* |--------------------------------------------------------------------------------------------------------------------------------------|
* | Mute  |    Tab    |   Q   |   W   |   E   |   R   |   T   |   Y   |   U   |   I   |   O   |   P   |   [   |   ]   |     \    |  Del  |
* |------+-------------------------------------------------------------------------------------------------------------------------------|
* | Misc  |    Caps    |   A   |   S   |   D   |   F   |   G   |   H   |   J   |   K   |   L   |   ;   |   '   |      Enter      |  PgUp |
* |--------------------------------------------------------------------------------------------------------------------------------------|
* |       |      Shift     |   Z   |   X   |   C   |   V   |   B   |   N   |   M   |   ,   |   .   |   /   |    Shift    |  Up   |  PgDn |
* |       |------------------------------------------------------------------------------------------------------------------------------|
* |       |   Ctrl  |   Alt   |   GUI   |                     Space                      | Lower | SetOS | Raise | Left  | Down  | Right |
* `--------------------------------------------------------------------------------------------------------------------------------------'
*/
    [_BASE] = LAYOUT_nibble_keloran(
                      KC_ESC,    KC_1,    KC_2,    KC_3, KC_4, KC_5, KC_6,   KC_7, KC_8,    KC_9,       KC_0,    KC_MINS,    KC_EQL,  KC_BSPC, KC_GRV,
        KC_MUTE,      KC_TAB,    KC_Q,    KC_W,    KC_E, KC_R, KC_T, KC_Y,   KC_U, KC_I,    KC_O,       KC_P,    KC_LBRC,    KC_RBRC, KC_BSLS, KC_DEL,
        TD(MISC_TAP), SUPERCAPS, KC_A,    KC_S,    KC_D, KC_F, KC_G, KC_H,   KC_J, KC_K,    KC_L,       KC_SCLN, KC_QUOT,             KC_ENT,  KC_PGUP,
                      KC_LSFT,   KC_Z,    KC_X,    KC_C, KC_V, KC_B, KC_N,   KC_M, KC_COMM, KC_DOT,     KC_SLSH, KC_RSFT,             KC_UP,   KC_PGDN,
                      KC_LCTL,   KC_LALT, KC_LGUI,                   KC_SPC,                MO(_LOWER), SET_OS,  MO(_RAISE), KC_LEFT, KC_DOWN, KC_RGHT
    ),

/* Lower
* ,--------------------------------------------------------------------------------------------------------------------------------------.
* |       |  Esc  |   F1  |  F2   |  F3   |  F4   |  F5   |  F6   |  F7   |  F8   |  F9   |  F10  |  F11  |  F12  |   Backspace  |       |
* |--------------------------------------------------------------------------------------------------------------------------------------|
* | Mute  |           |       |       |       |       |       |       |       |       |       |       |       |       |          |       |
* |------+-------------------------------------------------------------------------------------------------------------------------------|
* | Misc  |            |       |       |       |       |       |       |       |       |       |       |       |      Enter      |       |
* |--------------------------------------------------------------------------------------------------------------------------------------|
* |       |                |       |       |       |       |       |       |       |       |       |       |    Shift    |  Up   |       |
* |       |------------------------------------------------------------------------------------------------------------------------------|
* |       |   Ctrl  |   Alt   |   GUI   |                     Space                      | Lower |       | Raise | Left  | Down  | Right |
* `--------------------------------------------------------------------------------------------------------------------------------------'
*/
    [_LOWER] = LAYOUT_nibble_keloran(
                 KC_TRNS, KC_F1,   KC_F2,   KC_F3, KC_F4, KC_F5, KC_F6,   KC_F7, KC_F8, KC_F9,   KC_F10, KC_F11,  KC_F12,  KC_TRNS, KC_NO,
        KC_TRNS, KC_NO,   KC_NO,   KC_NO,   KC_NO, KC_NO, KC_NO, KC_NO,   KC_NO, KC_NO, KC_NO,   KC_NO,  KC_NO,   KC_NO,   KC_NO,   KC_NO,
        KC_TRNS, KC_NO,   KC_NO,   KC_NO,   KC_NO, KC_NO, KC_NO, KC_NO,   KC_NO, KC_NO, KC_NO,   KC_NO,  KC_NO,            KC_TRNS, KC_NO,
                 KC_NO,   KC_NO,   KC_NO,   KC_NO, KC_NO, KC_NO, KC_NO,   KC_NO, KC_NO, KC_NO,   KC_NO,  KC_NO,            KC_TRNS, KC_NO,
                 KC_TRNS, KC_TRNS, KC_TRNS,                      KC_TRNS,               KC_TRNS, KC_NO,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
    ),

/* Raise
* ,--------------------------------------------------------------------------------------------------------------------------------------.
* |       |  Esc  |       |       |       |       |       |       |       |       |       |       |       |       |   Backspace  |       |
* |--------------------------------------------------------------------------------------------------------------------------------------|
* | Mute  |           |   !=  |   :=  |   <-  |       |       |       |       |       |       |       |       |       |          |       |
* |------+-------------------------------------------------------------------------------------------------------------------------------|
* | Misc  |            |   ->  |  =>   |       |       |       |       |       |       |       |       |       |      Enter      |       |
* |--------------------------------------------------------------------------------------------------------------------------------------|
* |       |                |       |       |       |       |       |       |       |       |       |       |             |  Up   |       |
* |       |------------------------------------------------------------------------------------------------------------------------------|
* |       |   Ctrl  |   Alt   |   GUI   |                     Space                      | Lower | SetOS | Raise | Left  | Down  | Right |
* `--------------------------------------------------------------------------------------------------------------------------------------'
*/
    [_RAISE] = LAYOUT_nibble_keloran(
                 KC_TRNS, KC_NO,               KC_NO,          KC_NO,           KC_NO, KC_NO, KC_NO,   KC_NO, KC_NO, KC_NO,   KC_NO, KC_NO,   KC_NO,   KC_TRNS, KC_NO,
        KC_TRNS, KC_NO,   CODE_NOT_EQUAL,      CODE_GO_ASSIGN, CODE_GO_CHANNEL, KC_NO, KC_NO, KC_NO,   KC_NO, KC_NO, KC_NO,   KC_NO, KC_NO,   KC_NO,   KC_NO,   KC_NO,
        KC_TRNS, KC_NO,   CODE_ARROW_OPERATOR, CODE_FAT_ARROW, KC_NO,           KC_NO, KC_NO, KC_NO,   KC_NO, KC_NO, KC_NO,   KC_NO, KC_NO,            KC_TRNS, KC_NO,
                 KC_NO,   KC_NO,               KC_NO,          KC_NO,           KC_NO, KC_NO, KC_NO,   KC_NO, KC_NO, KC_NO,   KC_NO, KC_NO,            KC_TRNS, KC_NO,
                 KC_TRNS, KC_TRNS,             KC_TRNS,                                       KC_TRNS,               KC_TRNS, KC_NO, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
    ),

/* Adjust
* ,--------------------------------------------------------------------------------------------------------------------------------------.
* |       |  Esc  |       |       |       |       |       |       |       |       |       |       |       |       |   Backspace  |       |
* |--------------------------------------------------------------------------------------------------------------------------------------|
* | Mute  |           | HYPER |  MEH  |       |       |       |       |       |       |       |       |       |       |          |       |
* |------+-------------------------------------------------------------------------------------------------------------------------------|
* | Misc  |            |       |       |       |       |       |       |       |       |       |       |       |      Enter      |       |
* |--------------------------------------------------------------------------------------------------------------------------------------|
* |       |                |       |       |       |       |       |       |       |       |       |       |             |  Up   |       |
* |       |------------------------------------------------------------------------------------------------------------------------------|
* |       |   Ctrl  |   Alt   |   GUI   |                     Space                      | Lower | SetOS | Raise | Left  | Down  | Right |
* `--------------------------------------------------------------------------------------------------------------------------------------'
*/
    [_ADJUST] = LAYOUT_nibble_keloran(
                 KC_TRNS, KC_NO,   KC_NO,   KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,   KC_NO, KC_NO,   KC_NO,   KC_TRNS, KC_NO,
        KC_TRNS, KC_NO,   KC_HYPR, KC_MEH,  KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,   KC_NO, KC_NO,   KC_NO,   KC_NO,   KC_NO,
        KC_TRNS, KC_NO,   KC_NO,   KC_NO,   KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,   KC_NO, KC_NO,            KC_TRNS, KC_NO,
                 KC_NO,   KC_NO,   KC_NO,   KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,   KC_NO, KC_NO,            KC_TRNS, KC_NO,
                 KC_TRNS, KC_TRNS, KC_TRNS,                      KC_TRNS,             KC_TRNS, KC_NO, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
    )
};

void matrix_init_user(void) {
    // Initialize remote keyboard, if connected (see readme)
    matrix_init_remote_kb();
}

void matrix_scan_user(void) {
    // Scan and parse keystrokes from remote keyboard, if connected (see readme)
    matrix_scan_remote_kb();
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
        update_wpm(keycode);
        coding_macro(keycode);
        switch_layer(keycode);
        custom_funcs(keycode);
    }

    switch(keycode) {
        case RM_1: //remote macro 1
            if (record->event.pressed) {
            }
            break;

        case RM_2: //remote macro 2
            if (record->event.pressed) {
            }
            break;

        case RM_3: //remote macro 3
            if (record->event.pressed) {
            }
            break;

        case RM_4: //remote macro 4
            if (record->event.pressed) {
            }
            break;
    }

    return true;
}
