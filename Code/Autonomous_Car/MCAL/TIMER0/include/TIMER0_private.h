/*
 * TIMER0_private.h
 *
 * Created: 16-Sep-23 11:05:23 AM
 *  Author: M5_Autonomous_Car_TEAM
 */ 


#ifndef TIMER0_PRIVATE_H_
#define TIMER0_PRIVATE_H_

#define TIMER0_NormalMode         1
#define TIMER0_CTC                2
#define TIMER0_FAST_PWM_MODE      3

#define TIMER0_Prescaller_1       1
#define TIMER0_Prescaller_8       2
#define TIMER0_Prescaller_64      3
#define TIMER0_Prescaller_256     4 
#define TIMER0_Prescaller_1024    5

#define FastPWM_NonInverting_Mode 1
#define FastPWM_Inverting_Mode    2

#define TCCR0         (*(volatile u8*) 0x53)
#define CS00          0
#define CS01          1
#define CS02          2
#define WGM01         3
#define COM00         4
#define COM01         5
#define WGM00         6
#define FOC0          7

/*Timer/Counter Register*/
#define TCNT0         (*(volatile u8*) 0x52)

/**/
#define OCR0          (*(volatile u8*) 0x5c)

#define TIMSK         (*(volatile u8*) 0x59)
#define TOIE0         0
#define OCIE0         1

#define TIFR          (*(volatile u8*) 0x58)
#define TOV0          0
#define OCF0          1

#endif /* TIMER0_PRIVATE_H_ */