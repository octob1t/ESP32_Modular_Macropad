// KeyHandler.cpp
#include "KeyHandler.h"

KeyHandler::KeyHandler(uint8_t rows, uint8_t cols, char** keyMapping, 
                      uint8_t* rows_pins, uint8_t* cols_pins) {
    numRows = rows;
    numCols = cols;
    
    // Allocate memory for keyMap
    keyMap = new char*[rows];
    for(uint8_t i = 0; i < rows; i++) {
        keyMap[i] = new char[cols];
        for(uint8_t j = 0; j < cols; j++) {
            keyMap[i][j] = keyMapping[i][j];
        }
    }
    
    // Allocate and copy pin arrays
    rowPins = new uint8_t[rows];
    colPins = new uint8_t[cols];
    memcpy(rowPins, rows_pins, rows * sizeof(uint8_t));
    memcpy(colPins, cols_pins, cols * sizeof(uint8_t));
    
    // Create keypad instance
    keypad = new Keypad(makeKeymap((char*)keyMap), rowPins, colPins, rows, cols);
}

KeyHandler::~KeyHandler() {
    // Clean up dynamic memory
    for(uint8_t i = 0; i < numRows; i++) {
        delete[] keyMap[i];
    }
    delete[] keyMap;
    delete[] rowPins;
    delete[] colPins;
    delete keypad;
}

void KeyHandler::begin() {
    // Any additional initialization can go here
}

char KeyHandler::getKey() {
    char key = keypad->getKey();
    // Don't return 'X' keys
    return (key == 'X') ? NO_KEY : key;
}

bool KeyHandler::isKeyPressed(char key) {
    // Check if specific key is currently pressed
    for(uint8_t r = 0; r < numRows; r++) {
        for(uint8_t c = 0; c < numCols; c++) {
            if(keyMap[r][c] == key && keypad->isPressed(key)) {
                return true;
            }
        }
    }
    return false;
}

uint8_t KeyHandler::getTotalKeys() {
    uint8_t count = 0;
    for(uint8_t r = 0; r < numRows; r++) {
        for(uint8_t c = 0; c < numCols; c++) {
            if(keyMap[r][c] != 'X') { // 'X' represents no key
                count++;
            }
        }
    }
    return count;
}