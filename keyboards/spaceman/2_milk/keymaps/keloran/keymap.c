#include QMK_KEYBOARD_H
#include "keloran.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/*
 *     /\
 *    /  \
 *  ,------.
 *  | Misc |
 *  ,------.
 *  |  X  |
 *  `------'
 */
      [_BASE] = LAYOUT(
        TD(MISC_TAP ),
        KC_X
      )
};
