/*
 * EXTI.h
 *
 *  Created on: Jan 29, 2023
 *      Author: AMIT
 */


#include"EXTI_Config.h"

#ifndef MCAL_EXTI_EXTI_H_
#define MCAL_EXTI_EXTI_H_

void EXTI_Init(void);

void EXTI_GI_En(void);
void EXTI_GI_DIS(void);

void EXTI_Enable_INT0(void);
void EXTI_Disable_INT0(void);

void EXTI_SetCallBack(void (*CopyFuncPtr)(void));


void EXTI0_ISR(void);
void EXTI1_ISR(void);
void EXTI2_ISR(void);

#endif /* MCAL_EXTI_EXTI_H_ */
