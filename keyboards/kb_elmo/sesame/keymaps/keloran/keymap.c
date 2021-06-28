/* Copyright 2020 kb-elmo<mail@elmo.space>
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

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* Base */
    [_BASE] = LAYOUT_alice(
        KC_HOME, KC_GESC,   KC_1,  KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,   KC_8, KC_9,         KC_0,    KC_MINS, KC_EQL,     KC_BSPC,
        KC_END,  KC_TAB,    KC_Q,  KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,   KC_I, KC_O,         KC_P,    KC_LBRC, KC_RBRC,    KC_BSLS,
        WEB,     SUPERCAPS, KC_A,  KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,   KC_K, KC_L,         KC_SCLN, KC_QUOT,             KC_ENT,
                 KC_LSFT,   KC_Z,  KC_X,    KC_C,    KC_V,    KC_B,    KC_B,    KC_N,   KC_M, KC_COMM,      KC_DOT,  KC_SLSH, MO(_LOWER), MO(_RAISE),
                 KC_LCTL,          KC_LGUI,          KC_SPC,           KC_LALT, KC_SPC,       TD(MISC_TAP),                   KC_RCTL
    ),
    [_LOWER] = LAYOUT_alice(
        KC_NO, KC_GRV,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_DEL,
        KC_NO, KC_NO,   KC_HOME, KC_UP,   KC_END,  KC_PGUP, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_UP,   KC_NO,   KC_NO,   KC_NO,
        KC_NO, KC_NO,   KC_LEFT, KC_DOWN, KC_RGHT, KC_PGDN, KC_NO,   KC_NO,   KC_TRNS, KC_NO,   KC_LEFT, KC_DOWN, KC_RGHT,          KC_NO,
               KC_TRNS, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_VOLD, KC_VOLU, KC_MUTE, KC_MPRV, KC_MNXT, KC_MPLY, KC_TRNS, KC_TRNS,
               KC_TRNS,          KC_TRNS,          KC_NO,            KC_TRNS, KC_NO,            KC_NO,                     KC_NO
    ),
    [_RAISE] = LAYOUT_alice(
        KC_NO, KC_NO,   KC_NO,   KC_NO,   KC_NO,    KC_NO, KC_NO, KC_NO,   KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,   KC_TRNS,
        KC_NO, KC_NO,   KC_NO,   KC_UP,   KC_NO,    KC_NO, KC_NO, KC_NO,   KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,   KC_NO,
        KC_NO, KC_NO,   KC_LEFT, KC_DOWN, KC_RIGHT, KC_NO, KC_NO, KC_NO,   KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,          KC_NO,
               KC_TRNS, KC_NO,   KC_NO,   KC_NO,    KC_NO, KC_NO, KC_NO,   KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_TRNS, KC_TRNS,
               KC_TRNS,          KC_TRNS,           KC_NO,        KC_TRNS, KC_NO,        KC_NO,               KC_NO
    ),
    [_ADJUST] = LAYOUT_alice(
        KC_NO, RESET, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,       KC_NO, KC_NO, KC_NO, SET_OS,
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,       KC_NO, KC_NO, KC_NO, KC_NO,
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, LOCK_SCREEN, KC_NO, KC_NO,        KC_NO,
               KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,       KC_NO, KC_NO, KC_NO, KC_NO,
               KC_NO,        KC_NO,        KC_NO,        KC_NO, KC_NO,        KC_NO,                     KC_NO
    )
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    //uprintf("KL: kc: 0x%04X, col: %u, row: %u\n", keycode, record->event.key.col, record->event.key.row);

    if (record->event.pressed) {
        update_wpm(keycode);
        coding_macro(keycode);
        switch_layer(keycode);
        custom_funcs(keycode, record);
    }

    static uint16_t caps_timer;
    switch (keycode) {
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
