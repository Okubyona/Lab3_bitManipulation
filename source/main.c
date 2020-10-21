/*	Author: Andrew Bazua [abazu001]
 *  Partner(s) Name:
 *	Lab Section: 024
 *	Assignment: Lab #03  Exercise #4
 *	Exercise Description: [ Read an 8-bit value on PA7..PA0 and write that
        value on PB3..PB0PC7..PC4. That is to say,  take the upper nibble of PINA
        and map it to the lower nibble of PORTB, likewise take the lower nibble of
        PINA and map it to the upper nibble of PORTC (PA7 -> PB3, PA6 -> PB2, … PA1
        -> PC5, PA0 -> PC4) ]
 *
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 */
#include <avr/io.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif

int main(void) {
    /* Insert DDR and PORT initializations */
    DDRA = 0x00; PORTA = 0xFF;  // Sets PORTA as input PINA
    DDRB = 0xFF; PORTB = 0x00;  // Sets PORTB as output
    DDRC = 0xFF; PORTC = 0x00;  // Sets PORTC as output

    unsigned char tmpA = 0x00;
    unsigned char tmpB = 0x00;
    unsigned char tmpC = 0x00;

    while (1) {
        tmpA = (PINA & 0xF0) >> 4;  // Shifts upper nibble to lower nibble
        tmpB = tmpA;                // Assigns PINA's upper nibble to tmpB
                                    // --> PORTB's lower nibble

        tmpA = (PINA & 0x0F) << 4;  // Shifts lower nibble to upper nibble
        tmpC = tmpA;                // Assigns PINA's lower nibble to tmpC
                                    // --> PORTC's upper nibble

        PORTB = tmpB;
        PORTC = tmpC;

    }
    return 1;
}
