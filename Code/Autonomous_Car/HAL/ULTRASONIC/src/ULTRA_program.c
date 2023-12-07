/*
 * CFile1.c
 *
 * Created: 12/5/2023 1:37:38 PM
 *  Author: ayman
 */ 
#define F_CPU 16000000UL
#include <util/delay.h>

#include "../../../UTILITES/STD_TYPE.h"
#include "../../../UTILITES/BIT_MATH.h"

#include "../include/ULTRA_interface.h"

#include "../../../MCAL/TIMER0/include/TM0_interface.h"
#include "../../../MCAL/TIMER0/include/TM0_private.h"

#include "../../../MCAL/GLOBAL_INTERRUPT/include/GLBI_interfase.h"
#include "../../../MCAL/DIO/include/DIO_interface.h"
#include "../../../MCAL/EXTERNAL_INTERRUPT/include/EXTI_interface.h"




volatile float count_distance=0;
volatile u8 i=0;
volatile flag=0;
u16 NOVF=0;

void ULTRA_init()
{
			DIO_SetPinDirection   (DIO_PORTD, DIO_PIN2, DIO_PIN_INPUT);    //E
			DIO_SetPinDirection  (DIO_PORTB, DIO_PIN6, DIO_PIN_OUTPUT);  // T
			LCD_init();
			GLBI_Enable();
			TM0_init();
			EXTI_Enable(EXTI_INT0,EXTI_ANY_LOGICAL_CHANGE);
			TM0_setCALLbACK(&TAKE_NUM_OVF);
	
	
}

void ULTRA_Getdistance(f32 *distance)
{
	if(flag==0)
	{
	   DIO_SetPinValue(DIO_PORTB, DIO_PIN6, DIO_PIN_HIGH);
	   _delay_us(10);
	   DIO_SetPinValue(DIO_PORTB, DIO_PIN6, DIO_PIN_LOW);
	    flag=1;
	}		
		
		*distance=count_distance;
}

void  __vector_1(void) __attribute__((signal));
 void  __vector_1(void)
 {
		 i++;
		 if(i==1)
		 {
			  NOVF=0;
			  TM0_start();
		 }
		 
		 if(i==2)
		 {
			  TM0_stop();
			 count_distance=(TCNT0+((NOVF)*(256)))*(0.0686);
			 TCNT0=0;
			 i=0;
			flag=0;
			NOVF=0;
		 }
 }
 
 void TAKE_NUM_OVF(void)
 {
	 NOVF++;
 }