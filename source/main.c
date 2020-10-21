/*	Author: Andrew Bazua [abazu001]
 *  Partner(s) Name:
 *	Lab Section: 024
 *	Assignment: Lab #03  Exercise #3
 *	Exercise Description: [ In addition to the above, PA4 is 1 if a key is in
        the ignition, PA5 is one if a driver is seated, and PA6 is 1 if the driver's
        seatbelt is fastened. PC7 should light a "Fasten seatbelt" icon if a key
        is in the ignition, the driver is seated, but the belt is not fastened. ]
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
    DDRC = 0xFF; PORTC = 0x00;  // Sets PORTC as output

    unsigned char tmpA = 0x00;
    unsigned char tmpB = 0x00;  // Temp Variable that stores P4 P5 & P6
    unsigned char tmpC = 0x00;

    /* Insert your solution below */
    while (1) {
        tmpA = PINA;
        tmpB = PINA & 0x70;     // Masks allows P4 P5 & P6 through
        tmpA = PINA & 0x8F;     // Masks P4-P6

        if (tmpA == 0x00) { tmpC = 0x40; }

        else if (tmpA <= 0x02) { tmpC = 0x60; }

        else if (tmpA <= 0x04) { tmpC = 0x70; }

        else if (tmpA <= 0x06) { tmpC = 0x38; }

        else if (tmpA <= 0x09) { tmpC = 0x3C; }

        else if (tmpA <= 0x0C) { tmpC = 0x03E; }

        else { tmpC = 0x3F; }

        if (tmpB == 0x30) { //Check for seated driver and key in ignition
            tmpC = tmpC | 0x80; //Activates P7 for 'Fasten Seatbelt' light
        }

        PORTC = tmpC;

    }
    return 1;
}
