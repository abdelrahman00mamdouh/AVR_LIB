/*
 * KEYPAD.c
 *
 *  Created on: Jan 24, 2023
 *      Author: AMIT
 */

#include "KEYPAD.h"

uint8 keypad[4][4] = {	{'1','2','3','A'},
						{'4','5','6','B'},
						{'7','8','9','C'},
						{'*','0','#','D'}   };

void Keypad_Init(void){
	DIO_Set_Pin_Value(Keypad_Row_Port,Keypad_Row0,LOW);
	DIO_Set_Pin_Value(Keypad_Row_Port,Keypad_Row1,LOW);
	DIO_Set_Pin_Value(Keypad_Row_Port,Keypad_Row2,LOW);
	DIO_Set_Pin_Value(Keypad_Row_Port,Keypad_Row3,LOW);

	DIO_Set_Pin_Value(Keypad_Col_Port,Keypad_Col0,LOW);
	DIO_Set_Pin_Value(Keypad_Col_Port,Keypad_Col1,LOW);
	DIO_Set_Pin_Value(Keypad_Col_Port,Keypad_Col2,LOW);
	DIO_Set_Pin_Value(Keypad_Col_Port,Keypad_Col3,LOW);

	DIO_Set_Pin_Value(Keypad_Row_Port,Keypad_Row0,HIGH);				// pull-up rows
	DIO_Set_Pin_Value(Keypad_Row_Port,Keypad_Row1,HIGH);
	DIO_Set_Pin_Value(Keypad_Row_Port,Keypad_Row2,HIGH);
	DIO_Set_Pin_Value(Keypad_Row_Port,Keypad_Row3,HIGH);
}


uint8 Is_keypad_pressed(void){
	unsigned char row , colm;
	for (colm = 0 ; colm <= 3 ; colm++)
	{
		_delay_ms(30);
		DIO_Set_Pin_Direction(Keypad_Col_Port,Keypad_Col0,INPUT);		// Tri-state all columns with high impedance
		DIO_Set_Pin_Direction(Keypad_Col_Port,Keypad_Col1,INPUT);
		DIO_Set_Pin_Direction(Keypad_Col_Port,Keypad_Col2,INPUT);
		DIO_Set_Pin_Direction(Keypad_Col_Port,Keypad_Col3,INPUT);
		DIO_Set_Pin_Direction(Keypad_Col_Port,colm+4,OUTPUT);			// make only current column as output
		DIO_Set_Pin_Value (Keypad_Col_Port,colm+4,LOW);				// make only current column output is low
		for (row = 0 ; row <= 3 ; row++)
		{
			if (DIO_Get_Pin_Value(Keypad_Col_Port,row)== 0)				// key considered pressed when pin reads 0
			{
					return keypad[row][colm];
			}
		}
	}
	return 'p';														// return p if no key press is detected
}
