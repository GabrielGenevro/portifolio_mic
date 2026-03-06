/*
 * main.c
 *
 * Created: 2/27/2026 1:53:10 PM
 *  Author: Gabriel Genevro
 */ 
#define F_CPU 16000000
#include <xc.h>
#include "util/delay.h"
/* O que este c?digo faz:
	* Pisca um led ligado ao pino PC2 enquanto a chave
	* ligada ao pino PD3 estiver pressionada
*/
 
/*
 #define BIT3MASK 0b00001000 // ou BIT3MASK (1<<3) 
 //foi substituido por (1<<PORTD3) na linha 26
*/

int main(void)
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