/*
 * EXTI_interface.h
 *
 * Created: 09-Sep-23 11:31:24 AM
 *  Author:  M5_Autonomous_Car_TEAM 
 */ 


#ifndef EXTI_INTERFACE_H_
#define EXTI_INTERFACE_H_

typedef enum 
{
	 EXTI_INT0=0,  //PORT_D_PIN_2
	 EXTI_INT1 ,   //PORT_D_PIN_3
	 EXTI_INT2     //PORT_B_PIN_2
} EXTI_InterruptSource;

typedef enum 
{
	EXTI_RISING_EDGE=0,
	EXTI_FALLING_EDGE,
	EXTI_LOW_LEVEL,
	EXTI_ANY_LOGICAL_CHANGE
} EXTI_TriggerEdge;

void EXTI_Enable                   (EXTI_InterruptSource InterruptSource ,EXTI_TriggerEdge TriggerEdge);
void EXTI_Disable                  (EXTI_InterruptSource InterruptSource);
void EXTI_SetCallBackInt0          (void (*PtrToFunc)(void));
void EXTI_SetCallBackInt1          (void (*PtrToFunc)(void));
void EXTI_SetCallBackInt2          (void (*PtrToFunc)(void));

#endif /* EXTI_INTERFACE_H_ */