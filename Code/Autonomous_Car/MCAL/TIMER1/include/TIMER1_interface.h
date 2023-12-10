/*
 * TIMER1_interface.h
 *
 * Created: 22-Sep-23 8:34:37 AM
 *  Author: M5_Autonomous_Car_TEAM
 */ 


#ifndef TIMER1_INTERFACE_H_
#define TIMER1_INTERFACE_H_


void TMR1_init                         (void);
void TMR1_Start                        (void);
void TMR1_Stop                         (void);
void TMR1_SetDutyCycle_And_Freq_Value  (u16 Freq ,f32 Duty);

#endif /* TIMER1_INTERFACE_H_ */