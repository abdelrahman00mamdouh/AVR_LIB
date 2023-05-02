/*
 * PUSH_BUTTON.h
 *
 * Created: 1/18/2023 8:45:02 PM
 *  Author: abdel
 */ 

#include "PUSH_BUTTON_Config.h"

#ifndef PUSH_BUTTON_H_
#define PUSH_BUTTON_H_

void Push_Button_Init(PB_ID Push_Button_Id);

DIO_value Push_Button_pressed(PB_ID Push_Button_Id);


#endif /* PUSH_BUTTON_H_ */