/*
 * GPIO.c
 *
 * Created: 2/13/2019 10:41:19 AM
 * Author : AVE-LAP-44
 */ 



    /* Replace with your application code */
 
#include "Commen\commen.h"
#include "Dio\DIO_prog.h"
#include "Timer\Timer.h"



 int main(void)
 {   DIO_SetPinDirection(PINB4,HIGH);
	 	 DIO_WritePin(PINB4,HIGH);

	 while(1){
	 DIO_WritePin(PINB4,HIGH);
	 timer_mdelay_interrupt(TIME_1000MS);
	 DIO_WritePin(PINB4,LOW);
	 timer_mdelay_interrupt(TIME_1000MS);
	 }
	 return 0;
 }
