/*
 * LCD_Config.h
 *
 *  Created on: Jan 22, 2023
 *      Author: AMIT
 */
#include "../../MCAL/DIO/DIO.h"



#ifndef HAL_LCD_LCD_CONFIG_H_
#define HAL_LCD_LCD_CONFIG_H_

#define Four_BIT_MODE	1
#define Eight_BIT_MODE	0
///////////////////////////////////////////////////////////////////////////
#define LCD_DATA_PORT	PORTA

#define LCD_PIN0	PIN0
#define LCD_PIN1	PIN1
#define LCD_PIN2	PIN2
#define LCD_PIN3	PIN3

#define LCD_PIN4	PIN4
#define LCD_PIN5	PIN5
#define LCD_PIN6	PIN6
#define LCD_PIN7	PIN7
///////////////////////////////////////////////////////////////////////////
#define LCD_CTRL_PORT	PORTB

#define LCD_RS		PIN1
#define LCD_RW		PIN2
#define LCD_Enable	PIN3
//////////////////////////////////////////////////////////////////////////
#define LCD_CLR			0x00

#define LCD_Cursor_ON
#define LCD_Cursor_OFF
#define LCD_Cursor_Home 	0x80
/////////////////////////////////////////////////////////////////////////


#endif /* HAL_LCD_LCD_CONFIG_H_ */
