/*
 * main.c
 *
 * Created: 8/27/2026 8:54:29 AM
 *  Author: Aluno
 */ 


#define F_CPU 16000000
#include <xc.h>
#include <stdint.h>
#include "util/delay.h"

void GPIO_config(){
	DDRB = (1<<DDB6)|(1<<DDB4)|(1<<DDB2)|(1<<DDB0); //
}

int main(void) {
	GPIO_config();
	uint8_t tData = 0x03;	
    while(1) {
		PORTB = tData;
		_delay_ms(1000);
		tData = tData << 1; //0b00000000 0110, 0b00000000 1100, 0b00000000 0110 
		if(tData == 0) {
			tData = 0x03;
		}
    }
}