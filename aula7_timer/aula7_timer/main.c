/*
 * main.c
 *
 * Created: 5/15/2026 2:49:46 PM
 *  Author: Gabriel Genevro
 */ 

#define F_CPU 8000000
#include <xc.h>
#include "avr/interrupt.h"

ISR(TIMER0_OVF_vect)
	{
		PORTB ^= (1<<PORTB0); //alterna PB0
		
	}

int main(void)
	{
		TCCR0A = (1<<WGM00) | (1<<WGM01); //Modo CTC
		TCCR0B = (0<<WGM02) | (0<<CS02) | (1<<CS01) | (0<<CS00); //Prescaler de 8
		OCR0A = 249; //contagem até 250 us (Assumindo clk do timer é 1MHz)
		TIMSK0 = (1<<TOIE0); //Habilita interrupção de overflow do timer 0
		sei();
		while(1)
			{
				//TODO:: Please write your application code 
			}
	}