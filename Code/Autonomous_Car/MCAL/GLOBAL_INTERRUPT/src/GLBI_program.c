/*
 * GLBI_program.c
 *
 * Created: 09-Sep-23 5:58:45 PM
 *  Author: M5_Autonomous_Car_TEAM
 */ 

#include "../../../UTILITES/STD_TYPE.h"
#include "../../../UTILITES/BIT_MATH.h"

#include "../include/GLBI_interfase.h"
#include "../include/GLBI_private.h"
 
 void GLBI_Enable()
 {
	 SET_BIT(SREG,I);
 }