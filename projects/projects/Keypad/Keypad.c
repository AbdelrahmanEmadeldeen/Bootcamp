#include "Keypad.h"

/* keymap Global variable that contain the KEYPAD Values */
uint8 keymap[KEYPAD_ROW_NUM][KEYPAD_COL_NUM]={
	                                           {NUM_1,NUM_2,NUM_3},
	                                           {NUM_4,NUM_5,NUM_6},
											   {NUM_7,NUM_8,NUM_9}
										      };
/************************************************************************************
* Function Name:         Keypad_init
* Parameters (in):       void
* Parameters (inout):    void
* Parameters (out):      void
* Return value:          void
* Description:           Function that initialize the KEYPAD pin 
************************************************************************************/
void Keypad_init(void)
{
	
	DIO_SetPinDirection(KEYPAD_COL1,LOW);       /* Initialize KEYPAD_COL1 as INPUT */
	DIO_SetPinDirection(KEYPAD_COL2,LOW);       /* Initialize KEYPAD_COL2 as INPUT */
	DIO_SetPinDirection(KEYPAD_COL3,LOW);       /* Initialize KEYPAD_COL3 as INPUT */
	
	DIO_WritePin(KEYPAD_COL1,HIGH);             /* Enable the PUR for KEYPAD_COL1 */
	DIO_WritePin(KEYPAD_COL2,HIGH);             /* Enable the PUR for KEYPAD_COL2 */
	DIO_WritePin(KEYPAD_COL3,HIGH);             /* Enable the PUR for KEYPAD_COL3 */

	DIO_SetPinDirection(KEYPAD_RAW1,HIGH);      /* Initialize KEYPAD_COL1 as OUTPUT */
	DIO_SetPinDirection(KEYPAD_RAW2,HIGH);      /* Initialize KEYPAD_COL2 as OUTPUT */
	DIO_SetPinDirection(KEYPAD_RAW3,HIGH);      /* Initialize KEYPAD_COL3 as OUTPUT */
	
	
	
}
/************************************************************************************
* Function Name:        Keypad_getPressedKey
* Parameters (in):      void
* Parameters (inout):   void
* Parameters (out):     key
* Return value:         uint8
* Description:          Function that return the keypad value
************************************************************************************/

uint8 Keypad_getPressedKey(void){
	uint8 key=NUM_ZERO;
	uint8 success_flag=NUM_ZERO;
	uint8 raw;
	uint8 col;
	uint8 time_out=NUM_2;
	DIO_WritePin(KEYPAD_RAW1,NUM_ZERO);
	DIO_WritePin(KEYPAD_RAW2,NUM_ZERO);
	DIO_WritePin(KEYPAD_RAW3,NUM_ZERO);
	
    while(--time_out)
	{	
	    DIO_WritePin(KEYPAD_RAW1,LOW);
	    DIO_WritePin(KEYPAD_RAW2,NUM_1);
	    DIO_WritePin(KEYPAD_RAW3,NUM_1);
	    if(!DIO_ReadPin(KEYPAD_COL1))
	    {
		   col=NUM_ZERO;
		   raw=NUM_ZERO;
		   success_flag=NUM_1;
		   break;
	    }
	    else if(!DIO_ReadPin(KEYPAD_COL2))
	    {
		   col=NUM_1;
		   raw=NUM_ZERO;
		   success_flag=NUM_1;
		   break;
	    }
	    else if(!DIO_ReadPin(KEYPAD_COL3))
	    {
		  col=NUM_2;
		  raw=NUM_ZERO;
		  success_flag=NUM_1;
		  break;
	    }
	    
		DIO_WritePin(KEYPAD_RAW1,HIGH);
	    DIO_WritePin(KEYPAD_RAW2,LOW);
	    DIO_WritePin(KEYPAD_RAW3,HIGH);
	    if(!DIO_ReadPin(KEYPAD_COL1))
	    {
		  col=NUM_ZERO;
		  raw=NUM_1;
		  success_flag=NUM_1;
		  break;
	    }
	    else if(!DIO_ReadPin(KEYPAD_COL2))
	    {
		  col=NUM_1;
		  raw=NUM_1;
		  success_flag=NUM_1;
		  break;
	    }
	    else if(!DIO_ReadPin(KEYPAD_COL3))
	    {
		  col=NUM_2;
		  raw=NUM_1;
		  success_flag=NUM_1;
		  break;
	    }
	    DIO_WritePin(KEYPAD_RAW1,HIGH);
	    DIO_WritePin(KEYPAD_RAW2,HIGH);
	    DIO_WritePin(KEYPAD_RAW3,LOW);
	    if(!DIO_ReadPin(KEYPAD_COL1))
	    {
		  col=NUM_ZERO;
		  raw=NUM_2;
		  success_flag=NUM_1;
		  break;
	    }
	    else if(!DIO_ReadPin(KEYPAD_COL2))
	    {
		  col=NUM_1;
		  raw=NUM_2;
		  success_flag=NUM_1;
		  break;
	    }
	    else if(!DIO_ReadPin(KEYPAD_COL3))
	    {
		  col=NUM_2;
		  raw=NUM_2;
		  success_flag=NUM_1;
		  break;
	    }

	
   }
   if(NUM_1==success_flag)
   {
     key= keymap[raw][col];
   }
   else
   {  
	  key=0;
   }
return key;

}