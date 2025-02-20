// KeypadHandler.cpp
#include "KeypadHandler.h"

// Modified keymap where 'X' represents no button
// Rows 0 and 1 only have buttons in the last two columns
const char keys[ROWS][COLS] = {
    {'X', 'X', 'X', '4', '5'},  // Row 0: only cols 3-4
    {'X', 'X', 'X', '9', '0'},  // Row 1: only cols 3-4
    {'A', 'B', 'C', 'D', 'E'},  // Row 2: all columns
    {'F', 'G', 'H', 'I', 'J'},  // Row 3: all columns
    {'K', 'L', 'M', 'N', 'O'}   // Row 4: all columns
};

char getKey() {
    char key = keypad.getKey();
    // Don't return 'X' keys
    return (key == 'X') ? NO_KEY : key;
}