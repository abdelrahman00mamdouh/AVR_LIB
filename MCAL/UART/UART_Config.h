/*
 * UART_Config.h
 *
 * Created: 5/1/2023 9:20:17 AM
 *  Author: abdel
 */ 

#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_Types.h"

#ifndef UART_CONFIG_H_
#define UART_CONFIG_H_

#define USART_BAUDRATE 9600 /*9600, 1200, 2400, 4800, 19200, 115200 bps*/
#define RX_INTERRUPT_ENABLE	DISABLED
#define TX_INTERRUPT_ENABLE	DISABLED

#define BAUD_PRESCALE  (((F_CPU / (USART_BAUDRATE * 16UL))) - 1)
#define ENABLED  1
#define DISABLED 0

/*..................................................*/

// UART Registers
#define UDR		*((volatile uint8_t*)0x2C)
#define UCSRA	*((volatile uint8_t*)0x2B)
#define UCSRB	*((volatile uint8_t*)0x2A)
#define UCSRC	*((volatile uint8_t*)0x40)
#define UBRRL	*((volatile uint8_t*)0x29)
#define UBRRH	*((volatile uint8_t*)0x40)

// UCSRA Bits
#define RXC		7
#define TXC		6
#define UDRE	5
#define FE		4
#define DOR		3
#define PE		2
#define U2X		1
#define MPCM	0

// UCSRB Bits

#define RXCIE	7
#define TXCIE	6
#define UDRIE	5
#define RXEN	4
#define TXEN	3
#define UCSZ2	2
#define RXB8	1
#define TXB8	0

// UCSRC Bits
#define URSEL	7
#define UMSEL	6
#define UPM1	5
#define UPM0	4
#define USBS	3
#define UCSZ1	2
#define UCSZ0	1
#define UCPOL	0


#endif /* UART_CONFIG_H_ */