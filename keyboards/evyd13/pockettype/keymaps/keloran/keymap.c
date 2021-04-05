/* Copyright 2019 Maarten Dekkers <maartenwut@gmail.com>
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
/* Qwerty
* ,-----------------------------------------------------------------------------------.
* | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  |Bspc  |
* |------+------+------+------+------+------+------+------+------+------+------+------|
* | Esc  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  "   |
* |------+------+------+------+------+------+------+------+------+------+------+------|
* | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |Enter |
* |------+------+------+------+------+------+------+------+------+------+------+------|
* | Ctrl |      | Alt  | GUI  |Lower |Space | Del  |Raise | Left | Down |  Up  |Right |
* `-----------------------------------------------------------------------------------'
*/
    [_QWERTY] = LAYOUT_ortho_4x12(
        KC_TAB,    KC_Q,   KC_W,    KC_E,    KC_R,       KC_T,     KC_Y,   KC_U,       KC_I,     KC_O,    KC_P,      KC_BSPC,
        KC_ESCAPE, KC_A,   KC_S,    KC_D,    KC_F,       KC_G,     KC_H,   KC_J,       KC_K,     KC_L,    KC_SCOLON, KC_QUOTE,
        KC_LSFT,   KC_Z,   KC_X,    KC_C,    KC_V,       KC_B,     KC_N,   KC_M,       KC_COMMA, KC_DOT,  KC_SLASH,  KC_ENTER,
        KC_LCTRL,  KC_NO,  KC_LALT, KC_LGUI, MO(_LOWER), KC_SPACE, KC_DEL, MO(_RAISE), KC_LEFT,  KC_DOWN, KC_UP,     KC_RIGHT
    ),

/* Lower
* ,-----------------------------------------------------------------------------------.
* |      |      |      |      |      |      |      |      |      |      |      |Bspc  |
* |------+------+------+------+------+------+------+------+------+------+------+------|
* |      |      |      |      |      |      |      |      |      |      |      |      |
* |------+------+------+------+------+------+------+------+------+------+------+------|
* |      |      |      |      |      |      |      |      |      |      |      |Enter |
* |------+------+------+------+------+------+------+------+------+------+------+------|
* | Caps |      |      |      |Lower |      |      |Raise |      |      |      |      |
* `-----------------------------------------------------------------------------------'
*/
    [_LOWER] = LAYOUT_ortho_4x12(
        KC_NO,       KC_NO, KC_NO, KC_NO, KC_NO,      KC_NO, KC_NO, KC_NO,      KC_NO, KC_NO, KC_NO, KC_TRNS,
        KC_NO,       KC_NO, KC_NO, KC_NO, KC_NO,      KC_NO, KC_NO, KC_NO,      KC_NO, KC_NO, KC_NO, KC_NO,
        KC_NO,       KC_NO, KC_NO, KC_NO, KC_NO,      KC_NO, KC_NO, KC_NO,      KC_NO, KC_NO, KC_NO, KC_TRNS,
        KC_CAPSLOCK, KC_NO, KC_NO, KC_NO, MO(_LOWER), KC_NO, KC_NO, MO(_RAISE), KC_NO, KC_NO, KC_NO, KC_NO
    ),

/* Raise
* ,-----------------------------------------------------------------------------------.
* |      |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Bksp |
* |------+------+------+------+------+------+------+------+------+------+------+------|
* |      |      |      |      |      |      |      |      |      |      |      |      |
* |------+------+------+------+------+------+------+------+------+------+------+------|
* |      |      |      |      |      |      |      |      |      |      |      |Enter |
* |------+------+------+------+------+------+------+------+------+------+------+------|
* |      |      |      |      |Lower |      |      |Raise |      |      |      |      |
* `-----------------------------------------------------------------------------------'
*/
    [_RAISE] = LAYOUT_ortho_4x12(
        KC_NO, KC_1,  KC_2,  KC_3,  KC_4,       KC_5,  KC_6,  KC_7,       KC_8,    KC_9,  KC_0,  KC_TRNS,
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,      KC_NO, KC_NO, KC_NO,      KC_NO,   KC_NO, KC_NO, KC_NO,
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,      KC_NO, KC_NO, KC_NO,      KC_NO,   KC_NO, KC_5,  KC_TRNS,
        KC_NO, KC_NO, KC_NO, KC_NO, MO(_LOWER), KC_NO, KC_NO, MO(_RAISE), KC_TRNS, KC_NO, KC_NO, KC_NO
    ),

/* Adjust
* ,-----------------------------------------------------------------------------------.
* |      |      |      |      |      |      |      |      |      |      |      |Reset |
* |------+------+------+------+------+------+------+------+------+------+------+------|
* |      |      |      |      |      |      |      |      |      |      |      |      |
* |------+------+------+------+------+------+------+------+------+------+------+------|
* |      |      |      |      |      |      |      |      |      |      |      |      |
* |------+------+------+------+------+------+------+------+------+------+------+------|
* |      |      |      |      |      |      |      |      |      |      |      |      |
* `-----------------------------------------------------------------------------------'
*/
    [_ADJUST] = LAYOUT_ortho_4x12(
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,      KC_NO, KC_NO, KC_NO,      KC_NO, KC_NO, KC_NO, RESET,
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,      KC_NO, KC_NO, KC_NO,      KC_NO, KC_NO, KC_NO, KC_NO,
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,      KC_NO, KC_NO, KC_NO,      KC_NO, KC_NO, KC_NO, KC_NO,
        KC_NO, KC_NO, KC_NO, KC_NO, MO(_LOWER), KC_NO, KC_NO, MO(_RAISE), KC_NO, KC_NO, KC_NO, KC_NO
    ),
};
