/*
 * main.c
 *
 * Created: 10/22/2026 8:21:34 AM
 *  Author: Willian 
 */ 
#define F_CPU 16000000
#include <util
#include <xc.h>
#include "avr/interrupt.h"

ISR(TWI_vect) {
	PORTB|= (1<<PORTB0);
	//Tratar o estado atual da máquina do TWI
	uint8_t tStatusCode = (TWSR & 0b11111000);
		switch(tStatusCode) {
		case (0x60): {
			TWCR = (1<<TWINT)|(1<<TWEA);
		} break;
		case (0x80):{
			uint8_t tReceivedByte = TWDR; 
			TWCR = (1<<TWINT)|(1<<TWEA);
		}break;
		case(0xA0): { //Final de transmissão (stop condition ou repeated start)
		}break;
		default:{
			PORTB |=(1<<PORTB4);
			TWCR = (1<<TWEN)|(1<<TWIE)|(1<<TWINT);
	}
	} 
	TWCR = (1<<TWIE)|(1<<TWINT);
	_delay_ms(1);
	PORTB = 0;
	}
	
void TWI_slave_config(){
	TWBR = 64;                               //Divisor 64, fscl=100kH
	TWSR |= (0<<TWPS1)|(0<<TWPS0);           //
	TWCR |= (1<<TWEN)|(1<<TWIE); 
	TWAR = pAddress
}

int main(void){
   DDRB = (1<<DDB4)|(1<<DDB3)|(1<<DDB2)|(1<<DDB1)|(1<<DDB0);

    while(1)
    {
        //TODO:: Please write your application code 
    }
}   

//#incompleto. Irei refazer o código depois traduzindo o código do professor do guit para conseguir entender

