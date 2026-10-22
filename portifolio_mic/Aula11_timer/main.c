/*
 * main.c
 *
 * Created: 10/22/2026 10:51:02 AM
 *  Author: Willian da Silva
 */ 

#include <xc.h>
#include "avr/interrupt.h"
//Obter uma interrupção com periodo de 10 ms
ISR(TIMER0_COMPA_vect){  //Vetor interrupção do comparador  A do timer 0
	PORTB^= (1<<PORTB0); //Alterna PORTB0
	
}
void TMR0_config(){ //Pri8meiro colocar no modo de confg 2 através do registrador TCCR
	TCCR0A = (1<<WGM01)|(0<<WGM00); //Configuração do modo CTC
	TCCR0B = (0<<WGM02)|(1<<CS02)|(0<<CS01)|(1<<CS00);
	OCR0A = 155; //Corresponde a 9,984ms
	TIMSK0 = (1<<OCIE0A); //hBILITA INTERRUPÇÃO COMPA
}

int main(void){
	DDRB |= (1<<DDB0);
	TMR0_config();
	sei();
    while(1)
    {
        //TODO:: Please write your application code 
    }
}