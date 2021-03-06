/* Copyright 2020 Paul James
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
 * ,-----------------------------------------. ,-----------------------------------------.
 * |   `  |  1   |  2   |  3   |  4   |  5   | |  6   |  7   |  8   |  9   |  0   | BkSp |
 * |------+------+------+------+------+------| |------+------+------+------+------+------|
 * | Tab  |  Q   |  W   |  E   |  R   |  T   | |  Y   |  U   |  I   |  O   |  P   | Del  |
 * |------+------+------+------+------+------| |------+------+------+------+------+------|
 * | Esc  |  A   |  S   |  D   |  F   |  G   | |  H   |  J   |  K   |  L   |  ;   |  '   |
 * |------+------+------+------+------+------| |------+------+------+------+------+------|
 * | Shft |  Z   |  X   |  C   |  V   |  B   | |  N   |  M   |  ,   |  .   |  /   | Entr |
 * |------+------+------+------+------+------| |------+------+------+------+------+------|
 * | Ctrl | Misc | Alt  | Cmd  |Lower | Spac | | Spac |Raise | Left | Down |  Up  | Rght |
 * `-----------------------------------------' `-----------------------------------------'
 */
    [_BASE] = LAYOUT_ortho_5x12(
        KC_GRV,  KC_1,         KC_2,    KC_3,    KC_4,       KC_5,        KC_6,   KC_7,       KC_8,    KC_9,    KC_0,    KC_BSPC,
        KC_TAB,  KC_Q,         KC_W,    KC_E,    KC_R,       KC_T,        KC_Y,   KC_U,       KC_I,    KC_O,    KC_P,    KC_DEL,
        KC_GESC, KC_A,         KC_S,    KC_D,    KC_F,       KC_G,        KC_H,   KC_J,       KC_K,    KC_L,    KC_SCLN, KC_QUOT,
        KC_LSFT, KC_Z,         KC_X,    KC_C,    KC_V,       KC_B,        KC_N,   KC_M,       KC_COMM, KC_DOT,  KC_SLSH, KC_ENT,
        KC_LCTL, TD(MISC_TAP), KC_LALT, KC_LGUI, MO(_LOWER), KC_SPC,      KC_SPC, MO(_RAISE), KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT
    ),

/* Raise
* ,------------------------------------------. ,-----------------------------------------.
 * |   `  |   1  |   2  |   3  |   4  |   5  | |   6  |   7  |   8  |   9  |   0  | Bksp |
 * |------+------+------+------+------+------| |------+------+------+------+------+------|
 * |   `  |   1  |   2  |   3  |   4  |   5  | |   6  |   7  |   8  |   9  |   0  | Del  |
 * |------+------+------+------+------+------| |------+------+------+------+------+------|
 * | Del  |  F1  |  F2  |  F3  |  F4  |  F5  | |  F6  |   -  |   =  |   [  |   ]  |  \   |
 * |------+------+------+------+------+------| |------+------+------+------+------+------|
 * |      |  F7  |  F8  |  F9  |  F10 |  F11 | |  F12 |ISO # |ISO / |      |      |      |
 * |------+------+------+------+------+------| |------+------+------+------+------+------|
 * |      |      |      |      |      |      | |      |      | Next | Vol- | Vol+ | Play |
 * `-----------------------------------------' `-----------------------------------------'
 */
    [_RAISE] = LAYOUT_ortho_5x12(
        KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
        KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_DEL,
        KC_DEL,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_BSLS,
        KC_TRNS, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_NUHS, KC_NUBS, KC_PGUP, KC_PGDN, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY
    ),

/* Lower
* ,------------------------------------------. ,-----------------------------------------.
* |      |      |      |      |      |      | |   6  |   7  |   8  |   9  |   0  | Bksp |
* |------+------+------+------+------+------| |------+------+------+------+------+------|
* |   `  |   1  |   2  |   3  |      |      | |   6  |   7  |   8  |   9  |   0  | Del  |
* |------+------+------+------+------+------| |------+------+------+------+------+------|
* | Del  |  F1  |  F2  |  F3  |  F4  |  F5  | |  F6  |   -  |   =  |   [  |   ]  |  \   |
* |------+------+------+------+------+------| |------+------+------+------+------+------|
* |      |  F7  |  F8  |  F9  |  F10 |  F11 | |  F12 |ISO # |ISO / |      |      |      |
* |------+------+------+------+------+------| |------+------+------+------+------+------|
* |      |      |      |      |      |      | |      |      | Next | Vol- | Vol+ | Play |
* `-----------------------------------------' `-----------------------------------------'
*/
    [_LOWER] = LAYOUT_ortho_5x12(
        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO, KC_NO, KC_NO, KC_NO,
        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO, KC_NO, KC_NO, KC_NO,
        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO, KC_NO, KC_NO, KC_NO,
        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO, KC_NO, KC_NO, KC_NO,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_NO, KC_NO, KC_NO, KC_NO
    ),

/* Lower
* ,------------------------------------------. ,-----------------------------------------.
* |      |      |      |      |      |      | |   6  |   7  |   8  |   9  |   0  | Bksp |
* |------+------+------+------+------+------| |------+------+------+------+------+------|
* |   `  |   1  |   2  |   3  |      |      | |   6  |   7  |   8  |   9  |   0  | Del  |
* |------+------+------+------+------+------| |------+------+------+------+------+------|
* | Del  |  F1  |  F2  |  F3  |  F4  |  F5  | |  F6  |   -  |   =  |   [  |   ]  |  \   |
* |------+------+------+------+------+------| |------+------+------+------+------+------|
* |      |  F7  |  F8  |  F9  |  F10 |  F11 | |  F12 |ISO # |ISO / |      |      |      |
* |------+------+------+------+------+------| |------+------+------+------+------+------|
* |      |      |      |      |      |      | |      |      | Next | Vol- | Vol+ | Play |
* `-----------------------------------------' `-----------------------------------------'
*/
    [_ADJUST] = LAYOUT_ortho_5x12(
        RESET,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO, KC_NO, KC_NO, KC_NO,
        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO, KC_NO, KC_NO, KC_NO,
        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO, KC_NO, KC_NO, KC_NO,
        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO, KC_NO, KC_NO, KC_NO,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_NO, KC_NO, KC_NO, KC_NO
    )
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    // uprintf("KL: kc: 0x%04X, col: %u, row: %u\n", keycode, record->event.key.col, record->event.key.row);

    if (record->event.pressed) {
        update_wpm(keycode);
        coding_macro(keycode);
        switch_layer(keycode);
        custom_funcs(keycode, record);
    }

    return true;
}
