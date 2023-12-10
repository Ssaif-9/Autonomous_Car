/*
 * LDR_interface.h
 *
 * Created: 07-Dec-23 10:41:02 PM
 *  Author: M5_Autonomous_Car_TEAM
 */ 


#ifndef LDR_INTERFACE_H_
#define LDR_INTERFACE_H_


void LDR_init           (u8 PortId ,u8 PinId);
void LDR_ReadValue      (u8 ChannalId,u16 *AnalogLdrValue);


#endif /* LDR_INTERFACE_H_ */