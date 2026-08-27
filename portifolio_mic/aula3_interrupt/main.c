/*
 * main.c
 *
 * Created: 8/27/2026 10:26:18 AM
 *  Author: Aluno
 */ 

#define F_CPU 16000000
#include <xc.h>
#include "avr/interrupt.h"
#include "util/delay.h"
//Configuração de interrupção externa (INT0 / INT1)

/*ISR(INT0_vect){
	PORTB|= (1<<PORTB1); // ascende led em PB1
	_delay_ms(100);
	PORTB &= ~(1<<PORTB1); //apaga led em PB1
}

void INT_config() {
	EICRA = (1<<ISC01)||(0<<ISC00); //Configura INT0 na borda de descida
	EIMSK = (1<<INT0); //Habilita INT0
}

void GPIO_config() {
	DDRB |= (1<<DDB0); //PINO PB0 COMO SAÍDA
	DDRB |= (1<<DDB1); //PINO PB1 COMO SAÍDA
}

int main(void) {
	GPIO_config();
	INT_config();
	sei(); //habilita interrupçãoes globalmente
    while(1) {
		_delay_ms(100);
		PORTB ^= (1<<PORTB0); 
        //TODO:: Please write your application code 
    }
}*/

ISR(INT0_vect){ //função no vetor de interrupção INT0
	PORTB|= (1<<PORTB1); // ascende led em PB1
	_delay_ms(50);
	PORTB &= ~(1<<PORTB1); //apaga led em PB1
}

ISR(INT1_vect){ //função no vetor de interrupção INT0
	PORTB|= (1<<PORTB1); // ascende led em PB1
	_delay_ms(100);
	PORTB &= ~(1<<PORTB1); //apaga led em PB1
}

void INT_config() {
	EICRA = (1<<ISC01)||(0<<ISC00); //Configura INT0 na borda de descida
	EIMSK = (1<<INT0); //Habilita INT0
}

void GPIO_config() {
	DDRB |= (1<<DDB0); //PINO PB0 COMO SAÍDA
	DDRB |= (1<<DDB1); //PINO PB1 COMO SAÍDA
}

int main(void) {
	GPIO_config();
	INT_config();
	sei(); //habilita interrupçãoes globalmente
	while(1) {
		_delay_ms(100);
		PORTB ^= (1<<PORTB0);
		//TODO:: Please write your application code
	}
}
 