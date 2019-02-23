# 1 "DIO_prog.c"
# 1 "<built-in>"
# 1 "<command-line>"
# 1 "DIO_prog.c"
# 1 "DIO_prog.h" 1



# 1 "..\\Commen\\commen.h" 1




# 1 "..\\Commen\\Types.h" 1



typedef unsigned char uint8;
typedef signed char sint8;
typedef unsigned char* ptr8;
typedef unsigned short uint16;
typedef signed short sint16;
typedef unsigned long int uint32;
typedef signed long int sint32;
# 6 "..\\Commen\\commen.h" 2
# 1 "..\\Commen\\BitwiseOperations.h" 1
# 7 "..\\Commen\\commen.h" 2
# 1 "..\\Commen\\numbers.h" 1
# 8 "..\\Commen\\commen.h" 2
# 5 "DIO_prog.h" 2
extern void DIO_WritePin(uint8 PinNum,uint8 PinValue);
extern uint8 DIO_ReadPin(uint8 PinNum);
extern void DIO_SetPinDirection(uint8 PinNum,uint8 PinDirection);
# 2 "DIO_prog.c" 2
# 1 "../MC/atmega328P.h" 1
# 3 "DIO_prog.c" 2
# 1 "dio_config.h" 1
# 4 "DIO_prog.c" 2

void DIO_WritePin(uint8 PinNum,uint8 PinValue){
 if ((PinNum>=8)&&(PinNum<=13)){

  if(PinValue==1){
                   (*((ptr8)0x25))=(*((ptr8)0x25))|(1<<PinNum);
                 }
  else if(PinValue==0){
                    (*((ptr8)0x25))=(*((ptr8)0x25))&(~(1<<PinNum));
                      }
                 }
 else if ((PinNum>=14)&&(PinNum<=19)){
  PinNum-=14;
  if(PinValue==1){
   (*((ptr8)0x28))=(*((ptr8)0x28))|(1<<PinNum);
  }
  else if(PinValue==0){
   (*((ptr8)0x28))=(*((ptr8)0x28))&(~(1<<PinNum));
  }
 }
 else if ((PinNum>=0)&&(PinNum<=0)){
  PinNum-=0;
  if(PinValue==1){
   (*((ptr8)0x2B))=(*((ptr8)0x2B))|(1<<PinNum);
                 }
  else if(PinValue==0){
   (*((ptr8)0x2B))=(*((ptr8)0x2B))&(~(1<<PinNum));
                      }
                                   }
 else if ((PinNum>=0)&&(PinNum<7)){
   PinNum-=0;
   if(PinValue==1){
    (*((ptr8)0x2B))=(*((ptr8)0x2B))|(1<<PinNum);
                   }
   else if(PinValue==0){
    (*((ptr8)0x2B))=(*((ptr8)0x2B))&(~(1<<PinNum));
                       }
                                     }


 }





uint8 DIO_ReadPin(uint8 PinNum){
 uint8 PinValue;

 if ((PinNum>=8)&&(PinNum<=13)){
    PinValue=(((*((ptr8)0x23)))>>PinNum)&0x01);
    return PinValue;
                             }
 else if ((PinNum>=14)&&(PinNum<=19)){
  PinNum-=14;
  PinValue=(((*((ptr8)0x26)))>>PinNum)&0x01);
  return PinValue;
                                }

 else if ((PinNum>=0)&&(PinNum<=7)){
  PinNum-=0;
  PinValue=(((*((ptr8)0x29)))>>PinNum)&0x01);
  return PinValue;
                                 }

  else if ((PinNum>=0)&&(PinNum<=0)){
   PinNum-=0;
   PinValue=(((*((ptr8)0x29)))>>PinNum)&0x01);
   return PinValue;
                                  }
}
# 83 "DIO_prog.c"
void DIO_SetPinDirection(uint8 PinNum,uint8 PinDirection)
{
 if ((PinNum>=8)&&(PinNum<=13)) {

  if(PinDirection==1){
   (*((ptr8)0x24))=(*((ptr8)0x24))|(1<<PinNum);
                     }
  else if(PinDirection==0){
   (*((ptr8)0x24))=(*((ptr8)0x24))&(~(1<<PinNum));
                          }
                                }
 else if ((PinNum>=14)&&(PinNum<=14)){
  PinNum-=14;
  if(PinDirection==1){
   (*((ptr8)0x27))=(*((ptr8)0x27))|(1<<PinNum);
                     }
  else if(PinDirection==0){
   (*((ptr8)0x27))=(*((ptr8)0x27))&(~(1<<PinNum));
                          }
                                   }
 else if ((PinNum>=0)&&(PinNum<=7)){
  PinNum-=0;
  if(PinDirection==1){
   (*((ptr8)0x2A))=(*((ptr8)0x2A))|(1<<PinNum);
                     }
  else if(PinDirection==0){
   (*((ptr8)0x2A))=(*((ptr8)0x2A))&(~(1<<PinNum));
                          }
                                   }
 else if ((PinNum>=0)&&(PinNum<7)){
  PinNum-=0;
  if(PinDirection==1){
   (*((ptr8)0x2A))=(*((ptr8)0x2A))|(1<<PinNum);
                     }
  else if(PinDirection==0){
   (*((ptr8)0x2A))=(*((ptr8)0x2A))&(~(1<<PinNum));
                          }
                                    }
}
