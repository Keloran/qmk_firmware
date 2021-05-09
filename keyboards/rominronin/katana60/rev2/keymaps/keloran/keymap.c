/* Copyright 2019 rominronin
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

// MacOS based definitions.
#define K_SPCFN LT(SYMB, KC_SPACE) // Tap for space, hold for symbols layer
#define K_PRVWD LALT(KC_LEFT)      // Previous word
#define K_NXTWD LALT(KC_RIGHT)     // Next word
#define K_LSTRT LGUI(KC_LEFT)      // Start of line
#define K_LEND  LGUI(KC_RIGHT)     // End of line
#define UNDO    LGUI(KC_Z)         // UNDO
#define CUT     LGUI(KC_X)         // CUT
#define COPY    LGUI(KC_C)         // COPY
#define PASTE   LGUI(KC_V)         // PASTE

enum layer_names {
    BASE,
    NUMB,
    SYMB,
    CURS,
};

// Defines the keycodes used by our macros in process_record_user
enum custom_keycodes {
    QMKBEST = SAFE_RANGE,
    QMKURL
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] = LAYOUT_1_a(/* Base */
        KC_GESC,  KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,  TD(MISC_TAP),   KC_6,    KC_7,    KC_8,    KC_9,  KC_0, KC_MINS, KC_EQL,
        KC_TAB,      KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_LBRC, KC_RBRC, KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,         KC_BSPC,
        SUPERCAPS, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_HOME,      KC_END, KC_H,    KC_J,    KC_K,    KC_L,    KC_QUOT,   KC_ENT,
        KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,  KC_SCLN,  KC_DEL,  KC_SLASH, KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_UP, KC_RSFT,
        MO(_ADJUST),   KC_LCTL, KC_LALT, KC_LGUI,          KC_SPC,    KC_ENT,     K_SPCFN,       KC_RGUI, KC_NO, KC_LEFT, KC_DOWN,   KC_RIGHT
    ),
    [_ADJUST] = LAYOUT_1_a(
        RESET,  KC_NO,  KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,  KC_NO,   KC_NO,    KC_NO,    KC_NO,    KC_NO,  KC_NO, KC_NO, KC_NO,
        KC_NO,      KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO, KC_NO, KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,         KC_NO,
        KC_NO, KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,      KC_NO, KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,   KC_NO,
        KC_NO, KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,  KC_NO,  KC_NO,  KC_NO, KC_NO,    KC_NO,    KC_NO, KC_NO,  KC_NO, KC_NO,
        KC_NO,   KC_NO, KC_NO, KC_NO,          KC_NO,    KC_NO,     KC_NO,       KC_NO, KC_NO, KC_NO, KC_NO,   KC_NO
    )
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    uprintf("KL: kc: 0x%04X, col: %u, row: %u\n", keycode, record->event.key.col, record->event.key.row);

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
