/*
 * ADC_interface.h
 *
 * Created: 15-Sep-23 8:38:23 AM
 *  Author: M5_Autonomous_Car_TEAM
 */ 


#ifndef ADC_INTERFACE_H_
#define ADC_INTERFACE_H_

#define ADC_Prescaller_2            2
#define ADC_Prescaller_4            4
#define ADC_Prescaller_8            8
#define ADC_Prescaller_16           16
#define ADC_Prescaller_32           32
#define ADC_Prescaller_64           64
#define ADC_Prescaller_128          128


#define ADC_REFERENCE_AVCC        1
#define ADC_REFERENCE_AREF        2
#define ADC_REFERENCE_INTERNAL    3

#define ADC_CHANNEL_0             0
#define ADC_CHANNEL_1             1
#define ADC_CHANNEL_2             2
#define ADC_CHANNEL_3             3
#define ADC_CHANNEL_4             4
#define ADC_CHANNEL_5             5
#define ADC_CHANNEL_6             6
#define ADC_CHANNEL_7             7

void ADC_init                     (u8 RefrenceVolt,u8 ADC_Prescaller);

void ADC_ReadDigitalValue         (u8 ChannelId ,u16* DigitalValue);

void ADC_SetCallBackADC           (void (*PtrToFunc)(void));

#endif /* ADC_INTERFACE_H_ */