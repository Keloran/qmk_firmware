#include QMK_KEYBOARD_H

#include "keloran.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Base
* ,-------------------------------------------------------------------------------.
* |   Q   |   W   |   E   |   R   |   T   |   Y   |   U   |   I   |   O   |   P   |
* |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
* |   A   |   S   |   D   |   F   |   G   |   H   |   J   |   K   |   L   | Raise |
* |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
* |   Z   |   X   |   C   |   V   | Space | Enter |   B   |   N   |   M   | Lower |
* `-------------------------------------------------------------------------------'
*/
  [_BASE] = LAYOUT_ortho_3x10(
    KC_Q, KC_W, KC_E, KC_R, KC_T,   KC_Y,   KC_U, KC_I, KC_O, KC_P,
    KC_A, KC_S, KC_D, KC_F, KC_G,   KC_H,   KC_J, KC_K, KC_L, MO(_RAISE),
    KC_Z, KC_X, KC_C, KC_V, KC_SPC, KC_ENT, KC_B, KC_N, KC_M, MO(_LOWER)
  ),

/* Lower
* ,-------------------------------------------------------------------------------.
* |   1   |   2   |   3   |   4   |   5   |   6   |   7   |   8   |   9   |   0   |
* |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
* |  Tab  |       |       |       |       |       |       |       |       | Raise |
* |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
* |  Esc  |       |       |       |       |  Bspc |       |       |       | Lower |
* `-------------------------------------------------------------------------------'
*/
  [_LOWER] = LAYOUT_ortho_3x10(
    KC_1,   KC_2,  KC_3,  KC_4,  KC_5,  KC_6,    KC_7,  KC_8,  KC_9,  KC_0,
    KC_TAB, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,   KC_NO, KC_NO, KC_NO, KC_TRNS,
    KC_ESC, KC_NO, KC_NO, KC_NO, KC_NO, KC_BSPC, KC_NO, KC_NO, KC_NO, KC_TRNS
  ),

/* Raise
* ,-------------------------------------------------------------------------------.
* |       |   Up  |       |       |       |       |       |       |       |       |
* |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
* |  Left |  Down | Right |       |       |       |       |       |       | Raise |
* |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|         p
* |       |       |       |       |       |       |       |       |       | Lower |
* `-------------------------------------------------------------------------------'
*/
  [_RAISE] = LAYOUT_ortho_3x10(
    KC_NO,   KC_UP,   KC_NO,    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
    KC_LEFT, KC_DOWN, KC_RIGHT, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_TRNS,
    KC_NO,   KC_NO,   KC_NO,    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_TRNS
  ),

/* Adjust
* ,-------------------------------------------------------------------------------.
* | RESET |       |       |       |       |       |       |       |       |       |
* |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
* |       |       |       |       |       |       |       |       |       | Raise |
* |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
* |       |       |       |       |       |       |       |       |       | Lower |
* `-------------------------------------------------------------------------------'
*/
  [_ADJUST] = LAYOUT_ortho_3x10(
    RESET, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_TRNS,
    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_TRNS
  )
};

void keyboard_pre_init_user(void) {
  // Call the keyboard pre init code.

  // Set our LED pins as output
  setPinOutput(D5);
  setPinOutput(B0);
}

void led_set_user(uint8_t usb_led) {
  if (IS_LED_ON(usb_led, USB_LED_NUM_LOCK)) {
    writePinLow(D5);
  } else {
    writePinHigh(D5);
  }

  if (IS_LED_ON(usb_led, USB_LED_CAPS_LOCK)) {
    writePinLow(B0);
  } else {
    writePinHigh(B0);
  }
}
