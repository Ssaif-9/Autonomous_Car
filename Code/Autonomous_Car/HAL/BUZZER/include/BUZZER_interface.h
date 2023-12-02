/*
 * BUZZER_interface.h
 *
 * Created: 18-Sep-23 9:48:23 PM
 *  Author: SEIF EL_DIN SULTAN
 */ 


#ifndef BUZZER_INTERFACE_H_
#define BUZZER_INTERFACE_H_

void BUZZER_init       (u8 BuzzerPort ,u8 BuzzerPin );
void BUZZER_TurnOn     (u8 BuzzerPort ,u8 BuzzerPin );
void BUZZER_TurnOff    (u8 BuzzerPort ,u8 BuzzerPin );
void BUZZER_Toggle     (u8 BuzzerPort ,u8 BuzzerPin );




#endif /* BUZZER_INTERFACE_H_ */