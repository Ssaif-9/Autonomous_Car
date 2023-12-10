/*
 * TIMER0_program.c
 *
 * Created: 16-Sep-23 11:04:44 AM
 *  Author: M5_Autonomous_Car_TEAM
 */

#include "../../../UTILITES/BIT_MATH.h"
#include "../../../UTILITES/STD_TYPE.h"
 
#include "../include/TIMER0_config.h"
#include "../include/TIMER0_interface.h"
#include "../include/TIMER0_private.h"

static void (*PRIVATE_PtrCallBackOverFlowFlag) (void) = NULL;
static void (*PRIVATE_PtrCallBackCTC) (void) = NULL;

volatile static u16  Private_CTC_Counter = 0 ;              //it pass to ISR so it is volatile 

void TMR0_init(void)
{
#if TIMER0_MODE == TIMER0_NormalMode
	
	/*Select mode = Normal Mode  */
	CLR_BIT(TCCR0,WGM00);
	CLR_BIT(TCCR0,WGM01);
	
	/* preload value */
	TCNT0 = TMR0_PreloadValue;
	
	/*enable OVf */
	SET_BIT(TIMSK,TOIE0);
	
	
#elif TIMER0_MODE== TIMER0_CTC
	
	/*Select mode = CTC */
	CLR_BIT(TCCR0,WGM00);
	SET_BIT(TCCR0,WGM01);
	
	/*enable OCMf */
	SET_BIT(TIMSK,OCIE0);
	
#elif TIMER0_MODE== TIMER0_FAST_PWM_MODE
	/*Select mode = FAST PWM MODE */
	SET_BIT(TCCR0,WGM00);
	SET_BIT(TCCR0,WGM01);
	
	#if FastPWM_Mode == FastPWM_NonInverting_Mode
	/* non inverting */
	CLR_BIT(TCCR0,COM00);
	SET_BIT(TCCR0,COM01);
	#elif FastPWM_Mode == FastPWM_Inverting_Mode
	/*  inverting */
	SET_BIT(TCCR0,COM00);
	SET_BIT(TCCR0,COM01);
    #endif

#endif
}

void TMR0_Start(void)
{
#if TIMER0_Prescaller==TIMER0_Prescaller_1
	SET_BIT(TCCR0,CS00);
	CLR_BIT(TCCR0,CS01);
	CLR_BIT(TCCR0,CS02);
	
#elif TIMER0_Prescaller==TIMER0_Prescaller_8
	CLR_BIT(TCCR0,CS00);
	SET_BIT(TCCR0,CS01);
	CLR_BIT(TCCR0,CS02);
	
#elif TIMER0_Prescaller==TIMER0_Prescaller_64
	SET_BIT(TCCR0,CS00);
	SET_BIT(TCCR0,CS01);
	CLR_BIT(TCCR0,CS02);
	
#elif TIMER0_Prescaller==TIMER0_Prescaller_256
	CLR_BIT(TCCR0,CS00);
	CLR_BIT(TCCR0,CS01);
	SET_BIT(TCCR0,CS02);
	
#elif TIMER0_Prescaller==TIMER0_Prescaller_1024
	SET_BIT(TCCR0,CS00);
	CLR_BIT(TCCR0,CS01);
	SET_BIT(TCCR0,CS02);

#endif
}

void TMR0_Stop(void)
{
	/*	Prescaller = 0	*/
	CLR_BIT(TCCR0,CS00);
	CLR_BIT(TCCR0,CS01);
	CLR_BIT(TCCR0,CS02);
}

// void TMR0_SetCompareMatchValue (u8 CompareValue)
// {
// 	OCR0=CompareValue;
// }

void TMR0_SetDelay_ms_UsingCTC(u16 Delay_ms)
{
	//	Under Condition Tick Time = 4MS   -> Prescaller 64
	OCR0 = 249 ;
	Private_CTC_Counter=Delay_ms;
}

void TMR0_SetCompareMatchValue_FastPWM_NonInverting(f32 DutyCycle)
{
	#if FastPWM_Mode == FastPWM_NonInverting_Mode
	/* non inverting */
	OCR0=((DutyCycle/100)*256)-1;          //TAKE CARE OVERFLOW 
	#elif FastPWM_Mode == FastPWM_Inverting_Mode
	/*  inverting */
	OCR0=((DutyCycle/100)*256)-1;          //TAKE CARE OVERFLOW 
	#endif
}

void TMR0_SetCallBackOverFlow (void (*PtrToFunc) (void))
{
	if( PtrToFunc!=NULL )
	{
		PRIVATE_PtrCallBackOverFlowFlag=PtrToFunc;
	}
}

void TMR0_SetCallBackCTC(void (*PtrToFunc)(void))
{
	if( PtrToFunc!=NULL )
	{
		PRIVATE_PtrCallBackCTC=PtrToFunc;
	}
}




void __vector_10(void) __attribute__((signal));
void __vector_10(void)
{
	static u16 CTC_Counter =0;
	CTC_Counter++;
	
	if( Private_CTC_Counter == CTC_Counter)
	{
		CTC_Counter = 0;
		if (PRIVATE_PtrCallBackCTC != NULL)
		{
			PRIVATE_PtrCallBackCTC();
		}
	}
	
}
