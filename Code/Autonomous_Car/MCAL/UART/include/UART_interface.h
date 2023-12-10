/*
 * UART_interface.h
 *
 * Created: 29-Sep-23 11:38:48 AM
 *  Author: M5_Autonomous_Car_TEAM
 */ 


#ifndef UART_INTERFACE_H_
#define UART_INTERFACE_H_

void UART_init              (void);
void UART_ReceiveChar       (u8* ReciveData);

void UART_TransmiteChar     (u8 TransmiteData);
void UART_TransmiteString   (u8 *TransmiteData);
void UART_CallBack_RXC      (void(*PtrFunction)(void));
void UART_CallBack_UDRE     (void(*PtrFunction)(void));
void UART_CallBack_TXC      (void(*PtrFunction)(void));


#endif /* UART_INTERFACE_H_ */