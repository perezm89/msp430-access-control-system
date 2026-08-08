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
#define BUTTON1_IE     P1IE
#define BUTTON1_IES    P1IES
#define BUTTON1_IFG    P1IFG
#define GREEN_LED_PIN  BIT7
#define GREEN_LED_DIR  P9DIR
#define GREEN_LED_OUT  P9OUT

void GPIO_init(void)
{
    RED_LED_OUT &= ~RED_LED_PIN; // initially LED is turned off
    RED_LED_DIR |= RED_LED_PIN;

    GREEN_LED_OUT &= ~GREEN_LED_PIN;   // Start green LED off
    GREEN_LED_DIR |= GREEN_LED_PIN;
    PM5CTL0 &= ~LOCKLPM5; // clear the default high-impedance state

    BUTTON1_DIR &= ~BUTTON1_PIN;
    BUTTON1_REN |= BUTTON1_PIN;
    BUTTON1_OUT |= BUTTON1_PIN;

    BUTTON1_IES |= BUTTON1_PIN;   // Trigger on HIGH-to-LOW edge
    BUTTON1_IFG &= ~BUTTON1_PIN;  // Clear any pending interrupt flag
    BUTTON1_IE  |= BUTTON1_PIN;   // Enable interrupt for the button
}

void GPIO_redLEDOn(void)
{
    RED_LED_OUT |= RED_LED_PIN;
}

void GPIO_redLEDOff(void)
{
    RED_LED_OUT &= ~RED_LED_PIN;

}

void GPIO_greenLEDOn(void)
{
    GREEN_LED_OUT |= GREEN_LED_PIN;
}

void GPIO_greenLEDOff(void)
{
    GREEN_LED_OUT &= ~GREEN_LED_PIN;
}

bool GPIO_buttonPressed(void)
{
    return (BUTTON1_IN & BUTTON1_PIN) == 0;
}

void GPIO_redLEDToggle(void)
{
    RED_LED_OUT ^= RED_LED_PIN;
}
