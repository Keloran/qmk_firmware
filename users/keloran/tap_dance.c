#include QMK_KEYBOARD_H

#include "tap_dance.h"
#include "keloran.h"

#ifdef TAP_DANCE_ENABLE
static tap xtap_state = {
    .is_pressed = true,
    .state = 0,
};

// Tilers
void tile_main(void) {
    switch (myOperatingSys) {
        case _WindowsOS:
            tap_code16(G(KC_UP));
            break;

        case _macOS:
        default:
            register_code(KC_LALT);
            tap_code16(S(KC_ENTER));
            unregister_code(KC_LALT);
            break;
    }
}
void tile_layout(void) {
    switch (myOperatingSys) {
        case _WindowsOS:
            tap_code16(G(KC_RIGHT));
            break;

        case _macOS:
        default:
            register_code(KC_LALT);
            tap_code16(S(KC_SPACE));
            unregister_code(KC_LALT);
            break;
    }
}
void restart_tiler(void) {
    switch (myOperatingSys) {
        case _macOS:
        default:
            register_code(KC_LCTL);
            register_code(KC_LGUI);
            tap_code16(S(KC_Z));
            unregister_code(KC_LGUI);
            unregister_code(KC_LCTL);
            break;
    }
}

// TapDance
qk_tap_dance_action_t tap_dance_actions[] = {
    [MISC_TAP]      = ACTION_TAP_DANCE_FN_ADVANCED(NULL, key_finished, key_reset)
};

uint8_t tap_dance(qk_tap_dance_state_t *state) {
    switch (state->count) {
        case MONUPLE_PRESS:
            return MONUPLE_PRESS;
        case COUPLE_PRESS:
            return COUPLE_PRESS;
        case TRIPLE_PRESS:
            return TRIPLE_PRESS;
        case QUADRUPLE_PRESS:
            return QUADRUPLE_PRESS;
        case QUINTUPLE_PRESS:
            return QUINTUPLE_PRESS;
        case SEXTUPLE_PRESS:
            return SEXTUPLE_PRESS;
        case SEPTUPLE_PRESS:
            return SEPTUPLE_PRESS;
        case OCTUPLE_PRESS:
            return OCTUPLE_PRESS;
        case NONUPLE_PRESS:
            return NONUPLE_PRESS;
        case DECUPLE_PRESS:
            return DECUPLE_PRESS;
        default:
            return NONGENTUPLE_PRESS;
    }
}

void key_finished(qk_tap_dance_state_t *state, void *user_data) {
    xtap_state.state = tap_dance(state);

    switch (xtap_state.state) {
        case MONUPLE_PRESS:
            break;
        case COUPLE_PRESS:
            return tile_main();
        case TRIPLE_PRESS:
            return tile_layout();
        case QUADRUPLE_PRESS:
            set_layer(_FKEYS);
            return;
    }
}

void key_reset(qk_tap_dance_state_t *state, void *user_data) {
    switch (xtap_state.state) {
    }
}
#endif