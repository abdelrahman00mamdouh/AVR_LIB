/*
 * TIMER.h
 *
 * Created: 4/27/2023 8:31:04 AM
 *  Author: abdel
 */ 

#include "../Timer/TIMER_Config.h"

#ifndef TIMER_H_
#define TIMER_H_

void TIMER_Init(void);
void TIMER0_Set_OVF_Reg(uint8 OVF_Value);
void TIMER0_Set_CTC_Register(uint8 CTC_Value);
void TIMER0_Enable_OVF_INT(void);
void TIMER0_Disable_OVF_INT(void);
void TIMER0_Clear_OVF_Flag(void);
void TIMER0_Enable_CTC_INT(void);
void TIMER0_Disable_CTC_INT(void);
void TIMER0_Clear_CTC_Flag(void);

#endif /* TIMER_H_ */