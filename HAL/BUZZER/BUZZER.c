/*
 * BUZZER.c
 *
 * Created: 5/1/2023 11:12:17 AM
 *  Author: abdel
 */ 

#include "BUZZER.h"

void BUZZER_Init (void){
	
	DIO_Set_Pin_Direction(BUZZER_PORT,BUZZER_PIN,OUTPUT);

}

void BUZZER_On (void){

	DIO_Set_Pin_Value(BUZZER_PORT,BUZZER_PIN,HIGH);

}

void BUZZER_OFF(void){
	
	DIO_Set_Pin_Value(BUZZER_PORT,BUZZER_PIN,LOW);
	
}