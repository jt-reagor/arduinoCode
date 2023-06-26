// example of how to use PIR sensor

#include <Arduino.h>

#define PIR_PIN 12

void setup() {
    Serial.begin(9600);
    pinMode(PIR_PIN, INPUT); // do not use INPUT_PULLUP, always sets pin to high for some reason.
}

void loop() {
    while(digitalRead(PIR_PIN) == HIGH){
        Serial.println("Motion detected.");
        delay(1000);
    }
}