/*
 * ULTRA_interface.h
 *
 * Created: 12/5/2023 1:38:29 PM
 *  Author: ayman
 */ 






#ifndef ULTRA_INTERFACE_H_
#define ULTRA_INTERFACE_H_

#define F_CPU 16000000UL
#include <util/delay.h>


#include "../../../UTILITES/STD_TYPE.h"
#include "../../../UTILITES/BIT_MATH.h"

#include "../include/ULTRA_interface.h"

#include "../../../MCAL/TIMER0/include/TM0_interface.h"
#include "../../../MCAL/TIMER0/include/TM0_private.h"

#include "../../../MCAL/GLOBAL_INTERRUPT/include/GLBI_interfase.h"
#include "../../../MCAL/DIO/include/DIO_interface.h"
#include "../../../MCAL/EXTERNAL_INTERRUPT/include/EXTI_interface.h"

void ULTRA_init();
void ULTRA_Getdistance(f32 *distance);
void TAKE_NUM_OVF(void);





#endif /* ULTRA_INTERFACE_H_ */