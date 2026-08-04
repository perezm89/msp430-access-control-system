#include <msp430.h>
#include "gpio.h"

int main(void)
{
    WDTCTL = WDTPW | WDTHOLD;

    GPIO_init();

    __enable_interrupt();

    while (1)
    {
        // Main program no longer polls the button.
    }
}

#pragma vector=PORT1_VECTOR

__interrupt void Port_1_ISR(void)
{
    if (P1IFG & BIT1)
    {
        GPIO_redLEDToggle();

        P1IFG &= ~BIT1;
    }
}
