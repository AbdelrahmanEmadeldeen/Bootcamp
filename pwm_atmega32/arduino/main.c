/*
 * arduino.c
 *
 * Created: 2/22/2019 4:28:49 PM
 * Author : AVE-LAP-44
 */ 

#include "DIO/DIO_prog.h"
#include "Commen/commen.h"
#include "Motor/motor_config.h"
#include "Timer/Timer.h"

int main(void)
{
    /* Replace with your application code */
	
	DIO_SetPinDirection(MOTOR1_EN,OUTPUT);
	DIO_SetPinDirection(MOTOR1_A,OUTPUT);
	DIO_SetPinDirection(MOTOR1_B,OUTPUT);
	
	DIO_SetPinDirection(MOTOR2_EN,OUTPUT);
	DIO_SetPinDirection(MOTOR2_A,OUTPUT);
	DIO_SetPinDirection(MOTOR2_B,OUTPUT);
PWM_init();
	  
	uint8 flag=0;
	uint8 count=0;
	
    while (1) 
    {
     if (count==100){flag==1;}
	 if (count==0){flag==0;} 
	 if (flag==0){count++;}
     if (flag==1){count--;}
     PWM_timer1A(count);
     PWM_timer2A(count);
	 DIO_WritePin(MOTOR1_A,HIGH);
	 DIO_WritePin(MOTOR1_B,LOW);
	 

	  DIO_WritePin(MOTOR2_A,HIGH);
	  DIO_WritePin(MOTOR2_B,LOW);
	  timer_mdelay(TIME_100MS);

	 


	
		
    }
}

