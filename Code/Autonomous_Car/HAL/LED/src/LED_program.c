/*
 * LedProgram.c
 *
 * Created: 01-Sep-23 9:43:55 PM
 *  Author: SEIF EL_DIN SULTAN
 */ 

/*UTILITES*/
#include "STD_TYPE.h"
#include "BIT_MATH.h"
/*MCAL*/
#include "DIO_private.h"
#include "DIO_interface.h"
/*HAL*/
#include "LED_interface.h"
#include "LED_config.h"


void LED_init(u8 LedPort,u8 LedPin)
{
	if (LedPort <=3 && LedPin<=7)
	{
		DIO_SetPinDirection(LedPort,LedPin,DIO_PIN_OUTPUT);
	}
	
	else
	{
		//No Thing
	}
}


void LED_TurnON(u8 LedPort,u8 LedPin)
{
	if (LedPort <=3 && LedPin<=7)
	{
		DIO_SetPinValue(LedPort,LedPin,DIO_PIN_HIGH);
	}
	
	else
	{
		//No Thing
	}
}


void LED_TurnOFF(u8 LedPort,u8 LedPin)
{
	if (LedPort <=3 && LedPin<=7)
	{
		DIO_SetPinValue(LedPort,LedPin,DIO_PIN_LOW);
	}
	
	else
	{
		//No Thing
	}
}


void LED_Toggle(u8 LedPort,u8 LedPin)
{
	 if (LedPort <=3 && LedPin<=7)
	 {
		DIO_TogglePinValue(LedPort,LedPin);
	 }
	 
	 else
	 {
		 //No Thing
	 }
}

