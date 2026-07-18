#include "gpio.h"
#include <msp430.h>

#define RED_LED_PIN       BIT0
#define RED_LED_DIR       P1DIR
#define RED_LED_OUT       P1OUT

void GPIO_init(void)
{
    RED_LED_OUT &= ~RED_LED_PIN; // initially LED is turned off
    RED_LED_DIR |= RED_LED_PIN;
    PM5CTL0 &= ~LOCKLPM5; // clear the default high-impedance state
}

void LED_red_on(void)
{
    RED_LED_OUT |= RED_LED_PIN;
}

void LED_red_off(void)
{
    RED_LED_OUT &= ~RED_LED_PIN;

}

void LED_red_toggle(void)
{
    RED_LED_OUT ^= RED_LED_PIN;
}
