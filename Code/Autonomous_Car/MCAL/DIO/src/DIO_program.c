/*
 * DIO_program.c
 *
 * Created: 01-Sep-23 10:01:14 AM
 *  Author: SEIF EL-DIN SOLTAN
 */ 



/*UTILITES*/
#include "../../../UTILITES/STD_TYPE.h"
#include "../../../UTILITES/BIT_MATH.h"
/*MCAL*/
#include "../include/DIO_private.h"
#include "../include/DIO_interface.h"



DIO_ERRORSTATUS DIO_SetPinDirection(u8 PortId,u8 PinId,u8 PInDirection)
{
	DIO_ERRORSTATUS ErrorStatus = DIO_OK ;     
	if ((PortId <= DIO_PORTD) && (PinId <= DIO_PIN7) && (PInDirection<=DIO_PIN_OUTPUT))
	{
    	switch(PortId)
    	{
		   case DIO_PORTA:
		   (DIO_PIN_OUTPUT == PInDirection) ? (SET_BIT(DDRA_REG,PinId)) : (CLR_BIT(DDRA_REG,PinId)) ;
		   break;
		   
		   case DIO_PORTB:
		   (DIO_PIN_OUTPUT == PInDirection) ? (SET_BIT(DDRB_REG,PinId)) : (CLR_BIT(DDRB_REG,PinId)) ;
		   break;
		   
		   case DIO_PORTC:
		   (DIO_PIN_OUTPUT == PInDirection) ? (SET_BIT(DDRC_REG,PinId)) :(CLR_BIT(DDRC_REG,PinId));
		   break;
		   
		   case DIO_PORTD:
		   (DIO_PIN_OUTPUT == PInDirection) ? (SET_BIT(DDRD_REG,PinId)) : (CLR_BIT(DDRD_REG,PinId));
		   break;
	    }	
	} 
	else
	{
		ErrorStatus = DIO_NOK;
	}
	return ErrorStatus;
}

DIO_ERRORSTATUS DIO_SetPinValue(u8 PortId,u8 PinId,u8 PinValue)
{
	DIO_ERRORSTATUS ErrorStatus = DIO_OK ;
	if ((PortId <= DIO_PORTD) && (PinId <= DIO_PIN7) && (PinValue<=DIO_PIN_HIGH))
	{
			switch (PortId)
			{
				case DIO_PORTA:
			    (DIO_PIN_HIGH == PinValue ) ? (SET_BIT(PORTA_REG,PinId)) : (CLR_BIT(PORTA_REG,PinId)) ;
			    break;
			    
			    case DIO_PORTB:
			    (DIO_PIN_HIGH == PinValue ) ? (SET_BIT(PORTB_REG,PinId)) : (CLR_BIT(PORTB_REG,PinId)) ;
			    break;
			    
			    case DIO_PORTC:
			    (DIO_PIN_HIGH == PinValue ) ? (SET_BIT(PORTC_REG,PinId)) : (CLR_BIT(PORTC_REG,PinId)) ;
			    break;
			    
			    case DIO_PORTD:
			    (DIO_PIN_HIGH == PinValue ) ? (SET_BIT(PORTD_REG,PinId)) : (CLR_BIT(PORTD_REG,PinId)) ;
			    break;
			}	
		} 
	else
	{
		ErrorStatus = DIO_NOK;
	}
	return ErrorStatus;
}
	
DIO_ERRORSTATUS DIO_TogglePinValue    (u8 PortId ,u8 PinId) //To Test Work Or not 
{
	DIO_ERRORSTATUS ErrorStatus = DIO_OK ;              
	if ((PortId <= DIO_PORTD) && (PinId <= DIO_PIN7))  //edit all
	{
		switch (PortId)
		{
			case DIO_PORTA:
			TGL_BIT(PORTA_REG,PinId);
			break;
			
			case DIO_PORTB:
			TGL_BIT(PORTB_REG,PinId);
			break;
			
			case DIO_PORTC:
			TGL_BIT(PORTC_REG,PinId);
			break;
			
			case DIO_PORTD:
			TGL_BIT(PORTD_REG,PinId);
			break;
		}
	} 
	else
	{
		ErrorStatus = DIO_NOK;
	}
	return ErrorStatus;
}
	
	
DIO_ERRORSTATUS DIO_ReadValue (u8 PortId,u8 PinId , u8* PinValue )
{
	DIO_ERRORSTATUS ErrorStatus = DIO_OK;
	if ((PortId <= DIO_PORTD) && (PinId <= DIO_PIN7) && (PinValue!=NULL)) //wild pointer 
	{
		switch (PortId)
		{
			case DIO_PORTA:
			*PinValue= GET_BIT(PINA_REG,PinId);
			break;
			
			case DIO_PORTB:
			*PinValue= GET_BIT(PINB_REG,PinId);
			break;
			
			case DIO_PORTC:
			*PinValue= GET_BIT(PINC_REG,PinId);
			break;
			
			case DIO_PORTD:
			*PinValue= GET_BIT(PIND_REG,PinId);
			break;
		}
	} 
	else
	{
		ErrorStatus = DIO_NOK;
	}
	return ErrorStatus;
}
 
 DIO_ERRORSTATUS  DIO_activePinInPullUpResistance ( u8 PortId ,u8 PinId)
{
	 DIO_ERRORSTATUS ErrorStatus = DIO_OK;
	 if ((PortId <= DIO_PORTD) && (PinId <= DIO_PIN7))
	 {
		 switch(PortId)
		 {
			 case DIO_PORTA:
			 SET_BIT(PORTA_REG,PinId);
			 break;
			 
			 case DIO_PORTB:
			 SET_BIT(PORTB_REG,PinId);
			 break;
			 
			 case DIO_PORTC:
			 SET_BIT(PORTC_REG,PinId);
			 break;
			 
			 case DIO_PORTD:
			 SET_BIT(PORTD_REG,PinId);
			 break;
	      } 
	 }	 
	 else
	 {
		ErrorStatus = DIO_NOK;
	 }
	 return ErrorStatus;
}



DIO_ERRORSTATUS DIO_setPortDirection(u8 PortId, u8 PortDirection)
{
	DIO_ERRORSTATUS ErrorStatus = DIO_OK;
	if ( (PortId<=DIO_PORTD))
	{
		switch(PortId)
		{
			case DIO_PORTA:
			(DIO_PORT_OUTPUT == PortDirection)?(SET_REG(DDRA_REG)):(CLR_REG(DDRA_REG));
			break;
			
			case DIO_PORTB:
			(DIO_PORT_OUTPUT == PortDirection)?(SET_REG(DDRB_REG)):(CLR_REG(DDRB_REG));
			break;
			
			case DIO_PORTC:
			(DIO_PORT_OUTPUT == PortDirection)?(SET_REG(DDRC_REG)):(CLR_REG(DDRC_REG));
			break;
			
			case DIO_PORTD:
			(DIO_PORT_OUTPUT == PortDirection)?(SET_REG(DDRD_REG)):(CLR_REG(DDRD_REG));
			break;
		}
	} 
	else
	{
		ErrorStatus = DIO_NOK;
	}
	return ErrorStatus;
}


DIO_ERRORSTATUS DIO_setPortValue (u8 PortId, u8 PortValue)
{
	DIO_ERRORSTATUS ErrorStatus = DIO_OK;
	if ( (PortId<=DIO_PORTD) )
	{
		switch(PortId)
		{
			case DIO_PORTA:
			PORTA_REG=PortValue;
			break;
			
			case DIO_PORTB:
			PORTB_REG=PortValue;
			break;
			
			case DIO_PORTC:
			PORTC_REG=PortValue;
			break;
			
			case DIO_PORTD:
			PORTD_REG=PortValue;
			break;
		}
	}
	else
	{
	ErrorStatus = DIO_NOK;
	}
	return ErrorStatus;
}


DIO_ERRORSTATUS DIO_getPortValue(u8 PortId, u8* PortValue)
{
	DIO_ERRORSTATUS ErrorStatus = DIO_OK;
	if ( (PortId<=DIO_PORTD) && (PortValue!=NULL) )
	{
		switch(PortId)
		{
			case DIO_PORTA:
			*PortValue =PORTA_REG;
			break;
			
			case DIO_PORTB:
		    *PortValue =PORTB_REG;
			break;
			
			case DIO_PORTC:
			*PortValue =PORTC_REG;
			break;
			
			case DIO_PORTD:
			*PortValue =PORTD_REG;
			break;
		}
	}
	else
	{
		ErrorStatus = DIO_NOK;
	}
	return ErrorStatus;
}


DIO_ERRORSTATUS DIO_togglePortValue (u8 PortId)
{
	DIO_ERRORSTATUS ErrorStatus = DIO_OK;
	if ( (PortId<=DIO_PORTD))
	{
		switch(PortId)
		{
			case DIO_PORTA:
			TGL_REG(PORTA_REG);
			break;
			
			case DIO_PORTB:
			TGL_REG(PORTB_REG);
			break;
			
			case DIO_PORTC:
			TGL_REG(PORTC_REG);
			break;
			
			case DIO_PORTD:
			TGL_REG(PORTD_REG);
			break;
		}
	}
	else
	{
		ErrorStatus = DIO_NOK;
	}
	return ErrorStatus;
}


DIO_ERRORSTATUS DIO_activePortInPullUpResistance(u8 PortId)
{
	DIO_ERRORSTATUS ErrorStatus = DIO_OK;
	if ( (PortId<=DIO_PORTD))
	{
		switch(PortId)
		{
			case DIO_PORTA:
			SET_REG(PORTA_REG);
			break;
			
			case DIO_PORTB:
			SET_REG(PORTB_REG);
			break;
			
			case DIO_PORTC:
			SET_REG(PORTC_REG);
			break;
			
			case DIO_PORTD:
			SET_REG(PORTD_REG);
			break;
		}
	}
	else
	{
		ErrorStatus = DIO_NOK;
	}
	return ErrorStatus;
	
}

