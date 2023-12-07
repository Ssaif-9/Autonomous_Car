/*
 * TM0_program.c
 *
 * Created: 9/16/2023 11:08:03 AM
 *  Author: ayman
 */ 


#include "../../../UTILITES/STD_TYPE.h"
#include "../../../UTILITES/BIT_MATH.h"



#include "../include/TM0_confg.h"
#include "../include/TM0_interface.h"
#include "../include/TM0_private.h"
#include "../../DIO/include/DIO_interface.h"


volatile static u16 private_ctcCounter=0;



static void (*p)(void)=NULL;

void TM0_init(void)
{
	#if TMR0_MODE == TMR0_NORMAL_MODE
	// select mode
	CLR_BIT(TCCR0,6);
	CLR_BIT(TCCR0,3);
	
	
	//select preload
	TCNT0=TMR0_PRELOAD_VALUE;
	
	// enable interrupt
	SET_BIT(TIMSK,0);
	#elif TMR0_MODE == TMR0_CTC_MODE
	// select mode
	CLR_BIT(TCCR0,6);
	SET_BIT(TCCR0,3);
	// enable interrupt
	SET_BIT(TIMSK,1);
	#elif TMR0_MODE == TMR0_FAST_PWM_MODE
	CLR_BIT(TCCR0,4);
	SET_BIT(TCCR0,5);
	
	
	SET_BIT(TCCR0,3);
	SET_BIT(TCCR0,6);
	
	
	#endif
	
}


void TM0_start(void)
{
	
	SET_BIT(TCCR0,0);
	SET_BIT(TCCR0,1);
	CLR_BIT(TCCR0,2);
}



void TM0_stop(void)
{
		CLR_BIT(TCCR0,0);
		CLR_BIT(TCCR0,1);
		CLR_BIT(TCCR0,2);	
}






void TMR0_setCompareMatchValue(u8 compareValue)
{
	OCR0= compareValue;
}



void TMR0_setDelayms_usingCTC(u16 delay_ms)
{
	
	// under condition tick time 4 Ms(prescaler 64)
	OCR0=249;
	private_ctcCounter=delay_ms;
	
	
}






void TM0_setCALLbACK(void(*ptr)(void))
{
	if(ptr !=NULL)
	p=ptr;
}






void  __vector_11(void) __attribute__((signal));
void  __vector_11(void)
{
	static u16 OVFcounter=0;
	OVFcounter++;

	p();
	
}



void  __vector_10(void) __attribute__((signal));
void  __vector_10(void)
{
	static u16 CTCcounter=0;
	CTCcounter++;
	if(CTCcounter == private_ctcCounter)
	{
		CTCcounter=0;
		p();
	}
	
}


void TMR0_setDutyCycle(u8 duty)
{
	
	OCR0= ((duty/100)*256)-1;
}