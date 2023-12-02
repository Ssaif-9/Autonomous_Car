/*
 * BLUETOOTH_program.c
 *
 * Created: 09-Oct-23 3:09:27 PM
 *  Author: SEIF EL_DIN SULTAN 
 */ 
#include "STD_TYPE.h"
#include "STD_TYPE.h"

#include "UART_config.h"
#include "UART_interface.h"
#include "UART_private.h"

#include "BLUETOOTH_config.h"
#include "BLUETOOTH_interface.h"
#include "BLUETOOTH_private.h"


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