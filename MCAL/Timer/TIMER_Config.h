/*
 * TIMER_Config.h
 *
 * Created: 4/27/2023 8:31:32 AM
 *  Author: abdel
 */

#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_Types.h"


#ifndef TIMER_CONFIG_H_
#define TIMER_CONFIG_H_

#define OFF 0
#define ON  1

#define TIMER0_NORMAL					0
#define TIMER0_PWM_PHASE_CORRECT		1
#define TIMER0_CTC						2
#define TIMER0_FAST_PWM					3

#define TIMER0_STOP					0
#define	TIMER0_DIV_BY_1				1
#define TIMER0_DIV_BY_8				2
#define TIMER0_DIV_BY_64			3
#define TIMER0_DIV_BY_256			4
#define TIMER0_DIV_BY_1024			5

#define	TIMER0_DISABLE_INTERRUPT	0
#define	TIMER0_ENABLE_INTERRUPT		1

#define TIMER0_OVF_CALLBACK_INDEX				0
#define TIMER0_CTC_CALLBACK_INDEX				1


#define TIMER0_ENABLE		ON
#define TIMER0_MODE			TIMER0_NORMAL
#define TIMER0_PRESCALLER	TIMER0_DIV_BY_1024
#define TIMER0_INTERRUPT	TIMER0_DISABLE_INTERRUPT	

void (*TIMER_CallBack[8])(void) = {NULL};
	
/*...................................................TIMER0 Registers...........................................*/

#define TCCR0   (* (volatile uint8 *) (0x53))
#define TCNT0   (* (volatile uint8 *) (0x52))
#define OCR0    (* (volatile uint8 *) (0x5C))
#define TIMSK   (* (volatile uint8 *) (0x59))
#define TIFR    (* (volatile uint8 *) (0x58))

#define FOC0	7
#define WGM00	6
#define COM01	5
#define COM00	4
#define WGM01	3
#define CS02	2
#define CS01	1
#define CS00	0


#define OCIE0	1
#define TOIE0	0

#define OCF0	1
#define TOV0	0

void __vector_11(void) __attribute__((signal));
void __vector_10(void) __attribute__((signal));

/*..............................................................................................................*/

#endif /* TIMER_CONFIG_H_ */