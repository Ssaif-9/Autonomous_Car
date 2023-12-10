/*
 * BLUETOOTH_interface.h
 *
 * Created: 09-Oct-23 3:09:52 PM
 *  Author: M5_Autonomous_Car_TEAM
 */ 


#ifndef BLUETOOTH_INTERFACE_H_
#define BLUETOOTH_INTERFACE_H_

void BLUETOOTH_init                 (void);
void BLUETOOTH_TransimitChar        (u8 TransimitData);
void BLUETOOTH_TransimitString      (u8* TransimitData);
void BLUETOOTH_ReceiveChar          (u8* ReceiveData);


#endif /* BLUETOOTH_INTERFACE_H_ */