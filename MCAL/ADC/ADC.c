/*
 * ADC.c
 *
 *  Created on: Jan 29, 2023
 *      Author: AMIT
 */

#include "ADC.h"


void ADC_Init(void){

	Set_bit(ADMUX_Reg,6);
	Clr_bit(ADMUX_Reg,7);

	//SELECT RIGHT ADJUSTMENT
	Clr_bit(ADMUX_Reg,5);

	//SINGLE CONVERSATION MODE
	Clr_bit(ADCSRA_Reg,5);

	//PRESCALER 128 FOR 16MHZ =125KHZ
	Set_bit(ADCSRA_Reg,0);
	Set_bit(ADCSRA_Reg,1);
	Set_bit(ADCSRA_Reg,2);

	//ADC ENABLE
	Set_bit(ADCSRA_Reg,7);
}

void ADC_Start_Conversion(ADC_Channel Number){

	//CLEAR ADMUX CHANNEL BITS
		ADMUX_Reg &= ADC_CHANNEL_SELECTOR_CLR;
		//SELECT CHANNE NUMBER
		ADMUX_Reg |= Number;
		//start conversation
		Set_bit(ADCSRA_Reg,6);

}

uint16 ADC_Get_Reading(void){

	//WAIT FOR THE FLAG OF ADC
			while (0 == Get_bit(ADCSRA_Reg,4));
			//CLEAR FLAG
			Set_bit(ADCSRA_Reg,4);
			//READ DIGITAL VALUE
	return ADC_Reading_Reg;
}
