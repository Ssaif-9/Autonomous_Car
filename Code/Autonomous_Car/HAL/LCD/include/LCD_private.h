/*
 * LCD_private.h
 *
 * Created: 06-Sep-23 10:32:30 PM
 *  Author: SEIF EL-DIN SOLTAN
 */ 


#ifndef LCD_PRIVATE_H_
#define LCD_PRIVATE_H_

#define LCD_FourBitMode                 0
#define LCD_EightBitMode                1



#define LCD_COMMAND_FOR_FOUR_BIT_MODE         0b0010
#define LCD_FUNCTION_SET                      0b00101000
#define LCD_DISPLAY_ON_OFF_CONTROL            0b00001100   // 0b00001100 || 0b00001110 || 0b00001111
#define LCD_DESPLAY_CLEAR                     0b00000001
#define LCD_ENTRY_MODE_SET                    0b00000110


#define LCD_GO_TO_2ND_LINE                    0b11000000
#define LCD_GO_TO_1ND_LINE                    0b00000010
#define LCD_Cursor_At_Home_position           0b10000000
 
#define LCD_ShiftRight                        0b00011000
#define LCD_ShiftLeft                         0b00011100
#define LCD_CursonLeft                        0b00010000
#define LCD_CursonRight                       0b00010100


static void private_WriteHalfPort (u8 Value);


#endif /* LCD_PRIVATE_H_ */