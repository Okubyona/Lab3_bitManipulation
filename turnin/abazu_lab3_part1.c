/*	Author: Andrew Bazua [abazu001]
 *  Partner(s) Name:
 *	Lab Section: 024
 *	Assignment: Lab #03  Exercise #1
 *	Exercise Description: [optional - include for your own benefit]
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
    DDRB = 0x00; PORTB = 0xFF;  // Sets PORTB as input PINB
    DDRC = 0xFF; PORTC = 0x00;  // Sets PORTC as output

    unsigned char tmpA = 0x00;
    unsigned char tmpB = 0x00;
    unsigned char cnt  = 0x00;

    /* Insert your solution below */
    while (1) {
        tmpA = PINA;
        tmpB = PINB;

        for (unsigned char i = 0; i < 8; ++i) {
            if (tmpA % 2 == 1) { ++cnt; }
            if (tmpB % 2 == 1) { ++cnt; }
            tmpA = tmpA >> 1;
            tmpB = tmpB >> 1;
        }

        PORTC = cnt;
        cnt = 0x00;

    }
    return 1;
}
