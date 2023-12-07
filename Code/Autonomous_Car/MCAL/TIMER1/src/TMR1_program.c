/*
 * TMR1_program.c
 *
 * Created: 10/13/2023 9:37:38 AM
 *  Author: ayman
 */ 

#include "../../../UTILITES/STD_TYPE.h"
#include "../../../UTILITES/BIT_MATH.h"


#include "../include/TMR1_interface.h"
#include "../include/TMR1_private.h"




void TMR1_init()
{
	/// choose normal mode
		CLR_BIT(TCCR1A,WGM10);
		CLR_BIT(TCCR1A,WGM11);
		CLR_BIT(TCCR1B,WGM12);
		CLR_BIT(TCCR1B,WGM13);
		
		// prescaler
		SET_BIT(TCCR1B,0);
		SET_BIT(TCCR1B,1);
		CLR_BIT(TCCR1B,2);
	/// select preload 
	TCNT1_u16=0;
	// enable interrrupt
	SET_BIT(TIMSK,2);
	
	/*
	// CHOOSE MODE 14
	CLR_BIT(TCCR1A,WGM10);
	SET_BIT(TCCR1A,WGM11);
	SET_BIT(TCCR1B,WGM12);
	SET_BIT(TCCR1B,WGM13);
	
	// NON-INVERTING
	CLR_BIT(TCCR1A,COM1A0);
	SET_BIT(TCCR1A,COM1A1);	
	
	// total period time =20 ms
	//ICR1_u16=4999;
	*/
}




void TMR1_start()
{
	
		SET_BIT(TCCR1B,CS10);
		SET_BIT(TCCR1B,CS11);
		CLR_BIT(TCCR1B,CS12);
}



void TMR1_stop()
{
			CLR_BIT(TCCR1B,CS10);
			CLR_BIT(TCCR1B,CS11);
			CLR_BIT(TCCR1B,CS12);
	
}




void TMR1_setCompareMatchValueA(u16 compareValue)
{
	OCR1A_u16 = compareValue;
}




void TMR1_setFastPWM_usingMode14(f32 dutyCycle , u16 frequency)
{
	if (dutyCycle<=100)
	{
		
	ICR1_u16 =((1000000UL/frequency)/4)-1;
	OCR1A_u16=((dutyCycle*(ICR1_u16+1))/100.0)-1;
	}	
}