/*
 * LCD_interface.h
 *
 * Created: 06-Sep-23 6:41:56 PM
 *  Author: M5_Autonomous_Car_TEAM
 */ 


#ifndef LCD_INTERFACE_H_
#define LCD_INTERFACE_H_


	
/*	for four bit mode	*/

#define LCD_CmndBit0                          0
#define LCD_CmndBit1                          1
#define LCD_CmndBit2                          2
#define LCD_CmndBit3                          3



void LCD_init                                 (void);
void LCD_sendComnd                            (u8 cmnd);
void LCD_sendChar                             (u8 Character_Data);
void LCD_SendString                           (u8 *String_Data);
void LCD_SendRealNumber                       (f64 Number);
void LCD_ClearDesplay                         (void);
void LCD_GoToLocation                         (u8 X_Location, u8 LineNumber);
void LCD_SendIntegarNumber                    (u16 IntegerNumber);
void LCD_SendNumberToLocation                 (u16 Number,u8 X_Location, u8 LineNumber);
void LCD_Shift                                (u8 ShiftCmnd);

#endif /* LCD_INTERFACE_H_ */