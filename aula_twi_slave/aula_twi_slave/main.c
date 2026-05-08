/*
 * main.c
 *
 * Created: 5/8/2026 4:00:57 PM
 *  Author: Aluno
 */ 

#define F_CPU 16000000
#include <xc.h>
#include "util/delay.h"
#include "avr/interrupt.h"

uint8_t gTWIData = 5;

ISR(INT_vect)
	{
		uint8_t tState = (TWSR & 0b11111000);
        switch (tState)
            {
                case 0x60: //Slave receiver
					{
						gTWIData = TWDR;
						TWCR = (1<<TWINT)|(1<<TWEA)|(1<<TWEN);
					}break;
				case 0xA8: //Slave transmitter
					{
						TWDR = gTWIData;
						TWCR = (1<<TWINT)|(1<<TWEN);
					}break;
				default:
					{
						TWCR = (1<<TWINT)|(1<<TWEN);
					}break;
            }
	}

void TWI_slave_config()
	{
		//DDRC = (1<<DDC4) | (1<<DDC5);
		TWSR = (0<<TWPS1)| (0<<TWPS0);	//Prescaler=1
		TWBR = 12;	//bit rate 400 kHz
        TWAR = (0x55<<1);
		TWCR = (1<<TWEN)|(1<<TWIE);
		sei();
		
	}
	
int main(void)
{
	TWI_slave_config();
	_delay_ms(1000);
    while(1)
		{
			
		}
	
}