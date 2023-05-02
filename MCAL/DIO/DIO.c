/*
 * DIO.c
 *
 * Created: 1/18/2023 4:46:52 PM
 *  Author: abdel
 */ 
#include "DIO.h"

void DIO_Set_Port_Direction ( DIO_PORT_ID Port_ID, DIO_Port_Direction Direction){
	
	if (Direction==OUTPUT)
	{
		switch (Port_ID)
		{
			case PORTA: DDRA_Register=0xFF; break;
			case PORTB: DDRB_Register=0xFF; break;
			case PORTC: DDRC_Register=0xFF; break;
			case PORTD: DDRD_Register=0xFF; break;
		}
	}
	
	else if (Direction==INPUT)
	{
		switch(Port_ID)
		{
			case PORTA: DDRA_Register=0x00;break;
			case PORTB: DDRB_Register=0x00;break;
			case PORTC: DDRC_Register=0x00;break;
			case PORTD: DDRD_Register=0x00;break;
		}
	}
}
void DIO_Set_Port_Value ( DIO_PORT_ID Port_ID, uint8 value){
	
	switch(Port_ID){
			case PORTA: PORTA_Register=value;break;
			case PORTB: PORTB_Register=value;break;
			case PORTC: PORTC_Register=value;break;
			case PORTD: PORTD_Register=value;break;
	}
	
}


void DIO_Set_Pin_Direction ( DIO_PORT_ID Port_ID, DIO_pin_ID pin_ID, DIO_Port_Direction Direction){
	
	if (Port_ID<=PORTD && pin_ID <=PIN7)
	{
		if (Direction==OUTPUT)
		{
			switch(Port_ID){
				case PORTA:	Set_bit(DDRA_Register,pin_ID); break;
				case PORTB:	Set_bit(DDRB_Register,pin_ID); break;
				case PORTC:	Set_bit(DDRC_Register,pin_ID); break;
				case PORTD:	Set_bit(DDRD_Register,pin_ID); break;
			}
		}
		else if(Direction==INPUT)
		{
			switch(Port_ID){
				case PORTA:	Clr_bit(DDRA_Register,pin_ID); break;
				case PORTB:	Clr_bit(DDRB_Register,pin_ID); break;
				case PORTC:	Clr_bit(DDRC_Register,pin_ID); break;
				case PORTD:	Clr_bit(DDRD_Register,pin_ID); break;
			}
		}
	}
	
	
}
void DIO_Set_Pin_Value ( DIO_PORT_ID Port_ID, DIO_pin_ID pin_ID, DIO_value value){
	
	if (Port_ID<=PORTD && pin_ID<=PIN7)
	{
		if (value==HIGH)
		{
			switch(Port_ID)
			{
				case PORTA:	Set_bit(PORTA_Register,pin_ID); break;
				case PORTB:	Set_bit(PORTB_Register,pin_ID); break;
				case PORTC:	Set_bit(PORTC_Register,pin_ID); break;
				case PORTD:	Set_bit(PORTD_Register,pin_ID); break;
			}
		}
		
		else if (value==LOW)
		{
			switch(Port_ID)
			{
				case PORTA:	Clr_bit(PORTA_Register,pin_ID); break;
				case PORTB:	Clr_bit(PORTB_Register,pin_ID); break;
				case PORTC:	Clr_bit(PORTC_Register,pin_ID); break;
				case PORTD:	Clr_bit(PORTD_Register,pin_ID); break;
			}
		}
	}
	
	
}
void DIO_Toggle_pin_Value(DIO_PORT_ID Port_ID, DIO_pin_ID pin_ID){
	
	if (Port_ID<=PORTD && pin_ID<=PIN7)
	{
		switch(Port_ID)
		{
			case PORTA: Toggle_bit(PINA_register,pin_ID); break;
			case PORTB: Toggle_bit(PINB_register,pin_ID); break;
			case PORTC: Toggle_bit(PINC_register,pin_ID); break;
			case PORTD: Toggle_bit(PIND_register,pin_ID); break;
		}
	}
	
}
DIO_value DIO_Get_Pin_Value (DIO_PORT_ID Port_ID, DIO_pin_ID pin_ID){
	DIO_value volatile pin_value=0;
	
	if (Port_ID<=PORTD && pin_ID<=PIN7)
	{
			switch(Port_ID)
			{
				case PORTA:	pin_value=Get_bit(PINA_register,pin_ID); break;
				case PORTB:	pin_value=Get_bit(PINB_register,pin_ID); break;
				case PORTC:	pin_value=Get_bit(PINC_register,pin_ID); break;
				case PORTD:	pin_value=Get_bit(PIND_register,pin_ID); break;
			}
		}
	
	return pin_value;          
}
