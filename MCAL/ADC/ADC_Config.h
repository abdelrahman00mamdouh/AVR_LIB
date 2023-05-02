/*
 * ADC_Config.h
 *
 *  Created on: Jan 29, 2023
 *      Author: AMIT
 */

#include "../../LIB/STD_Types.h"
#include "../../LIB/BIT_MATH.h"

#ifndef MCAL_ADC_ADC_CONFIG_H_
#define MCAL_ADC_ADC_CONFIG_H_

/*ADC CHANNEL SELECT*/
typedef enum{
	ADC_Channel_0,
	ADC_Channel_1,
	ADC_Channel_2,
	ADC_Channel_3,
	ADC_Channel_4,
	ADC_Channel_5,
	ADC_Channel_6,
	ADC_Channel_7
}ADC_Channel;

/*ADC REGISTERS*/
#define ADMUX_Reg					*((volatile uint8*)0x27)
#define ADCSRA_Reg					*((volatile uint8*)0x26)
#define SFIOR_Reg					*((volatile uint8*)0x50)
#define ADCL_Reg					*((volatile uint8*)0x24)
#define ADCH_Reg					*((volatile uint8*)0x25)

#define ADC_Reading_Reg				*((volatile uint16*)0x24)


/*ADMUX clear Channel*/
#define ADC_CHANNEL_SELECTOR_CLR			0b11100000

#endif /* MCAL_ADC_ADC_CONFIG_H_ */
