#include "DIO_prog.h"

void DIO_WritePin(uint8 PinNum,uint8 PinValue){
	if ((PinNum>=0)&&(PinNum<8)){
		
		if(PinValue==1){
		                 Set_Bit(PORTA,PinNum);
		               }
		else if(PinValue==0){
		                  Clear_Bit(PORTA,PinNum);
		                    }
	                }
	else if ((PinNum>=8)&&(PinNum<16)){
		PinNum-=8;
		if(PinValue==1){
			Set_Bit(PORTB,PinNum);
		}
		else if(PinValue==0){
			Clear_Bit(PORTB,PinNum);
		}
	}
	else if ((PinNum>=16)&&(PinNum<24)){
		PinNum-=16;
		if(PinValue==1){
			Set_Bit(PORTC,PinNum);
		               }
		else if(PinValue==0){
			Clear_Bit(PORTC,PinNum);
		                    }
	                                  }
		else if ((PinNum>=24)&&(PinNum<32)){
			PinNum-=24;
			if(PinValue==1){
				Set_Bit(PORTD,PinNum);
		                	}
			else if(PinValue==0){
				Clear_Bit(PORTD,PinNum);
			                    }
		                                   }			
			
		   
	}
	
	
	
	

uint8 DIO_ReadPin(uint8 PinNum){
	uint8 PinValue;

	if ((PinNum>=0)&&(PinNum<8)){
		  PinValue=Get_Bit(PORTA,PinNum);
		  return PinValue;
	                            }
	else if ((PinNum>=8)&&(PinNum<16)){
		PinNum-=8;
		PinValue=Get_Bit(PORTB,PinNum);
		return PinValue;
		                              }                             
	
	else if ((PinNum>=16)&&(PinNum<24)){
		PinNum-=16;
		PinValue=Get_Bit(PORTC,PinNum);
		return PinValue;
		                               }
	                                 
		else if ((PinNum>=24)&&(PinNum<32)){
			PinNum-=24;
			PinValue=Get_Bit(PORTD,PinNum);
			return PinValue;
			                               }
}	
	
	
	
	




void DIO_SetPinDirection(uint8 PinNum,uint8 PinDirection)
{
	if ((PinNum>=0)&&(PinNum<8))  {
		
		if(PinDirection==1){
			Set_Bit(DDRA,PinNum);
		                   }
		else if(PinDirection==0){
			Clear_Bit(DDRA,PinNum);
		                        }
	                               }
	else if ((PinNum>=8)&&(PinNum<16)){
		PinNum-=8;
		if(PinDirection==1){
			Set_Bit(DDRB,PinNum);
		                   }
		else if(PinDirection==0){
			Clear_Bit(DDRB,PinNum);
		                        }
	                                  }
	else if ((PinNum>=16)&&(PinNum<24)){
		PinNum-=16;
		if(PinDirection==1){
			Set_Bit(DDRC,PinNum);
		                   }
		else if(PinDirection==0){
			Clear_Bit(DDRC,PinNum);
		                        }
	                                  }
	else if ((PinNum>=24)&&(PinNum<32)){
		PinNum-=24;
		if(PinDirection==1){
			Set_Bit(DDRD,PinNum);
		                   }
		else if(PinDirection==0){
			Clear_Bit(DDRD,PinNum);
		                        }
	                                   }
}