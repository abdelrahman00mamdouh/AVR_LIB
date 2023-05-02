/*
 * LED_Config.h
 *
 * Created: 1/18/2023 7:58:23 PM
 *  Author: abdel
 */ 

#include "..\..\MCAL\DIO\DIO.h"

#ifndef LED_CONFIG_H_
#define LED_CONFIG_H_

typedef enum{
	LED0,
	LED1,
	LED2
	}LED_ID;
	
	#define LED0_PORT	PORTC
	#define LED0_PIN	PIN2
	
	#define LED1_PORT	PORTC
	#define LED1_PIN	PIN7
		
	#define LED2_PORT	PORTD
	#define LED2_PIN	PIN3
	



#endif /* LED_CONFIG_H_ */
