/*
 * scheduler.h
 *
 * Created: 2/23/2019 4:21:42 PM
 *  Author: AVE-LAP-44
 */ 


#ifndef SCHEDULER_H_
#define SCHEDULER_H_
#include "../Commen/commen.h"
#include "../Timer/Timer.h"

#define OS_TICK_INTERVAL_MSEC 1
#define TASKS_MAX_NUM         10

void Scheduler();
uint8 scheduler_Add_Task(task task_pramters);
void schedulerInit(void);
void schedulerStart(void);
uint8 scheduler_Remove_Task(task removed_task);
void  Bubble_sort_algo(void);

#endif /* SCHEDULER_H_ */