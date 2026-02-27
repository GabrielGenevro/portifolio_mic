/*
 * main.c
 *
 * Created: 2/27/2026 1:53:10 PM
 *  Author: Gabriel Genevro
 */ 

#include <xc.h>
#include "gpio.h"
#include "usart.h"

int main(void)
{
	GPIO_initialize();
	USART_initialize();
    while(1)
    {
       GPIO_blinked();
	   USART_send();
    }
}