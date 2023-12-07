/*
 * BLUETOOTH_program.c
 *
 * Created: 09-Oct-23 3:09:27 PM
 *  Author: SEIF EL_DIN SULTAN 
 */ 

#include "../../../UTILITES/STD_TYPE.h"

#include "../../../MCAL/UART/include/UART_config.h"
#include "../../../MCAL/UART/include/UART_interface.h"
#include "../../../MCAL/UART/include/UART_private.h"

#include "../include/BLUETOOTH_config.h"
#include "../include/BLUETOOTH_interface.h"
#include "../include/BLUETOOTH_private.h"


void BLUETOOTH_init(void)
{
	UART_init();
}

void BLUETOOTH_TransimitChar(u8 TransimitData)
{
	UART_TransmiteChar(TransimitData);
}

void BLUETOOTH_ReceiveChar(u8* ReceiveData)
{
	UART_ReceiveChar(ReceiveData);
}

void BLUETOOTH_TransimitString (u8* TransimitData)
{
	UART_TransmiteString(TransimitData);
}