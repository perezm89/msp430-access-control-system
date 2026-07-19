#include <msp430.h>
#include "gpio.h"

int main(void)
{
    WDTCTL = WDTPW | WDTHOLD;

    GPIO_init();

    while (1)
    {
        if (GPIO_buttonPressed())
        {
            GPIO_redLEDOn();
        }
        else
        {
            GPIO_redLEDOff();
        }
    }
}
