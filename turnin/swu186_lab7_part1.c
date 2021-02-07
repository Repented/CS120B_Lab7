/*	Author: lab
 *  Partner(s) Name: 
 *	Lab Section:
 *	Assignment: Lab #7  Exercise #1
 *	Exercise Description: [optional - include for your own benefit]
 *
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 * 
 * Demo Link: <YouTubeLink>
 */
#include <avr/io.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif

unsigned short myShort = 0x00;
unsigned char lower_eight_B = 0x00;
unsigned char upper_two_D = 0x00;

void ADC_init() {
	ADCSRA |= (1 << ADEN) | (1 << ADSC) | (1 << ADATE);
}

int main(void) {
    /* Insert DDR and PORT initializations */
DDRA = 0x00; PORTA = 0xFF;
DDRB = 0xFF; PORTB = 0x00;
DDRD = 0xFF; PORTD = 0x00;
    /* Insert your solution below */
	ADC_init();
    while (1) {
    	myShort = ADC;
    	lower_eight_B = (char) myShort;
    	upper_two_D = (char) (myShort >> 8);
    	PORTB = lower_eight_B;
    	PORTD = upper_two_D;
    }
    return 1;
}