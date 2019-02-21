#include "BCDSevSegment.h"
void BCDSevegments_enable(uint8 num){
	DIO_SetPinDirection(num,1);
	DIO_WritePin(num,1);
	
	
}
void BCDSevegments_disable(void){
	
	DIO_WritePin(SEG_E1,0);
	DIO_WritePin(SEG_E2,0);
	DIO_WritePin(SEG_E3,0);
	DIO_WritePin(SEG_E4,0);
	
	
}

void BCDSevegments_displayNo(uint32 num)
{
		DIO_SetPinDirection(PINB0,1);
		DIO_SetPinDirection(PINB1,1);
		DIO_SetPinDirection(PINB2,1);
		DIO_SetPinDirection(PINB3,1);
uint8 i=5;
uint32 rem;

while(i--){
   if ((num>=0)&&(num<10))
    {	 
	 BCDSevegments_enable(SEG_E1);

	PORTB=PORTB&(~(0x0F));
	PORTB=PORTB|(num);
	timer_mdelay(5);
    BCDSevegments_disable();
	break;
	 
   }
  if ((num>=10)&&(num<100))
    {
		
	BCDSevegments_enable(SEG_E2);
    rem=num/10;
    PORTB=PORTB&(~(0x0F));
    PORTB=PORTB|(rem);
    timer_mdelay(5);
    BCDSevegments_disable();
    num -=rem*10;

	
    }
  if ((num>=100)&&(num<1000))
   {
	
	BCDSevegments_enable(SEG_E3);
	
	rem=num/100;
	PORTB=PORTB&(~(0x0F));
	PORTB=PORTB|(rem);
	timer_mdelay(5);
	BCDSevegments_disable();
	num -=rem*100;

	
	
   }
if ((num>=1000)&&(num<10000))
{
	
	BCDSevegments_enable(SEG_E4);
	
	rem=num/1000;
	PORTB=PORTB&(~(0x0F));
	PORTB=PORTB|(rem);
	timer_mdelay(5);
	BCDSevegments_disable();
	num -=rem*1000;

	
	
}
}
}
