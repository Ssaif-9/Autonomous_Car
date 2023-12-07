/*
 * TM0_private.h
 *
 * Created: 9/16/2023 11:09:00 AM
 *  Author: ayman
 */ 


#ifndef TM0_PRIVATE_H_
#define TM0_PRIVATE_H_



#define TCCR0             (*(volatile u8*)0x53)
#define TCNT0             (*(volatile u8*)0x52)
#define OCR0              (*(volatile u8*)0x5C)
#define TIFR              (*(volatile u8*)0x58)
#define TIMSK             (*(volatile u8*)0x59)
#define OCR0              (*(volatile u8*)0x5C)



#define CS00       0
#define CS01       1
#define CS02       2 
#define WGM01      3      
#define WGM00      6  
#define COM00      4
#define COm01      5
#define FOC0       7
    





#endif /* TM0_PRIVATE_H_ */