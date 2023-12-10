/*
 * Motor_Interface.h
 *
 * Created: 12/8/2023 12:40:27 PM
 *  Author: M5_Autonomous_Car_TEAM
 */ 


#ifndef MOTOR_INTERFACE_H_
#define MOTOR_INTERFACE_H_


void WHEEL_Init();
void WHEEL_MoveForward ();
void WHEEL_MoveBackward ();
void WHEEL_Stop ();
void WHEEL_MoveForwardRight ();
void WHEEL_MoveForwardleft ();
void WHEEL_MoveBackwardRight ();
void WHEEL_MoveBackwardleft ();
void WHEEL_TurnDirection ();
void WHEEL_SendDutyCycleAndStart(u8 speed);




#endif /* MOTOR_INTERFACE_H_ */