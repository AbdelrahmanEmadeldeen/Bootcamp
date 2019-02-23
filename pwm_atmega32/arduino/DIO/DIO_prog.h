
#ifndef DIO_PROG_H
#define DIO_PROG_H
#include "..\Commen\commen.h"

extern void DIO_WritePin(uint8 PinNum,uint8 PinValue);
/*******************************************************************
* NAME : void DIO_WritePin(uint8 PinNum,uint8 PinValue)
*
* DESCRIPTION : Write on GPIO Pin
*
* INPUTS :
*       PARAMETERS:
*               uint8 PinNum       PIN Number
*               uint8 PinValue     Value (HIGH 1),(LOW 0)
*       GLOBALS :
*               uint8 GPIO_PORTx_OUTPUT   the GPIO_OUTPUT register
*
* OUTPUTS :
*       PARAMETERS:
*                   void
*       GLOBALS :
*                  GPIO_PORTx_OUTPUT
*       RETURN :
*                  void
* PROCESS :
*                   [1]check the region of the pin          example PORT0 FROM 10 TO 17 ...The PinNum =15
*                   [2]convert the pin number to bit number         the PinNum =PinNum-start =>PinNum=15-10=BIT5
*                   [3]Check the Value
*                   [4]SET if the value==1
*                   [5]clear if the value ==0
*
* NOTES :
* CHANGES :

*  NO    DATE         WHO     DETAIL
*  0    22/2/19       Emad    Create the module

*/

extern uint8 DIO_ReadPin(uint8 PinNum);

/*******************************************************************
* NAME :          uint8 DIO_ReadPin(uint8 PinNum)
*
* DESCRIPTION :    Read GPIO pin value
*
* INPUTS :
*       PARAMETERS:
*                 uint8 PinNum           The Pin number
*       GLOBALS :
*                 GPIO_PORTx_INPUT      The GPIO INPUT register
*
* OUTPUTS :
*
*       GLOBALS :
*                 -
*       RETURN :
*            Uint8    Pinvalue
* PROCESS :
*                   [1]Get the INPUT register Number
*                   [2]Get the actual value of the pin
*                   [3]Get the Pin Value
*                   [4]Return the Pin Value
*
*
* NOTES :
* CHANGES :

*  NO    DATE       WHO     DETAIL
*  0    22/2/2019   Emad    Create

*/
extern void DIO_SetPinDirection(uint8 PinNum,uint8 PinDirection);

/*******************************************************************
* NAME :           DIO_SetPinDirection(uint8 PinNum,uint8 PinDirection)
*
* DESCRIPTION :   Set GPIO Pin direction (INPUT - OUTPUT)
*
* INPUTS :
*       PARAMETERS:
*                uint8 PinNum                  GPIO PIN Number
*                uint8 PinDirection            GPIO PIN Value   ( OUTPUT 1) ,(INPUT 1)
*       GLOBALS :
*                GPIO_PORTx_DIR                GPIO Direction register
*
* OUTPUTS :
*
*       GLOBALS :
*                   -
*       RETURN :
*            void
* PROCESS :
*                   [1]Get the Direction register Number
*                   [2]Get the actual value of the pin
*                   [3]Check the pin   DIR Value
*                   [4]Set bit (OUTPUT) Clear bit (Input)
*
* NOTES :
* CHANGES :

*  NO    DATE        WHO     DETAIL
*  0    22/2/2019    Emad    Create

*/

#endif
