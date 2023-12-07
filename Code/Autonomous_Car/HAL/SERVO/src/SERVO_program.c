/*
 * SERVO_program.c
 *
 * Created: 12/7/2023 12:35:19 PM
 *  Author: Abdullah Ashraf
 */ 


#include "../include/SERVO_interface.h"

void SERVO_init(void)
{
	TMR1_init();
	DIO_SetPinDirection(DIO_PORTD, DIO_PIN5, DIO_PIN_OUTPUT);
	//DIO_setPinDirection(SERVO_ENABLE_PORT, SERVO_ENABLE_PIN, DIO_PIN_INPUT);
	//DIO_setPinValue(SERVO_ENABLE_PORT, SERVO_ENABLE_PIN, DIO_PIN_HIGH);
	TMR1_start();
}


void SERVO_Left(void)
{
	
	TMR1_setFastPWM_usingMode14(2,50);
}

void SERVO_Right(void)
{	
	TMR1_setFastPWM_usingMode14(12,50);
}

void SERVO_Forward(void)
{
	TMR1_setFastPWM_usingMode14(7,50);
}

void SERVO_AnyAngle(u8 AngleinDegrees)
{
	if(AngleinDegrees <= 180 && AngleinDegrees >= 0)
	{
		f32 Duty = ( (f32)AngleinDegrees/18.0 ) + 2.0;
		TMR1_setFastPWM_usingMode14(Duty,50);
	}
}
