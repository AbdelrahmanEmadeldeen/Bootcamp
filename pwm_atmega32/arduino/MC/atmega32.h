/*
 * atmega32.h
 *
 * Created: 2/20/2019 5:32:27 PM
 *  Author: AVE-LAP-44
 */ 


#ifndef ATMEGA32_H_
#define ATMEGA32_H_
/* GPIO */
#define PORTA_START   0
#define PORTA_END     7  

#define PORTB_START   8
#define PORTB_END     15

#define PORTC_START   16
#define PORTC_END     23

#define PORTD_START   24
#define PORTD_END     31

#define PORTA (*((volatile ptr8)0x3B)) // address of portA (output)
#define DDRA  (*((volatile ptr8)0x3A))//address of ddrA (direction)
#define PINA  (*((volatile ptr8)0x39))//address of pinA	(input)

#define PORTB (*((volatile ptr8)0x38))// address of portB
#define DDRB  (*((volatile ptr8)0x37))//address of ddrB
#define PINB  (*((volatile ptr8)0x36))//address of pinB

#define PORTC (*((volatile ptr8)0x35))// address of portC
#define DDRC  (*((volatile ptr8)0x34))//address of ddrC
#define PINC  (*((volatile ptr8)0x33))//address of pinC

#define PORTD (*((volatile ptr8)0x32))// address of portD
#define DDRD  (*((volatile ptr8)0x31))//address of ddrD
#define PIND  (*((volatile ptr8)0x30))//address of pinD

/* Timer0*/
#define TCCR0 (*((volatile ptr8) 0x53))
#define OCR0  (*((volatile ptr8) 0x5C))
#define TIFR  (*((volatile ptr8)  0x58))
#define TCNT0 (*((volatile ptr8)  0x52))
#define TIMSK (*((volatile ptr8)  0x59))



/* Timer 1     */
/* 
Mode WGM13   WGM12    WGM11      WGM10   Timer/Counter Mode   TOP    OCR1x   TOV1Flag
            (CTC1)   (PWM11)    (PWM10)                              Update   Set on
            
 0    0       0        0           0          Normal         0xFFFF Immediate  MAX
 1    0       0        0           1        pwm_Phase8-bit   0x00FF   TOP     BOTTOM
 2    0       0        1           0        PWM_Phase9-bit   0x01FF   TOP     BOTTOM
 3    0       0        1           1        PWM_Phase10-bit  0x03FF   TOP     BOTTOM
 4    0       1        0           0           CTC           OCR1A  Immediate MAX
 5    0       1        0           1        Fast_PWM8-bit    0x00FF  BOTTOM   TOP
 6    0       1        1           0        Fast_PWM9-bit    0x01FF  BOTTOM   TOP
 7    0       1        1           1        Fast_PWM10-bit   0x03FF  BOTTOM   TOP
 8    1       0        0           0        PWM_Phase         ICR1   BOTTOM  BOTTOM
                                            &Frequency Correct
 9    1       0        0           1        PWM&Frequency     OCR1A  BOTTOM   BOTTOM
 10   1       0        1           0        PWMPhase Correct  ICR1    TOP     BOTTOM
 11   1       0        1           1        PWMPhase Correct  OCR1A   TOP     BOTTOM
 12   1       1        0           0            CTC           ICR1  Immediate MAX
 13   1       1        0           1           Reserved 
 14   1       1        1           0           Fast PWM       ICR1    BOTTOM  TOP
 15   1       1        1           1           Fast PWM       OCR1A   BOTTOM  TOP 
 */


/*Compare Output Mode, non-PWM
COM1A1/COM1B1 COM1A0/COM1B0 Description
    0               0       Normal port operation, OC1A/OC1B disconnected.
    0               1       Toggle OC1A/OC1B on compare match
    1               0       Clear OC1A/OC1B on compare match (Set output to low level)
    1               1       Set OC1A/OC1B on compare match (Set output to high level)
 */

/*
Compare Output Mode, Fast PWM
COM1A1/COM1B1 COM1A0/COM1B0 Description
      0             0       Normal port operation, OC1A/OC1B disconnected.
      0             1       WGM13:0 = 15: Toggle OC1A on Compare Match, 
	                        OC1B disconnected (normal port operation).
                            For all other WGM13:0 settings, normal port             
				               operation, OC1A/OC1B disconnected.
     
	  1             0       Clear OC1A/OC1B on compare match, set
                            OC1A/OC1B at BOTTOM,(non-inverting mode)
  
      1             1      Set OC1A/OC1B on compare match, clear
                           OC1A/OC1B at BOTTOM,(inverting mode)
						    */
/*
The FOC1A/FOC1B bits are only active when the WGM13:0 bits specifies a non-PWM mode.
However, for ensuring compatibility with future devices, these bits must be set to zero when
TCCR1A is written when operating in a PWM mode. When writing a logical one to the
FOC1A/FOC1B bit, an immediate compare match is forced on the Waveform Generation unit.
The OC1A/OC1B output is changed according to its COM1x1:0 bits setting. Note that the
FOC1A/FOC1B bits are implemented as strobes. Therefore it is the value present in the
COM1x1:0 bits that determine the effect of the forced compare.
*/
#define TCCR1A (*((volatile ptr8) 0x4F))   /*$2F ($4F) TCCR1A COM1A1 COM1A0 COM1B1 COM1B0 FOC1A FOC1B WGM11 WGM10 107 */
#define TCCR1B (*((volatile ptr8) 0x4E))   /*$2E ($4E) TCCR1B ICNC1 ICES1 – WGM13 WGM12 CS12 CS11 CS10 110 */
#define TCNT1H (*((volatile ptr8) 0x4D))   /*$2D ($4D) TCNT1H Timer/Counter1 – Counter Register High Byte 111 */
#define TCNT1L (*((volatile ptr8) 0x4C))   /*$2C ($4C) TCNT1L Timer/Counter1 – Counter Register Low Byte 111 */
#define OCR1AH (*((volatile ptr8) 0x4B))   /*$2B ($4B) OCR1AH Timer/Counter1 – Output Compare Register A High Byte 111 */
#define OCR1AL (*((volatile ptr8) 0x4A))   /*$2A ($4A) OCR1AL Timer/Counter1 – Output Compare Register A Low Byte 111 */
#define OCR1BH (*((volatile ptr8) 0x49))   /*$29 ($49) OCR1BH Timer/Counter1 – Output Compare Register B High Byte 111 */
#define OCR1BL (*((volatile ptr8) 0x48))   /*$28 ($48) OCR1BL Timer/Counter1 – Output Compare Register B Low Byte 111 */
#define ICR1H  (*((volatile ptr8) 0x47))   /*$27 ($47) ICR1H Timer/Counter1 – Input Capture Register High Byte 111 */
#define ICR1L  (*((volatile ptr8) 0x46))   /*$26 ($46) ICR1L Timer/Counter1 – Input Capture Register Low Byte 111*/
/*$2F ($4F) TCCR1A COM1A1 COM1A0 COM1B1 COM1B0 FOC1A FOC1B WGM11 WGM10 107 */
#define WGM10      BIT0
#define WGM11      BIT1
#define FOC1B      BIT2
#define FOC1A      BIT3
#define COM1B0     BIT4
#define COM1B1     BIT5
#define COM1A0     BIT6
#define COM1A1     BIT7
/*
CS12 CS11 CS10 Description
 0    0    0   No clock source (Timer/Counter stopped).
 0    0    1   clkI/O/1 (No prescaling)
 0    1    0   clkI/O/8 (From prescaler)
 0    1    1   clkI/O/64 (From prescaler)
 1    0    0   clkI/O/256 (From prescaler)
 1    0    1   clkI/O/1024 (From prescaler)
 1    1    0   External clock source on T1 pin. Clock on falling edge.
 1    1    1   External clock source on T1 pin. Clock on rising edge. 
 */
/*$2E ($4E) TCCR1B ICNC1 ICES1 – WGM13 WGM12 CS12 CS11 CS10 110 */

#define CS10       BIT0
#define CS11       BIT1
#define CS12       BIT2
#define WGM12      BIT3
#define WGM13      BIT4

#define ICES1      BIT6
#define ICNC1      BIT7


#endif /* ATMEGA32_H_ */