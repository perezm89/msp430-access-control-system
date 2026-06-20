# MSP430 Access Control System Architecture

## Overview

The MSP430 Access Control System is an embedded application that authenticates user PIN entries and controls access through a state-machine architecture.

The system provides visual feedback through LEDs, user feedback through a display, and event logging through UART communication.

## System States

- LOCKED
- UNLOCKED
- DENIED
- ALARM
- ADMIN

## Authentication Workflow

1. User enters PIN.
2. System validates entered PIN against stored credential.
3. If valid:
   - Transition to UNLOCKED state.
   - Turn on green LED.
   - Start auto-lock timer.
4. If invalid:
   - Increment failed-attempt counter.
   - Turn on red LED.
5. After three consecutive failures:
   - Transition to ALARM state.
   - Disable authentication for lockout period.

## Hardware Components

- MSP430FR6989 LaunchPad
- Keypad (future)
- LCD/OLED Display (future)
- Green Status LED
- Red Status LED
- Pushbuttons (initial prototype)

## Future Enhancements

- ESP32 communication module using UART
- Web-based administrative dashboard
- Access event history and logging
- Remote system configuration
- Custom PCB implementation