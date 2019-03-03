/*
 * tasks.c
 *
 * Created: 2/23/2019 3:17:49 PM
 *  Author: AVE-LAP-44
 */ 
#include "../DIO/DIO_prog.h"
#include "tasks.h"
#include "../LED/led.h"






 void task1(void)
{
	
DIO_TogglePin(LED0);
		
}

 void task2(void)
{
	    DIO_TogglePin(LED1);		
}
	
	

 void task3(void)
{
	
	DIO_TogglePin(LED2);
		
}
 