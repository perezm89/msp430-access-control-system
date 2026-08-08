#ifndef GPIO_H
#define GPIO_H

#include <stdbool.h>

void GPIO_init(void);
void GPIO_redLEDOn(void);
void GPIO_redLEDOff(void);
bool GPIO_buttonPressed(void);
void GPIO_redLEDToggle(void);
void GPIO_greenLEDOn(void);
void GPIO_greenLEDOff(void);

#endif
