/*
 * PUSH_BUTTON_Config.h
 *
 * Created: 1/18/2023 8:45:44 PM
 *  Author: abdel
 */ 

#include "..\..\MCAL\DIO\DIO.h"

#ifndef PUSH_BUTTON_CONFIG_H_
#define PUSH_BUTTON_CONFIG_H_

typedef enum{
	Push_Button0,
	Push_Button1,	
	Push_Button2,	
	}PB_ID;
	
	
#define PB0_Port	PORTB
#define PB0_pin		PIN0

#define PB1_Port	PORTD
#define PB1_pin		PIN6

#define PB2_Port	PORTD
#define PB2_pin		PIN2


#endif /* PUSH_BUTTON_CONFIG_H_ */
