/*
 * WATCHDOG_interface.h
 *
 * Created: 07-Dec-23 10:52:31 PM
 *  Author: SEIF EL_DIN SULTAN
 */ 


#ifndef WATCHDOG_INTERFACE_H_
#define WATCHDOG_INTERFACE_H_

#define WatchDog_u8_5VCC_TIME_OUT_16_3MS           0x00
#define WatchDog_u8_5VCC_TIME_OUT_32_5MS           0x01
#define WatchDog_u8_5VCC_TIME_OUT_65MS             0x02
#define WatchDog_u8_5VCC_TIME_OUT_0_13SEC          0x03
#define WatchDog_u8_5VCC_TIME_OUT_0_26SEC          0x04
#define WatchDog_u8_5VCC_TIME_OUT_0_52SEC          0x05
#define WatchDog_u8_5VCC_TIME_OUT_1_0SEC           0x06
#define WatchDog_u8_5VCC_TIME_OUT_2_1SEC           0x07


void  WATCHDOG_Enable(u8 Time);

void  WATCHDOG_Disable();



#endif /* WATCHDOG_INTERFACE_H_ */