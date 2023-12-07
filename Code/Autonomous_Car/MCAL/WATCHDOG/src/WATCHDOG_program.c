/*
 * WATCHDOG_program.c
 *
 * Created: 07-Dec-23 10:53:22 PM
 *  Author: SEIF EL_DIN SULTAN
 */ 

#include "../../../UTILITES/STD_TYPE.h"
#include "../../../UTILITES/BIT_MATH.h"

#include "../include/WATCHDOG_interface.h"
#include "../include/WATCHDOG_private.h"
void  WATCHDOG_Enable(u8 Time)
{
	WDTCR |=Time;
	WDTCR |=0x08;
}

void  WATCHDOG_Disable()
{
	WDTCR |= 0x18;
	WDTCR  =0x00;
}