/*
 * Static test: drives nibble = 1111, BLANK_N = HIGH (not blanked),
 * DP = HIGH, and holds it there forever. No timing involved — useful
 * for probing each pin with a multimeter at leisure, or confirming
 * what the display shows for a known, unchanging input.
 *
 * Wiring (same as main.c):
 *   PD2 -> nibble bit0 (LSB)
 *   PD3 -> nibble bit1
 *   PD4 -> nibble bit2
 *   PD5 -> nibble bit3 (MSB)
 *   PD6 -> BLANK_N
 *   PD7 -> DP
 */

#include <avr/io.h>

int main(void) {
    DDRD |= (1 << PD2) | (1 << PD3) | (1 << PD4) | (1 << PD5) |
            (1 << PD6) | (1 << PD7);

    PORTD |= (1 << PD2) | (1 << PD3) | (1 << PD4) | (1 << PD5) |
             (1 << PD6) | (1 << PD7);

    while (1) {
        // hold forever
    }
}
