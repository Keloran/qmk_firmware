/* Copyright 2019 Ryota Goto
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

// Defines the keycodes used by our macros in process_record_user
enum custom_keycodes {
  KBINFO = SAFE_RANGE
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT( /* Base */
        KBINFO
    ),
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    //uprintf("KL: kc: 0x%04X, col: %u, row: %u\n", keycode, record->event.key.col, record->event.key.row);

    switch (keycode) {
        case KBINFO:
            if (record->event.pressed) {
                SEND_STRING("Beep");
            } else {
                SEND_STRING("Peeb");
            }
            break;
    }
    return true;
}
