/*
 * TMR2_private.h
 *
 * Created: 24-Sep-23 10:34:52 PM
 *  Author: M5_Autonomous_Car_TEAM
 */ 


#ifndef TMR2_PRIVATE_H_
#define TMR2_PRIVATE_H_
 
#define TMR2_PRESCALLER_1                    0
#define TMR2_PRESCALLER_8                    1
#define TMR2_PRESCALLER_32                   2
#define TMR2_PRESCALLER_64                   3
#define TMR2_PRESCALLER_128                  4
#define TMR2_PRESCALLER_256                  5
#define TMR2_PRESCALLER_1024                 6

#define TMR2_NORMAL_MODE                     0
#define TMR2_PHASECORRECT_MODE               1
#define TMR2_CTC_MODE                        2
#define TMR2_FASTPWM_MODE                    3

#define TMR2_FastPWM_Inverting_Mode          0
#define TMR2_FastPWM_NonInverting_Mode       1
   
#define  TMR2_PaseCorrect_Inverting_Mode     0
#define  TMR2_PaseCorrect_NonInverting_Mode  1
                        
#define    TCCR2           (*(volatile u8*) 0x45)
#define    CS20            0
#define    CS21		       1
#define    CS22		       2
#define    WGM21		   3
#define    COM20		   4
#define    COM21		   5
#define    WGM20		   6
#define    FOC2            7
	       
#define    TCNT2           (*(volatile u8*) 0x44)
	       
#define    OCR2            (*(volatile u8*) 0x43)
	       
#define    ASSR            (*(volatile u8*) 0x42)
#define    TCR2UB           0
#define    OCR2UB		    1
#define    TCN2UB		    2
#define    AS2		        3
	       
	       
#define    TIMSK           (*(volatile u8*) 0x59)
#define    TOIE2		    6
#define    OCIE2            7
	       
#define    TIFR           (*(volatile u8*) 0x58)
#define    TOV2		      6
#define    OCF2           7
	       
#define    SFIOR          (*(volatile u8*) 0x50)
#define    PSR2            1

#endif /* TMR2_PRIVATE_H_ */