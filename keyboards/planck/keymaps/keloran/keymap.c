#include QMK_KEYBOARD_H
#ifdef AUDIO_ENABLE
#   include "muse.h"
#endif
#include "eeprom.h"

#include "keloran.h"

#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Base
* ,-----------------------------------------------------------------------------------.
* |  Tab |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
* |------+------+------+------+------+------+------+------+------+------+------+------|
* |  Esc |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |   "  |
* |------+------+------+------+------+------+------+------+------+------+------+------|
* |Shift |   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |  Up  |Enter |
* |------+------+------+------+------+------+------+------+------+------+------+------|
* | Ctrl | Misc | Alt  | GUI  |Lower |    Space    |Raise |   /  | Left | Down |Right |
* `-----------------------------------------------------------------------------------'
*/
  [_BASE] = LAYOUT_ortho_4x12(
        KC_TAB,    KC_Q,         KC_W,    KC_E,    KC_R,       KC_T,      KC_Y,      KC_U,       KC_I,      KC_O,     KC_P,      KC_BSPACE,
        KC_GESC,   KC_A,         KC_S,    KC_D,    KC_F,       KC_G,      KC_H,      KC_J,       KC_K,      KC_L,     KC_SCOLON, KC_QUOTE,
        KC_LSHIFT, KC_Z,         KC_X,    KC_C,    KC_V,       KC_B,      KC_N,      KC_M,       KC_COMMA,  KC_DOT,   KC_UP,     KC_ENTER,
        KC_LCTRL,  TD(MISC_TAP), KC_LALT, KC_LGUI, MO(_LOWER), KC_SPACE,  KC_NO,     MO(_RAISE), KC_SLASH,  KC_LEFT,  KC_DOWN,   KC_RIGHT
  ),

/* Lower
 * ,-----------------------------------------------------------------------------------.
 * |  ~   |   !  |   @  |ALT_3 |   $  |   %  |   ^  |   &  |   (  |   )  |   *  |  ⇩  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |  |   |   §  |HYPER |   #  |   =  |      |      |   _  |   {  |   }  |   +  |  `   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |   \  | MEH  |      |      |      |      |   =  |   -  |      |  ⇩  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Caps |      |      |      |  ⇩   |      ⇩     |  ⇩  |   \  |  ⇩   |  ⇩  |  ⇩  |
 * `-----------------------------------------------------------------------------------'
 */
  [_LOWER] = LAYOUT_ortho_4x12(
        KC_TILD,     KC_EXLM,         KC_AT,   LALT(KC_3), KC_DLR,      KC_PERC,  KC_CIRC, KC_AMPR,    KC_LPRN,   KC_RPRN, KC_ASTR, KC_TRNS,
        KC_PIPE,     KC_NONUS_BSLASH, KC_HYPR, KC_HASH,    KC_KP_EQUAL, KC_NO,    KC_NO,   KC_UNDS,    KC_LCBR,   KC_RCBR, KC_PLUS, KC_GRAVE,
        KC_NO,       KC_NONUS_HASH,   KC_MEH,  KC_NO,      KC_NO,       KC_NO,    KC_NO,   KC_EQUAL,   KC_MINUS,  KC_NO,   KC_TRNS, KC_NO,
        KC_CAPSLOCK, KC_NO,           KC_NO,   KC_NO,      MO(_LOWER),  KC_SPACE, KC_NO,   MO(_RAISE), KC_BSLASH, KC_TRNS, KC_TRNS, KC_TRNS
  ),

/* Raise
* ,-----------------------------------------------------------------------------------.
* |  `   |   %  |   &  |   ?  |   +  |   @  |   $  |   _  |   [  |   ]  |   !  |  ⇩   |
* |------+------+------+------+------+------+------+------+------+------+------+------|
* |  Del |   /  |   (  |   =  |   0  |   {  |   }  |   1  |   *  |   )  |   -  |  .   |
* |------+------+------+------+------+------+------+------+------+------+------+------|
* |      |   6  |  7   |   8  |   9  |   |  |   \  |   2  |   3  |  4   |   5  |      |
* |------+------+------+------+------+------+------+------+------+------+------+------|
* |      |      |      |      |   ⇩  |      ⇩     |  ⇩  |      |      |      |      |
* `-----------------------------------------------------------------------------------'
*/
  [_RAISE] = LAYOUT_ortho_4x12(
        KC_GRAVE,  KC_PERC,  KC_AMPR, KC_QUES,  KC_PLUS,    KC_AT,    KC_DLR,    KC_UNDS,    KC_LBRACKET, KC_RBRACKET, KC_EXLM,  KC_TRNS,
        KC_DELETE, KC_SLASH, KC_LPRN, KC_EQUAL, KC_0,       KC_LCBR,  KC_RCBR,   KC_1,       KC_ASTR,     KC_RPRN,     KC_MINUS, KC_KP_DOT,
        KC_NO,     KC_6,     KC_7,    KC_8,     KC_9,       KC_PIPE,  KC_BSLASH, KC_2,       KC_3,        KC_4,        KC_5,     KC_NO,
        KC_NO,     KC_NO,    KC_NO,   KC_NO,    MO(_LOWER), KC_SPACE, KC_NO,     MO(_RAISE), KC_NO,       KC_NO,       KC_NO,    KC_NO
  ),

/* Adjust
* ,------------------------------------------------------------------------------------.
* | MISC |      |Workman| Game |      | FKeys |      |      |      |      |      |Reset |
* |------+------+-------+------+------+-------+------+------+------+------+------+------|
* |      |      |Qwerty | Civ  |      |       |      |  RGB |BRGTH+|BRGTH-|      |      |
* |------+------+-------+------+------+-------+------+------+------+------+------+------|
* |      |      |       |      |      |       |      |RGBMod| Hue+ | Hue- |      |      |
* |------+------+-------+------+------+-------+------+------+------+------+------+------|
* |      | Oryx |       |      |   ⇩  |             |  ⇩   | RGB+ | RGB- |      |      |
* `-------------------------------------------------------------------------------------'
*/
    [_ADJUST] = LAYOUT_ortho_4x12(
        MO(_MISC), KC_NO,       WORKMAN_LAYER, OLDFPS_LAYER, KC_NO,      OSL(_FKEYS), KC_NO, KC_NO,      KC_NO,   KC_NO,   KC_NO, RESET,
        KC_NO,     KC_NO,       BASE_LAYER,  CIV_LAYER,    KC_NO,      KC_NO,       KC_NO, RGB_TOG,    RGB_VAI, RGB_VAD, KC_NO, KC_NO,
        KC_NO,     KC_NO,       KC_NO,         KC_NO,        KC_NO,      KC_NO,       KC_NO, RGB_MOD,    RGB_HUI, RGB_HUD, KC_NO, KC_NO,
        KC_NO,     WEBUSB_PAIR, KC_NO,         KC_NO,        MO(_LOWER), KC_NO,       KC_NO, MO(_RAISE), RGB_SPI, RGB_SPD, KC_NO, KC_NO
    ),

/* OldGames Layer
* ,------------------------------------------------------------------------------------.
* |      |      |  Up  |      |      |       |      |      |      |      |      |      |
* |------+------+------+------+------+-------+------+------+------+------+------+------|
* | ESC  | Left | Down |Right |      |       |      |      |      |      |      |      |
* |------+------+------+------+------+-------+------+------+------+------+------+------|
* |Shift |      |      |      |      |       |      |      |      |      |      |Enter |
* |------+------+------+------+------+-------+------+------+------+------+------+------|
* | Ctrl |      |      |      |  ⇩   |    Space    |   ⇩  |      |      |      |      |
* `------------------------------------------------------------------------------------'
*/
  [_OLDFPS] = LAYOUT_ortho_4x12(
        KC_NO,     KC_NO,   KC_UP,   KC_NO,    KC_NO,      KC_NO,    KC_NO, KC_NO,      KC_NO, KC_NO, KC_NO, KC_NO,
        KC_ESC,    KC_LEFT, KC_DOWN, KC_RIGHT, KC_NO,      KC_NO,    KC_NO, KC_NO,      KC_NO, KC_NO, KC_NO, KC_NO,
        KC_LSHIFT, KC_NO,   KC_NO,   KC_NO,    KC_NO,      KC_NO,    KC_NO, KC_NO,      KC_NO, KC_NO, KC_NO, KC_ENTER,
        KC_LCTRL,  KC_NO,   KC_NO,   KC_NO,    MO(_LOWER), KC_SPACE, KC_NO, MO(_RAISE), KC_NO, KC_NO, KC_NO, KC_NO
  ),

/* Function Keys
* ,------------------------------------------------------------------------------------.
* |      |      |      |      |      |       |      |      |      |      |      |      |
* |------+------+------+------+------+-------+------+------+------+------+------+------|
* |      |  F1  |  F2  |  F3  |  F4  |  F5   |  F6  |  F7  |  F8  |  F9  |  F10 |      |
* |------+------+------+------+------+-------+------+------+------+------+------+------|
* |      | F11  | F12  | F13  | F14  | F15   | F16  | F17  | F18  | F19  |  F20 |      |
* |------+------+------+------+------+-------+------+------+------+------+------+------|
* |      |      |      |      |   ⇩  |             |   ⇩  |      |      |      |      |
* `------------------------------------------------------------------------------------'
*/
  [_FKEYS] = LAYOUT_ortho_4x12(
        KC_NO, KC_NO,  KC_NO,  KC_NO,  KC_NO,      KC_NO,  KC_NO,  KC_NO,      KC_NO,  KC_NO,  KC_NO,  KC_NO,
        KC_NO, KC_F1,  KC_F2,  KC_F3,  KC_F4,      KC_F5,  KC_F6,  KC_F7,      KC_F8,  KC_F9,  KC_F10, KC_NO,
        KC_NO, KC_F11, KC_F12, KC_F13, KC_F14,     KC_F15, KC_F16, KC_F17,     KC_F18, KC_F19, KC_F20, KC_NO,
        KC_NO, KC_NO,  KC_NO,  KC_NO,  MO(_LOWER), KC_NO,  KC_NO,  MO(_RAISE), KC_NO,  KC_NO,  KC_NO,  KC_NO
  ),

/* Workman
* ,-----------------------------------------------------------------------------------.
* | Tab  |   Q  |   D  |   R  |   W  |   B  |   J  |   F  |   U  |   P  |   ;  | Bksp |
* |------+------+------+------+------+------+------+------+------+------+------+------|
* | Esc  |   A  |   S  |   H  |   T  |   G  |   Y  |   N  |   E  |   O  |   I  |  "   |
* |------+------+------+------+------+------+------+------+------+------+------+------|
* | Shift|   Z  |   X  |   M  |   C  |   V  |   K  |   L  |   ,  |   .  |   /  |Enter |
* |------+------+------+------+------+------+------+------+------+------+------+------|
* | Ctrl | Lead | Alt  | GUI  |   ⇩  |    Space   |   ⇩  | Left | Down |  Up  |Right |
* `-----------------------------------------------------------------------------------'
*/
    [_WORKMAN] = LAYOUT_ortho_4x12(
        KC_TAB,    KC_Q,     KC_D,    KC_R,    KC_W,       KC_B,     KC_J,  KC_F,       KC_U,     KC_P,    KC_SCOLON, KC_BSPACE,
        KC_ESCAPE, KC_A,     KC_S,    KC_H,    KC_T,       KC_G,     KC_Y,  KC_N,       KC_E,     KC_O,    KC_I,      KC_QUOTE,
        KC_LSFT,   KC_Z,     KC_X,    KC_M,    KC_C,       KC_V,     KC_K,  KC_L,       KC_COMMA, KC_DOT,  KC_SLASH,  KC_ENTER,
        KC_LCTRL,  KC_LEAD,  KC_LALT, KC_LGUI, MO(_LOWER), KC_SPACE, KC_NO, MO(_RAISE), KC_LEFT,  KC_DOWN, KC_UP,     KC_RIGHT
    ),

/* MISC
* ,----------------------------------------------------------------------------------.
* |Term1 |Term2 | GUI  |      |      |      |     |      |      |      |      |      |
* |------+------+------+------+------+------+-----+------+------+------+------+------|
* |      |      |      |      |      |      |     |      |      |      |      | PgUp |
* |------+------+------+------+------+------+-----+------+------+------+------+------|
* |      |      |      |      |      |      |     |      |      |      |      | PgDn |
* |------+------+------+------+------+------+-----+------+------+------+------+------|
* |      |      |      |      |   ⇩  |           |   ⇩  |      |      |      |      |
* `----------------------------------------------------------------------------------'
*/
    [_MISC] = LAYOUT_ortho_4x12(
        LINUX_TERM1, LINUX_TERM2, LINUX_GUI, KC_NO, KC_NO,      KC_NO,    KC_NO, KC_NO,      KC_NO, KC_NO, KC_NO, KC_NO,
        KC_NO,       KC_NO,       KC_NO,     KC_NO, KC_NO,      KC_NO,    KC_NO, KC_NO,      KC_NO, KC_NO, KC_NO, KC_PGUP,
        KC_NO,       KC_NO,       KC_NO,     KC_NO, KC_NO,      KC_NO,    KC_NO, KC_NO,      KC_NO, KC_NO, KC_NO, KC_PGDN,
        KC_NO,       KC_NO,       KC_NO,     KC_NO, MO(_LOWER), KC_SPACE, KC_NO, MO(_RAISE), KC_NO, KC_NO, KC_NO, KC_NO
    ),
};

extern bool g_suspend_state;
extern rgb_config_t rgb_matrix_config;

void keyboard_post_init_user(void) {
  rgb_matrix_enable();
}

#define RGB_BLACK 0x00, 0x00, 0x00
#define RGB_ROMAN_LEAF 0x55, 0xCB, 0x9E
#define RGB_LIGHT_RED 0x00, 0xB7, 0xEE
#define RGB_SUPER_LIGHT_PURPLE 0xF9, 0xE4, 0xFF
#define RGB_LIGHT_BLUE 0x8D, 0xFF, 0xE9

const uint8_t PROGMEM ledmap[][DRIVER_LED_TOTAL][3] = {
    // Lower
    [_LOWER] = {
        {RGB_BLACK},              {RGB_BLACK}, {RGB_BLACK}, {RGB_BLACK},  {RGB_BLACK}, {RGB_BLACK},     {RGB_BLACK}, {RGB_BLACK}, {RGB_LIGHT_BLUE},  {RGB_LIGHT_BLUE},  {RGB_BLACK}, {RGB_BLACK},
        {RGB_BLACK},              {RGB_BLACK}, {RGB_BLACK}, {RGB_PURPLE}, {RGB_BLACK}, {RGB_PINK},      {RGB_BLACK}, {RGB_BLACK}, {RGB_ROMAN_LEAF},  {RGB_ROMAN_LEAF},  {RGB_BLACK}, {RGB_BLACK},
        {RGB_BLACK},              {RGB_BLACK}, {RGB_BLACK}, {RGB_BLACK},  {RGB_BLACK}, {RGB_LIGHT_RED}, {RGB_BLACK}, {RGB_BLACK}, {RGB_BLACK},       {RGB_BLACK},       {RGB_BLACK}, {RGB_BLACK},
        {RGB_SUPER_LIGHT_PURPLE}, {RGB_BLACK}, {RGB_BLACK}, {RGB_BLACK},  {RGB_BLACK}, {RGB_BLACK},                  {RGB_BLACK}, {RGB_BLACK},       {RGB_BLACK},       {RGB_BLACK}, {RGB_BLACK}
    },

    // Raise
    [_RAISE] = {
        {RGB_BLACK}, {RGB_BLACK},      {RGB_BLACK},      {RGB_BLACK},      {RGB_BLACK},      {RGB_BLACK}, {RGB_BLACK}, {RGB_BLACK},      {RGB_ROMAN_LEAF}, {RGB_ROMAN_LEAF}, {RGB_BLACK},      {RGB_BLACK},
        {RGB_BLACK}, {RGB_BLACK},      {RGB_BLACK},      {RGB_BLACK},      {RGB_LIGHT_BLUE}, {RGB_BLACK}, {RGB_BLACK}, {RGB_LIGHT_BLUE}, {RGB_BLACK},      {RGB_BLACK},      {RGB_BLACK},      {RGB_BLACK},
        {RGB_BLACK}, {RGB_LIGHT_BLUE}, {RGB_LIGHT_BLUE}, {RGB_LIGHT_BLUE}, {RGB_LIGHT_BLUE}, {RGB_BLACK}, {RGB_BLACK}, {RGB_LIGHT_BLUE}, {RGB_LIGHT_BLUE}, {RGB_LIGHT_BLUE}, {RGB_LIGHT_BLUE}, {RGB_BLACK},
        {RGB_BLACK}, {RGB_BLACK},      {RGB_BLACK},      {RGB_BLACK},      {RGB_BLACK},      {RGB_BLACK},              {RGB_BLACK},      {RGB_BLACK},      {RGB_BLACK},      {RGB_BLACK},      {RGB_BLACK}
    },

    // Adjust
    [_ADJUST] = {
        {RGB_BLACK},      {RGB_BLACK}, {RGB_ROMAN_LEAF}, {RGB_ROMAN_LEAF}, {RGB_BLACK}, {RGB_LIGHT_BLUE}, {RGB_BLACK}, {RGB_BLACK}, {RGB_BLACK}, {RGB_BLACK}, {RGB_BLACK}, {RGB_BLACK},
        {RGB_BLACK},      {RGB_BLACK}, {RGB_ROMAN_LEAF}, {RGB_BLACK},      {RGB_BLACK}, {RGB_BLACK},      {RGB_BLACK}, {RGB_CORAL}, {RGB_CORAL}, {RGB_CORAL}, {RGB_BLACK}, {RGB_RED},
        {RGB_BLACK},      {RGB_BLACK}, {RGB_ROMAN_LEAF}, {RGB_BLACK},      {RGB_BLACK}, {RGB_BLACK},      {RGB_BLACK}, {RGB_CORAL}, {RGB_CORAL}, {RGB_CORAL}, {RGB_BLACK}, {RGB_BLACK},
        {RGB_LIGHT_BLUE}, {RGB_BLACK}, {RGB_BLACK},      {RGB_BLACK},      {RGB_BLACK}, {RGB_BLACK},                   {RGB_BLACK}, {RGB_BLACK}, {RGB_BLACK}, {RGB_BLACK}, {RGB_BLACK}
    },

    // Game
    [_OLDFPS] = {
        {RGB_BLACK}, {RGB_BLACK}, {RGB_BLACK}, {RGB_BLACK}, {RGB_BLACK}, {RGB_BLACK}, {RGB_BLACK}, {RGB_BLACK}, {RGB_BLACK}, {RGB_BLACK}, {RGB_BLACK},       {RGB_BLACK},
        {RGB_BLACK}, {RGB_BLACK}, {RGB_BLACK}, {RGB_BLACK}, {RGB_BLACK}, {RGB_BLACK}, {RGB_BLACK}, {RGB_BLACK}, {RGB_BLACK}, {RGB_BLACK}, {RGB_LIGHT_RED},   {RGB_BLACK},
        {RGB_BLACK}, {RGB_BLACK}, {RGB_BLACK}, {RGB_BLACK}, {RGB_BLACK}, {RGB_BLACK}, {RGB_BLACK}, {RGB_BLACK}, {RGB_BLACK}, {RGB_BLACK}, {RGB_BLACK},       {RGB_BLACK},
        {RGB_BLACK}, {RGB_BLACK}, {RGB_BLACK}, {RGB_BLACK}, {RGB_BLACK}, {RGB_BLACK},              {RGB_BLACK}, {RGB_BLACK}, {RGB_BLACK}, {RGB_BLACK},       {RGB_BLACK}
    },

    // Function Keys
    [_FKEYS] = {
        {RGB_BLACK}, {RGB_BLACK}, {RGB_BLACK}, {RGB_BLACK}, {RGB_BLACK}, {RGB_BLACK}, {RGB_BLACK}, {RGB_BLACK}, {RGB_BLACK}, {RGB_BLACK},      {RGB_BLACK},      {RGB_BLACK},
        {RGB_BLACK}, {RGB_PINK},  {RGB_PINK},  {RGB_PINK},  {RGB_PINK},  {RGB_PINK},  {RGB_PINK},  {RGB_PINK},  {RGB_PINK},  {RGB_PINK},       {RGB_PINK},       {RGB_BLACK},
        {RGB_BLACK}, {RGB_PINK},  {RGB_PINK},  {RGB_GREEN}, {RGB_GREEN}, {RGB_GREEN}, {RGB_GREEN}, {RGB_GREEN}, {RGB_GREEN}, {RGB_GREEN},      {RGB_GREEN},      {RGB_BLACK},
        {RGB_BLACK}, {RGB_BLACK}, {RGB_BLACK}, {RGB_BLACK}, {RGB_BLACK}, {RGB_BLACK},              {RGB_BLACK}, {RGB_BLACK}, {RGB_LIGHT_BLUE}, {RGB_LIGHT_BLUE}, {RGB_LIGHT_BLUE}
    },

    // Misc Keys
    [_MISC] = {
        {RGB_PINK},  {RGB_PINK},  {RGB_PINK},  {RGB_BLACK}, {RGB_BLACK}, {RGB_BLACK}, {RGB_BLACK}, {RGB_BLACK}, {RGB_BLACK}, {RGB_BLACK}, {RGB_BLACK}, {RGB_BLACK},
        {RGB_BLACK}, {RGB_BLACK}, {RGB_BLACK}, {RGB_BLACK}, {RGB_BLACK}, {RGB_BLACK}, {RGB_BLACK}, {RGB_BLACK}, {RGB_BLACK}, {RGB_BLACK}, {RGB_BLACK}, {RGB_CORAL},
        {RGB_BLACK}, {RGB_BLACK}, {RGB_BLACK}, {RGB_BLACK}, {RGB_BLACK}, {RGB_BLACK}, {RGB_BLACK}, {RGB_BLACK}, {RGB_BLACK}, {RGB_BLACK}, {RGB_BLACK}, {RGB_CORAL},
        {RGB_BLACK}, {RGB_BLACK}, {RGB_BLACK}, {RGB_BLACK}, {RGB_BLACK}, {RGB_BLACK},              {RGB_BLACK}, {RGB_BLACK}, {RGB_BLACK}, {RGB_BLACK}, {RGB_BLACK}
    },
};

void set_layer_color(int layer) {
  for (int i = 0; i < DRIVER_LED_TOTAL; i++) {
    HSV hsv = {
      .h = pgm_read_byte(&ledmap[layer][i][0]),
      .s = pgm_read_byte(&ledmap[layer][i][1]),
      .v = pgm_read_byte(&ledmap[layer][i][2]),
    };
    if (!hsv.h && !hsv.s && !hsv.v) {
        rgb_matrix_set_color( i, 0, 0, 0 );
    } else {
        RGB rgb = hsv_to_rgb( hsv );
        float f = (float)rgb_matrix_config.hsv.v / UINT8_MAX;
        rgb_matrix_set_color( i, f * rgb.r, f * rgb.g, f * rgb.b );
    }
  }
}

void rgb_matrix_indicators_user(void) {
  if (g_suspend_state || keyboard_config.disable_layer_led) { return; }

  uint8_t keyID = biton32(layer_state);
  switch (keyID) {
    case _LOWER:
    case _RAISE:
    case _OLDFPS:
    case _FKEYS:
    case _ADJUST:
    case _MISC:
      set_layer_color(keyID);
      break;
   default:
    if (rgb_matrix_get_flags() == LED_FLAG_NONE)
      rgb_matrix_set_color_all(0, 0, 0);
    break;
  }
}

void linux_macro_keys(int f) {
    register_code(KC_RCTRL);
    register_code(KC_RALT);

    switch (f) {
        case 1:
            tap_code(KC_F1);
            break;
        case 2:
            tap_code(KC_F2);
            break;
        case 7:
            tap_code(KC_F7);
            break;
    }

    unregister_code(KC_RCTRL);
    unregister_code(KC_RALT);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
        coding_macro(keycode);
        switch_layer(keycode);
        custom_funcs(keycode, record);
    }

    return true;
}

