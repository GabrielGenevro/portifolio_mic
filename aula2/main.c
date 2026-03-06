/*
 * main.c
 *
 * Created: 2/27/2026 1:53:10 PM
 *  Author: Gabriel Genevro
 */ 
#define F_CPU 16000000
#include <xc.h>
#include "util/delay.h"
 
/*
 #define BIT3MASK 0b00001000 // ou BIT3MASK (1<<3) 
 //foi substituido por (1<<PORTD3) na linha 26
*/
/**
*	@brief Pisca um led ligado ao pino PC2 enquanto a chave
*	ligada ao pino PD3 estiver pressionado
*/

void atividade()
	{
		DDRC |= (1<<DDC2); //ligar o pino PC2 como sa?da
		DDRD &= (1<<DDD3); //Configura pino PD3 como entrada
		while(1)
			{
				if((PIND & (1<<PORTD3)) != 0)// Ler o valor da chave (PD3)
					{
						//Chave pressionada
						PORTC |= (1<<PORTC2); //acende led
						_delay_ms(300);
						PORTC &= ~(1<<PORTC2); //apaga led
						_delay_ms(700);
					}
				else
					{
						//Chave aberta
						PORTC &= ~(1<<PORTC2); //apaga led
					}
			}
	}

/**
* @brief Controla 6 leds (PB0 a PB5) em uma lógica de "pinheirinho de natal"
*
*/
void atividade2()
	{
		DDRD &= (1<<DDD3); //Configura pino PD3 como entrada
		//Configurar pinos pb0 a pb5 como saída
		DDRB |= (1<<DDB0) | (1<<DDB1) | (1<<DDB2) | (1<<DDB3) | (1<<DDB4) | (1<<DDB5);
		uint8_t tState = 1; //Guarda estado de adcionamento dos LEDs
		while(1)
			{
				tState = tState <<1;
				if(tState == 0b01000000)
					{
						tState = 1;
					}
				if((PIND & (1<<PORTD3)) != 0)// Ler o valor da chave (PD3)
					{
						//Chave pressionada
						PORTB = tState;
					}
				else
					{
						//Chave aberta
						PORTB = 0;
					}
				_delay_ms(200);
			}
	}	

int main(void)
	{
		atividade2();
	}