/*
 * UART_config.h
 *
 * Created: 29-Sep-23 11:39:20 AM
 *  Author: SEIF EL_DIN SULTAN
 */ 


#ifndef UART_CONFIG_H_
#define UART_CONFIG_H_

#define  UART_SelectedBoudRate 9600 // 2400 || 4800 || 9600 || 14400 || 19200 || 28800 || 38400 || 57600 || 76800 || 115200 || 230400 ||250000

#define UART_TX_PORT   DIO_PORTD
#define UART_TX_PIN    DIO_PIN1

#define UART_RX_PORT   DIO_PORTD
#define UART_RX_PIN    DIO_PIN0


#endif /* UART_CONFIG_H_ */