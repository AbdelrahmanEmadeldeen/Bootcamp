/*
 * GPIO.c
 *
 * Created: 2/13/2019 10:41:19 AM
 * Author : AVE-LAP-44
 */ 



    /* Replace with your application code */
#include "avr\interrupt.h"
#include "Commen\commen.h"
#include "LED\led.h"
#include "DIO\DIO_prog.h"
#include "Tasks\tasks.h"
#include "Scheduler\scheduler.h"
#include "Sevenseg\BCDSevSegment.h"
#include "Keypad\Keypad.h"
 

 int main(void)
 {
	 
	 BCDSevegments_init();
	 Keypad_init();
     uint8 prv=0;
     uint8 key;
	 sei();
	 while(1)
	 {   
		 key=Keypad_getPressedKey();
		 if(key !=0){prv=key;}
		 BCDSevegments_displayNo(prv);
		 timer_mdelay(NUM_5);
		 
		 
		 
	 }
#if 0


	 /* tasktype address;
	 uint16    priority;
	 uint16    periodicity;
	 uint16    Remaining; */
	 schedulerInit();
task task1_pramters={task1,NUM_1,NUM_1000,NUM_1000};
task task2_pramters={task2,NUM_1,NUM_2000,NUM_2000};
task task3_pramters={task3,NUM_1,NUM_3000,NUM_3000};
	 scheduler_Add_Task(task1_pramters);
	 scheduler_Add_Task(task2_pramters);
	 scheduler_Add_Task(task3_pramters);
	 schedulerStart();




    #endif
}


	


