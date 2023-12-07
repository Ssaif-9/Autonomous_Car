/*
 * UART_program.c
 *
 * Created: 29-Sep-23 11:39:34 AM
 *  Author: SEIF EL_DIN SULTAN
 */ 

#define F_CPU 16000000UL

#include "../../../UTILITES/STD_TYPE.h"
#include "../../../UTILITES/BIT_MATH.h"

#include "../include/UART_config.h"
#include "../include/UART_interface.h"
#include "../include/UART_private.h"

static void (*Private_UART_CallBack_RXC)  (void)=NULL;
static void (*Private_UART_CallBack_UDRE) (void)=NULL;
static void (*Private_UART_CallBack_TXC)  (void)=NULL;



#define UART_UBBR_VALUE (((F_CPU)/(UART_SelectedBoudRate*16UL))-1)

void UART_init (void)
{
	CLR_BIT(UCSRB,UCSZ2);
	
	u8 UCSRC_Value =0X00 ;
	CLR_BIT(UCSRC_Value,UCPOL);
	SET_BIT(UCSRC_Value,UCSZ0);
	SET_BIT(UCSRC_Value,UCSZ1);
	CLR_BIT(UCSRC_Value,USBS);
	CLR_BIT(UCSRC_Value,UPM0);
	CLR_BIT(UCSRC_Value,UPM1);
	CLR_BIT(UCSRC_Value,UMSEL);
	SET_BIT(UCSRC_Value,URSEL);
	
	UCSRC=UCSRC_Value;      // Set UART Mode: 8-bit data, 1 stop bit, no parity (0x86)
	
	UBRRL=UART_UBBR_VALUE;     // Set baud rate = 9600 -> 103;
    UBRRH = (UART_UBBR_VALUE >> 8);
	
	CLR_BIT(UCSRA,U2X);   // Stop double speed
	
	
	SET_BIT(UCSRB,RXCIE);  // Enable Rx Interrupt 
	SET_BIT(UCSRB,TXCIE);  // Enable Tx Interrupt 
	SET_BIT(UCSRB,UDRIE);  // Enable UDR Interrupt 
	
	SET_BIT(UCSRB,TXEN);  // Enable Tx
	SET_BIT(UCSRB,RXEN);  // Enable Rx
}

void UART_ReceiveChar (u8* ReceiveData)
{
	if(ReceiveData!=NULL)
	{
		while(0 == GET_BIT(UCSRA,RXC));
		*ReceiveData=UDR;
	}
}



void UART_TransmiteChar(u8 TransmiteData)
{
	UDR=TransmiteData;
	while(0 == GET_BIT(UCSRA,UDRE));
}

void UART_TransmiteString(u8 *TransmiteData)
{
	u8 Index=0;

	while (TransmiteData[Index]!='\0')		/* Send string till null */
	{
		UART_TransmiteChar(TransmiteData[Index]);
		Index++;
	}
}

void UART_CallBack_RXC (void(*PtrFunction)(void))
{
	Private_UART_CallBack_RXC=PtrFunction;
}

void UART_CallBack_UDRE(void(*PtrFunction)(void))
{
	Private_UART_CallBack_UDRE=PtrFunction;
}

void UART_CallBack_TXC(void(*PtrFunction)(void))
{
	Private_UART_CallBack_TXC=PtrFunction;
}


// Receive Complete Interrupt Request
void __vector_13(void) __attribute__((signal));
void __vector_13(void)
{
	if (Private_UART_CallBack_RXC!=NULL)
	{
		Private_UART_CallBack_RXC();
	}
}

// Data Register Empty Interrupt Request
void __vector_14(void) __attribute__((signal));
void __vector_14()
{
	if (Private_UART_CallBack_UDRE!=NULL)
	{
		Private_UART_CallBack_UDRE();
	} 
}

// Transmit Complete Interrupt Request
void __vector_15(void) __attribute__((signal));
void __vector_15()
{
	if (Private_UART_CallBack_TXC!=NULL)
	{
		Private_UART_CallBack_TXC();
	} 
}