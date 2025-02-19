// EncoderHandler.cpp
#include "EncoderHandler.h"

Encoder encoder(ENCODER_PIN_A, ENCODER_PIN_B);
long lastEncoderPosition = 0;

void initializeEncoder() {
    // Initialization if needed
}

long getEncoderPosition() {
    return encoder.read();
}

void handleEncoderMovement() {
    long newPosition = encoder.read();
    if (newPosition != lastEncoderPosition) {
        // Handle position change
        lastEncoderPosition = newPosition;
    }
}