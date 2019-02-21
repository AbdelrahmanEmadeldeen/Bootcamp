#include "Timer.h"

void timer_mdelay(uint32 n){
	uint32 i=0;
	TCCR0=0;
	OCR0=250;
	TCCR0=0b10001011;
	TCNT0=0;
	
	for(;i<n;i++){
		while(!Get_Bit(TIFR,1)){}
			Set_Bit(TIFR,1);
}
	}
void timer_udelay(uint32 n){
	TCCR0=0;
	OCR0=16;
	uint32 i=0;
	TCCR0=0b10001001;
	TCNT0=0;
	
	for(;i<n;i++){
		while(!Get_Bit(TIFR,1)){}
			Set_Bit(TIFR,1);
}
	}
void timer_init(){
	
	OCR0=250;
	TCCR0=0b10001011;
	
	
	
	
	
}