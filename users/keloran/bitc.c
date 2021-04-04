#include "bitc.h"
#include "keloran.h"

#ifdef BIT_C
void set_bit_c_LED(uint8_t mode) {
    switch(mode) {
        case LED_ON:
            setPinOutput(PIN_LED);
            writePin(PIN_LED, GPIO_STATE_HIGH);
            break;

        case LED_DIM:
            setPinInput(PIN_LED);
            break;

        case LED_OFF:
            setPinOutput(PIN_LED);
            writePin(PIN_LED, GPIO_STATE_LOW);
            break;

        default:
            break;
    }
}

void keyboard_post_init_kb(void) {
    set_bit_c_LED(LED_OFF);
}

void bitc_led_state(uint8_t caps_state) {
    caps_state ? set_bit_c_LED(LED_ON) : set_bit_c_LED(LED_OFF);
}
#endif
