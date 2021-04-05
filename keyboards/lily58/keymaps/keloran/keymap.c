#include QMK_KEYBOARD_H

#ifdef PROTOCOL_LUFA
  #include "lufa.h"
  #include "split_util.h"
#endif

#include "keloran.h"

extern uint8_t is_master;

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 * ,-------------------------------------------.                    ,-------------------------------------------.
 * |   Tab  |   Q  |   W  |   E  |   R  |   T  |                    |   Y  |   U  |   I  |   O  |   P  | BckSpc |
 * |--------+------+------+------+------+------|                    |------+------+------+------+------+--------|
 * |   Esc  |   A  |   S  |   D  |   F  |   G  |                    |   H  |   J  |   K  |   L  |   ;  |    '   |
 * |--------+------+------+------+------+------|                    |------+------+------+------+------+--------|
 * | LShift |   Z  |   X  |   C  |   V  |   B  |-------.    ,-------|   N  |   M  |   ,  |   .  |   /  |    -   |
 * |--------+------+------+------+------+------|   [   |    |    ]  |------+------+------+------+------+--------|
 * | LCtrl  |   1  |   2  |   3  |   4  |   5  |-------|    |-------|   6  |   7  |   8  |   9  |   0  | Delete |
 * `-------------------------------------------/       /     \      \-------------------------------------------'
 *                     | LAlt | LGUI | Lower |/ Space /       \ Enter\| Raise |  `   | MISC |
 *                     `-----------------------------'         `----------------------------'
 */
    [_QWERTY] = LAYOUT(
        KC_TAB,   KC_Q,   KC_W,    KC_E,    KC_R,    KC_T,                             KC_Y,       KC_U,   KC_I,    KC_O,   KC_P,    KC_BSPC,
        KC_ESC,   KC_A,   KC_S,    KC_D,    KC_F,    KC_G,                             KC_H,       KC_J,   KC_K,    KC_L,   KC_SCLN, KC_QUOT,
        KC_LSFT,  KC_Z,   KC_X,    KC_C,    KC_V,    KC_B,                             KC_N,       KC_M,   KC_COMM, KC_DOT, KC_SLSH, KC_MINS,
        KC_LCTRL, KC_1,   KC_2,    KC_3,    KC_4,    KC_5,       KC_LBRC,    KC_RBRC,  KC_6,       KC_7,   KC_8,    KC_9,   KC_0,    KC_DELETE,
                                   KC_LALT, KC_LGUI, MO(_LOWER), KC_SPC,     KC_ENT,   MO(_RAISE), KC_GRV, TD(MISC_TAP)
    ),

/* Lower
 * ,-------------------------------------------.                    ,-----------------------------------------.
 * |      | HYPER |  MEH |       |      |      |                    |      |      |      |      |      |  ⇩  |
 * |------+-------+------+-------+------+------|                    |------+------+------+------+------+------|
 * |      |       |      |       |      |      |                    |      |      |      |      |      |      |
 * |------+-------+------+-------+------+------|                    |------+------+------+------+------+------|
 * |   ⇩  |   !   |   @  |   #   |   $  |   %  |-------.    ,-------|   ^  |   &  |   *  |   (  |   )  |  ~  |
 * |------+-------+------+-------+------+-------|   ⇩  |    |   ⇩  |------+------+------+------+------+-----|
 * |   ⇩  |       |      | ALT_3 |      |      |-------|    |-------|      |   _  |   +  |   {  |   }  |  |  |
 * `-------------------------------------------/       /     \      \----------------------------------------'
 *                     |   ⇩  |   ⇩  |   ⇩   |/   ⇩ /       \  ⇩   \|   ⇩   |      | Expose |
 *                     `-----------------------------'         `------------------------------'
 */
    [_LOWER] = LAYOUT(
        KC_NO,   KC_HYPR, KC_MEH, KC_NO,      KC_NO,   KC_NO,                            KC_NO,      KC_NO,   KC_NO,        KC_NO,   KC_NO,   KC_TRNS,
        KC_NO,   KC_NO,   KC_NO,  KC_NO,      KC_NO,   KC_NO,                            KC_NO,      KC_NO,   KC_NO,        KC_NO,   KC_NO,   KC_NO,
        KC_TRNS, KC_EXLM, KC_AT,  KC_HASH,    KC_DLR,  KC_PERC,                          KC_CIRC,    KC_AMPR, KC_ASTR,      KC_LPRN, KC_RPRN, KC_TILD,
        KC_TRNS, KC_NO,   KC_NO,  LALT(KC_3), KC_NO,   KC_NO,      KC_TRNS,    KC_TRNS,  KC_NO,      KC_UNDS, KC_PLUS,      KC_LCBR, KC_RCBR, KC_PIPE,
                                  KC_TRNS,    KC_TRNS, MO(_LOWER), KC_TRNS,    KC_TRNS,  MO(_RAISE), KC_NO,   MAC_EXPOSE
    ),
/* Raise
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |   (  |   )  |      |      |SET_OS|                    |   +  |   -  |   =  |      |   \  |   ⇩  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |   `  |      |      |      |  F1  |  F2  |                    |  :=  |      |      |  Up  |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |   ⇩  |      |      |      |      |      |-------.    ,-------|  !=  |      | Left | Down |Right |      |
 * |------+------+------+------+------+------|   ⇩   |    |  ⇩    |------+------+------+------+------+------|
 * |   ⇩  |      |  <-  |  =>  |  ->  |      |-------|    |-------|      |      |      |      |      |Delete|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   |   ⇩  |   ⇩  |    ⇩  |/   ⇩ /       \  ⇩   \|   ⇩   |      |      |
 *                   `-----------------------------'         `----------------------------'
 */

    [_RAISE] = LAYOUT(
        KC_NO,   KC_LPRN, KC_RPRN,         KC_NO,          KC_NO,               SET_OS,                          KC_KP_PLUS,     KC_MINS, KC_EQL,  KC_NO,   KC_BSLS,  KC_TRNS,
        KC_GRV,  KC_NO,   KC_NO,           KC_NO,          KC_F1,               KC_F2,                           CODE_GO_ASSIGN, KC_NO,   KC_NO,   KC_UP,   KC_NO,    KC_NO,
        KC_TRNS, KC_NO,   KC_NO,           KC_NO,          KC_NO,               KC_NO,                           CODE_NOT_EQUAL, KC_NO,   KC_LEFT, KC_DOWN, KC_RIGHT, KC_NO,
        KC_TRNS, KC_NO,   CODE_GO_CHANNEL, CODE_FAT_ARROW, CODE_ARROW_OPERATOR, KC_NO,      KC_TRNS,    KC_TRNS, KC_NO,          KC_NO,   KC_NO,   KC_NO,   KC_NO,    KC_DELETE,
                                           KC_TRNS,        KC_TRNS,             MO(_LOWER), KC_TRNS,    KC_TRNS, MO(_RAISE),     KC_NO,   KC_NO
    ),
/* Adjust
 * ,--------------------------------------------.                    ,--------------------------------------------.
 * |      |      |Qwerty |Workman|      |       |                    |       |      |      | OLD FPS | CIV  |     |
 * |------+------+-------+-------+------+-------|                    |-------+------+------+---------+------+-----|
 * |      |      |       |       |      | RESET |                    | RESET |      |      |LOCK SCN |      |     |
 * |------+------+-------+-------+------+-------|                    |-------+------+------+---------+------+-----|
 * |      |      |       |       |      |       |-------.    ,-------|       | MUTE |      |         |      |
 * |------+------+-------+-------+------+-------|       |    |       |-------+------+------+---------+------+-----|
 * | CAPS |      |       |       |      |       |-------|    |-------|       |      |      |         |      |     |
 * `-------------------------------------------/       /     \       \--------------------------------------------'
 *                   |       |      |   ⇩    |/       /       \       \|   ⇩   |      |       |
 *                   `-------------------------------'         `------------------------------'
 */
    [_ADJUST] = LAYOUT(
        KC_NO,       KC_NO, QWERTY_LAYER, WORKMAN_LAYER, KC_NO, KC_NO,                       KC_NO,      KC_NO,    KC_NO, OLDFPS_LAYER, CIV_LAYER,   KC_NO,
        KC_NO,       KC_NO, KC_NO,        KC_NO,         KC_NO, RESET,                       RESET,      KC_NO,    KC_NO, LOCK_SCREEN,  KC_NO,       KC_NO,
        KC_NO,       KC_NO, KC_NO,        KC_NO,         KC_NO, KC_NO,                       KC_NO,      KC__MUTE, KC_NO, KC_NO,        KC_NO,       KC_NO,
        KC_CAPSLOCK, KC_NO, KC_NO,        KC_NO,         KC_NO, KC_NO,      KC_NO,    KC_NO, KC_NO,      KC_NO,    KC_NO, KC_NO,        KC_NO,       KC_NO,
                                          KC_NO,         KC_NO, MO(_LOWER), KC_NO,    KC_NO, MO(_RAISE), KC_NO,    KC_NO
  ),

/* Civilization
 * ,-----------------------------------------------------------------.                      ,------------------------------------------------------------.
 * |         |          |    Up    |          |          |           |                      |        |           |             |          | Pause |      |
 * |---------+----------+----------+----------+----------+-----------|                      |--------+-----------+-------------+----------+-------+------|
 * |   ESC   |   Left   |   Down   |  Right   |          |           |                      |        |           |             |          |       |      |
 * |---------+----------+----------+----------+----------+-----------|                      |--------+-----------+-------------+----------+-------+------|
 * |         |          |          |          |          |           |---------.     ,------|        |           |             |          |       |      |
 * |---------+----------+----------+----------+----------+-----------|   Menu  |     |      |--------+-----------+-------------+----------+-------+------|
 * | Capital | PrevCity | NextCity | PrevUnit | NextUnit | QuickSave |---------|     |------| Civics | Espionage | GreatPeople | TechTree |       |      |
 * `-----------------------------------------------------------------/  Next   /     \      \-----------------------------------------------------------'
 *                              | StratView |            |  LOWER  |/  Turn   /       \      \| RAISE |      |      |
 *                              `--------------------------------------------'         `----------------------------'
 */
    [_CIV] = LAYOUT(
        KC_NO,   KC_NO,   KC_UP,   KC_NO,    KC_NO,  KC_NO,                          KC_NO,      KC_NO, KC_NO, KC_NO, KC_P,  KC_NO,
        KC_ESC,  KC_LEFT, KC_DOWN, KC_RIGHT, KC_NO,  KC_NO,                          KC_NO,      KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
        KC_NO,   KC_NO,   KC_NO,   KC_NO,    KC_NO,  KC_NO,                          KC_NO,      KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
        KC_BSLS, KC_LBRC, KC_RBRC, KC_COMM,  KC_DOT, KC_F5,      KC_HOME,     KC_NO, KC_C,       KC_F3, KC_O,  KC_T,  KC_NO, KC_NO,
                                   KC_EQL,   KC_NO,  MO(_LOWER), KC_ENTER,    KC_NO, MO(_RAISE), KC_NO, KC_NO
    ),

/* Old FPS
 * ,-------------------------------------------.                    ,-----------------------------------------.
 * |       |      |  Up  |       |      |      |                    |      |      |      |      |      |      |
 * |-------+------+------+-------+------+------|                    |------+------+------+------+------+------|
 * |  ESC  | Left | Down | Right |      |      |                    |      |      |      |      |      |      |
 * |-------+------+------+-------+------+------|                    |------+------+------+------+------+------|
 * | Shift |      |      |       |      |      |-------.    ,-------|      |      |      |      |      |      |
 * |-------+------+------+-------+------+------|       |    |       |------+------+------+------+------+------|
 * | LCTRL |      |      |       |      |      |-------|    |-------|      |      |      |      |      |      |
 * `-------------------------------------------/       /     \      \-----------------------------------------'
 *                   |      |      |  LOWER  |/ Space /       \ Enter\| RAISE |     |      |
 *                   `-------------------------------'         `---------------------------'
 */
    [_OLDFPS] = LAYOUT(
        KC_NO,     KC_NO,   KC_UP,   KC_NO,    KC_NO, KC_NO,                             KC_NO,      KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
        KC_ESC,    KC_LEFT, KC_DOWN, KC_RIGHT, KC_NO, KC_NO,                             KC_NO,      KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
        KC_LSHIFT, KC_NO,   KC_NO,   KC_NO,    KC_NO, KC_NO,                             KC_NO,      KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
        KC_LCTRL,  KC_NO,   KC_NO,   KC_NO,    KC_NO, KC_NO,      KC_NO,       KC_NO,    KC_NO,      KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
                                     KC_NO,    KC_NO, MO(_LOWER), KC_SPACE,    KC_ENTER, MO(_RAISE), KC_NO, KC_NO
    ),

/* Workman
 * ,-------------------------------------------.                    ,-------------------------------------------.
 * |   Tab  |   Q  |   D  |   R  |   W  |   B  |                    |   J  |   F  |   U  |   P  |   ;  | BckSpc |
 * |--------+------+------+------+------+------|                    |------+------+------+------+------+--------|
 * |   Esc  |   A  |   S  |   H  |   T  |   G  |                    |   Y  |   N  |   E  |   O  |   I  |    '   |
 * |--------+------+------+------+------+------|                    |------+------+------+------+------+--------|
 * | LShift |   Z  |   X  |   M  |   C  |   V  |-------.    ,-------|   K  |   L  |   ,  |   .  |   /  |    -   |
 * |--------+------+------+------+------+------|   [   |    |    ]  |------+------+------+------+------+--------|
 * | LCtrl  |   1  |   2  |   3  |   4  |   5  |-------|    |-------|   6  |   7  |   8  |   9  |   0  | Delete |
 * `-------------------------------------------/       /     \      \-------------------------------------------'
 *                     | LAlt | LGUI | LOWER |/ Space /       \ Enter\| RAISE |  `   | MISC |
 *                     `-----------------------------'         `----------------------------'
 */
    [_WORKMAN] = LAYOUT(
        KC_TAB,   KC_Q,   KC_D,    KC_R,    KC_W,    KC_B,                             KC_J,       KC_F,   KC_U,    KC_P,   KC_SCLN, KC_BSPC,
        KC_ESC,   KC_A,   KC_S,    KC_H,    KC_T,    KC_G,                             KC_Y,       KC_N,   KC_E,    KC_O,   KC_I,    KC_QUOT,
        KC_LSFT,  KC_Z,   KC_X,    KC_M,    KC_C,    KC_V,                             KC_K,       KC_L,   KC_COMM, KC_DOT, KC_SLSH, KC_MINS,
        KC_LCTRL, KC_1,   KC_2,    KC_3,    KC_4,    KC_5,       KC_LBRC,    KC_RBRC,  KC_6,       KC_7,   KC_8,    KC_9,   KC_0,    KC_DELETE,
                                   KC_LALT, KC_LGUI, MO(_LOWER), KC_SPC,     KC_ENT,   MO(_RAISE), KC_GRV, TD(MISC_TAP)
    ),

/* F Keys
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |  F1  |  F2  |  F3  |  F4  |  F5  |                    |      |      |      |      |      |QWERTY|
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |  F6  |  F7  |  F8  |  F9  |  F10 |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |Shift |  F11 |  F12 |      |      |      |-------.    ,-------|      |      |      |      |      |      |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * | CTRL |      |      |      |      |      |-------|    |-------|      |      |      |      |      |      |
 * `-----------------------------------------/       /     \      \----------------------------------------'
 *                     | LAlt | LGUI | LOWER |/Space /       \ Enter\| RAISE |      | MISC |
 *                     `----------------------------'         `----------------------------'
 */
    [_FKEYS] = LAYOUT(
        KC_NO,     KC_F1,   KC_F2,    KC_F3,   KC_F4,   KC_F5,                         KC_NO,      KC_NO, KC_NO, KC_NO, KC_NO, QWERTY_LAYER,
        KC_NO,     KC_F6,   KC_F7,    KC_F8,   KC_F9,   KC_F10,                        KC_NO,      KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
        KC_LSHIFT, KC_F11,  KC_F12,   KC_NO,   KC_NO,   KC_NO,                         KC_NO,      KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
        KC_LCTRL,  KC_NO,   KC_NO,    KC_NO,   KC_NO,   KC_NO,      KC_NO,     KC_NO,  KC_NO,      KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
                                      KC_LALT, KC_LGUI, MO(_LOWER), KC_SPC,    KC_ENT, MO(_RAISE), KC_NO, TD(MISC_TAP)
    ),
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
        update_wpm(keycode);
        coding_macro(keycode);
        switch_layer(keycode);
        custom_funcs(keycode);
    }

  return true;
}
