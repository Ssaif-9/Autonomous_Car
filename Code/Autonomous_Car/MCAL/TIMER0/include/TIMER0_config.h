/*
 * TIMER0_config.h
 *
 * Created: 16-Sep-23 11:05:35 AM
 *  Author: M5_Autonomous_Car_TEAM
 */ 


#ifndef TIMER0_CONFIG_H_
#define TIMER0_CONFIG_H_



#define  TIMER0_MODE           TIMER0_NormalMode         // TIMER0_CTC || TIMER0_NormalMode || TIMER0_FAST_PWM_MODE
#define  TIMER0_Prescaller     TIMER0_Prescaller_1       // TIMER0_Prescaller_1 || TIMER0_Prescaller_8 || TIMER0_Prescaller_64 || TIMER0_Prescaller_256 || TIMER0_Prescaller_1024
#define  FastPWM_Mode          FastPWM_NonInverting_Mode   // FastPWM_NonInverting_Mode || FastPWM_Inverting_Mode


/*	For CTC Mode	*/
//#define TMR0_CTC_Counter     2500            

/*	For Normal Mode	*/
#define TMR0_PreloadValue     0
#define TMR0_OverFlowCounter  0 


#endif /* TIMER0_CONFIG_H_ */