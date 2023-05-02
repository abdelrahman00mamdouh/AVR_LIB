/*
 * LED.c
 *
 * Created: 1/18/2023 7:56:42 PM
 *  Author: abdel
 */ 
#include "LED.h"

void LED_Init (LED_ID LED_Number){
	
	if (LED_Number==LED0)
	{
		DIO_Set_Pin_Direction(LED0_PORT,LED0_PIN,OUTPUT);
	}
	else if (LED_Number==LED1)
	{
	DIO_Set_Pin_Direction(LED1_PORT,LED1_PIN,OUTPUT);
	}
	else if (LED_Number==LED2)
	{
	DIO_Set_Pin_Direction(LED2_PORT,LED2_PIN,OUTPUT);
	}
	
}

void LED_On (LED_ID LED_Number){
	
	if (LED_Number==LED0)
	{
		DIO_Set_Pin_Value(LED0_PORT,LED0_PIN,HIGH);
	}
	else if (LED_Number==LED1)
	{
		DIO_Set_Pin_Value(LED0_PORT,LED1_PIN,HIGH);
	}
	else if (LED_Number==LED2)
	{
		DIO_Set_Pin_Value(LED2_PORT,LED2_PIN,HIGH);
	}
	
}

void LED_OFF(LED_ID LED_Number){
	
		if (LED_Number==LED0)
		{
			DIO_Set_Pin_Value(LED0_PORT,LED0_PIN,LOW);
		}
		else if (LED_Number==LED1)
		{
			DIO_Set_Pin_Value(LED0_PORT,LED1_PIN,LOW);
		}
		else if (LED_Number==LED2)
		{
			DIO_Set_Pin_Value(LED2_PORT,LED2_PIN,LOW);
		}
	
}