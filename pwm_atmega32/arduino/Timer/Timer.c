#include "Timer.h"
 
uint32 counter=0;

void timer_mdelay(uint32 n){
	uint32 i=0;
	TCCR0=0;
	OCR0=250;
	TCCR0=0b10001011;
	TCNT0=0;
	for(;i<n;i++){
		while(!Get_Bit(TIFR,BIT1)){}
			Set_Bit(TIFR,BIT1);
			
}
	}
	
void timer_mdelay_interrupt(uint32 n){
		uint32 i=0;
		TCCR0=0;
		OCR0=250;
		counter=n;
		Set_Bit(TIMSK,BIT1);
		
		
		TCNT0=0;
		TCCR0=0b10001011;
		while(counter){};
		
		
		
		
			
		
	}
void timer_udelay(uint32 n){
	TCCR0=0;
	OCR0=16;
	uint32 i=0;
	TCCR0=0b10001001;
	TCNT0=0;
	
	for(;i<n;i++){
		while(!Get_Bit(TIFR,BIT1)){}
			Set_Bit(TIFR,BIT1);
}
	}
void timer_init(){
	
	OCR0=250;
	TCCR0=0b10001011;
	
	
	
	
	
}
/* TIMER 1 REG */

void PWM_timer1A(uint8 duty_cycle){
	if(duty_cycle<=NUM_100){
	uint16 compare_value=duty_cycle*MAX_10BITS/NUM_100; 
	OCR1AH =(compare_value>>NUM_8);
	OCR1AL =compare_value;
	
	
	}
	else {}
		
	
		
}

 void PWM_timer2A(uint8 duty_cycle){
	if(duty_cycle<=NUM_100){
		uint16 compare_value=duty_cycle*MAX_10BITS/NUM_100;
		OCR1BH =(compare_value>>NUM_8);
		OCR1BL =compare_value;
	
		
	}
	else {}
	
	
	
}	 
	 
	 
	 
	 
	 
 

void PWM_init(){
	/*$2F ($4F) TCCR1A COM1A1 COM1A0 COM1B1 COM1B0 FOC1A FOC1B WGM11 WGM10 107 */
	/* for 10 bit        1      0      1     0      0      0     1     1
non_inverting mode
	 */ 
	
	
	Set_Bit(TCCR1A,WGM10);
	Set_Bit(TCCR1A,WGM11);
	Clear_Bit(TCCR1A,FOC1B);
	Clear_Bit(TCCR1A,FOC1A);
	Clear_Bit(TCCR1A,COM1B0);
	Set_Bit(TCCR1A,COM1B1);
	Clear_Bit(TCCR1A,COM1A0);
	Set_Bit(TCCR1A,COM1A1);
/*$2E ($4E) TCCR1B ICNC1 ICES1 – WGM13 WGM12 CS12 CS11 CS10 110 */
 /* for 10 bit
 non_inverting mode 0      0   0  0     1     0     0    1 
 */
	 
	Set_Bit(TCCR1B,CS10);
	Clear_Bit(TCCR1B,CS11);
	Clear_Bit(TCCR1B,CS12);
	Set_Bit(TCCR1B,WGM12);
	Clear_Bit(TCCR1B,WGM13);
	Clear_Bit(TCCR1B,ICES1);
	Clear_Bit(TCCR1B,ICNC1);
		TCNT1H=0;
		TCNT1L=0;
}
