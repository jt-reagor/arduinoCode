#include "ping.h"

long ping_us(uint8_t pin)
{
    long t0, t1;
    pinMode(pin, OUTPUT);
    digitalWrite(pin, HIGH);
    delay(1);
    digitalWrite(pin, LOW);
    pinMode(pin, INPUT_PULLUP);
    while (!digitalRead(12))
    {
        ;
    }
    t0 = micros();
    while (digitalRead(12))
    {
        ;
    }
    t1 = micros();

    return (t1 - t0);
}

long ping_us_new(uint8_t pin)
{
    pinMode(pin, OUTPUT);
    digitalWrite(pin, HIGH);
    delay(1);
    digitalWrite(pin, LOW);
    pinMode(pin, INPUT_PULLUP);
    long us = pulseIn(pin, HIGH); // didn't know this existed...
    return us;
}

float ping_in(uint8_t pin)
{
    float us = ping_us_new(pin);
    float round_trip = (SOS_IN_PER_SEC * us) / (float)1000000;
    float one_way = round_trip / 2;
    return one_way;
}

float ping_cm(uint8_t pin)
{
    long us = ping_us_new(pin);
    float round_trip = (SOS_CM_PER_SEC * us) / 1000000;
    float one_way = round_trip / 2;
    return one_way;
}