/*
 * gpio.c
 *
 * Created: 27/02/2026 14:15:19
 *  Author: Gabriel Genevro
 */ 

#define F_CPU 16000000
#include "gpio.h"
#include <xc.h>
#include "util/delay.h"

void GPIO_initialize()
	{
		DDRB = (1<<DDB0); //configura o pino PB0 como sa�da
	}

void GPIO_blinked()
	{
		PORTB |= (1<< PORTB0); //aciona o pino PB0
		_delay_ms(300);
		PORTB &= ~(1<< PORTB0); //desaciona o pino PB0
		_delay_ms(700);
	}