/* Copyright 2018 Carlos Filoteo
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

#include "rgb_matrix.h"
#include "print.h"

#define LT3_TAB LT(3, KC_TAB)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Base Layer
* ,-------------------------------------------------------------------------.
* | Tab |  Q  |  W  |  E  |  R  |  T  |  Y  |  U  |  I  |  O  |  P  |Bspace |
* |-------------------------------------------------------------------------+
* | Esc  |  A  |  S  |  D  |  F  |  G  |  H  |  J  |  K  |  L  |  ;  |   '  |
* |-------------------------------------------------------------------------+
* | Shift |  Z  |  X  |  C  |  V  |  B  |  N  |  M  |  ,  |  .  |  Up |Enter|
* |-------------------------------------------------------------------------+
* | Ctrl| Lead| Alt | Gui |Lower |   Space   |Raise |  /  |Left |Down |Right|
* `-------------------------------------------------------------------------'
*/
    [_QWERTY] = LAYOUT(
        KC_TAB,    KC_Q,    KC_W,    KC_E,    KC_R,       KC_T,     KC_Y,  KC_U,       KC_I,     KC_O,    KC_P,      KC_BSPACE,
        KC_ESCAPE, KC_A,    KC_S,    KC_D,    KC_F,       KC_G,     KC_H,  KC_J,       KC_K,     KC_L,    KC_SCOLON, KC_QUOTE,
        KC_LSHIFT, KC_Z,    KC_X,    KC_C,    KC_V,       KC_B,     KC_N,  KC_M,       KC_COMMA, KC_DOT,  KC_UP,     KC_ENTER,
        KC_LCTRL,  KC_LEAD, KC_LALT, KC_LGUI, MO(_LOWER), KC_SPACE,        MO(_RAISE), KC_SLASH, KC_LEFT, KC_DOWN,   KC_RIGHT
    ),

/* Lower Layer
* ,-------------------------------------------------------------------------.
* |  ~ |  !  |  @  |ALT_3 |  $  |  %  |  ^  |  &  |  (  |  )  |  *  |   ⇩  |
* |-------------------------------------------------------------------------|
* |  | |  §   |HYPER |  #  |  =  |     |     |  _  |  {  |  }  |  +  |   `  |
* |-------------------------------------------------------------------------|
* |      |  \  | MEH |     |     |     |     |  =  |  [  |  ]  |  ⇩  |     |
* |-------------------------------------------------------------------------|
* |Caps |    |    |     |   ⇩  |    ⇩    |  ⇩   |  \   |  ⇩  |  ⇩  |  ⇩ |
* `-------------------------------------------------------------------------'
*/
    [_LOWER] = LAYOUT(
        KC_TILD,     KC_EXLM,         KC_AT,   LALT(KC_3), KC_DLR,      KC_PERC,  KC_CIRC, KC_AMPR,    KC_LPRN,   KC_RPRN, KC_ASTR,   KC_TRNS,
        KC_PIPE,     KC_NONUS_BSLASH, KC_HYPR, KC_HASH,    KC_KP_EQUAL, KC_NO,    KC_NO,   KC_UNDS,    KC_LCBR,   KC_RCBR, KC_PLUS,   KC_GRAVE,
        KC_NO,       KC_NONUS_HASH,   KC_MEH,  KC_NO,      KC_NO,       KC_NO,    KC_NO,   KC_EQUAL,   KC_LBRC,   KC_RBRC, KC_TRNS,   KC_NO,
        KC_CAPSLOCK, KC_NO,           KC_NO,   KC_NO,      MO(_LOWER),  KC_SPACE,          MO(_RAISE), KC_BSLASH, KC_TRNS, KC_TRNS,   KC_TRNS
    ),

/* Raise
* ,-----------------------------------------------------------------------------------.
* |  `   |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  |  ⇩  |
* |------+------+------+------+------+------+------+------+------+------+------+------|
* |  Del |      |      |      |      |      |      |      |      |      |  -   |      |
* |------+------+------+------+------+------+------+------+------+------+------+------|
* |Shift |      |      |      |      |      |      |      |      |      |  ⇩   |  ⇩  |
* |------+------+------+------+------+------+------+------+------+------+------+------|
* |      |      |      |      |   ⇩  |      ⇩     |  ⇩  |      |  ⇩   |  ⇩  |  ⇩  |
* `-----------------------------------------------------------------------------------'
*/
    [_RAISE] = LAYOUT(
        KC_GRAVE,  KC_1,  KC_2,  KC_3,  KC_4,       KC_5,     KC_6,  KC_7,       KC_8,  KC_9,    KC_0,     KC_TRNS,
        KC_DELETE, KC_NO, KC_NO, KC_NO, KC_NO,      KC_NO,    KC_NO, KC_NO,      KC_NO, KC_NO,   KC_MINUS, KC_NO,
        KC_LSHIFT, KC_NO, KC_NO, KC_NO, KC_NO,      KC_NO,    KC_NO, KC_NO,      KC_NO, KC_NO,   KC_TRNS,  KC_TRNS,
        KC_NO,     KC_NO, KC_NO, KC_NO, MO(_LOWER), KC_SPACE,        MO(_RAISE), KC_NO, KC_TRNS, KC_TRNS,  KC_TRNS
    ),

/* Adjust
* ,------------------------------------------------------------------------------------.
* | MISC |      |Workman| Game |      | FKeys |      |      |      |      |      |Reset |
* |------+------+-------+------+------+-------+------+------+------+------+------+------|
* |      |      |Qwerty | Civ  |      |       |      |      |      |      |      |      |
* |------+------+-------+------+------+-------+------+------+------+------+------+------|
* |      |      |       |      |      |       |      |      |      |      |      |      |
* |------+------+-------+------+------+-------+------+------+------+------+------+------|
* |      |      |       |      |  ⇩  |              |  ⇩   |      |      |      |      |
* `-------------------------------------------------------------------------------------'
*/
    [_ADJUST] = LAYOUT(
        MO(_MISC), KC_NO, WORKMAN_LAYER, OLDFPS_LAYER, KC_NO,      OSL(_FKEYS), KC_NO, KC_NO,      KC_NO, KC_NO, KC_NO, RESET,
        KC_NO,     KC_NO, QWERTY_LAYER,  CIV_LAYER,    KC_NO,      KC_NO,       KC_NO, KC_NO,      KC_NO, KC_NO, KC_NO, KC_NO,
        KC_NO,     KC_NO, KC_NO,         KC_NO,        KC_NO,      KC_NO,       KC_NO, KC_NO,      KC_NO, KC_NO, KC_NO, KC_NO,
        KC_NO,     KC_NO, KC_NO,         KC_NO,        MO(_LOWER), KC_NO,              MO(_RAISE), KC_NO, KC_NO, KC_NO, KC_NO
    ),

/* Function Keys
* ,------------------------------------------------------------------------------------.
* |      |      |      |      |      |       |      |      |      |      |      |      |
* |------+------+------+------+------+-------+------+------+------+------+------+------|
* |      |  F1  |  F2  |  F3  |  F4  |  F5   |  F6  |  F7  |  F8  |  F9  |  F10 |      |
* |------+------+------+------+------+-------+------+------+------+------+------+------|
* |      | F11  | F12  | F13  | F14  | F15   | F16  | F17  | F18  | F19  |  F20 |      |
* |------+------+------+------+------+-------+------+------+------+------+------+------|
* |      |      |      |      |  ⇩  |              |   ⇩  |      |      |      |      |
* `------------------------------------------------------------------------------------'
*/
    [_FKEYS] = LAYOUT(
        KC_NO, KC_NO,  KC_NO,  KC_NO,  KC_NO,      KC_NO,  KC_NO,  KC_NO,      KC_NO,  KC_NO,  KC_NO,  KC_NO,
        KC_NO, KC_F1,  KC_F2,  KC_F3,  KC_F4,      KC_F5,  KC_F6,  KC_F7,      KC_F8,  KC_F9,  KC_F10, KC_NO,
        KC_NO, KC_F11, KC_F12, KC_F13, KC_F14,     KC_F15, KC_F16, KC_F17,     KC_F18, KC_F19, KC_F20, KC_NO,
        KC_NO, KC_NO,  KC_NO,  KC_NO,  MO(_LOWER), KC_NO,          MO(_RAISE), KC_NO,  KC_NO,  KC_NO,  KC_NO
    ),

/* MISC
* ,----------------------------------------------------------------------------------.
* |Term1 |Term2 | GUI  |      |      |      |     |      |      |      |      |      |
* |------+------+------+------+------+------+-----+------+------+------+------+------|
* |      |      |      |      |      |      |     |      |      |      |      | PgUp |
* |------+------+------+------+------+------+-----+------+------+------+------+------|
* |      |      |      |      |      |      |     |      |      |      |      | PgDn |
* |------+------+------+------+------+------+-----+------+------+------+------+------|
* |      |      |      |      |  ⇩  |            |   ⇩  |      |      |      |      |
* `----------------------------------------------------------------------------------'
*/
    [_MISC] = LAYOUT(
        LINUX_TERM1, LINUX_TERM2, LINUX_GUI, KC_NO, KC_NO,      KC_NO,    KC_NO, KC_NO,      KC_NO, KC_NO, KC_NO, KC_NO,
        KC_NO,       KC_NO,       KC_NO,     KC_NO, KC_NO,      KC_NO,    KC_NO, KC_NO,      KC_NO, KC_NO, KC_NO, KC_PGUP,
        KC_NO,       KC_NO,       KC_NO,     KC_NO, KC_NO,      KC_NO,    KC_NO, KC_NO,      KC_NO, KC_NO, KC_NO, KC_PGDN,
        KC_NO,       KC_NO,       KC_NO,     KC_NO, MO(_LOWER), KC_SPACE,        MO(_RAISE), KC_NO, KC_NO, KC_NO, KC_NO
    )
};

extern bool g_suspend_state;

const rgblight_segment_t PROGMEM rgb_base_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 8, HSV_RED}
);
const rgblight_segment_t PROGMEM rgb_lower_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 8, HSV_GOLD}
);
const rgblight_segment_t PROGMEM rgb_raise_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 8, HSV_BLUE}
);
const rgblight_segment_t PROGMEM rgb_adjust_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 8, HSV_PURPLE}
);
const rgblight_segment_t PROGMEM rgb_caps_lock[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 8, HSV_WHITE}
);
const rgblight_segment_t* const PROGMEM rgb_layers[] = RGBLIGHT_LAYERS_LIST(
    rgb_caps_lock,
    rgb_adjust_layer,
    rgb_raise_layer,
    rgb_lower_layer,
    rgb_base_layer
);

void keyboard_post_init_user(void) {
    rgblight_layers = rgb_layers;
}
