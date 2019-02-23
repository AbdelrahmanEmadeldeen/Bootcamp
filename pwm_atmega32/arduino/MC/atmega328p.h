/*
 * atmega328p.h
 *
 * Created: 2/22/2019 4:39:29 PM
 *  Author: AVE-LAP-44
 */ 


#ifndef ATMEGA328P_H_
#define ATMEGA328P_H_

#define PINB (*((ptr8)0x23))   // address of portB (Input)
#define DDRB (*((ptr8)0x24))    // address of portB (Direction)
#define PORTB (*((ptr8)0x25))   // address of portB (Output)

#define PORTB_START  8
#define PORTB_END    13

#define PINC (*((ptr8)0x26))   // address of portC (Input)
#define DDRC (*((ptr8)0x27))    // address of portC (Direction)
#define PORTC (*((ptr8)0x28))   // address of portC (output)

#define PORTC_START  14
#define PORTC_END    20

#define PIND (*((ptr8)0x29))  // address of portD (Input)
#define DDRD (*((ptr8)0x2A))   // address of portD (Direction)
#define PORTD (*((ptr8)0x2B))  // address of portD (Output)

#define PORTD_START   0
#define PORTD_END     7



#endif /* ATMEGA328P_H_ */