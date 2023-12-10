/*
 * ADC_program.c
 *
 * Created: 15-Sep-23 8:38:07 AM
 *  Author: M5_Autonomous_Car_TEAM
 */ 
#define F_CPU 16000000UL
#include <util/delay.h>

#include "../../../UTILITES/STD_TYPE.h"
#include "../../../UTILITES/BIT_MATH.h"

#include "../include/ADC_private.h"
#include "../include/ADC_config.h"
#include "../include/ADC_interface.h"

static void (*PRIVATE_PtrCallBackADC) (void) = NULL;

void ADC_init(u8 RefrenceVolt,u8 ADC_Prescaller)
{
	/*	Select reference voltage	*/
	switch (RefrenceVolt)
	{
		case ADC_REFERENCE_AREF:
		CLR_BIT(ADMUX,REFS0);
		CLR_BIT(ADMUX,REFS1);
		break;
		
		case ADC_REFERENCE_AVCC:
		SET_BIT(ADMUX,REFS0);
		CLR_BIT(ADMUX,REFS1);
		break;
		
		case ADC_REFERENCE_INTERNAL:
		SET_BIT(ADMUX,REFS0);
		SET_BIT(ADMUX,REFS1);
		break;
	}
	
	/*		ADCR	*/
	CLR_BIT(ADMUX,ADLAR);
	
	/*auto trigger mode (1) or single conversion mode (0) */
	CLR_BIT(ADCSRA,ADATE);
	
	/*	Interrupt enable	*/
	CLR_BIT(ADCSRA,ADIE);
	
	/*	Prescaller Select 128 for 16MHZ(125 KHZ)	*/
	
	if (ADC_Prescaller >= 2 && ADC_Prescaller <= 128 )
	{
		switch(ADC_Prescaller)
		{
			case ADC_Prescaller_2:
			CLR_BIT(ADCSRA,ADPS0);
			CLR_BIT(ADCSRA,ADPS1);
			CLR_BIT(ADCSRA,ADPS2);
			break;
			
			case ADC_Prescaller_4:
			CLR_BIT(ADCSRA,ADPS0);
			SET_BIT(ADCSRA,ADPS1);
			CLR_BIT(ADCSRA,ADPS2);
			break;
			
			case ADC_Prescaller_8:
			SET_BIT(ADCSRA,ADPS0);
			SET_BIT(ADCSRA,ADPS1);
			CLR_BIT(ADCSRA,ADPS2);
			break;
			
			case ADC_Prescaller_16:
			CLR_BIT(ADCSRA,ADPS0);
			CLR_BIT(ADCSRA,ADPS1);
			SET_BIT(ADCSRA,ADPS2);
			break;
			
			case ADC_Prescaller_32:
			SET_BIT(ADCSRA,ADPS0);
			CLR_BIT(ADCSRA,ADPS1);
			SET_BIT(ADCSRA,ADPS2);
			break;
			
			case ADC_Prescaller_64:
			CLR_BIT(ADCSRA,ADPS0);
			SET_BIT(ADCSRA,ADPS1);
			SET_BIT(ADCSRA,ADPS2);
			break;
			
			case ADC_Prescaller_128:
			SET_BIT(ADCSRA,ADPS0);
			SET_BIT(ADCSRA,ADPS1);
			SET_BIT(ADCSRA,ADPS2);
			break;
		}
	}
	else
	{
		//No Thing 
	}
	
	/*Enable ADC */                          //best in last line in function
	SET_BIT(ADCSRA,ADEN);
}

void ADC_ReadDigitalValue(u8 ChannelId ,u16* DigitalValue)
{
	if( DigitalValue != NULL && ChannelId <32 )
	{
		
		/*	type without 32 switch case but take care about #define of channel id */
// 		ADMUX & = 0xE0;
// 		ADMUX | = ChannelId;


		switch (ChannelId)
		{
			case ADC_CHANNEL_0:
			CLR_BIT(ADMUX,MUX0);
			CLR_BIT(ADMUX,MUX1);
			CLR_BIT(ADMUX,MUX2);
			CLR_BIT(ADMUX,MUX3);
			CLR_BIT(ADMUX,MUX4);
			break;
			
			case ADC_CHANNEL_1:
			SET_BIT(ADMUX,MUX0);
			CLR_BIT(ADMUX,MUX1);
			CLR_BIT(ADMUX,MUX2);
			CLR_BIT(ADMUX,MUX3);
			CLR_BIT(ADMUX,MUX4);
			break;
			
			case ADC_CHANNEL_2:
			CLR_BIT(ADMUX,MUX0);
			SET_BIT(ADMUX,MUX1);
			CLR_BIT(ADMUX,MUX2);
			CLR_BIT(ADMUX,MUX3);
			CLR_BIT(ADMUX,MUX4);
			break;
			
			case ADC_CHANNEL_3:
			SET_BIT(ADMUX,MUX0);
			SET_BIT(ADMUX,MUX1);
			CLR_BIT(ADMUX,MUX2);
			CLR_BIT(ADMUX,MUX3);
			CLR_BIT(ADMUX,MUX4);
			break;
			
			case ADC_CHANNEL_4:
			CLR_BIT(ADMUX,MUX0);
			CLR_BIT(ADMUX,MUX1);
			SET_BIT(ADMUX,MUX2);
			CLR_BIT(ADMUX,MUX3);
			CLR_BIT(ADMUX,MUX4);
			break;
			
			case ADC_CHANNEL_5:
			SET_BIT(ADMUX,MUX0);
			CLR_BIT(ADMUX,MUX1);
			SET_BIT(ADMUX,MUX2);
			CLR_BIT(ADMUX,MUX3);
			CLR_BIT(ADMUX,MUX4);
			break;
			
			case ADC_CHANNEL_6:
			CLR_BIT(ADMUX,MUX0);
			SET_BIT(ADMUX,MUX1);
			SET_BIT(ADMUX,MUX2);
			CLR_BIT(ADMUX,MUX3);
			CLR_BIT(ADMUX,MUX4);
			break;
			
			case ADC_CHANNEL_7:
			SET_BIT(ADMUX,MUX0);
			SET_BIT(ADMUX,MUX1);
			SET_BIT(ADMUX,MUX2);
			CLR_BIT(ADMUX,MUX3);
			CLR_BIT(ADMUX,MUX4);
			break;
		} 
		SET_BIT(ADCSRA,ADSC);                //start conversion 
		
		while( 0 == GET_BIT(ADCSRA,ADIF) );  //wait for flag set 1
		
		*DigitalValue=ADC_DATA;
		
		SET_BIT(ADCSRA,ADIF);                   //TO Clear flag again 
	}
	
}


void ADC_SetCallBackADC (void (*PtrToFunc) (void))
{
	if( PtrToFunc!=NULL )
	{
		PRIVATE_PtrCallBackADC=PtrToFunc;
	}
}

void  __vector_16(void) __attribute__((signal));
void  __vector_16(void)
{
	if (PRIVATE_PtrCallBackADC != NULL)
	{
		PRIVATE_PtrCallBackADC();
	}
}