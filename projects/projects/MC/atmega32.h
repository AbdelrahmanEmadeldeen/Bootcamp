/*
 * atmega32.h
 *Description: The file Contain the Memory addresses for AVR Atmega 32
 * Created: 2/20/2019 5:32:27 PM
 *  Author: Emad
 */ 


#ifndef ATMEGA32_H_
#define ATMEGA32_H_
#define F_CPU 16000000UL
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

/* 
 Clock Select Bit Description
CS02    CS01     CS00              Description
  0       0       0                No clock source (Timer/Counter stopped).
  0       0       1                clkI/O/(No prescaling)
  0       1       0                clkI/O/8 (From prescaler)
  0       1       1                clkI/O/64 (From prescaler)
  1       0       0                clkI/O/256 (From prescaler)
  1       0       1                clkI/O/1024 (From prescaler)
  1       1       0                External clock source on T0 pin. Clock on falling edge.
  1       1       1                External clock source on T0 pin. Clock on rising edge.

*/
/*
Compare Output Mode, non-PWM Mode
COM01    COM00      Description
 0        0         Normal port operation, OC0 disconnected.
 0        1         Toggle OC0 on compare match
 1        0         Clear OC0 on compare match
 1        1         Set OC0 on compare match */

/*
Compare Output Mode, Fast PWM Mode
COM01    COM00      Description
 0        0         Normal port operation, OC0 disconnected.
 0        1         Reserved
 1        0         Clear OC0 on compare match, set OC0 at BOTTOM,
                            (non-inverting mode)
 1        1         Set OC0 on compare match, clear OC0 at BOTTOM,
                    (inverting mode  
*/
/*
Compare Output Mode, Phase Correct PWM Mode
COM01   COM00       Description
 0        0         Normal port operation, OC0 disconnected.
 0        1         Reserved
 1        0         Clear OC0 on compare match when up-counting. Set OC0 on compare
                    match when downcounting.
 1        1         Set OC0 on compare match when up-counting. Clear OC0 on compare
                    match when downcounting
*/
/*
Waveform Generation Mode Bit Description
Mode   WGM01      WGM00         Timer/Counter Mode      TOP    Update of       TOV0 Flag
      (CTC0)     (PWM0)                                          OCR0            Set-on
 
0       0          0                Normal              0xFF    Immediate          MAX
1       0          1                PWM-Phase Correct   0xFF     TOP              BOTTOM
2       1          0                CTC                 OCR0    Immediate          MAX
3       1          1                Fast,PWM            0xFF    BOTTOM             MAX
*/

/* FOC0 active when the WGM00 bit specifies a non-PWM mode */
/* $33 ($53) TCCR0 FOC0 WGM00 COM01 COM00 WGM01 CS02 CS01 CS00 80 */
#define TCCR0 (*((volatile ptr8) 0x53))
#define CS00      BIT0
#define CS01      BIT1
#define CS02      BIT2
#define WGM01     BIT3
#define COM00     BIT4
#define COM01     BIT5
#define WGM00     BIT6
#define FOC0      BIT7

/*$39 ($59) TIMSK OCIE2 TOIE2 TICIE1 OCIE1A OCIE1B TOIE1 OCIE0 TOIE0 82, 112, 130  */
#define TIMSK      (*((volatile ptr8)  0x59))
#define TOIE0      BIT0
#define OCIE0      BIT1
#define TOIE1      BIT2
#define OCIE1B     BIT3
#define OCIE1A     BIT4
#define TICIE1     BIT5
#define TOIE2      BIT6
#define OCIE2      BIT7




/* $38 ($58) TIFR OCF2 TOV2 ICF1 OCF1A OCF1B TOV1 OCF0 TOV0 83, 112, 130 */
#define TIFR  (*((volatile ptr8)  0x58))
#define TOV0      BIT0
#define OCF0      BIT1
#define TOV1      BIT2
#define OCF1B     BIT3
#define OCF1A     BIT4
#define ICF1      BIT5
#define TOV2      BIT6
#define OCF2      BIT7

/* $32 ($52) TCNT0 Timer/Counter0 (8 Bits) 82 */
#define TCNT0 (*((volatile ptr8)  0x52))

/* $3C ($5C) OCR0 Timer/Counter0 Output Compare Register 82 */
#define OCR0  (*((volatile ptr8) 0x5C))


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

/*  UART */

/* $0B ($2B) UCSRA RXC TXC UDRE FE DOR PE U2X MPCM 158 
*/
#define UCSRA (*((volatile ptr8) 0x2B)) 

#define  MPCM          BIT0   /* Bit 0 – MPCM: Multi-processor Communication Mode */
#define  U2X           BIT1   /* Bit 1 – U2X: Double the USART Transmission Speed */
#define  PE            BIT2   /* Bit 2 – PE: Parity Error */
#define  DOR           BIT3   /* Bit 3 – DOR: Data OverRun */
#define  FE            BIT4   /* Bit 4 – FE: Frame Error */
#define  UDRE          BIT5   /* Bit 5 – UDRE: USART Data Register Empty */
#define  TXC           BIT6   /* Bit 6 – TXC: USART Transmit Complete */
#define  RXC           BIT7   /* Bit 7 – RXC: USART Receive Complete */

/*$0A ($2A) UCSRB RXCIE TXCIE UDRIE RXEN TXEN UCSZ2 RXB8 TXB8 159
*/
#define  UCSRB   (*((volatile ptr8) 0x2A))
#define  TXB8          BIT0   /* Bit 0 – TXB8: Transmit Data Bit 8 */
#define  RXB8          BIT1   /* Bit 1 – RXB8: Receive Data Bit 8 */
#define  UCSZ2         BIT2   /* Bit 2 – UCSZ2: Character Size */
#define  TXEN          BIT3   /* Bit 3 – TXEN: Transmitter Enable */
#define  RXEN          BIT4   /* Bit 4 – RXEN: Receiver Enable */
#define  UDRIE         BIT5   /* Bit 5 – UDRIE: USART Data Register Empty Interrupt Enable */
#define  TXCIE         BIT6   /* Bit 6 – TXCIE: TX Complete Interrupt Enable */
#define  RXCIE         BIT7   /* Bit 7 – RXCIE: RX Complete Interrupt Enable */


/* $20(2) ($40)(2) UBRRH URSEL  –     –     – UBRR[11:8]              162
                   UCSRC URSEL UMSEL UPM1 UPM0 USBS UCSZ1 UCSZ0 UCPOL 160
*/


/*
UPM1 UPM0 Parity Mode
 0     0  Disabled
 0     1  Reserved
 1     0 Enabled, Even Parity
 1     1 Enabled, Odd Parity
 */


/*USBS Stop Bit(s)
  0    1-bit
  1    2-bit 
 */
/*  
UCSZ Bits Settings
UCSZ2    UCSZ1     UCSZ0   Character Size
 0         0        0      5-bit
 0         0        1      6-bit
 0         1        0      7-bit
 0         1        1      8-bit
 1         0        0      Reserved
 1         0        1      Reserved
 1         1        0      Reserved
 1         1        1      9-bit
*/

/*
UCPOL     Transmitted Data Changed            Received Data Sampled
            (Output of TxD Pin)                 (Input on RxD Pin)
			
0            Rising XCK Edge                     Falling XCK Edge
1            Falling XCK Edge                    Rising XCK Edge


 */
#define   UCSRC   (*((volatile ptr8) 0x40))
#define   UBRRH   (*((volatile ptr8) 0x40))

#define  UCPOL          BIT0
#define  UCSZ0          BIT1
#define  UCSZ1          BIT2
#define  USBS           BIT3
#define  UPM0           BIT4
#define  UPM1           BIT5    
#define  UMSEL          BIT6    /* Bit 6 – UMSEL: USART Mode Select 0 Asynchronous Operation 1 Synchronous Operation */
#define  URSEL          BIT7    /* Bit 7 – URSEL: Register Select URSEL=1 to write as UCSRC URSEL = 0 to write in UBRRH */


/*
$09 ($29) UBRRL USART Baud Rate Register Low Byte 162
*/

#define UBRRL   (*((volatile ptr8) 0x29))


/*$ 0C ($2C) UDR USART I/O Data Register */
#define UDR (*((volatile ptr8) 0x2C))

/* Timer 2 */



/* 
 Clock Select Bit Description
CS22    CS21     CS20              Description
  0       0       0                No clock source (Timer/Counter stopped).
  0       0       1                clkI/O/     (No prescaling)
  0       1       0                clkI/O/8    (From prescaler)
  0       1       1                clkI/O/32   (From prescaler)
  1       0       0                clkI/O/64   (From prescaler)
  1       0       1                clkI/O/128  (From prescaler)
  1       1       0                clkI/O/256  (From prescaler)
  1       1       1                clkI/O/1024 (From prescaler)
*/
/*
Compare Output Mode, non-PWM Mode
COM21    COM20      Description
 0        0         Normal port operation, OC2 disconnected.
 0        1         Toggle OC2 on compare match
 1        0         Clear OC2 on compare match
 1        1         Set OC2 on compare match */

/*
Compare Output Mode, Fast PWM Mode
COM21    COM20      Description
 0        0         Normal port operation, OC2 disconnected.
 0        1         Reserved
 1        0         Clear OC2 on compare match, set OC2 at BOTTOM,
                            (non-inverting mode)
 1        1         Set OC2 on compare match, clear OC2 at BOTTOM,
                    (inverting mode  
*/
/*
Compare Output Mode, Phase Correct PWM Mode
COM21   COM20       Description
 0        0         Normal port operation, OC2 disconnected.
 0        1         Reserved
 1        0         Clear OC2 on compare match when up-counting. Set OC2 on compare
                    match when downcounting.
 1        1         Set OC2 on compare match when up-counting. Clear OC2 on compare
                    match when downcounting
*/
/*
Waveform Generation Mode Bit Description
Mode   WGM21      WGM20         Timer/Counter Mode      TOP    Update of       TOV0 Flag
      (CTC2)     (PWM2)                                          OCR0            Set-on
 
0       0          0                Normal              0xFF    Immediate          MAX
1       0          1                PWM-Phase Correct   0xFF     TOP              BOTTOM
2       1          0                CTC                 OCR2    Immediate          MAX
3       1          1                Fast,PWM            0xFF    BOTTOM             MAX
*/

/* FOC2 active when the WGM00 bit specifies a non-PWM mode */

/* $25 ($45) TCCR2 FOC2 WGM20 COM21 COM20 WGM21 CS22 CS21 CS20 123 */
#define TCCR2 (*((volatile ptr8) 0x45))
#define CS20      BIT0
#define CS21      BIT1
#define CS22      BIT2
#define WGM21     BIT3
#define COM20     BIT4
#define COM21     BIT5
#define WGM20     BIT6
#define FOC2      BIT7


/* $24 ($44) TCNT2 Timer/Counter2 (8 Bits) 125 */
#define TCNT2 (*((volatile ptr8)  0x44))

/* $23 ($43) OCR2 Timer/Counter2 Output Compare Register 125 */
#define OCR2  (*((volatile ptr8) 0x43))






#endif /* ATMEGA32_H_ */