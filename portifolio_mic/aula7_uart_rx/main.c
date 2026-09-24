/*
 * main.c
 *
 * Created: 9/24/2026 10:20:41 AM
 *  Author: Willian
 */ 
#define F_CPU 16000000
#include <stdio.h>
#include <stdlib.h>
#include <xc.h>
#include "util/delay.h"


/**
 * Configuração do módulo USART0 para modo assíncrono, frame de 8 bits, paridade par, BAUD de 9600
 */

void UART_config_RX(uint16_t pBAUD) {
    UCSR0A = (0<<U2X0);                           //Modo double speed
    UCSR0B = (1<<RXEN0)|(0<<TXEN0)|(0<<UCSZ02);   //Habilita o transmissor UART0, frame de 8 bits
    UCSR0C = (0<<UMSEL01)|(0<<UMSEL00)       //Modo assíncrono
            |(1<<UPM01)|(0<<UPM00)         //Habilita paridade par
            |(0<<USBS0)                    //1 bit de stop
            |(1<<UCSZ01)|(1<<UCSZ00)       //frame de 8bits
            |(0<<UCPOL0);                 //Polaridade do clock
    UBRR0 = (16000000 / pBAUD) - 1;      //TABELA 19.1
}

void GPIO_config(){
	DDRC = (1<<DDC0)|(1<<DDC1);
}

int main(void) {
    GPIO_config();
	UART_config_RX(9600);
    while(1) {
        while((UCSR0A & (1<<RXC0) == 0)); //Semafaro na flag de recebimento da UART
		uint8_t tReceivedByte = UDR0;
		if(tReceivedByte == 'M') {
			PORTC |= (1<<PORTC0); //led verde
    } else {
		PORTC |= (1<<PORTC1); //led vermelho
	}
	_delay_ms(1);
	PORTC = 0; //apaga todos os leds
	}
}