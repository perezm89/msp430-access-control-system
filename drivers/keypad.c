#include "keypad.h"
#include <msp430.h>
#define KEYPAD_R1      BIT4
#define KEYPAD_R2      BIT5
#define KEYPAD_R3      BIT6
#define KEYPAD_R4      BIT7

#define KEYPAD_C1      BIT0
#define KEYPAD_C2      BIT1
#define KEYPAD_C3      BIT2
#define KEYPAD_C4      BIT3

#define NUM_COLS  4
#define NUM_ROWS  4

#define KEYPAD_ROWS    (KEYPAD_R1 | KEYPAD_R2 | KEYPAD_R3 | KEYPAD_R4)
#define KEYPAD_COLS    (KEYPAD_C1 | KEYPAD_C2 | KEYPAD_C3 | KEYPAD_C4)

const uint8_t COL_MASKS[NUM_COLS] = { KEYPAD_C1, KEYPAD_C2, KEYPAD_C3, KEYPAD_C4 };

const char keypad_map[NUM_ROWS][NUM_COLS] = {
    {'1', '2', '3', 'A'},
    {'4', '5', '6', 'B'},
    {'7', '8', '9', 'C'},
    {'*', '0', '#', 'D'}
};

void KEYPAD_init(void)
{
    P8DIR &= ~KEYPAD_ROWS; // input selected
    P8REN |= KEYPAD_ROWS; // resistor enabled
    P8OUT |= KEYPAD_ROWS; // pull-up selected

    // Columns: input, no pull resistor = Hi-Z
    P9DIR &= ~KEYPAD_COLS;
    P9REN &= ~KEYPAD_COLS;
}

char KEYPAD_getKey(void)
{
    char pressed_char = '\0'; // Variable to hold our result

    for(int col = 0; col < NUM_COLS; col++ )
    {
        // Start with all columns Hi-Z
        P9DIR &= ~KEYPAD_COLS;

        // Prepare selected column LOW
        P9OUT &= ~COL_MASKS[col];

        // Enable selected column as output
        P9DIR |= COL_MASKS[col];

        switch ((~P8IN) & KEYPAD_ROWS)
        {
           case KEYPAD_R1:
               pressed_char = keypad_map[0][col];
               break;

           case KEYPAD_R2:
               pressed_char = keypad_map[1][col];
               break;

           case KEYPAD_R3:
               pressed_char = keypad_map[2][col];
               break;

           case KEYPAD_R4:
               pressed_char = keypad_map[3][col];
               break;

           default:
               pressed_char = '\0';
               break;
        }

        if (pressed_char != '\0') {
                break; // Exits the for loop
            }
    }

    // reset all columns to Hi-Z
    P9DIR &= ~KEYPAD_COLS;

    return pressed_char;
}
