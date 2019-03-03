/*
 * scheduler.c
 *
 * Created: 2/23/2019 4:21:58 PM
 *  Author: Emad
 */ 

#include "scheduler.h"

static volatile uint16  tec_number=NUM_ZERO;             /* Variable to hold the tec number */
static volatile uint16  isrflag=NUM_ZERO;                /* Variable to hold the ISR count */ 

static volatile uint8 new_tec_flag=FALSE;                /* Boolean Variable hold the tec status    */
static task  tasks_arrey[TASKS_MAX_NUM];                 /* Array that holds the tasks  */

 static volatile uint8 tasks_index=NUM_ZERO;                       /* Tasks index */
 /***********************************************************************
 * NAME :             scheduler_Remove_Task
 *
 * DESCRIPTION :    remove a task
 *
 * INPUTS :
 *       PARAMETERS:
 *                task removed_task                   the task you want to remove 
 *       GLOBALS :
 *              tasks_arrey[TASKS_MAX_NUM]            the tasks in the OS 
 *
 * OUTPUTS :
 *         
 *       GLOBALS :
 *       New   tasks_arrey[TASKS_MAX_NUM]             the new array with out the removed tasks 
 *       RETURN :
 *            Type:   uint8    success_flag
 *            Values: True ,False
 * PROCESS :
 *                   [1]Loop in the array
 *                   [2]if the address of the removed task matches an address in array 
 *                   [3]make the task priority lowest
 *                   [4]sort based on priority
 *                   [5]decrement the array index by 1 
 *
 * NOTES :
 * CHANGES :
 *
 *  NO    DATE        WHO     DETAIL
 *  0    27/2/2019   Emad     Create
 ************************************************************************                                                                      *
 */
 uint8 scheduler_Remove_Task(task removed_task){
	 uint8 success_flag=FALSE;
	
	 uint8 loop_counter=NUM_ZERO;
	 for(loop_counter;loop_counter<tasks_index;loop_counter++){
		 if(tasks_arrey[loop_counter].address==removed_task.address){
			 tasks_arrey[loop_counter].priority=MAX_8BITS;
			 Bubble_sort_algo();
			 tasks_index -=NUM_1;
             success_flag=TRUE;
		 }

	 }
	 
	 return success_flag;
 }
 
 
 
 
 

/***********************************************************************
* NAME :          Bubble_sort_algo()                                   *
*                                                                      *
* DESCRIPTION : Function that sort the tasks array based on priorities.*                                         *
*                                                                      *
* INPUTS :                                                             *
*       PARAMETERS:                                                    *
*                     void                                             *
*       GLOBALS :                                                      *
*           tasks_arrey[TASKS_MAX_NUM]      task array                 *
*           tasks_index                     task index                 *
* OUTPUTS :                                                            *
*                                                                      *
*                                                                      *
*       GLOBALS :                                                      *
*          tasks_arrey      Sorted task array                          *
*       RETURN :                                                       *
*                void                                                  *
* PROCESS :                                                            *
*                   [1]Take an index                                   *
*                   [2]LOOP on other index                             *
*                   [3]if the index of one element lower than the base *
*                        Swap                                          *
*                                                                      *
*                                                                      *
*                                                                      *
* NOTES :                                                              *
* CHANGES :                                                            *
*                                                                      *
*  NO    DATE        WHO     DETAIL                                    *
*  0    25/2/2019    Emad    Create                                    *
************************************************************************                                                                      *
*/

	
	
	
	
 
void Bubble_sort_algo()
{
	
	uint8 LOOP1_counter=NUM_ZERO;
	uint8 LOOP2_counter=NUM_ZERO;
	task temp;
	
	for(LOOP1_counter=NUM_ZERO;LOOP1_counter<tasks_index;LOOP1_counter++)
	{
		
		for(LOOP2_counter=LOOP1_counter;LOOP2_counter<tasks_index;LOOP2_counter++)
		{
			if (tasks_arrey[LOOP2_counter].priority<tasks_arrey[LOOP1_counter].priority)
			{
				temp=tasks_arrey[LOOP1_counter];
				tasks_arrey[LOOP1_counter]=tasks_arrey[LOOP2_counter];
				tasks_arrey[LOOP2_counter]=temp;
			}
			
		}
	}
		
	
}
/***********************************************************************
* NAME :           scheduler_Add_Task
*
* DESCRIPTION :
*               function that take variable of type task and add it to global tasks 
* INPUTS :
*       PARAMETERS:
*            task task_pramters             the task you want to add 
*       GLOBALS :
*             tasks_arrey                   the tasks array   
*             tasks_index                   the task index
* OUTPUTS :
*
*       GLOBALS :
*          tasks_arrey
*          tasks_index
*       RETURN :
*            Type:   uint8  success_flag
*            Values: True or False
* PROCESS :
*                   [1]Check that we didn't reach array max size
*                   [2]Add the new task
*                   [3]Increment the task index 
*                   [4]Sort the array
*                   [5]return True if it success,return False if its the index overflow
*
* NOTES :
* CHANGES :
*
*  NO    DATE         WHO     DETAIL
*  0     25/2/2019   Emad     Create
************************************************************************                                                                      *
*/

uint8 scheduler_Add_Task(task task_pramters){
	uint8  success_flag;

	if(tasks_index<=TASKS_MAX_NUM){
		tasks_arrey[tasks_index]=task_pramters;
		tasks_index +=NUM_1;
		success_flag=TRUE;
	}
  
	else{
		success_flag=FALSE;
	}
	
	return success_flag;
}
/***********************************************************************
* NAME :                 scheduler_newtick
*
* DESCRIPTION :
*                          function used in timer call back to increment the tick numbers
* INPUTS :
*       PARAMETERS:
*                  void
*       GLOBALS :
*                  new_tec_flag
*                  tec_number 
*
* OUTPUTS :
*                 
*       GLOBALS :
*               new_tec_flag
*                  tec_number
*       RETURN :
*              void
* PROCESS :
*                   [1]Increment the ISR flag counter
*                   [2]if the ISR flag counter = OS_TICK_INTERVAL_MSEC
*                   [3]increment the OS count
*                   [4]Set the new_teck_flag high
*                   
*
* NOTES :
* CHANGES :
*
*  NO    DATE        WHO     DETAIL
*  0   27/2/2019     Emad    Create
************************************************************************                                                                      *
*/


void scheduler_newtick(void){
	isrflag++;      
	if(OS_TICK_INTERVAL_MSEC==isrflag)              /* If isrflag reach OS TICK  */
	{         
	isrflag=0;                                      /* Increment the timer0_COMP_ISR flag */ 	                               
    new_tec_flag=TRUE;
	tec_number++;                                   /* Increment tec number */
	}
	
}

void schedulerInit(void){                /* Send Pointer of  scheduler_newtick function to timer0 */
timer0_setcallback(scheduler_newtick);


}	
void schedulerStart(void){
timer0_os_init(50);	
                                                 /* initiate timer0 for OS */
while(1){
	
	if(TRUE==new_tec_flag)
	{
			Scheduler();                     /* GO to the Scheduler */

		new_tec_flag=FALSE;
		  
	}
}

}
	
	
void Scheduler(){
	uint8 loop_counter;
    
	for(loop_counter=NUM_ZERO;loop_counter<tasks_index;loop_counter++)
    {
	    
	    if(NUM_ZERO==tasks_arrey[loop_counter].Remaining)
	    {
		tasks_arrey[loop_counter].Remaining=tasks_arrey[loop_counter].periodicity;
		(*(tasks_arrey[loop_counter].address))();
		
	    }
		tasks_arrey[loop_counter].Remaining -=NUM_1;
   }
}
	
	
	
	
