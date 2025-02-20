// KeyHandler.h
#ifndef KEY_HANDLER_H
#define KEY_HANDLER_H

#include <Keypad.h>

class KeyHandler {
private:
    Keypad* keypad;
    uint8_t numRows;
    uint8_t numCols;
    char** keyMap;
    uint8_t* rowPins;
    uint8_t* colPins;

public:
    // Constructor that takes all matrix parameters
    KeyHandler(uint8_t rows, uint8_t cols, char** keyMapping, 
               uint8_t* rows_pins, uint8_t* cols_pins);
    
    // Destructor to clean up dynamic memory
    ~KeyHandler();
    
    // Initialize the key matrix
    void begin();
    
    // Get the current pressed key
    char getKey();
    
    // Check if specific key is pressed without consuming the event
    bool isKeyPressed(char key);
    
    // Get number of rows
    uint8_t getRows() { return numRows; }
    
    // Get number of columns
    uint8_t getCols() { return numCols; }
    
    // Get total number of keys
    uint8_t getTotalKeys();
    
    // Get raw keypad object if needed
    Keypad* getRawKeypad() { return keypad; }
};

#endif // KEY_HANDLER_H
