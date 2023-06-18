#include <avr/io.h>
#include <util/delay.h>

#define TRIGGER_PIN PORTD3
#define ECHO_PIN PIND4
#define LED_PIN PORTB5

unsigned long measureDistance() {
    PORTD |= 1 << TRIGGER_PIN;
    _delay_us(10);
    PORTD &= ~(1 << TRIGGER_PIN);

    unsigned long pulseDuration = 0;
    while (!(PIND & (1 << ECHO_PIN))) {} // wait indefinitely until ECHO_PIN is 1
    while (PIND & (1 << ECHO_PIN)) {
        pulseDuration++;
        _delay_ms(1);
    } // pulseDuration is in miliseconds I think...

    unsigned long distance = (pulseDuration * 343) / 2; // miliseconds * m/s = mm

    distance *= 10; // cm

    return distance;
}

int main (){
    DDRD |= 1 << TRIGGER_PIN;
    DDRD &= ~(1 << ECHO_PIN); // clever way of setting one bit to 0
    DDRB = 1 << LED_PIN;

    PORTD |= 1 << ECHO_PIN; // enable pull-up resistor

    while (1) {
        unsigned long distance = measureDistance();
        if (distance < 1) {
            PORTB ^= 1 << LED_PIN;
        }
        for (uint16_t i=0; i<500; i++) _delay_ms(10);
    }


    // DDRB = 1 << DDB5;
    // PORTB = 0 << PORTB5;
    // DDRD = 1 << DDD4;

    // while (1) {
    //     _delay_ms(10000);
    //     PORTD ^= 1 << PORTD4;   // write 1 to ping sig
    //     uint8_t bitShifted = (PORTD >> PORTD4) & 0b1;   // 
    //     PORTB = bitShifted << PORTB5;
    // }
}