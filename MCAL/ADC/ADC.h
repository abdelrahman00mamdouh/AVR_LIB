/*
 * ADC.h
 *
 *  Created on: Jan 29, 2023
 *      Author: AMIT
 */

#include "ADC_Config.h"

#ifndef MCAL_ADC_ADC_H_
#define MCAL_ADC_ADC_H_

void ADC_Init(void);
void ADC_Start_Conversion(ADC_Channel Number);
uint16 ADC_Get_Reading(void);

#endif /* MCAL_ADC_ADC_H_ */
