#include "gpio.h"
#include <msp430.h>

#define RED_LED_PIN    BIT0
#define RED_LED_DIR    P1DIR
#define RED_LED_OUT    P1OUT
#define BUTTON1_PIN    BIT1
#define BUTTON1_DIR    P1DIR
#define BUTTON1_IN     P1IN
#define BUTTON1_REN    P1REN
#define BUTTON1_OUT    P1OUT

void GPIO_init(void)
{
    RED_LED_OUT &= ~RED_LED_PIN; // initially LED is turned off
    RED_LED_DIR |= RED_LED_PIN;
    PM5CTL0 &= ~LOCKLPM5; // clear the default high-impedance state

    BUTTON1_DIR &= ~BUTTON1_PIN;
    BUTTON1_REN |= BUTTON1_PIN;
    BUTTON1_OUT |= BUTTON1_PIN;
}

void GPIO_redLEDOn(void)
{
    RED_LED_OUT |= RED_LED_PIN;
}

void GPIO_redLEDOff(void)
{
    RED_LED_OUT &= ~RED_LED_PIN;

}

bool GPIO_buttonPressed(void)
{
    return (BUTTON1_IN & BUTTON1_PIN) == 0;
}
