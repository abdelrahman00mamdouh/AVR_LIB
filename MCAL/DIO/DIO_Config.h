/*
 * DIO_Config.h
 *
 * Created: 1/18/2023 5:31:45 PM
 *  Author: abdel
 */ 


#include "../../LIB/STD_Types.h"
#include "../../LIB/BIT_MATH.h"


#ifndef DIO_CONFIG_H_
#define DIO_CONFIG_H_

#define F_CPU 16000000UL

typedef enum {
	INPUT,
	OUTPUT
}DIO_Port_Direction;

typedef enum {
	PORTA,
	PORTB,
	PORTC,
	PORTD
}DIO_PORT_ID;

typedef enum {
	LOW,
	HIGH
}DIO_value;

typedef enum{
	PIN0,
	PIN1,
	PIN2,
	PIN3,
	PIN4,
	PIN5,
	PIN6,
	PIN7
}DIO_pin_ID;

#define PORTA_Register	*((volatile uint8 *)0x3B)
#define DDRA_Register	*((volatile uint8 *)0x3A)
#define PINA_register	*((volatile uint8 *)0x39)

#define PORTB_Register	*((volatile uint8 *)0x38)
#define DDRB_Register	*((volatile uint8 *)0x37)
#define PINB_register	*((volatile uint8 *)0x36)

#define PORTC_Register	*((volatile uint8 *)0x35)
#define DDRC_Register	*((volatile uint8 *)0x34)
#define PINC_register	*((volatile uint8 *)0x33)

#define PORTD_Register	*((volatile uint8 *)0x32)
#define DDRD_Register	*((volatile uint8 *)0x31)
#define PIND_register   *((volatile uint8 *)0x30)

#endif /* DIO_CONFIG_H_ */
