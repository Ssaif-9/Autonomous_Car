/*
 * Autonomous_Car.c
 *
 * Created: 02-Dec-23 12:48:25 AM
 *  Author: M5_Autonomous_Car_TEAM
 */ 

#define F_CPU 16000000UL
#include <util/delay.h>

/****** UTILITES LIB *******/
#include "../UTILITES/BIT_MATH.h"
#include "../UTILITES/STD_TYPE.h"

/****** MCAL *******/
#include "../MCAL/DIO/include/DIO_config.h"
#include "../MCAL/DIO/include/DIO_interface.h"

#include "../MCAL/UART/include/UART_config.h"
#include "../MCAL/UART/include/UART_interface.h"

#include "../MCAL/EXTERNAL_INTERRUPT/include/EXTI_config.h"
#include "../MCAL/EXTERNAL_INTERRUPT/include/EXTI_interface.h"

#include "../MCAL/GLOBAL_INTERRUPT/include/GLBI_interfase.h"

#include "../MCAL/TIMER0/include/TIMER0_config.h"
#include "../MCAL/TIMER0/include/TIMER0_interface.h"

#include "../MCAL/TIMER1/include/TIMER1_config.h"
#include "../MCAL/TIMER1/include/TIMER1_interface.h"

#include "../MCAL/TIMER2/include/TMR2_config.h"
#include "../MCAL/TIMER2/include/TMR2_interface.h"

/****** HAL *******/
#include "../HAL/BLUETOOTH/include/BLUETOOTH_config.h"
#include "../HAL/BLUETOOTH/include/BLUETOOTH_interface.h"

#include "../HAL/BUZZER/include/BUZZER_config.h"
#include "../HAL/BUZZER/include/BUZZER_interface.h"

#include "../HAL/BUTTON/include/BUTTON_config.h"
#include "../HAL/BUTTON/include/BUTTON_interface.h"

#include "../HAL/LCD/include/LCD_config.h"
#include "../HAL/LCD/include/LCD_interface.h"

#include "../HAL/LED/include/LED_config.h"
#include "../HAL/LED/include/LED_interface.h"

#include "../HAL/MOTOR/include/MOTOR_config.h"
#include "../HAL/MOTOR/include/MOTOR_interface.h"

#include "../HAL/ULTRASONIC/include/ULTRASONIC_config.h"
#include "../HAL/ULTRASONIC/include/ULTRASONIC_interface.h"

#include "../HAL/SERVO/include/SERVO_config.h"
#include "../HAL/SERVO/include/SERVO_interface.h"

void BlueToothMode_SuperLoop  (void);
void UltraSonicMode_SuperLoop (void);

#define ULTRASONIC_MODE 0
#define BLUETOOTH_MODE  1

static u16 Speed=50;

#define MAX_SPEED                         100
#define MIN_SPEED                         0


int main(void)
{
	u8 ModeValue ;
	
	GLBI_Enable();
	
	BUTTON_init(BUTTON_MODE_PORT,BUTTON_MODE_PIN);
	BUTTON_ReadValue(BUTTON_MODE_PORT,BUTTON_MODE_PIN,&ModeValue,BUTTON_PullDown);
	
	LCD_init();
	
	WHEEL_Init();
	
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
	
	
	if (ULTRASONIC_MODE == ModeValue)
	{
		LCD_GoToLocation(1,1);
		LCD_SendString("Ultrasonic ON");
		_delay_ms(1000);
		
		SERVO_init();
		SERVO_TurnON(FORWARD_Angle);
		ULTRASOIC_init();
		_delay_ms(1000);
		UltraSonicMode_SuperLoop();
	}
	else
	{
		LCD_GoToLocation(1,1);
		LCD_SendString("BlueTooth ON");
		_delay_ms(1000);
		LCD_ClearDesplay();
		
		BLUETOOTH_init();
		BlueToothMode_SuperLoop();
	}	
}

void BlueToothMode_SuperLoop()
{
	u8 BlueToothValue;
	while(1)
	{	
		BLUETOOTH_ReceiveChar(&BlueToothValue);
		switch(BlueToothValue)
		{
			case 'F' :
			WHEEL_MoveForward();
			break;
			
			case 'B' :
			WHEEL_MoveBackward ();
			break;
			
			case 'S' :
			WHEEL_Stop ();
			break;
			
			case 'i' :
			WHEEL_MoveForwardRight ();
			break;
			
			case 'G' :
			WHEEL_MoveForwardleft ();
			break;
			
			case 'j' :
			WHEEL_MoveBackwardRight ();
			break;
			
			case 'H' :
			WHEEL_MoveBackwardleft ();
			break;
			
			case 'q' :
			if(Speed<MAX_SPEED)
			{
				Speed+=1;
				WHEEL_SendDutyCycleAndStart(Speed);
				
			}
			else
			{	
			}
			break;
			
			case '0' :
			if (Speed>MIN_SPEED)
			{
				Speed-=1;
				Speed == MIN_SPEED? (WHEEL_Stop()) : (WHEEL_SendDutyCycleAndStart(Speed)) ;
				
			}
			else
			{
			}
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


void UltraSonicMode_SuperLoop()
{
	f64 UltraSonic_ForwardValue ;
	f64 UltraSonic_RightValue ;
	f64 UltraSonic_LeftValue ;
	while(1)
	{
		ULTRASOIC_GetDistance(&UltraSonic_ForwardValue);
		LCD_ClearDesplay();
		LCD_GoToLocation(1,1);
		LCD_SendString("Distance=");
		LCD_SendIntegarNumber((u16)UltraSonic_ForwardValue);
		LCD_SendString("CM");
		if (UltraSonic_ForwardValue==0 || UltraSonic_ForwardValue>30.0)
		{
			WHEEL_MoveForward();
			//LCD_ClearDesplay();
			LCD_GoToLocation(1,2);
			LCD_SendString("    Forward    ");
		}
		else
		{
			BUZZER_Toggle(BUZZER_PORT,BUZZER_PIN);
			
			//	MOVE A Little Backward
			WHEEL_MoveBackward();
			LED_TurnON(LED_BACK_PORT,LED_BACK_PIN);
			LCD_ClearDesplay();
			LCD_GoToLocation(1,1);
			LCD_SendString("      Back      ");
			_delay_ms(500);
			WHEEL_Stop();
			
			// Measure Distance At Right
			SERVO_TurnON(RIGHT_Angle);
			ULTRASOIC_GetDistance(&UltraSonic_RightValue);
			LCD_ClearDesplay();
			LCD_GoToLocation(1,1);
			LCD_SendString("R_Distance=");
			LCD_SendIntegarNumber((u16)UltraSonic_RightValue);
			LCD_SendString("CM");
			_delay_ms(500);
			
			// Measure Distance At Left
			SERVO_TurnON(LEFT_Angle);
			ULTRASOIC_GetDistance(&UltraSonic_LeftValue);
			LCD_ClearDesplay();
			LCD_GoToLocation(1,1);
			LCD_SendString("L_Distance=");
			LCD_SendIntegarNumber((u16)UltraSonic_LeftValue);
			LCD_SendString("CM");
			_delay_ms(500);
			LED_TurnOFF(LED_BACK_PORT,LED_BACK_PIN);
			
			if (UltraSonic_RightValue > UltraSonic_LeftValue)
			{
				//MOVE Right
				SERVO_TurnON(FORWARD_Angle);
				LED_TurnON(LED_FORWARD_RIGHT_PORT,LED2_FORWARD_RIGHT_PIN);
				WHEEL_MoveForwardRight();
				LCD_ClearDesplay();
				LCD_GoToLocation(1,1);
				LCD_SendString("  Turn Right->> ");
				_delay_ms(1000);
				LED_TurnOFF(LED_FORWARD_RIGHT_PORT,LED2_FORWARD_RIGHT_PIN);
				WHEEL_Stop();
			}
			else
			{
				//MOVE Left 
				SERVO_TurnON(FORWARD_Angle);
				LED_TurnON(LED_FORWARD_LEFT_PORT,LED2_FORWARD_LEFT_PIN);
				WHEEL_MoveForwardleft();
				LCD_ClearDesplay();
				LCD_GoToLocation(1,1);
				LCD_SendString(" <<- Turn Left  ");
				_delay_ms(1000);
				LED_TurnOFF(LED_FORWARD_LEFT_PORT,LED2_FORWARD_LEFT_PIN);
				WHEEL_Stop();
			}
		}
		//_delay_ms(500);
	}
}

