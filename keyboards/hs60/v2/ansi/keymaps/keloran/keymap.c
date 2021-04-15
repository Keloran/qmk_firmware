/* Copyright 2018 Yiancar
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
#include "print.h"

enum hs60_custom {
    SUPERCAPS = SAFE_RANGE
};

//This is the ANSI version of the PCB

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
* |   Ctrl  |   Alt   |   GUI   |                     Space                       |  Lower  |   Misc  |  Misc  |  Raise  |
* `----------------------------------------------------------------------------------------------------------------------'
*/
    [_BASE] = LAYOUT_60_ansi(
        KC_GESC,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,       KC_0,         KC_MINS, KC_EQL,       KC_BSPC,
        KC_TAB,     KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,       KC_P,         KC_LBRC, KC_RBRC,      KC_BSLS,
        SUPERCAPS,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,       KC_SCLN,      KC_QUOT,               KC_ENT,
        KC_LSFT,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,     KC_SLSH,                             KC_RSFT,
        KC_LCTL,    KC_LALT, KC_LGUI,                   KC_SPC,                             MO(_LOWER), TD(MISC_TAP),          TD(MISC_TAP), MO(_RAISE)
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
* |   Ctrl  |   Alt   |   GUI   |                     Space                       |  Lower  |         |  Misc  |  Raise  |
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
* |   `   |       |       |       |       |      |       |       |       |       |       |       |       |   Delete      |
* |----------------------------------------------------------------------------------------------------------------------|
* |    Tab    |       |  Up   |       |       |       |       |       |       |       |       |       |       |          |
* |----------------------------------------------------------------------------------------------------------------------|
* |            |  Left |  Down | Right |       |       |       |       |       |       |       |       |      Enter      |
* |----------------------------------------------------------------------------------------------------------------------|
* |     Shift      |       |       |       |       |       |       |       |       |       |       |       Shift         |
* |----------------------------------------------------------------------------------------------------------------------|
* |   Ctrl  |   Alt   |   GUI   |                     Space                       |  Lower  |         |  Misc  |  Raise  |
* `----------------------------------------------------------------------------------------------------------------------'
*/
    [_LOWER] = LAYOUT_60_ansi(
        KC_GRV,  KC_NO,   KC_NO,   KC_NO,      KC_NO, KC_NO,   KC_NO, KC_NO, KC_NO, KC_NO,   KC_NO,   KC_NO, KC_NO,   KC_DEL,
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
* |            |RGB_TOG|RGB_MOD|       |       |       |       |       |       |       |       |       |      Enter      |
* |----------------------------------------------------------------------------------------------------------------------|
* |     Shift      |       |       |       |       |       |       |       |       |       |       |       Shift         |
* |----------------------------------------------------------------------------------------------------------------------|
* |   RGB   |   Alt   |   GUI   |                     Space                       |  Lower  |         |  Misc  |  Raise  |
* `----------------------------------------------------------------------------------------------------------------------'
*/
    [_ADJUST] = LAYOUT_60_ansi(
        RESET,   KC_NO,   KC_NO,   KC_NO, KC_NO, KC_NO,   KC_NO, KC_NO, KC_NO, KC_NO,   KC_NO,   KC_NO, KC_NO,   KC_TRNS,
        KC_TRNS, KC_NO,   KC_NO,   KC_NO, KC_NO, KC_NO,   KC_NO, KC_NO, KC_NO, KC_NO,   KC_NO,   KC_NO, KC_NO,   KC_NO,
        KC_NO,   RGB_TOG, RGB_MOD, KC_NO, KC_NO, KC_NO,   KC_NO, KC_NO, KC_NO, KC_NO,   KC_NO,   KC_NO,          KC_TRNS,
        KC_TRNS, KC_NO,   KC_NO,   KC_NO, KC_NO, KC_NO,   KC_NO, KC_NO, KC_NO, KC_NO,   KC_NO,                   KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS,               KC_TRNS,                      KC_TRNS, KC_TRNS,        KC_TRNS, KC_TRNS
    ),
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    uprintf("KL: kc: 0x%04X, col: %u, row: %u\n", keycode, record->event.key.col, record->event.key.row);

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
                    register_code(KC_ESC);
                    unregister_code(KC_ESC);
                } else {
                    register_code(KC_CAPS);
                }
            }

            return false;
    }

    return true;
}