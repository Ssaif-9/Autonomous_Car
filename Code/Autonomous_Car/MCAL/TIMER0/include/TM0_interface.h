/*
 * TM0_interface.h
 *
 * Created: 9/16/2023 11:08:22 AM
 *  Author: ayman
 */ 


#ifndef TM0_INTERFACE_H_
#define TM0_INTERFACE_H_


#define TMR0_NORMAL_MODE    1
#define TMR0_CTC_MODE       2
#define TMR0_FAST_PWM_MODE  3


void TM0_init(void);
void TM0_start(void);
void TMR0_setCompareMatchValue(u8 compareValue);
void TM0_stop(void);
void TM0_setCALLbACK(void(*ptr)(void));
void TMR0_setDelayms_usingCTC(u16 delay_ms);
void TMR0_setDutyCycle(u8 duty);


#endif /* TM0_INTERFACE_H_ */