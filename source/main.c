/*	Author: Andrew Bazua [abazu001]
 *  Partner(s) Name:
 *	Lab Section: 023
 *	Assignment: Lab #03  Exercise #5
 *	Exercise Description: [ A car's passenger-seat weight sensor outputs 
        a 9-bit value (ranging from 0 to 511) and connects to input 
        PD7..PD0PB0 on the microcontroller. If the weight is equal to or 
        above 70 pounds, the airbag should be enabled by setting PB1 to 1.
        If the weight is above 5 but below 70, the airbag should be disabled
        and an "Airbag disabled" icon should light by setting PB2 to 1. 
        (Neither B1 nor B2 should be set if the weight is 5 or less, as 
        there is no passenger). ]
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
