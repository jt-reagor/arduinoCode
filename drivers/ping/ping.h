#ifndef PING_H
#define PING_H

#include <Arduino.h>

#define SOS_CM_PER_SEC 34029.0
#define SOS_IN_PER_SEC 13503.0

float ping_in(uint8_t pin);
float ping_cm(uint8_t pin);
long ping_us(uint8_t pin);

#endif