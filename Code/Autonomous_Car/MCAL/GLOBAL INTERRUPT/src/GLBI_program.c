/*
 * GLBI_program.c
 *
 * Created: 09-Sep-23 5:58:45 PM
 *  Author: SEIF EL-DIN SULTAN OSMAN
 */ 

#include "STD_TYPE.h"
#include "BIT_MATH.h"

#include "GLBI_interfase.h"
#include "GLBI_private.h"
 
 void GLBI_Enable()
 {
	 SET_BIT(SREG,I);
 }