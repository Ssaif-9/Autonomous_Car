/*
 * TMR2_program.c
 *
 * Created: 24-Sep-23 10:34:16 PM
 *  Author: SEIF EL-DIN SOLTAN
 */ 

#include "../../../UTILITES/STD_TYPE.h"
#include "../../../UTILITES/BIT_MATH.h"

#include "../include/TMR2_config.h"
#include "../include/TMR2_interface.h"
#include "../include/TMR2_private.h"

static void (*PRIVATE_PtrCallBackOverFlowFlag) (void) = NULL;
static void (*PRIVATE_PtrCallBackCTC) (void) = NULL;

volatile static u16  Private_CTC_Counter = 0 ;     

         
void TMR2_init()
{
	#if TMR2_MODE == TMR2_NORMAL_MODE
	
	/*Select mode = Normal Mode  */
	CLR_BIT(TCCR2,WGM20);
	CLR_BIT(TCCR2,WGM21);
	
	/* preload value */
	TCNT2 = TMR2_PreloadValue;
	
	/*enable OVf */
	SET_BIT(TIMSK,TOIE2);
	
	
	#elif TMR2_MODE == TMR2_CTC_MODE
	
	/*Select mode = CTC */
	CLR_BIT(TCCR2,WGM20);
	SET_BIT(TCCR2,WGM21);
	
	/*enable OCMf */
	SET_BIT(TIMSK,OCIE2);
	
	#elif TMR2_MODE == TMR2_FASTPWM_MODE
	
	/*Select mode = FAST PWM MODE */
	SET_BIT(TCCR2,WGM20);
	SET_BIT(TCCR2,WGM21);
	
	#if TMR2_SelectFastPWM_Mode == TMR2_FastPWM_NonInverting_Mode
	/* non inverting */
	CLR_BIT(TCCR2,COM20);
	SET_BIT(TCCR2,COM21);
	#elif TMR2_SelectFastPWM_Mode == TMR2_FastPWM_Inverting_Mode
	/*  inverting */
	SET_BIT(TCCR2,COM20);
	SET_BIT(TCCR2,COM21);
	#endif

	#elif TMR2_MODE == TMR2_PHASECORRECT_MODE
	
	/*Select mode = Phase Correct MODE */
	SET_BIT(TCCR2,WGM20);
	CLR_BIT(TCCR2,WGM21); 
	
	#if TMR2_SelectFastPWM_Mode == TMR2_FastPWM_NonInverting_Mode
	/* non inverting */
	CLR_BIT(TCCR2,COM20);
	SET_BIT(TCCR2,COM21);
	#elif TMR2_SelectFastPWM_Mode == TMR2_FastPWM_Inverting_Mode
	/*  inverting */
	SET_BIT(TCCR2,COM20);
	SET_BIT(TCCR2,COM21);
	#endif

	#endif
	
}

void TMR2_Start()
{
#if TMR2_PRESCALLER == TMR2_PRESCALLER_1
	SET_BIT(TCCR2,CS20);
	CLR_BIT(TCCR2,CS21);
	CLR_BIT(TCCR2,CS22);

#elif TMR2_PRESCALLER == TMR2_PRESCALLER_8
	CLR_BIT(TCCR2,CS20);
	SET_BIT(TCCR2,CS21);
	CLR_BIT(TCCR2,CS22);
	
#elif TMR2_PRESCALLER == TMR2_PRESCALLER_32
	SET_BIT(TCCR2,CS20);
	SET_BIT(TCCR2,CS21);
	CLR_BIT(TCCR2,CS22);
	
#elif TMR2_PRESCALLER == TMR2_PRESCALLER_64
	CLR_BIT(TCCR2,CS20);
	CLR_BIT(TCCR2,CS21);
	SET_BIT(TCCR2,CS22);
	
#elif TMR2_PRESCALLER == TMR2_PRESCALLER_128
	SET_BIT(TCCR2,CS20);
	CLR_BIT(TCCR2,CS21);
	SET_BIT(TCCR2,CS22);
	
#elif TMR2_PRESCALLER == TMR2_PRESCALLER_256
	CLR_BIT(TCCR2,CS20);
	SET_BIT(TCCR2,CS21);
	SET_BIT(TCCR2,CS22);
	
#elif TMR2_PRESCALLER == TMR2_PRESCALLER_1024
	SET_BIT(TCCR2,CS20);
	SET_BIT(TCCR2,CS21);
	SET_BIT(TCCR2,CS22);
	
#endif	
}

void TMR2_Stop()
{
	CLR_BIT(TCCR2,CS20);
	CLR_BIT(TCCR2,CS21);
    CLR_BIT(TCCR2,CS22);
}	

void TMR2_SetDelay_ms_UsingCTC(u16 Delay_ms)
{
	//	Under Condition Tick Time = 4MS   -> Prescaller 64
	
	OCR2 = 249 ;
	Private_CTC_Counter=Delay_ms;
}


void TMR2_SetDutyCycleValue_FastPWM (f32 DutyCycle)
{
	#if TMR2_SelectFastPWM_Mode == TMR2_FastPWM_NonInverting_Mode
	/* non inverting */
	OCR2=((DutyCycle/100)*256)-1;          //TAKE CARE OVERFLOW
	#elif TMR2_SelectFastPWM_Mode == TMR2_FastPWM_Inverting_Mode
	/*  inverting */
	OCR2=(255-(256*(DutyCycle/100)));          //TAKE CARE OVERFLOW
	#endif
}

void TMR2_SetDutyCycleValue_PhaseCorrect(f32 DutyCycle)
{
	#if TMR2_SelectPaseCorrect_Mode == TMR2_PaseCorrect_NonInverting_Mode
	/* non inverting */
	OCR2=((DutyCycle/100)*256);          //TAKE CARE OVERFLOW
	#elif TMR2_SelectPaseCorrect_Mode == TMR2_PaseCorrect_Inverting_Mode
	/*  inverting */
	OCR2=(256-(256*(DutyCycle/100)));          //TAKE CARE OVERFLOW
	#endif
}
void TMR2_SetCallBackOverFlow(void (*PtrToFunc)(void))
{
	if( PtrToFunc!=NULL )
	{
		PRIVATE_PtrCallBackOverFlowFlag=PtrToFunc;
	}
}

void TMR2_SetCallBackCTC(void (*PtrToFunc)(void))
{
	if( PtrToFunc!=NULL )
	{
		PRIVATE_PtrCallBackCTC=PtrToFunc;
	}
}

void __vector_5(void) __attribute__((signal));
void __vector_5(void)
{
	static u16 OverFlowCounter =0;
	OverFlowCounter++;
	
	if( TMR2_OverFlowCounter == OverFlowCounter)
	{
		OverFlowCounter = 0;
		TCNT2 = TMR2_PreloadValue;
		if (PRIVATE_PtrCallBackOverFlowFlag != NULL)
		{
			PRIVATE_PtrCallBackOverFlowFlag();
		}
	}
	
}

void __vector_4(void) __attribute__((signal));
void __vector_4(void)
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