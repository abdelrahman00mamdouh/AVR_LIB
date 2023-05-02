/*
 * LCD.c
 *
 *  Created on: Jan 22, 2023
 *      Author: AMIT
 */

#include "LCD.h"


#if Four_BIT_MODE==1
volatile static char Init_Step_Finished=0;
#endif

void LCD_Init(void){

#if Four_BIT_MODE==1


 	DIO_Set_Pin_Direction(LCD_DATA_PORT,LCD_PIN4,OUTPUT);
	DIO_Set_Pin_Direction(LCD_DATA_PORT,LCD_PIN5,OUTPUT);
	DIO_Set_Pin_Direction(LCD_DATA_PORT,LCD_PIN6,OUTPUT);
	DIO_Set_Pin_Direction(LCD_DATA_PORT,LCD_PIN7,OUTPUT);

	DIO_Set_Pin_Direction(LCD_CTRL_PORT,LCD_RS,OUTPUT);
	DIO_Set_Pin_Direction(LCD_CTRL_PORT,LCD_RW,OUTPUT);
	DIO_Set_Pin_Direction(LCD_CTRL_PORT,LCD_Enable,OUTPUT);

	_delay_ms(30);
	LCD_Write_Command(0x20);
	LCD_Write_Command(0x20);
	LCD_Write_Command(0x80);
	_delay_ms(1);
	LCD_Write_Command(0x00);
	LCD_Write_Command(0xF0);
	_delay_ms(1);
	LCD_Write_Command(0x00);
	LCD_Write_Command(0x10);
	_delay_ms(2);

	Init_Step_Finished=1;

#elif Eight_BIT_MODE==1

	DIO_Set_Port_Direction(LCD_DATA_PORT,OUTPUT);

	DIO_Set_Pin_Direction(LCD_CTRL_PORT,LCD_RS,OUTPUT);
	DIO_Set_Pin_Direction(LCD_CTRL_PORT,LCD_RW,OUTPUT);
	DIO_Set_Pin_Direction(LCD_CTRL_PORT,LCD_Enable,OUTPUT);

	_delay_ms(20);		/* LCD Power ON delay always >15ms */
	LCD_Write_Command (0x38);	/* Initialization of 16X2 LCD in 8bit mode */


	LCD_Write_Command (0x01);	/* clear display */

	LCD_Write_Command (0x80);	/* cursor at home position */

#endif

}

void LCD_Write_Command(uint8 Command){

#if Four_BIT_MODE==1

	DIO_Set_Pin_Value(LCD_CTRL_PORT,LCD_RS,LOW);
	DIO_Set_Pin_Value(LCD_CTRL_PORT,LCD_RW,LOW);

	DIO_Set_Pin_Value(LCD_DATA_PORT,LCD_PIN4,Get_bit(Command,4));
	DIO_Set_Pin_Value(LCD_DATA_PORT,LCD_PIN5,Get_bit(Command,5));
	DIO_Set_Pin_Value(LCD_DATA_PORT,LCD_PIN6,Get_bit(Command,6));
	DIO_Set_Pin_Value(LCD_DATA_PORT,LCD_PIN7,Get_bit(Command,7));

	DIO_Set_Pin_Value(LCD_CTRL_PORT,LCD_Enable,HIGH);
	_delay_ms(1);
	DIO_Set_Pin_Value(LCD_CTRL_PORT,LCD_Enable,LOW);

	if(Init_Step_Finished==1){

	DIO_Set_Pin_Value(LCD_DATA_PORT,LCD_PIN4,Get_bit(Command,0));
	DIO_Set_Pin_Value(LCD_DATA_PORT,LCD_PIN5,Get_bit(Command,1));
	DIO_Set_Pin_Value(LCD_DATA_PORT,LCD_PIN6,Get_bit(Command,2));
	DIO_Set_Pin_Value(LCD_DATA_PORT,LCD_PIN7,Get_bit(Command,3));

	DIO_Set_Pin_Value(LCD_CTRL_PORT,LCD_Enable,HIGH);
	_delay_ms(1);
	DIO_Set_Pin_Value(LCD_CTRL_PORT,LCD_Enable,LOW);

	_delay_ms(2);

	}

#elif Eight_BIT_MODE==1



	DIO_Set_Pin_Value(LCD_CTRL_PORT,LCD_RS,LOW);
	DIO_Set_Pin_Value(LCD_CTRL_PORT,LCD_RW,LOW);

	DIO_Set_Port_Value(LCD_DATA_PORT,Command);

	DIO_Set_Pin_Value(LCD_CTRL_PORT,LCD_Enable,HIGH);
	_delay_ms(1);
	DIO_Set_Pin_Value(LCD_CTRL_PORT,LCD_Enable,LOW);
	_delay_ms(3);

#endif

}

void LCD_Write_chr(uint8 Data){

#if Four_BIT_MODE==1

	DIO_Set_Pin_Value(LCD_CTRL_PORT,LCD_RS,HIGH);
	DIO_Set_Pin_Value(LCD_CTRL_PORT,LCD_RW,LOW);

	DIO_Set_Pin_Value(LCD_DATA_PORT,LCD_PIN4,Get_bit(Data,4));
	DIO_Set_Pin_Value(LCD_DATA_PORT,LCD_PIN5,Get_bit(Data,5));
	DIO_Set_Pin_Value(LCD_DATA_PORT,LCD_PIN6,Get_bit(Data,6));
	DIO_Set_Pin_Value(LCD_DATA_PORT,LCD_PIN7,Get_bit(Data,7));

	DIO_Set_Pin_Value(LCD_CTRL_PORT,LCD_Enable,HIGH);
	_delay_ms(1);
	DIO_Set_Pin_Value(LCD_CTRL_PORT,LCD_Enable,LOW);

	DIO_Set_Pin_Value(LCD_DATA_PORT,LCD_PIN4,Get_bit(Data,0));
	DIO_Set_Pin_Value(LCD_DATA_PORT,LCD_PIN5,Get_bit(Data,1));
	DIO_Set_Pin_Value(LCD_DATA_PORT,LCD_PIN6,Get_bit(Data,2));
	DIO_Set_Pin_Value(LCD_DATA_PORT,LCD_PIN7,Get_bit(Data,3));

	DIO_Set_Pin_Value(LCD_CTRL_PORT,LCD_Enable,HIGH);
	_delay_ms(1);
	DIO_Set_Pin_Value(LCD_CTRL_PORT,LCD_Enable,LOW);

	_delay_ms(2);

#elif Eight_BIT_MODE==1



	DIO_Set_Pin_Value(LCD_CTRL_PORT,LCD_RS,HIGH);
	DIO_Set_Pin_Value(LCD_CTRL_PORT,LCD_RW,LOW);

	DIO_Set_Port_Value(LCD_DATA_PORT,Data);

	DIO_Set_Pin_Value(LCD_CTRL_PORT,LCD_Enable,HIGH);
	_delay_ms(1);
	DIO_Set_Pin_Value(LCD_CTRL_PORT,LCD_Enable,LOW);
	_delay_ms(2);

#endif


}

void LCD_Write_String(uint8 * Str){

	uint8 index=0;

	while(Str[index]!=(uint8*)NULL){

LCD_Write_chr(Str[index]);
index++;
	}

	LCD_Write_Command (0x80);
}


void LCD_GoTo_Position(uint8 row, uint8 col){

	volatile uint8 Address=0;
	if ( (row<2) && (col<16) ){
		Address= (row*(0x40)) + col;
		Address= Set_bit(Address,7);
		LCD_Write_Command(Address);
	}

}


void LCD_Store_cstm_chr(uint8* Pattern,uint8 CGRAM_Index){
	uint8 Address=0;
	uint8 Index=0;
	if(CGRAM_Index<8){

		Address=CGRAM_Index*8;
		Address=Set_bit(Address,6);
		LCD_Write_Command(Address);
		for(Index=0;Index<8;Index++){

			LCD_Write_chr(Pattern[Index]);

		}
	}
	LCD_Write_Command(0x02);
}

void LCD_Disp_cstm_chr(uint8 CGRAM_Index){

LCD_Write_chr(CGRAM_Index);
}
