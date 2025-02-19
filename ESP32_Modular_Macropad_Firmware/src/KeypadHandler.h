// KeypadHandler.h
#ifndef KEYPAD_HANDLER_H
#define KEYPAD_HANDLER_H

#include <Keypad.h>

// Keypad dimensions
#define ROWS 5
#define COLS 5

// Pin definitions for keypad
const uint8_t ROW_PINS[ROWS] = {3, 5, 26, 47, 33};  // Row0-4
const uint8_t COL_PINS[COLS] = {34, 21, 13, 6, 12}; // Col0-4

// Function declarations
void initializeKeypad();
char getKey();
extern Keypad keypad;

#endif