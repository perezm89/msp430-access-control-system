#include <msp430.h>
#include "gpio.h"
#include "timer.h"
#include "access_control.h"

int main(void)
{
    WDTCTL = WDTPW | WDTHOLD;

    GPIO_init();
    TIMER_init();
    AccessControl_init();

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
        P1IE &= ~BIT1;      // Temporarily disable button interrupt

        TIMER_start();      // Start debounce timer

        P1IFG &= ~BIT1;     // Clear button interrupt flag
    }
}

#pragma vector=TIMER0_A0_VECTOR
__interrupt void Timer_A0_ISR(void)
{
    TIMER_stop();

    if (GPIO_buttonPressed())
    {
        AccessControl_handleButtonPress();
    }

    P1IFG &= ~BIT1;
    P1IE |= BIT1;
}
