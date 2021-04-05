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

// Defines names for use in layer keycodes and the keymap
enum layer_names {
    _BASE = 0,
    _ALWAYS,
    _FUNC,
    _NAV,
    _LSYM,
    _RSYM,
    _MOUSE,
    _NUM
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

#define KC_ALW LT(1, KC_SPC)
#define KC_FUN LT(2, KC_S)
#define KC_NAV LT(3, KC_D)
#define KC_RSM LT(4, KC_F)
#define KC_LSM LT(5, KC_J)
#define KC_MOU LT(6, KC_K)
#define KC_NUMP LT(7, KC_L)
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
KC_ASH,   KC_FUN,   KC_NAV,   KC_RSM,   KC_G,     KC_H,   KC_LSM,   KC_MOU,    KC_NUMP,   KC_CLSH,
    KC_Z,     KC_XCT,   KC_CGU,   KC_V,     KC_B,     KC_N,   KC_M,     KC_CMGU,   KC_DTCT,   KC_SLSH,
    KC_BSPC,            KC_ALW
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
),
[_MOUSE] = LAYOUT(
    _______,   KC_BTN1,   KC_MS_U,   KC_BTN2,  _______,   _______,   KC_WH_U,   _______,   _______,   _______,
    _______,   KC_MS_L,   KC_MS_D,   KC_MS_R,  _______,   _______,   KC_WH_L,   KC_NO,     KC_WH_R,   _______,
    _______,   _______,   _______,   _______,  _______,   _______,   KC_WH_D,   _______,   _______,   _______,
    _______,              _______
),
[_NUM] = LAYOUT(
    _______,   KC_7,   KC_8,   KC_9,  _______,      _______,   _______,   _______,   _______,   _______,
    KC_0,      KC_4,   KC_5,   KC_6,  _______,   _______,   _______,   _______,   KC_NO,     _______,
    _______,   KC_1,   KC_2,   KC_3,  _______,   _______,   _______,   _______,   _______,   _______,
    _______,              _______
),
};

#ifdef OLED_DRIVER_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
	return OLED_ROTATION_180;
}

static void render_kawa_logo(void) {
    static const char PROGMEM kawa_logo[] = {
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xfc, 0xfc, 0xfc, 0xfc, 0xfc, 0xfc, 0xf8,
		0x00, 0x00, 0x00, 0x00, 0x80, 0xf8, 0xfc, 0xfc, 0xfc, 0xfc, 0xfc, 0xfc, 0x3c, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0xc0, 0xf0, 0xf8, 0xfc, 0xfc, 0xfc, 0xfc, 0xfc, 0xfc, 0xfc, 0xfc, 0xfc, 0xfc,
		0xfc, 0xfc, 0xfc, 0xfc, 0xf8, 0xf8, 0xe0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xfc, 0x04, 0x04,
		0x04, 0x04, 0x04, 0xfc, 0x00, 0x00, 0x00, 0x00, 0x00, 0xfc, 0xfc, 0x04, 0x04, 0x04, 0x04, 0x04,
		0xfc, 0x00, 0x00, 0x00, 0x00, 0x00, 0xfc, 0x0c, 0x04, 0x04, 0x04, 0x04, 0x0c, 0xfc, 0x00, 0x00,
		0x00, 0x00, 0x00, 0xc0, 0xf0, 0xf8, 0xfc, 0xfc, 0xfc, 0xfc, 0xfc, 0xfc, 0xfc, 0xfc, 0xfc, 0xfc,
		0xfc, 0xfc, 0xfc, 0xfc, 0xfc, 0xf8, 0xe0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
		0x00, 0x00, 0xc0, 0xf8, 0xff, 0xff, 0xff, 0xff, 0xff, 0x7f, 0x0f, 0x01, 0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f,
		0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00,
		0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00,
		0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00,
		0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f,
		0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
		0xe0, 0xfc, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xc3, 0xc0, 0xc0, 0x80, 0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0,
		0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00,
		0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00,
		0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00,
		0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0,
		0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
		0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
		0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00,
		0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00,
		0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00,
		0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
		0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00,
		0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00,
		0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00,
		0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x00, 0xc0, 0xc0, 0x00, 0x00,
		0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0xc0, 0xff, 0x00, 0x00,
		0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07,
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x07, 0x06,
		0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x06, 0x03, 0x03, 0x07, 0x06,
		0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x06, 0x03, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
    };
    oled_write_raw_P(kawa_logo, sizeof(kawa_logo));
}

void oled_task_user(void) {
    render_kawa_logo();
}
#endif