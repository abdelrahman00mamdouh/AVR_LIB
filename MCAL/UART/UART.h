/*
 * UART.h
 *
 * Created: 5/1/2023 9:20:02 AM
 *  Author: abdel
 */ 

#include "../UART/UART_Config.h"

#ifndef UART_H_
#define UART_H_

void UART_init(void);
void UART_Transmitte(uint8 ch);
uint8 UART_Recieve(void);
void UART_SendString(uint8 *str);


#endif /* UART_H_ */