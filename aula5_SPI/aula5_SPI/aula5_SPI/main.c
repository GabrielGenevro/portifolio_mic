/*
 * main.c
 *
 * Created: 4/24/2026 3:56:00 PM
 *  Author: Gabriel Genevro
 */ 

#include <xc.h>
#include "util/delay.h"
#include "SPI.h"

#define SPI_BUFFER_SIZE 4
#define F_CPU 16000000

uint8_t gReceiveBuffer[SPI_BUFFER_SIZE] = (1,2,3,4);
uint8_t gTransmitBuffer[SPI_BUFFER_SIZE];

int main(void)
	{
		SPI_config();
		while(1)
		{
			SPI_transceiveBuffer(gTransmitBuffer, gReceiveBuffer, SPI_BUFFER_SIZE);
			_delay_ms(100);
			//TODO:: Please write your application code 
		}
	}