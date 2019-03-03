#include "BCDSevSegment.h"
void BCDSevegments_enable(uint8 num){
	DIO_WritePin(num,HIGH);
	
	
}
void BCDSevegments_disable(void)
{
	
	DIO_WritePin(SEG_E1,LOW);
	DIO_WritePin(SEG_E2,LOW);
	DIO_WritePin(SEG_E3,LOW);
	DIO_WritePin(SEG_E4,LOW);
	
	
}
void BCDSevegments_init()
{
	DIO_SetPinDirection(SEG_A,OUTPUT);
	DIO_SetPinDirection(SEG_B,OUTPUT);
	DIO_SetPinDirection(SEG_C,OUTPUT);
	DIO_SetPinDirection(SEG_D,OUTPUT);
	DIO_SetPinDirection(SEG_E1,OUTPUT);
	DIO_SetPinDirection(SEG_E2,OUTPUT);
	DIO_SetPinDirection(SEG_E3,OUTPUT);
	DIO_SetPinDirection(SEG_E4,OUTPUT);
    DIO_SetPinDirection(SEG_DP,OUTPUT);

}

void BCDSevegments_displayNo(uint32 num)
{
		
    uint8  time_out=NUM_4;
    uint32 rem;

    uint8  SEG_A_vaule;
    uint8  SEG_B_vaule;
    uint8  SEG_C_vaule;
    uint8  SEG_D_vaule;
    uint8  num_flag=NUM_ZERO;

    while(time_out--)
    {  
		if ((NUM_1000<=num)&&(NUM_9999>=num))
	    {
		    
		    BCDSevegments_enable(SEG_E4);
		    rem=num/NUM_1000;
		    SEG_A_vaule=Get_Bit(rem,BIT0);
		    SEG_B_vaule=Get_Bit(rem,BIT1);
		    SEG_C_vaule=Get_Bit(rem,BIT2);
		    SEG_D_vaule=Get_Bit(rem,BIT3);
		    DIO_WritePin(SEG_A,SEG_A_vaule);
		    DIO_WritePin(SEG_B,SEG_B_vaule);
		    DIO_WritePin(SEG_C,SEG_C_vaule);
		    DIO_WritePin(SEG_D,SEG_D_vaule);
		    timer_mdelay(TIME_2MS);
		    BCDSevegments_disable();
		    num -=rem*NUM_1000;
		    num_flag=NUM_2;
		    
		    
	   }
	   if (((NUM_100<=num)&&(NUM_999>=num))||(NUM_2==num_flag))
	   {
		   
		   BCDSevegments_enable(SEG_E3);
		   
		   rem=num/NUM_100;
		   SEG_A_vaule=Get_Bit(rem,BIT0);
		   SEG_B_vaule=Get_Bit(rem,BIT1);
		   SEG_C_vaule=Get_Bit(rem,BIT2);
		   SEG_D_vaule=Get_Bit(rem,BIT3);
		   DIO_WritePin(SEG_A,SEG_A_vaule);
		   DIO_WritePin(SEG_B,SEG_B_vaule);
		   DIO_WritePin(SEG_C,SEG_C_vaule);
		   DIO_WritePin(SEG_D,SEG_D_vaule);
		   timer_mdelay(TIME_5MS);
		   BCDSevegments_disable();
		   num -=rem*NUM_100;
		   num_flag=NUM_1;
	   }
       
      if (((NUM_10<=num)&&(NUM_99>=num))||(NUM_1==num_flag))
      {
		
	     BCDSevegments_enable(SEG_E2);
         rem=num/NUM_10;
         SEG_A_vaule=Get_Bit(rem,BIT0);
         SEG_B_vaule=Get_Bit(rem,BIT1);
         SEG_C_vaule=Get_Bit(rem,BIT2);
         SEG_D_vaule=Get_Bit(rem,BIT3);
         DIO_WritePin(SEG_A,SEG_A_vaule);
         DIO_WritePin(SEG_B,SEG_B_vaule);
         DIO_WritePin(SEG_C,SEG_C_vaule);
         DIO_WritePin(SEG_D,SEG_D_vaule);
         timer_mdelay(TIME_2MS);
         BCDSevegments_disable();
         num -=rem*NUM_10;
		 num_flag=NUM_ZERO;

	
      }
      if (((NUM_ZERO<=num)&&(NUM_9>=num))&&(NUM_ZERO==num_flag))
      {
	      BCDSevegments_enable(SEG_E1);
	      SEG_A_vaule=Get_Bit(num,BIT0);
	      SEG_B_vaule=Get_Bit(num,BIT1);
	      SEG_C_vaule=Get_Bit(num,BIT2);
	      SEG_D_vaule=Get_Bit(num,BIT3);
	      DIO_WritePin(SEG_A,SEG_A_vaule);
	      DIO_WritePin(SEG_B,SEG_B_vaule);
	      DIO_WritePin(SEG_C,SEG_C_vaule);
	      DIO_WritePin(SEG_D,SEG_D_vaule);
	      timer_mdelay(TIME_2MS);
	      BCDSevegments_disable();
	      break;
	      
      }
     
  }
}
