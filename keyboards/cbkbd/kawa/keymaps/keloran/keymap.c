/* Copyright 2020 sofubi
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

// Defines names for use in layer keycodes and the keymap
enum layer_names {
    _ALWAYS,
    _FUNC,
    _NAV,
    _LSYM,
    _RSYM,
};

enum best_keycodes {
    KC_ALW = SAFE_RANGE,
    KC_FUN,
    KC_NAV,
    KC_RSM,
    KC_LSM,
    KC_MOU,
    KC_NUMP,
    KC_ASH,
    KC_XCT,
    KC_CGU,
    KC_CMGU,
    KC_DTCT,
    KC_CLSH,
    KC_TTY
};

#define KC_ALW LT(_ALWAYS, KC_SPC)
#define KC_FUN LT(_FUNC, KC_S)
#define KC_NAV LT(_NAV, KC_D)
#define KC_RSM LT(_LSYM, KC_F)
#define KC_NUMP LT(_RSYM, KC_L)
#define KC_ASH LSFT_T(KC_A)
#define KC_XCT LCTL_T(KC_X)
#define KC_CGU LGUI_T(KC_C)
#define KC_CMGU LGUI_T(KC_COMM)
#define KC_DTCT LCTL_T(KC_DOT)
#define KC_CLSH LSFT_T(KC_SCLN)
#define KC_TTY LCTL(KC_LALT)



const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] = LAYOUT(
        KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     KC_Y,   KC_U,     KC_I,      KC_O,      KC_P,
        KC_ASH,   KC_FUN,   KC_NAV,   KC_RSM,   KC_G,     KC_H,   KC_J,     KC_K,      KC_L,      KC_CLSH,
        KC_Z,     KC_XCT,   KC_CGU,   KC_V,     KC_B,     KC_N,   KC_M,     KC_CMGU,   KC_DTCT,   KC_SLSH,
                                        KC_ALW,            KC_BSPC
    ),
    [_ALWAYS] = LAYOUT(
        _______,   _______,   KC_COLN,   KC_ESC,   _______,   _______,   _______,   _______,   _______,   KC_DEL,
        _______,   _______,   _______,   KC_ENT,   _______,   _______,   KC_LGUI,   _______,   _______,   _______,
        _______,   _______,   _______,   _______,  _______,   _______,   _______,   _______,   _______,   RESET,
        KC_TAB,               KC_NO
    ),
    [_FUNC] = LAYOUT(
        _______,   _______,   _______,   _______,  _______,   _______,   KC_F7,   KC_F8,   KC_F9,   KC_F10,
        _______,   KC_NO,     KC_TTY,   _______,   _______,   _______,   KC_F4,   KC_F5,   KC_F6,   KC_F11,
        _______,   _______,   _______,   _______,  _______,   _______,   KC_F1,   KC_F2,   KC_F3,   KC_F12,
        _______,             _______
    ),
    [_NAV] = LAYOUT(
        _______,   _______,   _______,   _______,  _______,   _______,   _______,   _______,   _______,   _______,
        _______,   _______,   KC_NO,     _______,  _______,   KC_LEFT,   KC_DOWN,   KC_UP,     KC_RIGHT,  _______,
        _______,   _______,   _______,   _______,  _______,   _______,   _______,   _______,   _______,   _______,
        _______,				_______
    ),
    [_LSYM] = LAYOUT(
        _______,   _______,   _______,   _______,  _______,   _______,    KC_UNDS,   KC_PIPE,   KC_QUOT,   _______,
        KC_CIRC,   KC_ASTR,   KC_AMPR,   KC_NO,    _______,   KC_HASH,    KC_TILD,   KC_SLSH,   KC_DQUO,   KC_DLR,
        _______,   _______,   _______,   _______,  _______,   _______,    KC_MINS,   KC_BSLS,   KC_GRV,    _______,
        _______,              _______
    ),
    [_RSYM] = LAYOUT(
        _______,   KC_COLN,   KC_LT,     KC_GT,    _______,   _______,   _______,   _______,   _______,   _______,
        KC_LCBR,   KC_RCBR,   KC_LPRN,   KC_RPRN,  KC_AT,     _______,   KC_NO,     KC_EQL,    KC_PLUS,   KC_PERC,
        _______,   KC_EXLM,   KC_LBRC,   KC_RBRC,  _______,   _______,   _______,   _______,   _______,   _______,
        _______,              _______
    )
};
