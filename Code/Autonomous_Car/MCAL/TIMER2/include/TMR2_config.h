/*
 * TMR2_config.h
 *
 * Created: 24-Sep-23 10:34:40 PM
 *  Author: M5_Autonomous_Car_TEAM
 */ 


#ifndef TMR2_CONFIG_H_
#define TMR2_CONFIG_H_

#define TMR2_PRESCALLER                 TMR2_PRESCALLER_64                   // TMR2_PRESCALLER_1 || TMR2_PRESCALLER_8 || TMR2_PRESCALLER_32  || TMR2_PRESCALLER_64  || TMR2_PRESCALLER_128  ||TMR2_PRESCALLER_256 ||TMR2_PRESCALLER_1024
#define TMR2_MODE                       TMR2_PHASECORRECT_MODE               //  TMR2_NORMAL_MODE  || TMR2_CTC_MODE || TMR2_PHASECORRECT_MODE || TMR2_FASTPWM_MODE
#define TMR2_SelectFastPWM_Mode         TMR2_FastPWM_Inverting_Mode       // TMR2_FastPWM_NonInverting_Mode || TMR2_FastPWM_Inverting_Mode
#define TMR2_SelectPaseCorrect_Mode     TMR2_PaseCorrect_Inverting_Mode   // TMR2_PaseCorrect_NonInverting_Mode || TMR2_PaseCorrect_Inverting_Mode


/*	For Normal Mode	*/
#define TMR2_OverFlowCounter          977
#define TMR2_PreloadValue             113

#endif /* TMR2_CONFIG_H_ */