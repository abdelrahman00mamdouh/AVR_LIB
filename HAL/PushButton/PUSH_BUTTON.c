/*
 * PUSH_BUTTON.c
 *
 * Created: 1/18/2023 8:44:46 PM
 *  Author: abdel
 */ 

#include "PUSH_BUTTON.h"

void Push_Button_Init(PB_ID Push_Button_Id){
	
	if (Push_Button_Id==Push_Button0)
	{
			DIO_Set_Pin_Direction(PB0_Port,PB0_pin,INPUT);
	}
	else if (Push_Button_Id==Push_Button1)
	{
			DIO_Set_Pin_Direction(PB1_Port,PB1_pin,INPUT);
	}
	else if (Push_Button_Id==Push_Button2)
	{
			DIO_Set_Pin_Direction(PB2_Port,PB2_pin,INPUT);
	}

}
DIO_value Push_Button_pressed(PB_ID Push_Button_Id){
	
	if (Push_Button_Id==Push_Button0)
	{
	return DIO_Get_Pin_Value(PB0_Port,PB0_pin);
	}
	
	else if (Push_Button_Id==Push_Button1)
	{
	return DIO_Get_Pin_Value(PB1_Port,PB1_pin);
	}
	
	else if (Push_Button_Id==Push_Button2)
	{
	return DIO_Get_Pin_Value(PB2_Port,PB2_pin);
	}

	return 0;
	
}
