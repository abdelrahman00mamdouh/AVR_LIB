/*
 * EXTI_Config.h
 *
 *  Created on: Jan 29, 2023
 *      Author: AMIT
 */
#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_Types.h"

#ifndef MCAL_EXTI_EXTI_CONFIG_H_
#define MCAL_EXTI_EXTI_CONFIG_H_

#define EXTI_Low_Level			0
#define EXTI_Any_Logical_Change 1
#define EXTI_Rising_Edge		2
#define EXTI_Falling_Edge		3

#define EXTI_INT2_Falling_Edge	0
#define EXTI_INT2_Rising_Edge	1

#define EXTI_Enable_State		0
#define EXTI_Disable_State		1


#define SREG_REG	(*(volatile uint8*) 0x5F)
#define MCUCR_REG	(*(volatile uint8*) 0x55)
#define MCUCSR_REG	(*(volatile uint8*) 0x54)
#define GICR_REG	(*(volatile uint8*) 0x5B)
#define GIFR_REG	(*(volatile uint8*) 0x5A)


#define EXTI0_MODE	EXTI_Falling_Edge

#define EXTI1_MODE	EXTI_Falling_Edge
#define EXTI2_MODE	EXTI_Falling_Edge

void __vector_1(void)__attribute__((signal,used));
void __vector_2(void)__attribute__((signal,used));
void __vector_3(void)__attribute__((signal,used));

#endif /* MCAL_EXTI_EXTI_CONFIG_H_ */
