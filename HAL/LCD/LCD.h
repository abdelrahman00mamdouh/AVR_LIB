/*
 * LCD.h
 *
 *  Created on: Jan 22, 2023
 *      Author: AMIT
 */
#include "LCD_Config.h"

#ifndef HAL_LCD_LCD_H_
#define HAL_LCD_LCD_H_

void LCD_Init(void);
void LCD_Write_Command(uint8 Command);
void LCD_Write_chr(uint8 Data);
void LCD_Write_String(uint8 * Str);
void LCD_GoTo_Position(uint8 row, uint8 col);
void LCD_Store_cstm_chr(uint8* Pattern,uint8 CGRAM_Index);
void LCD_Disp_cstm_chr(uint8 CGRAM_Index);


#endif /* HAL_LCD_LCD_H_ */
