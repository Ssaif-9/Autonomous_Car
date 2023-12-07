/*
 * BUZZER_program.c
 *
 * Created: 18-Sep-23 9:45:05 PM
 *  Author: SEIF EL_DIN SULTAN
 */ 

/*UTILITES*/
#include "../../../UTILITES/STD_TYPE.h"
#include "../../../UTILITES/BIT_MATH.h"
/*MCAL*/
#include "../../../MCAL/DIO/include/DIO_config.h"
#include "../../../MCAL/DIO/include/DIO_interface.h"
#include "../../../MCAL/DIO/include/DIO_private.h"

/*HAL*/
#include "../include/BUZZER_config.h"
#include "../include/BUZZER_interface.h"
#include "../include/BUZZER_private.h"

void BUZZER_init(u8 BuzzerPort ,u8 BuzzerPin )
{
	if(BuzzerPort<=3 && BuzzerPin<=7)
	{
		DIO_SetPinDirection(BuzzerPort,BuzzerPin,DIO_PIN_OUTPUT);
	}
	else
	{
		//No Thing
	}
	
}


void BUZZER_TurnOn(u8 BuzzerPort ,u8 BuzzerPin )
{
	if(BuzzerPort<=3 && BuzzerPin<=7)
	{
		DIO_SetPinValue(BuzzerPort,BuzzerPin,DIO_PIN_HIGH);
	}
	else
	{
		//No Thing 
	}
}

void BUZZER_TurnOff(u8 BuzzerPort ,u8 BuzzerPin )
{
	if(BuzzerPort<=3 && BuzzerPin<=7)
	{
		DIO_SetPinValue(BuzzerPort,BuzzerPin,DIO_PIN_LOW);
	}
	else
	{
		//No Thing
	}
}	

void BUZZER_Toggle(u8 BuzzerPort ,u8 BuzzerPin )
{
	if(BuzzerPort<=3 && BuzzerPin<=7)
	{
		DIO_TogglePinValue(BuzzerPort,BuzzerPin);
	}
	else
	{
		//No Thing
	}
}
	