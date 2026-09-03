/*
 * main.c
 *
 * Created: 9/3/2026 8:57:08 AM
 *  Author: Aluno
 */ 

#include <xc.h>

ISR(PCINT0_vect) {
	
	
	
}
void GPIO_config() {
	/*0b0000 1111; inicialmente b0,b1,b2,b3 = 1. Se coloca o "~" elesinvertem e mudam pra zero */
	DDRB &= ~((1<<DDB0))|((1<<DDB1))|((1<<DDB2))|((1<<DDB3)); // Portas PB0, PB1, PB2, PB3 como entrada
	DDRD = 0xff; //seta todo mundo como saída, mesmo que 0b11111111
	DDRD |= (1<<DDB0))|((1<<DDB1))|((1<<DDB2))|((1<<DDB3)
		 | ((1<<DDB4))|((1<<DDB5))|((1<<DDB6))|((1<<DDB7); // configura PD0, PD1, PD2, PD3, PD4, PD5, PD6, PD7 COMO SAÍDA
}

void PCINT_config() {
	
	
	
}


int main(void)
{
    while(1)
    {
		
		
    }
}