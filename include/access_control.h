#ifndef ACCESS_CONTROL_H
#define ACCESS_CONTROL_H

typedef enum
{
    STATE_LOCKED,
    STATE_UNLOCKED,
    STATE_ALARM
} AccessState;

void AccessControl_init(void);
void AccessControl_handleButtonPress(void);
AccessState AccessControl_getState(void);

#endif
