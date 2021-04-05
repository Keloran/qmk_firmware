#include QMK_KEYBOARD_H

#include "rgb.h"
#include "keloran.h"

#ifdef RGBLIGHT_LAYERS
void rgb_led_state(uint8_t caps_state) {
    extern rgblight_config_t rgblight_config;
    if (!rgblight_config.enable) {
        rgblight_enable();
    }

    rgblight_set_layer_state(3, !caps_state);
    rgblight_set_layer_state(0, caps_state);
}

void rgb_layer_colors(layer_state_t state) {
    rgblight_set_layer_state(3, layer_state_cmp(state, _QWERTY));
    rgblight_set_layer_state(2, layer_state_cmp(state, _LOWER));
    rgblight_set_layer_state(1, layer_state_cmp(state, _RAISE));
}
#endif