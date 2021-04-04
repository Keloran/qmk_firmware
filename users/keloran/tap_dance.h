#pragma once

#ifdef TAP_DANCE_ENABLE
enum tapKeys {
    MISC_TAP = 0
};
typedef struct {
    bool is_pressed;
    uint8_t state;
} tap;
enum tapPresses {
    MONUPLE_PRESS    = 1,
    COUPLE_PRESS,
    TRIPLE_PRESS,
    QUADRUPLE_PRESS,
    QUINTUPLE_PRESS,
    SEXTUPLE_PRESS,
    SEPTUPLE_PRESS,
    OCTUPLE_PRESS,
    NONUPLE_PRESS,
    DECUPLE_PRESS,

    NONGENTUPLE_PRESS    = 90,
};
void tile_main(void);
void tile_layout(void);
void restart_tiler(void);

// Tilers
void tile_main(void);
void tile_layout(void);
void restart_tiler(void);

// TapDance
uint8_t tap_dance(qk_tap_dance_state_t *state);
void key_finished(qk_tap_dance_state_t *state, void *user_data);
void key_reset(qk_tap_dance_state_t *state, void *user_data);
#endif