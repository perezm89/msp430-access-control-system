#include <msp430.h>
#include "timer.h"

#define DEBOUNCE_TICKS 818 // 32,768 * 0.025 = 819 - 1 counts

void TIMER_init(void)
{
    TA0CCTL0 |= CCIE;             // Enable CCR0 interrupt
    TA0CCR0 = DEBOUNCE_TICKS;    // About 25 ms with 32.768 kHz ACLK

    TA0CTL = TASSEL__ACLK | MC__STOP | TACLR;
}

void TIMER_start(void)
{
    TA0CTL = TASSEL__ACLK | MC__UP | TACLR;
}

void TIMER_stop(void)
{
    TA0CTL = TASSEL__ACLK | MC__STOP | TACLR;
}
