/*
 * TIMER.c
 *
 * Created: 4/27/2023 8:31:16 AM
 *  Author: abdel
 */ 

#include "../Timer/TIMER.h"


void TIMER_Init(void){
	
	#if TIMER0_ENABLE == ON
	
			#if TIMER0_MODE == TIMER0_NORMAL
				Clr_bit(TCCR0,WGM00);
				Clr_bit(TCCR0,WGM01);
			#elif TIMER0_MODE == TIMER0_PWM_PHASE_CORRECT
				Set_bit(TCCR0,WGM00);
				Clr_bit(TCCR0,WGM01);
			#elif TIMER0_MODE == TIMER0_CTC
				Clr_bit(TCCR0,WGM00);
				Set_bit(TCCR0,WGM01);
			#elif TIMER0_MODE == TIMER0_FAST_PWM
				Set_bit(TCCR0,WGM00);
				Set_bit(TCCR0,WGM01);
			#endif


			#if TIMER0_PRESCALLER == TIMER0_STOP
				Clr_bit(TCCR0,CS00);
				Clr_bit(TCCR0,CS01);
				Clr_bit(TCCR0,CS02);
			#elif TIMER0_PRESCALLER == TIMER0_DIV_BY_1
				Set_bit(TCCR0,CS00);
				Clr_bit(TCCR0,CS01);
				Clr_bit(TCCR0,CS02);
			#elif TIMER0_PRESCALLER == TIMER0_DIV_BY_8
				Clr_bit(TCCR0,CS00);
				Set_bit(TCCR0,CS01);
				Clr_bit(TCCR0,CS02);
			#elif TIMER0_PRESCALLER == TIMER0_DIV_BY_64
				Set_bit(TCCR0,CS00);
				Set_bit(TCCR0,CS01);
				Clr_bit(TCCR0,CS02);
			#elif TIMER0_PRESCALLER == TIMER0_DIV_BY_256
				Clr_bit(TCCR0,CS00);
				Clr_bit(TCCR0,CS01);
				Set_bit(TCCR0,CS02);
			#elif TIMER0_PRESCALLER == TIMER0_DIV_BY_1024
				Set_bit(TCCR0,CS00);
				Clr_bit(TCCR0,CS01);
				Set_bit(TCCR0,CS02);
			#endif

			#if TIMER0_INTERRUPT == TIMER0_ENABLE_INTERRUPT
					
					#if TIMER0_MODE == TIMER0_NORMAL
						Set_bit(TIMSK,TOIE0);
					#elif TIMER0_MODE == TIMER0_CTC
						Set_bit(TIMSK,OCIE0);
					#endif

			#endif
		
	#endif
	
	}

void TIMER0_Set_OVF_Reg(uint8 OVF_Value){
			TCNT0 = OVF_Value;
}

void TIMER0_Set_CTC_Register(uint8 CTC_Value){
			OCR0 = CTC_Value;
}

void TIMER0_Enable_OVF_INT(void){
	Set_bit(TIMSK , TOIE0);

}

void TIMER0_Disable_OVF_INT(void){
	Clr_bit(TIMSK , TOIE0);
}

void TIMER0_Clear_OVF_Flag(void){
	Set_bit(TIFR , TOV0);

}

void TIMER0_Enable_CTC_INT(void){
	Set_bit(TIMSK , OCIE0);
}

void TIMER0_Disable_CTC_INT(void){
	Clr_bit(TIMSK , OCIE0);
}

void TIMER0_Clear_CTC_Flag(void){
	Set_bit(TIFR , OCF0);
}

void __vector_11(void){
	TIMER_CallBack[TIMER0_OVF_CALLBACK_INDEX]();
	TIMER0_Clear_OVF_Flag();
}

void __vector_10(void){
	TIMER_CallBack[TIMER0_CTC_CALLBACK_INDEX]();
	TIMER0_Clear_CTC_Flag();
}