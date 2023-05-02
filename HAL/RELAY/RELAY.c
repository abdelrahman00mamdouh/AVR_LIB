/*
 * RELAY.c
 *
 * Created: 5/1/2023 11:13:11 AM
 *  Author: abdel
 */ 

#include "RELAY.h"

void RELAY_Init (void){
	
		DIO_Set_Pin_Direction(RELAY_PORT,RELAY_PIN,OUTPUT);

}

void RELAY_On (void){

		DIO_Set_Pin_Value(RELAY_PORT,RELAY_PIN,HIGH);

}

void RELAY_OFF(void){
 
		DIO_Set_Pin_Value(RELAY_PORT,RELAY_PIN,LOW);
 
}