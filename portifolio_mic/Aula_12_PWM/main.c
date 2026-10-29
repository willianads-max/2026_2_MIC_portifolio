/*
 * main.c
 *
 * Created: 10/29/2026 8:35:45 AM
 *  Author: Willian 
 */ 

#include <xc.h>

void PWM_config() {
	// PAGINA 84 DATASHEET, CAP 14, Table 14
	//Grafico pag 80
	TCCR0A = (1<<COM0A1)|(0<<COM0A0)
			|(1<<COM0B1)|(0<<COM0B0)
			|(1<<WGM01)|(0<<WGM00);
	 //Modo fast PWM, saida OCR0A não inversor
	
	TCCR0B = (0<<WGM02)|(0<<CS02)|(0<<CS01)|(1<<CS00);
	OCR0A = 101; //Razao de ciclo de 40%
	OCR0B = 76;
	DDRD = (1<<DDD6)|(1<<DDD5); //Configura o pino PD6 como saida
}

int main(void) {
	PWM_config();
    while(1) { 
    }
}