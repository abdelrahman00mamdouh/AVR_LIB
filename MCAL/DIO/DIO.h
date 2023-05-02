/*
 * DIO.h
 *
 * Created: 1/18/2023 4:49:01 PM
 *  Author: abdel
 */ 
#include "DIO_Config.h"



#ifndef DIO_H_
#define DIO_H_

void DIO_Set_Port_Direction ( DIO_PORT_ID Port_ID, DIO_Port_Direction Direction);
void DIO_Set_Port_Value ( DIO_PORT_ID Port_ID, uint8 value);
uint8 DIO_Get_Port_Value(DIO_PORT_ID Port_ID);

void DIO_Set_Pin_Direction ( DIO_PORT_ID Port_ID, DIO_pin_ID pin_ID, DIO_Port_Direction Direction);
void DIO_Set_Pin_Value ( DIO_PORT_ID Port_ID, DIO_pin_ID pin_ID, DIO_value value);
void DIO_Toggle_pin_Value( DIO_PORT_ID Port_ID, DIO_pin_ID pin_ID);
DIO_value DIO_Get_Pin_Value ( DIO_PORT_ID Port_ID, DIO_pin_ID pin_ID);

#endif /* DIO_H_ */
