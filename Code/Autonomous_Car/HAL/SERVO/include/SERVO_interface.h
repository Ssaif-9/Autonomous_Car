/*
 * SERVO_interface.h
 *
 * Created: 12/7/2023 12:35:39 PM
 *  Author: Abdullah Ashraf
 */ 


#ifndef SERVO_INTERFACE_H_
#define SERVO_INTERFACE_H_

#include "../../../UTILITES/STD_TYPE.h"
#include "../../../UTILITES/BIT_MATH.h"

#include "../../../MCAL/DIO/include/DIO_config.h"
#include "../../../MCAL/DIO/include/DIO_interface.h"
#include "../../../MCAL/DIO/include/DIO_private.h"


#include "../../../MCAL/TIMER1/include/TMR1_config.h"
#include "../../../MCAL/TIMER1/include/TMR1_interface.h"
#include "../../../MCAL/TIMER1/include/TMR1_private.h"


#include "../include/SERVO_config.h"

void SERVO_init(void);

void SERVO_Left();
void SERVO_Forward();
void SERVO_Right();

void SERVO_AnyAngle(u8 Angleindegrees);

#endif /* SERVO_INTERFACE_H_ */