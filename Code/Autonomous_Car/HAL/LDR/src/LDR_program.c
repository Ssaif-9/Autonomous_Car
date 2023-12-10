/*
 * LDR_program.c
 *
 * Created: 07-Dec-23 10:42:50 PM
 *  Author: M5_Autonomous_Car_TEAM
 */ 

#define F_CPU 16000000UL
#include <util/delay.h>

#include "../../../UTILITES/STD_TYPE.h"
#include "../../../UTILITES/BIT_MATH.h"

#include "../../../MCAL/DIO/include/DIO_config.h"
#include "../../../MCAL/DIO/include/DIO_interface.h"
#include "../../../MCAL/DIO/include/DIO_private.h"


#include "../../../MCAL/ADC/include/ADC_config.h"
#include "../../../MCAL/ADC/include/ADC_interface.h"
#include "../../../MCAL/ADC/include/ADC_private.h"


#include "../include/LDR_config.h"
#include "../include/LDR_interface.h"
#include "../include/LDR_private.h"

void LDR_init(u8 PortId ,u8 PinId)
{
	if (PortId<=3 && PinId <=7  )
	{
		DIO_SetPinDirection(PortId,PinId,DIO_PIN_INPUT);
		ADC_init(ADC_REFERENCE_AVCC,ADC_Prescaller_128);
	}
	else
	{
		//No Thing
	}
}

void LDR_ReadValue(u8 ChannalId,u16 *AnalogLdrValue)
{
	u16 DigitalLdrValue ;
	if (AnalogLdrValue != NULL && ChannalId<=7)
	{
		ADC_ReadDigitalValue(ChannalId,&DigitalLdrValue);
		*AnalogLdrValue=DigitalLdrValue;
	}
	else
	{
		//No Thing
	}
}