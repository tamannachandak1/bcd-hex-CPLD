/*
 * Sanity-check firmware: toggles PD2 high/low every 5 seconds.
 * No nibble logic, no BLANK_N/DP — just confirms the chip is running
 * and _delay_ms() timing is correct before debugging the CPLD side.
 *
 * Probe PD2 (Arduino D2) with a multimeter or LED+resistor to GND.
 * You should see it flip roughly every 5 seconds.
 */

#ifndef F_CPU
#define F_CPU 16000000UL
#endif

#include <avr/io.h>
#include <util/delay.h>

static void delay_ms_long(uint32_t ms) {
    while (ms >= 10) {
        _delay_ms(10);
        ms -= 10;
    }
    while (ms > 0) {
        _delay_ms(1);
        ms -= 1;
    }
}

int main(void) {
    DDRD |= (1 << PD2);

    while (1) {
        PORTD ^= (1 << PD2);
        delay_ms_long(5000);
    }
}
