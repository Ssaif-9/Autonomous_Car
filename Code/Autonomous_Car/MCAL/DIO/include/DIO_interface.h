/*
 * IncFile1.h
 *
 * Created: 01-Sep-23 10:01:31 AM
 *  Author: SEIF EL-DIN SOLTAN
 */ 


#ifndef INCFILE1_H_
#define INCFILE1_H_
					            
#define DIO_PORTA                0
#define DIO_PORTB                1
#define DIO_PORTC                2
#define DIO_PORTD                3
					            
					            
#define DIO_PIN0                 0
#define DIO_PIN1                 1
#define DIO_PIN2                 2
#define DIO_PIN3                 3
#define DIO_PIN4                 4
#define DIO_PIN5                 5
#define DIO_PIN6                 6
#define DIO_PIN7                 7
					            
#define DIO_PIN_INPUT            0
#define DIO_PIN_OUTPUT           1 
					            
#define DIO_PIN_LOW              0
#define DIO_PIN_HIGH             1

#define DIO_PORT_INPUT            0x00
#define DIO_PORT_OUTPUT           0xff

#define DIO_PORT_LOW              0x00
#define DIO_PORT_HIGH             0xff


					            
typedef enum {
	          DIO_OK,
	          DIO_NOK
			 } DIO_ERRORSTATUS;
					            
      


DIO_ERRORSTATUS    DIO_SetPinDirection              (u8 PortId,u8 PinId,u8 PInDirection);
DIO_ERRORSTATUS    DIO_SetPinValue                  (u8 PortId,u8 PinId,u8 PinValue);
DIO_ERRORSTATUS    DIO_TogglePinValue               (u8 PortId ,u8 PinId);
DIO_ERRORSTATUS    DIO_ReadValue                    (u8 PortId,u8 PinId,u8* PinValue);
DIO_ERRORSTATUS    DIO_activePinInPullUpResistance  ( u8 PortId ,u8 PinId);

/* Port Apis */

DIO_ERRORSTATUS DIO_setPortDirection                (u8 PortId, u8 PortDirection);
DIO_ERRORSTATUS DIO_setPortValue                    (u8 PortId, u8 PortValue);
DIO_ERRORSTATUS DIO_getPortValue                    (u8 PortId, u8* PortValue);
DIO_ERRORSTATUS DIO_togglePortValue                 (u8 PortId);
DIO_ERRORSTATUS DIO_activePortInPullUpResistance    (u8 PortId);


#endif /* INCFILE1_H_ */