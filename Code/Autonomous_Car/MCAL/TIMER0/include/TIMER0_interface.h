/*
 * TIMER0_interface.h
 *
 * Created: 16-Sep-23 11:05:09 AM
 *  Author: M5_Autonomous_Car_TEAM
 */ 


#ifndef TIMER0_INTERFACE_H_
#define TIMER0_INTERFACE_H_



void TMR0_init                                      (void);
void TMR0_Start                                     (void);
void TMR0_Stop                                      (void);
//void TMR0_SetCompareMatchValue                      (u8 CompareValue);
void TMR0_SetDelay_ms_UsingCTC                      (u16 Delay_ms);
void TMR0_SetCompareMatchValue_FastPWM_NonInverting (f32 DutyCycle);
void TMR0_SetCallBackOverFlow                       (void (*PtrToFunc)(void));
void TMR0_SetCallBackCTC                            (void (*PtrToFunc)(void));



#endif /* TIMER0_INTERFACE_H_ */