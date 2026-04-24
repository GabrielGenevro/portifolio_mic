/*
 * CFile1.c
 *
 * Created: 24/04/2026 15:56:38
 *  Author: Gabriel Genevro
 */ 

#include <xc.h>

void SPI_config ()
	{
		DDRB |= (1<<DDB3) | (1<<DDB5);
		SPCR = (0<<SPIE) | (1<<SPE)		//Desabilita interrupção, habilita SPI
			 | (0<<DORD) | (1<<MSTR)	//Ordem: MSB primeiro, Modo Mestre
			 | (0<<CPOL) | (0<<CPHA)	//SPI modo 0
			 | (0<<SPR1) | (1<<SPR0); 	//Divisor 16, freq= 1MHz
		SPSR - (0<<SPI2X);
	}

uint8_t SPI_transceiveByte(uint8_t pTransmittedByte)
	{
		uint8_t rReceivedByte;
		SPDR = 0x0A; //inicia uma transmissão
		while ((SPSR & (1<<SPIF)) == 0); //poll do SPIF: bloqueia execução enquanto SPIF for igual a zero		
		rReceivedByte = SPDR;
		return rReceivedByte;
	}

void SPI_transceiveBuffer(	uint8_t *pTransmitBuffer,
							uint8_t *pReceiveBuffer,
							uint16_t pSize)
	{
		uint8_t *tTransmitPtr = pTransmitBuffer;
		uint8_t *tReceivePtr = pReceiveBuffer;
		uint16_t tCounter;
		for(tCounter=0; tCounter<pSize;tCounter++)
			{
				*tReceivePtr = SPI_transceiveByte(*tTransmitPtr);
				tReceivePtr++;
				tTransmitPtr++;
			}
	}