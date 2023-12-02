/*
 * LedInterface.h
 *
 * Created: 01-Sep-23 9:43:39 PM
 *  Author: SEIF EL_DIN SULTAN
 */ 


#ifndef LEDINTERFACE_H_
#define LEDINTERFACE_H_


				               
void LED_init                  (u8 LedPort,u8 LedPin);
void LED_TurnON                (u8 LedPort,u8 LedPin);
void LED_TurnOFF               (u8 LedPort,u8 LedPin);
void LED_Toggle                (u8 LedPort,u8 LedPin);



#endif /* LEDINTERFACE_H_ */