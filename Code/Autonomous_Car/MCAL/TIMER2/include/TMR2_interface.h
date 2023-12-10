/*
 * TMR2_interface.h
 *
 * Created: 24-Sep-23 10:34:29 PM
 *  Author: M5_Autonomous_Car_TEAM
 */ 


#ifndef TMR2_INTERFACE_H_
#define TMR2_INTERFACE_H_

void TMR2_init                                      (void);
void TMR2_Start                                     (void);
void TMR2_Stop                                      (void);

void TMR2_SetDelay_ms_UsingCTC                      (u16 Delay_ms);
void TMR2_SetDutyCycleValue_FastPWM                 (f32 DutyCycle);
void TMR2_SetDutyCycleValue_PhaseCorrect            (f32 DutyCycle);

void TMR2_SetCallBackOverFlow                       (void (*PtrToFunc)(void));
void TMR2_SetCallBackCTC                            (void (*PtrToFunc)(void));



#endif /* TMR2_INTERFACE_H_ */