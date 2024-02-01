/*
 * ULTRASONIC_program.c
 *
 * Created: 05-Nov-23 2:52:15 PM
 *  Author: SEIF EL-DIN SOLTAN
 */ 

#define F_CPU 16000000UL
#include <util/delay.h>

#include "../../../UTILITES/BIT_MATH.h"
#include "../../../UTILITES/STD_TYPE.h"


#include "../../../MCAL/DIO/include/DIO_config.h"
#include "../../../MCAL/DIO/include/DIO_interface.h"
#include "../../../MCAL/DIO/include/DIO_private.h"

#include "../../../MCAL/TIMER0/include/TIMER0_config.h"
#include "../../../MCAL/TIMER0/include/TIMER0_interface.h"
#include "../../../MCAL/TIMER0/include/TIMER0_private.h"

#include "../../../MCAL/GLOBAL_INTERRUPT/include/GLBI_config.h"
#include "../../../MCAL/GLOBAL_INTERRUPT/include/GLBI_interfase.h"
#include "../../../MCAL/GLOBAL_INTERRUPT/include/GLBI_private.h"

#include "../../../MCAL/EXTERNAL_INTERRUPT/include/EXTI_config.h"
#include "../../../MCAL/EXTERNAL_INTERRUPT/include/EXTI_interface.h"
#include "../../../MCAL/EXTERNAL_INTERRUPT/include/EXTI_private.h"

#include "../include/ULTRASONIC_config.h"
#include "../include/ULTRASONIC_interface.h"
#include "../include/ULTRASONIC_private.h"


u8 sensor_working=0;
u8 rising_edge=0;
u32 timer_counter=0;
f64 distance;



void Ultrasonic_init(void)
{
	DIO_SetPinDirection(ULTRASONIC_TRIGGER_PORT,ULTRASONIC_TRIGGER_PIN,DIO_PIN_OUTPUT);
	DIO_SetPinDirection(ULTRASONIC_ECHO_PORT,ULTRASONIC_ECHO_PIN,DIO_PIN_INPUT);
	DIO_SetPinValue(ULTRASONIC_ECHO_PORT,ULTRASONIC_ECHO_PIN,DIO_PIN_HIGH);
	EXTI_Enable(EXTI_INT1,EXTI_ANY_LOGICAL_CHANGE);
	TMR0_init();
	TMR0_Start();
}

void Ultrasonic_ReadDistance(f64* DistanceValue)
{
	if (!sensor_working)
	{
		DIO_SetPinValue(ULTRASONIC_TRIGGER_PORT,ULTRASONIC_TRIGGER_PIN,DIO_PIN_HIGH);
		_delay_us(15);
		DIO_SetPinValue(ULTRASONIC_TRIGGER_PORT,ULTRASONIC_TRIGGER_PIN,DIO_PIN_LOW);
		sensor_working=1;

	}		
	*DistanceValue=distance;	
}


void  __vector_2(void) __attribute__((signal));
void  __vector_2(void)
{
	if(sensor_working==1)
	{
		if (rising_edge==0)
		{
			TCNT0=0X00;
			rising_edge=1;
			timer_counter=0;
		}
		else
		{
			distance=(343*(timer_counter*256+TCNT0)/320000)+1;
			_delay_ms(40);
			timer_counter=0;
			rising_edge=0;
		}
	}
}


void __vector_11(void) __attribute__((signal));
void __vector_11(void)
{
	timer_counter++;
	if( timer_counter >1462)
	{
		TCNT0 = 0x00;
		sensor_working=0;
		rising_edge=0;
		timer_counter=0;
	}
	
}