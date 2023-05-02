/*
 * Seven_Segment.c
 *
 *  Created on: Jan 19, 2023
 *      Author: AMIT
 */

#include"Seven_Segment.h"

void Seven_Segment_Init(void){

DIO_Set_Pin_Direction(PORTA,PIN4,OUTPUT); //A
DIO_Set_Pin_Direction(PORTA,PIN5,OUTPUT); //B
DIO_Set_Pin_Direction(PORTA,PIN6,OUTPUT); //C
DIO_Set_Pin_Direction(PORTA,PIN7,OUTPUT); //D


DIO_Set_Pin_Direction(PORTB,PIN2,OUTPUT); //EN1
DIO_Set_Pin_Direction(PORTB,PIN1,OUTPUT); //EN2

}

void Seven_Segment_write_Number(uint8 number){

if (number<10){

	DIO_Set_Pin_Value( PORTA, PIN4, Get_bit(number,0)); //A
	DIO_Set_Pin_Value( PORTA, PIN5, Get_bit(number,1)); //B
	DIO_Set_Pin_Value( PORTA, PIN6, Get_bit(number,2)); //C
	DIO_Set_Pin_Value( PORTA, PIN7, Get_bit(number,3)); //D

	}

}

void Seven_Segment1_Enable(void){

	DIO_Set_Pin_Value(PORTB,PIN2,HIGH); //EN1


}
void Seven_Segment2_Enable(void){

	DIO_Set_Pin_Value(PORTB,PIN1,HIGH); //EN2

}

void Seven_Segment1_Disable(void){

	DIO_Set_Pin_Value(PORTB,PIN2,LOW); //EN1

}
void Seven_Segment2_Disable(void){

	DIO_Set_Pin_Value(PORTB,PIN1,LOW); //EN1

}
