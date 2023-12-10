/*
 * TIMER1_private.h
 *
 * Created: 22-Sep-23 8:34:14 AM
 *  Author: M5_Autonomous_Car_TEAM
 */ 


#ifndef TIMER1_PRIVATE_H_
#define TIMER1_PRIVATE_H_

#define TCCR1A          (*(volatile u8*) 0x4F)
#define WGM10           0
#define WGM11           1
#define FOC1B           2
#define FOC1A           3
#define COM1B0          4
#define COM1B1          5
#define COM1A0          6
#define COM1A1          7

#define TCCR1B          (*(volatile u8*) 0x4E)
#define CS10            0
#define CS11            1
#define CS12            2
#define WGM12           3
#define WGM13           4
#define ICES1           6
#define ICNC1           7


#define TCNT1L          (*(volatile u16*) 0x4C)

#define OCR1AL          (*(volatile u16*) 0x4A)

#define OCR1BL          (*(volatile u16*) 0x48)

#define ICR1L           (*(volatile u16*) 0x46)

#define TIMSK           (*(volatile u8*) 0x59)
#define TOIE1           2
#define OCIE1B          3
#define OCIE1A          4
#define TICIE1          5

#define TIFR            (*(volatile u8*) 0x58)
#define TOV1            2
#define OCF1B           3
#define OCF1A           4
#define ICF1            5









#endif /* TIMER1_PRIVATE_H_ */