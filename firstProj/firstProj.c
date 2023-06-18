#include <avr/io.h>
#include <util/delay.h>

#define set_all_output(register) register = 0xff

int main(){
    // set_all_output(DDRB);
    DDRB = 1 << DDB5;
    PORTB = 0;
    while(1) {
        PORTB ^= 1 << PB5;
        _delay_ms(1000);
    }
}