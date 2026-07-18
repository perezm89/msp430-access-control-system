#include <msp430.h>
#include "gpio.h"

int main(void)
{
    WDTCTL = WDTPW | WDTHOLD;   // Stop the watchdog timer

    GPIO_init();

//    LED_red_on();
//    LED_red_off();
    LED_red_toggle();
    while (1)
    {

    }
}
