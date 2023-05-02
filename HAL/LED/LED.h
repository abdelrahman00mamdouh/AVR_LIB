/*
 * LED.h
 *
 * Created: 1/18/2023 7:56:56 PM
 *  Author: abdel
 */ 

#include "LED_Config.h"

#ifndef LED_H_
#define LED_H_


void LED_Init (LED_ID LED_Number);

void LED_On (LED_ID LED_Number);
void LED_OFF(LED_ID LED_Number);


#endif /* LED_H_ */