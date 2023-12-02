/*
 * Autonomous_Car.c
 *
 * Created: 02-Dec-23 12:48:25 AM
 *  Author: SEIF EL-DIN SULTAN OSMAN
 */ 

#define F_CPU 16000000UL
#include <util/delay.h>

/****** UTILITES LIB *******/
#include "../UTILITES/BIT_MATH.h"
#include "../UTILITES/STD_TYPE.h"

/****** MCAL *******/
#include "../MCAL/DIO/include/DIO_config.h"
#include "../MCAL/DIO/include/DIO_interface.h"

#include "../MCAL/EXTERNAL INTERRUPT/include/EXTI_config.h"
#include "../MCAL/EXTERNAL INTERRUPT/include/EXTI_interface.h"

#include "../MCAL/GLOBAL INTERRUPT/include/GLBI_interfase.h"

#include "../MCAL/UART/include/UART_config.h"
#include "../MCAL/UART/include/UART_interface.h"

/****** HAL *******/
#include "../HAL/BLUETOOTH/include/BLUETOOTH_config.h"
#include "../HAL/BLUETOOTH/include/BLUETOOTH_interface.h"

#include "../HAL/BUTTON/include/BUTTON_config.h"
#include "../HAL/BUTTON/include/BUTTON_interface.h"

#include "../HAL/BUZZER/include/BUZZER_config.h"
#include "../HAL/BUZZER/include/BUZZER_interface.h"

#include "../HAL/LCD/include/LCD_config.h"
#include "../HAL/LCD/include/LCD_interface.h"

#include "../HAL/LED/include/LED_config.h"
#include "../HAL/LED/include/LED_interface.h"

#define ULTRASONIC_MODE 0
#define BLUETOOTH_MODE  1
int main(void)
{
	u8 ModeValue ;
	
	BUTTON_init(MODE_PORT,MODE_PIN);
	BUTTON_ReadValue(MODE_PORT,MODE_PIN,&ModeValue,BUTTON_PullDown);
	
	if (ULTRASONIC_MODE == ModeValue)
	{
		SERVO_init();
		ULTRASONIC_init();
		UltraSonicMode_SuperLoop()
	} 
	else
	{
		BLUETOOTH_init();
		BlueToothMode_SuperLoop()
	}
}

void BlueToothMode_SuperLoop()
{
	u8 BlueToothValue ;
	while(1)
	{
		BLUETOOTH_ReceiveChar(&BlueToothValur);
		switch(BlueToothValue)
		{
			case '' :
			WHEEL_MoveForward();
			break;
			
			case '' :
			WHEEL_MoveBackward();
			break;
			
			case '' :
			WHEEL_Stop();
			break;
			
			case '' :
			WHEEL_MoveForwardRight();
			break;
			
			case '' :
			WHEEL_MoveForwardleft();
			break;
			
			case '' :
			WHEEL_MoveBackwardRight();
			break;
			
			case '' :
			WHEEL_MoveBackwardleft();
			break;
			
			case '' :
			WHEEL_TurnDirection();
			break;
			
			case '' :
			WHEEL_SpeedUP();
			break;
			
			case '' :
			WHEEL_SpeedDOWN();
			break;
			
			default:
			//NO THING
		}
	}
	
}

void UltraSonicMode_SuperLoop()
{
	f64 UltraSonic_ForwardValue ;
	f64 UltraSonic_RightValue ;
	f64 UltraSonic_LeftValue ;
	while (1)
	{
		ULTRASONIC_ReadDistance(&UltraSonic_ForwardValue);
		if (UltraSonicValue>30.0)
		{
			WHEEL_MoveForward();
		} 
		else
		{
			WHEEL_MoveBackword();
			_delay_ms(500);
			WHEEL_Stop();
			
			SERVO_SetAngle(180);
			ULTRASONIC_ReadDistance(&UltraSonic_RightValue);
			_delay_ms(500);
			
			SERVO_SetAngle(0);
			ULTRASONIC_ReadDistance(&UltraSonic_LeftValue);
			_delay_ms(500);
			
			if (UltraSonic_RightValue > UltraSonic_LeftValue)
			{
				SERVO_SetAngle(90);
				WHEEL_MoveForwardRight();
				_delay_ms(500);
				WHEEL_Stop();
			} 
			else
			{
				SERVO_SetAngle(90);
				WHEEL_MoveForwardleft();
				_delay_ms(500);
				WHEEL_Stop();
			}
		}
		_delay_ms(500);
	}
}