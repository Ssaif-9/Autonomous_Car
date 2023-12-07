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

#include "../MCAL/EXTERNAL_INTERRUPT/include/EXTI_config.h"
#include "../MCAL/EXTERNAL_INTERRUPT/include/EXTI_interface.h"

#include "../MCAL/GLOBAL_INTERRUPT/include/GLBI_interfase.h"

#include "../MCAL/UART/include/UART_config.h"
#include "../MCAL/UART/include/UART_interface.h"

#include "../MCAL/ADC/include/ADC_config.h"
#include "../MCAL/ADC/include/ADC_interface.h"

#include "../MCAL/TIMER0/include/TM0_confg.h"
#include "../MCAL/TIMER0/include/TM0_interface.h"

#include "../MCAL/TIMER1/include/TMR1_config.h"
#include "../MCAL/TIMER1/include/TMR1_interface.h"

#include "../MCAL/TIMER2/include/TMR2_config.h"
#include "../MCAL/TIMER2/include/TMR2_interface.h"

#include "../MCAL/WATCHDOG/include/WATCHDOG_config.h"
#include "../MCAL/WATCHDOG/include/WATCHDOG_interface.h"

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

#include "../HAL/LDR/include/LDR_config.h"
#include "../HAL/LDR/include/LDR_interface.h"

void SwitchMode(void);
void BlueToothMode_SuperLoop();
void UltraSonicMode_SuperLoop();
void LDR_SuperLoop();

#define ULTRASONIC_MODE 0
#define BLUETOOTH_MODE  1



int main(void)
{
	u8 ModeValue ;
	u16 LdrValue;
	
	WATCHDOG_Disable();
	
	GLBI_Enable();
	
	EXTI_Enable(EXTI_INT0,EXTI_ANY_LOGICAL_CHANGE);         //For Ultrasonic
	EXTI_Enable(EXTI_INT1,EXTI_ANY_LOGICAL_CHANGE);         // for Change Mode
	EXTI_SetCallBackInt1(&SwitchMode);
	
	BUTTON_init(BUTTON_MODE_PORT,BUTTON_MODE_PIN);
	BUTTON_ReadValue(BUTTON_MODE_PORT,BUTTON_MODE_PIN,&ModeValue,BUTTON_PullDown);
	
	LCD_init();
	LDR_init(LDR_PORT,LDR_PIN);
	
	LED_init(LED_BACK_PORT,LED_BACK_PIN);
	LED_init(LED_FORWARD_RIGHT_PORT,LED2_FORWARD_RIGHT_PIN);
	LED_init(LED_FORWARD_LEFT_PORT,LED2_FORWARD_LEFT_PIN);
	LED_init(LED_FLASH_PORT,LED_FLASH_PIN);
	BUZZER_init(BUZZER_PORT,BUZZER_PIN);
	
	LED_TurnOFF(LED_FORWARD_RIGHT_PORT,LED2_FORWARD_RIGHT_PIN);
	LED_TurnOFF(LED_FORWARD_LEFT_PORT,LED2_FORWARD_LEFT_PIN);
	LED_TurnOFF(LED_BACK_PORT,LED_BACK_PIN);
	LED_TurnOFF(LED_FLASH_PORT,LED_FLASH_PIN);
	BUZZER_TurnOff(BUZZER_PORT,BUZZER_PIN);
	
	/*Want Loop All Time */
	LDR_ReadValue(ADC_CHANNEL_0,&LdrValue);
	LCD_GoToLocation(1,1);
	LCD_SendIntegarNumber(LdrValue);
	_delay_ms(1500);
	if (LdrValue>=500)
	{
		LED_TurnON(LED_FLASH_PORT,LED_FLASH_PIN);
	}
	else
	{
		LED_TurnOFF(LED_FLASH_PORT,LED_FLASH_PIN);
	}
	/************************/
	
	if (ULTRASONIC_MODE == ModeValue)
	{
		LCD_GoToLocation(1,2);
		LCD_SendString("Ultrasonic ON");
		_delay_ms(2000);
		
		SERVO_init();
		ULTRA_init();
		//UltraSonicMode_SuperLoop()
	} 
	else
	{
		LCD_GoToLocation(1,2);
		LCD_SendString("BlueTooth ON");
		_delay_ms(2000);
		
		BLUETOOTH_init();
		
		BlueToothMode_SuperLoop();
	}
}


void BlueToothMode_SuperLoop()
{
	u8 BlueToothValue ;
	while(1)
	{
		BLUETOOTH_ReceiveChar(&BlueToothValue);
		switch(BlueToothValue)
		{
			case 'F' :
			//WHEEL_MoveForward();
			break;
			
			case 'B' :
			//WHEEL_MoveBackward();
			break;
			
			case 'S' :
			//WHEEL_Stop();
			break;
			
			case 'i' :
			//WHEEL_MoveForwardRight();
			break;
			
			case 'G' :
			//WHEEL_MoveForwardleft();
			break;
			
			case 'j' :
			//WHEEL_MoveBackwardRight();
			break;
			
			case 'H' :
			//WHEEL_MoveBackwardleft();
			break;
			
			case 'q' :
			//WHEEL_SpeedUP();
			break;
			
			case '0' :
			//WHEEL_SpeedDOWN();
			break;
			
			case 'U' :         //BACK LIGHT ON
			LED_TurnON(LED_BACK_PORT,LED_BACK_PIN);
			break;
			
			case 'u' :         //BACK LIGHT OFF
			LED_TurnOFF(LED_BACK_PORT,LED_BACK_PIN);
			break;
			
			case 'W' :         //Flash  ON
			LED_TurnON(LED_FLASH_PORT,LED_FLASH_PIN);
			break;
			
			case 'w' :         //Flash  OFF
			LED_TurnOFF(LED_FLASH_PORT,LED_FLASH_PIN);
			break;
			
			case 'C' :         //FR  ON
			LED_TurnON(LED_FORWARD_RIGHT_PORT,LED2_FORWARD_RIGHT_PIN);
			LED_TurnOFF(LED_FORWARD_LEFT_PORT,LED2_FORWARD_LEFT_PIN);
			break;
			
			case 'c' :         //FR  OFF
			LED_TurnOFF(LED_FORWARD_RIGHT_PORT,LED2_FORWARD_RIGHT_PIN);
			LED_TurnOFF(LED_FORWARD_LEFT_PORT,LED2_FORWARD_LEFT_PIN);
			break;
			
			case 'X' :         //FL  ON
			LED_TurnOFF(LED_FORWARD_RIGHT_PORT,LED2_FORWARD_RIGHT_PIN);
			LED_TurnON(LED_FORWARD_LEFT_PORT,LED2_FORWARD_LEFT_PIN);
			break;
			
			case 'x' :         //FL  OFF
			LED_TurnOFF(LED_FORWARD_RIGHT_PORT,LED2_FORWARD_RIGHT_PIN);
			LED_TurnOFF(LED_FORWARD_LEFT_PORT,LED2_FORWARD_LEFT_PIN);
			break;
			
			
			case 'V' :         //Horn  ON
			BUZZER_TurnOn(BUZZER_PORT,BUZZER_PIN);
			break;
			
			case 'v' :         //Horn  OFF
			BUZZER_TurnOff(BUZZER_PORT,BUZZER_PIN);
			break;
			
			default:
			
			break;
		}
	}
	
}
/*
void UltraSonicMode_SuperLoop()
{
	f64 UltraSonic_ForwardValue ;
	f64 UltraSonic_RightValue ;
	f64 UltraSonic_LeftValue ;
	while (1)
	{
		ULTRA_Getdistance(&UltraSonic_ForwardValue);
		if (UltraSonic_ForwardValue>30.0)
		{
			WHEEL_MoveForward();
		} 
		else
		{
			WHEEL_MoveBackword();
			_delay_ms(500);
			WHEEL_Stop();
			
			SERVO_Right();
			ULTRA_Getdistance(&UltraSonic_RightValue);
			_delay_ms(500);
			
			SERVO_Left();
			ULTRA_Getdistance(&UltraSonic_LeftValue);
			_delay_ms(500);
			
			if (UltraSonic_RightValue > UltraSonic_LeftValue)
			{
				SERVO_Forward();
				WHEEL_MoveForwardRight();
				_delay_ms(500);
				WHEEL_Stop();
			} 
			else
			{
				SERVO_Forward();
				WHEEL_MoveForwardleft();
				_delay_ms(500);
				WHEEL_Stop();
			}
		}
		_delay_ms(500);
	}
}
*/

void SwitchMode(void)
{
	WATCHDOG_Enable(WatchDog_u8_5VCC_TIME_OUT_1_0SEC);
}