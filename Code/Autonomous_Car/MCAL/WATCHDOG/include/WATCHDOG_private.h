/*
 * WATCHDOG_private.h
 *
 * Created: 07-Dec-23 10:53:04 PM
 *  Author: SEIF EL_DIN SULTAN
 */ 


#ifndef WATCHDOG_PRIVATE_H_
#define WATCHDOG_PRIVATE_H_


#define MCUCSR                   (*(volatile u8*)0X54) // for WatchDog Timer Flag [MCU Control and Status Register]
#define WDTCR                    (*(volatile u8*)0X41) // for WatchDog Control Register



#endif /* WATCHDOG_PRIVATE_H_ */