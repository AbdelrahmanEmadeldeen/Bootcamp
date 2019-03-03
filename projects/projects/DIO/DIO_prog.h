
#ifndef DIO_PROG_H
#define DIO_PROG_H
#include "..\Commen\commen.h"

void DIO_WritePin(uint8 PinNum,uint8 PinValue);
/************************************************************************************
* Function Name:       DIO_WritePin
* Parameters (in):     uint8 PinNum      PIN Number
                       uint8 PinValue    Value (HIGH 1),(LOW 0)
* Parameters (inout):  GPIO_PORTx_OUTPUT   the GPIO_OUTPUT register
* Parameters (out):    void
* Return value:        void
* Description:         Write on GPIO Pin
************************************************************************************/

uint8 DIO_ReadPin(uint8 PinNum);
/************************************************************************************
* Function Name:       DIO_ReadPin
* Parameters (in):     uint8 PinNum          GPIO PIN number
                       GPIO_PORTx_INPUT      GPIO PORTX INPUT register
* Parameters (inout): void
* Parameters (out):uint8 PinValue
* Return value:(HIGH=1) (LOW=0) 
* Description:Function that return GPIO PIN Value
************************************************************************************/	


void DIO_SetPinDirection(uint8 PinNum,uint8 PinDirection);
/************************************************************************************
* Function Name:       DIO_SetPinDirection
* Parameters (in):     uint8 PinNum          the pin number
                       uint8 PinDirection    the pin direction (OUTPUT =1) ,(INPUT=0)
* Parameters (inout):  GPIO_PORT0_DIR
* Parameters (out):    void
* Return value:        void
* Description:         Function that Set a GPIO PIN Direction
************************************************************************************/

void DIO_TogglePin(uint8 PinNum);
/************************************************************************************
* Function Name:       DIO_TogglePin
* Parameters (in):     uint8 PinNum
* Parameters (inout):  GPIO_PORT0_OUTPUT
* Parameters (out):    void
* Return value:        void
* Description:         Function that toggle a GPIO PIN
************************************************************************************/
#endif
