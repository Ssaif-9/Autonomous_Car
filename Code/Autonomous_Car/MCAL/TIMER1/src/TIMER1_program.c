/*
 * TIMER1_program.c
 *
 * Created: 22-Sep-23 8:33:59 AM
 *  Author: M5_Autonomous_Car_TEAM
 */ 
#define F_CPU 16000000UL
#include <util/delay.h>

#include "../../../UTILITES/STD_TYPE.h"
#include "../../../UTILITES/BIT_MATH.h"


#include "../include/TIMER1_config.h"
#include "../include/TIMER1_interface.h"
#include "../include/TIMER1_private.h"


void TMR1_init(void)
{
	/*Select Mode : mode 14  */
	CLR_BIT(TCCR1A,WGM10);
	SET_BIT(TCCR1A,WGM11);
	SET_BIT(TCCR1B,WGM12);
	SET_BIT(TCCR1B,WGM13);
	
	CLR_BIT(TCCR1A,COM1A0);
	SET_BIT(TCCR1A,COM1A1);
	
	CLR_BIT(TCCR1A,COM1B0);
	SET_BIT(TCCR1A,COM1B1);
}

void TMR1_Start(void)
{
	/*select prescaler : 64*/
	
	SET_BIT(TCCR1B,CS10);
	SET_BIT(TCCR1B,CS11);
	CLR_BIT(TCCR1B,CS12);
}


void TMR1_Stop(void)
{
	CLR_BIT(TCCR1B,CS10);
	CLR_BIT(TCCR1B,CS11);
	CLR_BIT(TCCR1B,CS12);
}


void TMR1_SetDutyCycle_And_Freq_Value(u16 Freq ,f32 Duty)
{
	// 	OCR1BL=Duty;
	if(Duty<=100)
	{
		ICR1L =((1000000UL/Freq)/4)-1;
		OCR1AL=((Duty*(ICR1L+1))/100.0)-1;
	}
}