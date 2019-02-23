
#ifndef TIMER_DELAY
#define TIMER_DELAY


#include "..\Commen\commen.h"
#include "..\MC\atmega32.h"


 void timer_mdelay(uint32 n);
 void timer_udelay(uint32 n);
 void timer_mdelay_interrupt(uint32 n);
 void timer_init();
 void PWM_init();
 void PWM_timer1A(uint8 duty_cycle);
 void PWM_timer2A(uint8 duty_cycle);
#endif
