#include "ping.h"

#define PING_PIN 12

void setup() {
    Serial.begin(9600);
}

void loop() {
    float distance_in = ping_in(PING_PIN);
    Serial.print("Distance: ");
    Serial.println(distance_in);
    delay(500);
}