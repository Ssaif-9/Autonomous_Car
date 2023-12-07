/*
 * LCD_program.c
 *
 * Created: 06-Sep-23 6:41:33 PM
 *  Author: SEIF EL-DIN SOLTAN 
 */ 

#define F_CPU 16000000UL
#include <util/delay.h>

/*	UTILES_LIB	*/
#include "../../../UTILITES/STD_TYPE.h"
#include "../../../UTILITES/BIT_MATH.h"
/*	MCAL	*/
#include "../../../MCAL/DIO/include/DIO_config.h"
#include "../../../MCAL/DIO/include/DIO_interface.h"
#include "../../../MCAL/DIO/include/DIO_private.h"

/*	HAL	*/
#include "../include/LCD_interface.h"
#include "../include/LCD_config.h"
#include "../include/LCD_private.h"


void LCD_init(void)
{
	#if   LCD_MODE == LCD_FourBitMode 
	//SET PIN AS OUTPUT
	DIO_SetPinDirection(LCD_RS_PORT,LCD_RS_PIN,DIO_PIN_OUTPUT);
	DIO_SetPinDirection(LCD_RW_PORT,LCD_RW_PIN,DIO_PIN_OUTPUT);
	DIO_SetPinDirection(LCD_EN_PORT,LCD_EN_PIN,DIO_PIN_OUTPUT);
	
	
	DIO_SetPinDirection(LCD_D4_PORT,LCD_D4_PIN,DIO_PIN_OUTPUT);
	DIO_SetPinDirection(LCD_D5_PORT,LCD_D5_PIN,DIO_PIN_OUTPUT);
	DIO_SetPinDirection(LCD_D6_PORT,LCD_D6_PIN,DIO_PIN_OUTPUT);
	DIO_SetPinDirection(LCD_D7_PORT,LCD_D7_PIN,DIO_PIN_OUTPUT);
	
	
	_delay_ms(35);
	DIO_SetPinValue(LCD_RS_PORT,LCD_RS_PIN,DIO_PIN_LOW);
	DIO_SetPinValue(LCD_RW_PORT,LCD_RW_PIN,DIO_PIN_LOW);
	private_WriteHalfPort(LCD_COMMAND_FOR_FOUR_BIT_MODE);
	DIO_SetPinValue(LCD_EN_PORT,LCD_EN_PIN,DIO_PIN_HIGH);
	_delay_ms(1);
	DIO_SetPinValue(LCD_EN_PORT,LCD_EN_PIN,DIO_PIN_LOW);
	
	LCD_sendComnd(LCD_FUNCTION_SET);
	_delay_us(45);
	
	LCD_sendComnd(LCD_DISPLAY_ON_OFF_CONTROL);
	_delay_us(45);
	
	LCD_sendComnd(LCD_DESPLAY_CLEAR);
	_delay_ms(2);
	
	LCD_sendComnd(LCD_ENTRY_MODE_SET);
	_delay_us(45);
	
	#elif LCD_MODE == LCD_EightBitMode 
	//SET PIN AS OUTPUT
	DIO_SetPinDirection(LCD_RS_PORT,LCD_RS_PIN,DIO_PIN_OUTPUT);
	DIO_SetPinDirection(LCD_RW_PORT,LCD_RW_PIN,DIO_PIN_OUTPUT);
	DIO_SetPinDirection(LCD_EN_PORT,LCD_EN_PIN,DIO_PIN_OUTPUT);
	
	DIO_setPortDirection(LCD_PORT,DIO_PORT_OUTPUT);
	
	_delay_ms(35);
	//     DIO_SetPinValue(LCD_RS_PORT,LCD_RS_PIN,DIO_PIN_LOW);
	//     DIO_SetPinValue(LCD_RW_PORT,LCD_RW_PIN,DIO_PIN_LOW);
	
	LCD_sendComnd(LCD_FUNCTION_SET);
	_delay_us(45);
	
	LCD_sendComnd(LCD_DISPLAY_ON_OFF_CONTROL);
	_delay_us(45);
	
	LCD_sendComnd(LCD_DESPLAY_CLEAR);
	_delay_ms(2);
	
	LCD_sendComnd(LCD_ENTRY_MODE_SET);
	_delay_us(45);
	
	#endif
}

void LCD_sendComnd(u8 Cmnd)
{
	#if   LCD_MODE == LCD_FourBitMode
	
	DIO_SetPinValue(LCD_RS_PORT,LCD_RS_PIN,DIO_PIN_LOW);
	DIO_SetPinValue(LCD_RW_PORT,LCD_RW_PIN,DIO_PIN_LOW);
	
	private_WriteHalfPort(Cmnd>>4);                                    //PORTA_REG= (PORTA_REG & 0x0f) | (Cmnd & 0xf0)
	DIO_SetPinValue(LCD_EN_PORT,LCD_EN_PIN,DIO_PIN_HIGH);
	_delay_ms(1);
	DIO_SetPinValue(LCD_EN_PORT,LCD_EN_PIN,DIO_PIN_LOW);
	
	private_WriteHalfPort(Cmnd);                                      //PORTA_REG= (PORTA_REG & 0x0f) | ((Cmnd & 0xf0) <<4)
	DIO_SetPinValue(LCD_EN_PORT,LCD_EN_PIN,DIO_PIN_HIGH);
	_delay_ms(1);
	DIO_SetPinValue(LCD_EN_PORT,LCD_EN_PIN,DIO_PIN_LOW);
	
	#elif LCD_MODE == LCD_EightBitMode
	
	DIO_SetPinValue(LCD_RS_PORT,LCD_RS_PIN,DIO_PIN_LOW);
	DIO_SetPinValue(LCD_RW_PORT,LCD_RW_PIN,DIO_PIN_LOW);
	
	DIO_setPortValue(LCD_PORT,Cmnd);
	DIO_SetPinValue(LCD_EN_PORT,LCD_EN_PIN,DIO_PIN_HIGH);
	_delay_ms(1);
	DIO_SetPinValue(LCD_EN_PORT,LCD_EN_PIN,DIO_PIN_LOW);
	
	#endif
	
}


void LCD_sendChar(u8 Character_Data)
{
	#if   LCD_MODE == LCD_FourBitMode
	
	DIO_SetPinValue(LCD_RS_PORT,LCD_RS_PIN,DIO_PIN_HIGH);
	DIO_SetPinValue(LCD_RW_PORT,LCD_RW_PIN,DIO_PIN_LOW);
	
	private_WriteHalfPort(Character_Data>>4);                        //PORTA_REG= (PORTA_REG & 0x0f) | (Character_Data & 0xf0)
	DIO_SetPinValue(LCD_EN_PORT,LCD_EN_PIN,DIO_PIN_HIGH);
	_delay_ms(1);
	DIO_SetPinValue(LCD_EN_PORT,LCD_EN_PIN,DIO_PIN_LOW);
	
	private_WriteHalfPort(Character_Data);                         //PORTA_REG= (PORTA_REG & 0x0f) | ((Character_Data & 0xf0) <<4)
	DIO_SetPinValue(LCD_EN_PORT,LCD_EN_PIN,DIO_PIN_HIGH);
	_delay_ms(1);
	DIO_SetPinValue(LCD_EN_PORT,LCD_EN_PIN,DIO_PIN_LOW);
	
	#elif LCD_MODE == LCD_EightBitMode
	
	DIO_SetPinValue(LCD_RS_PORT,LCD_RS_PIN,DIO_PIN_HIGH);
	DIO_SetPinValue(LCD_RW_PORT,LCD_RW_PIN,DIO_PIN_LOW);
	
	DIO_setPortValue(LCD_PORT,Character_Data);
	DIO_SetPinValue(LCD_EN_PORT,LCD_EN_PIN,DIO_PIN_HIGH);
	_delay_ms(1);
	DIO_SetPinValue(LCD_EN_PORT,LCD_EN_PIN,DIO_PIN_LOW);
	
	#endif
}

void LCD_SendString (u8 *String_Data)
{
	while((*String_Data)!='\0')
	{
		LCD_sendChar(*String_Data);
		String_Data++;
	}
}

void LCD_SendRealNumber(f64 Number)
{
	u8 str [16];
	u8 *tmpsign = (Number < 0)? "-" : "";
	f32 tmpval = (Number < 0)? -Number : Number;
	u16 tmpint1 = (u16)tmpval;
	f32 tmpfrac = tmpval - (float)tmpint1;
	u16 tmpint2 = tmpfrac * 10000;
	sprintf(str,"%s%d.%04d", tmpsign, tmpint1, tmpint2);
	LCD_SendString(str);
}

void LCD_ClearDesplay()
{
	LCD_sendComnd (LCD_DESPLAY_CLEAR);
	_delay_ms(2);
	LCD_sendComnd (LCD_Cursor_At_Home_position);	
}

void LCD_GoToLocation(u8 X_Location, u8 LineNumber)
{
	u8 FirstLocation[] = {0x80, 0xC0, 0x94, 0xD4};
	LCD_sendComnd(FirstLocation[LineNumber-1] + X_Location-1);
	_delay_us(1000);
}

void LCD_SendIntegarNumber(u16 IntegerNumber)
{
	u16 NumberString[16];
	snprintf(NumberString,17,"%d",IntegerNumber);
	LCD_SendString(NumberString);
}


void LCD_SendNumberToLocation(u16 Number,u8 X_Location, u8 LineNumber)
{
	LCD_GoToLocation(X_Location,LineNumber);
	LCD_SendIntegarNumber(Number);
}


void LCD_Shift(u8 ShiftCmnd)
{
	LCD_sendComnd(ShiftCmnd);
}

void private_WriteHalfPort (u8 Value)
{
	(DIO_PIN_LOW==GET_BIT(Value,LCD_CmndBit0)) ? (DIO_SetPinValue(LCD_D4_PORT,LCD_D4_PIN,DIO_PIN_LOW)) : (DIO_SetPinValue(LCD_D4_PORT,LCD_D4_PIN,DIO_PIN_HIGH));
	(DIO_PIN_LOW==GET_BIT(Value,LCD_CmndBit1)) ? (DIO_SetPinValue(LCD_D5_PORT,LCD_D5_PIN,DIO_PIN_LOW)) : (DIO_SetPinValue(LCD_D5_PORT,LCD_D5_PIN,DIO_PIN_HIGH));
	(DIO_PIN_LOW==GET_BIT(Value,LCD_CmndBit2)) ? (DIO_SetPinValue(LCD_D6_PORT,LCD_D6_PIN,DIO_PIN_LOW)) : (DIO_SetPinValue(LCD_D6_PORT,LCD_D6_PIN,DIO_PIN_HIGH));
	(DIO_PIN_LOW==GET_BIT(Value,LCD_CmndBit3)) ? (DIO_SetPinValue(LCD_D7_PORT,LCD_D7_PIN,DIO_PIN_LOW)) : (DIO_SetPinValue(LCD_D7_PORT,LCD_D7_PIN,DIO_PIN_HIGH));
}

