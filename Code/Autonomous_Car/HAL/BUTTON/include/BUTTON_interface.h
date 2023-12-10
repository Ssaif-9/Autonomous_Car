/*
 * ButtonInterface.h
 *
 * Created: 01-Sep-23 10:41:00 PM
 *  Author: M5_Autonomous_Car_TEAM
 */ 


#ifndef BUTTONINTERFACE_H_
#define BUTTONINTERFACE_H_


#define BUTTON_PullUp   1
#define BUTTON_PullDown 0


void BUTTON_init            (u8 ButtonPort ,u8 ButtonPin);
void BUTTON_ActivePullUp    (u8 ButtonPort ,u8 ButtonPin);
void BUTTON_ReadValue       (u8 ButtonPort ,u8 ButtonPin,u8* PinValue,u8 BUTTON_STATUE);


#endif /* BUTTONINTERFACE_H_ */