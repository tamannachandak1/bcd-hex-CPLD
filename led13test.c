/*
 * Fast blink sanity check: toggles onboard LED (pin 13 / PB5) every
 * ~250ms. If this looks solid too, the chip isn't executing the loop
 * at all (or PB5 isn't the right pin on this board) rather than just
 * running on an unexpectedly slow clock.
 */

#ifndef F_CPU
#define F_CPU 16000000UL
#endif

#include <avr/io.h>
#include <util/delay.h>

int main(void) {
    DDRB |= (1 << PB5);

    while (1) {
        PORTB ^= (1 << PB5);
        _delay_ms(250);
    }
}
