#pragma once
#include "quantum.h"

#ifdef BIT_C
#define LED_ON          2
#define LED_DIM         1
#define LED_OFF         0
#define GPIO_STATE_LOW  0
#define GPIO_STATE_HIGH 1
#define PIN_LED         F0

void set_bit_c_LED(uint8_t mode);
void bitc_led_state(uint8_t caps_state);
#endif
