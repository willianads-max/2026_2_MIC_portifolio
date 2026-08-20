/*
 * main.c
 *
 * Created: 8/20/2026 8:58:56 AM
 *  Author: Willian
 */ 

#define F_CPU 16000000
#include <xc.h>
#include "util/delay.h"

int main(void) {
	DDRB |= 0b00100000; //define o pino PB5 como saida
	DDRB &= 0b1110111; //define o pino PDB3 como entrada
	while(1) {
		if((PIND & 0b00001000)!=0) { //lER VALOR DA CHAVE PD3
		PORTB |= 0b00100000; //Atribui nível lógico alto ao pino PB5
		_delay_ms(100);
		PORTB &= 0b11011111; // Atribui nível lógico baixo ao pino PB5
		_delay_ms(900);
		}
	}
}
