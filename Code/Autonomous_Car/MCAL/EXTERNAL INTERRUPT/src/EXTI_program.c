/*
 * EXTI_program.c
 *
 * Created: 09-Sep-23 11:30:36 AM
 *  Author:  SEIF EL-DIN SULTAN OSMAN 
 */ 
#define F_CPU 16000000UL
#include <util/delay.h>

#include "BIT_MATH.h"
#include "STD_TYPE.h"

#include "EXTI_private.h"
#include "EXTI_config.h"
#include "EXTI_interface.h"

static void (*PRIVATE_PtrCallBackInt0) (void) = NULL;
static void (*PRIVATE_PtrCallBackInt1) (void) = NULL;
static void (*PRIVATE_PtrCallBackInt2) (void) = NULL;

void EXTI_Enable(EXTI_InterruptSource InterruptSource ,EXTI_TriggerEdge TriggerEdge)
{
	switch(InterruptSource)
	{
		case EXTI_INT0:
		switch(TriggerEdge)
		{
			case EXTI_RISING_EDGE:
			SET_BIT(MCUCR,ISC00);
			SET_BIT(MCUCR,ISC01);
			break;
			
			case EXTI_FALLING_EDGE:
			CLR_BIT(MCUCR,ISC00);
			SET_BIT(MCUCR,ISC01);
			break;
			
			case EXTI_LOW_LEVEL:
			CLR_BIT(MCUCR,ISC00);
			CLR_BIT(MCUCR,ISC01);
			break;
			
			case EXTI_ANY_LOGICAL_CHANGE:
			SET_BIT(MCUCR,ISC00);
			CLR_BIT(MCUCR,ISC01);
			break;
		}
		SET_BIT(GICR,INT0);
		break;
		
		case EXTI_INT1:
		switch(TriggerEdge)
		{
			case EXTI_RISING_EDGE:
			SET_BIT(MCUCR,ISC10);
			SET_BIT(MCUCR,ISC11);
			break;
			
			case EXTI_FALLING_EDGE:
			CLR_BIT(MCUCR,ISC10);
			SET_BIT(MCUCR,ISC11);
			break;
			
			case EXTI_LOW_LEVEL:
			CLR_BIT(MCUCR,ISC10);
			CLR_BIT(MCUCR,ISC11);
			break;
			
			case EXTI_ANY_LOGICAL_CHANGE:
			SET_BIT(MCUCR,ISC10);
			CLR_BIT(MCUCR,ISC11);
			break;
		}
		SET_BIT(GICR,INT1);
		break;
		
		case EXTI_INT2:
		switch(TriggerEdge)
		{
			case EXTI_RISING_EDGE:
			SET_BIT(MCUCSR,ISC2);
			break;
			
			case EXTI_FALLING_EDGE:
			CLR_BIT(MCUCSR,ISC2);
			break;
		}
		SET_BIT(GICR,INT2);
		break;
	}
}

void EXTI_Disable(EXTI_InterruptSource InterruptSource)
{
	switch(InterruptSource)
	{
		case EXTI_INT0:
		CLR_BIT(GICR,INT0);
		break;
		
		case EXTI_INT1:
		CLR_BIT(GICR,INT1);
		break;
		
		case EXTI_INT2:
		CLR_BIT(GICR,INT2);
		break;
	}
	
}
void EXTI_SetCallBackInt0 (void (*PtrToFunc) (void))
{
	if( PtrToFunc!=NULL )
	{
		PRIVATE_PtrCallBackInt0=PtrToFunc;
	}
}
void EXTI_SetCallBackInt1 (void (*PtrToFunc) (void))
{
	if( PtrToFunc!=NULL )
	{
		PRIVATE_PtrCallBackInt1=PtrToFunc;
	}
}
void EXTI_SetCallBackInt2 (void (*PtrToFunc) (void))
{
	if( PtrToFunc!=NULL )
	{
		PRIVATE_PtrCallBackInt2=PtrToFunc;
	}
}


void  __vector_1(void) __attribute__((signal)); 
void  __vector_1(void)
{
	if (PRIVATE_PtrCallBackInt0 != NULL)
	{
		PRIVATE_PtrCallBackInt0();
	}
}

void  __vector_2(void) __attribute__((signal)); 
void  __vector_2(void)
{
	if (PRIVATE_PtrCallBackInt1 != NULL)
	{
		PRIVATE_PtrCallBackInt1();
	}
}

void  __vector_3(void) __attribute__((signal)); 
void  __vector_3(void)
{
	if (PRIVATE_PtrCallBackInt2 != NULL)
	{
		PRIVATE_PtrCallBackInt2();
	}
}