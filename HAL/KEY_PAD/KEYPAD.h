/*
 * KEYPAD.H
 *
 *  Created on: Jan 24, 2023
 *      Author: AMIT
 */

#include"KEYPAD_Config.h"

#ifndef HAL_KEYPAD_KEYPAD_H_
#define HAL_KEYPAD_KEYPAD_H_

void Keypad_Init(void);

uint8 Is_keypad_pressed (void);

#endif /* HAL_KEYPAD_KEYPAD_H_ */
