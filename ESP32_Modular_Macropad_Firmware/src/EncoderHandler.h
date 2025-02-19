// EncoderHandler.h
#ifndef ENCODER_HANDLER_H
#define ENCODER_HANDLER_H

#include <Encoder.h>

// Pin definitions for rotary encoder
#define ENCODER_PIN_A 2  // RotaryA
#define ENCODER_PIN_B 4  // RotaryB

// Function declarations
void initializeEncoder();
long getEncoderPosition();
void handleEncoderMovement();
extern Encoder encoder;

#endif // ENCODER_HANDLER_H