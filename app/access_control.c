#include "access_control.h"
#include "gpio.h"

static AccessState currentState = STATE_LOCKED;

static void AccessControl_updateOutputs(void)
{
    switch (currentState)
    {
        case STATE_LOCKED:

            GPIO_redLEDOn();
            GPIO_greenLEDOff();

            break;

        case STATE_UNLOCKED:

            GPIO_redLEDOff();
            GPIO_greenLEDOn();

            break;

        case STATE_ALARM:

            GPIO_redLEDOn();
            GPIO_greenLEDOn();

            break;

        default:

            break;
    }
}

void AccessControl_init(void)
{
    currentState = STATE_LOCKED;

    AccessControl_updateOutputs();
}

void AccessControl_handleButtonPress(void)
{
    switch (currentState)
    {
        case STATE_LOCKED:

            currentState = STATE_UNLOCKED;

            break;

        case STATE_UNLOCKED:

            currentState = STATE_LOCKED;

            break;

        case STATE_ALARM:

            break;

        default:

            break;
    }

    AccessControl_updateOutputs();
}

AccessState AccessControl_getState(void)
{
    return currentState;
}
