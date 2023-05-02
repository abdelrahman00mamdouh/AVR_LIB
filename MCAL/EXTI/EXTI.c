/*
 * EXTI.c
 *
 *  Created on: Jan 29, 2023
 *      Author: AMIT
 */

#include"EXTI.h"

static void (*CallBackPtr)(void)=NULL;

void EXTI_Init(void){

	Clr_bit(MCUCR_REG,0);
	Clr_bit(MCUCR_REG,1);
	Clr_bit(MCUCR_REG,2);
	Clr_bit(MCUCR_REG,3);
	Clr_bit(MCUCSR_REG,6);

#if EXTI0_MODE == EXTI_Low_Level
	MCUCR_REG |= EXTI_Low_Level;

#elif	EXTI0_MODE == EXTI_Any_Logical_Change
	MCUCR_REG |= EXTI_Any_Logical_Change;

#elif	EXTI0_MODE == EXTI_Falling_Edge
	MCUCR_REG |= EXTI_Falling_Edge;

#elif	EXTI0_MODE == EXTI_Rising_Edge
	MCUCR_REG |= EXTI_Rising_Edge;

 #endif

#if EXTI1_MODE == EXTI_Low_Level
	MCUCR_REG |= EXTI_Low_Level;

#elif	EXTI1_MODE == EXTI_Any_Logical_Change
	MCUCR_REG |= (EXTI_Any_Logical_Change<<2);

#elif	EXTI1_MODE == EXTI_Falling_Edge
	MCUCR_REG |= (EXTI_Falling_Edge<<2);

#elif	EXTI1_MODE == EXTI_Rising_Edge
	MCUCR_REG |= (EXTI_Rising_Edge<<2);

 #endif

#if	EXTI2_MODE == EXTI_INT2_Falling_Edge
	MCUCSR_REG |= EXTI_INT2_Falling_Edge;

#elif	EXTI2_MODE == EXTI_INT2_Rising_Edge
	MCUCSR_REG |= EXTI_INT2_Rising_Edge;

 #endif

	Set_bit(GIFR_REG,5);
	Set_bit(GIFR_REG,6);
	Set_bit(GIFR_REG,7);
}

void EXTI_GI_En(void){
	Set_bit(SREG_REG,7);

}
void EXTI_GI_DIS(void){

	Clr_bit(SREG_REG,7);

}

void EXTI_Enable_INT0(void){

	Set_bit(GICR_REG,6);

}
void EXTI_Disable_INT0(void){

	Clr_bit(GICR_REG,6);

}

void EXTI_SetCallBack(void (*CopyFuncPtr)(void)){
	CallBackPtr=CopyFuncPtr;
}


void __vector_1(void){
	if(CallBackPtr != NULL){
	CallBackPtr();
}
}


void __vector_2(void){
	if(CallBackPtr != NULL){
		CallBackPtr();
	}
}




void __vector_3(void){
	if(CallBackPtr != NULL){
		CallBackPtr();
	}
}