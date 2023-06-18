#include <avr/io.h>
#include <util/delay.h>

#define TRIGGER_PIN PORTD3
#define ECHO_PIN PIND4
#define LED_PIN PORTB5

void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);

  DDRD |= 1 << TRIGGER_PIN;
  DDRD &= ~(1 << ECHO_PIN); // clever way of setting one bit to 0
  DDRB = 1 << LED_PIN;

  PORTD |= 1 << ECHO_PIN; // enable pull-up resistor
}

void loop() {
  unsigned long distance = measureDistance();
  if (distance < 1) {
    PORTB ^= 1 << LED_PIN;
  }
  delay(1000);
}

unsigned long measureDistance() {
    PORTD |= 1 << TRIGGER_PIN;
    _delay_us(10);
    PORTD &= ~(1 << TRIGGER_PIN);

    unsigned long pulseDuration = 0;
    Serial.print(PIND&(1<<ECHO_PIN));
    while (!(PIND & (1 << ECHO_PIN))) {} // wait indefinitely until ECHO_PIN is 1
    while (PIND & (1 << ECHO_PIN)) {
        pulseDuration++;
        _delay_us(1);
    } // pulseDuration is in miliseconds I think...

    Serial.print(pulseDuration);
    Serial.print(" miliseconds.\n");

    unsigned long distance = (pulseDuration * 343) / 2; // miliseconds * m/s = mm

    distance *= 10; // cm

    return distance;
}
