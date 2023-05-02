/*
 * UART.c
 *
 * Created: 5/1/2023 9:19:48 AM
 *  Author: abdel
 */ 

#include "../UART/UART.h"

void UART_init(void)
{
	Set_bit(UCSRB,RXEN);
	Set_bit(UCSRB,TXEN);
	
	Set_bit(UCSRC,URSEL);	
	Set_bit(UCSRC,UCSZ0);
	Set_bit(UCSRC,UCSZ1);

	    // Interrupts
	    #if RX_INTERRUPT_ENABLE == ENABLED
	    Set_bit(UCSRB, RXCIE);
	    #else
	    Clr_bit(UCSRB, RXCIE);
	    #endif

	    #if TX_INTERRUPT_ENABLE == ENABLED
	    Set_bit(UCSRB, TXCIE);
	    #else
	    Clr_bit(UCSRB, TXCIE);
	    #endif
	
	UBRRL = BAUD_PRESCALE;			
	UBRRH = (BAUD_PRESCALE >> 8);		
}

void UART_Transmitte(uint8 ch)
{
	while (Get_bit(UCSRA,5) == 0);	
	UDR = ch ;
}

uint8 UART_Recieve(void)
{
	while (Get_bit(UCSRA,7) == 0);
	return UDR;		
}

void UART_SendString(uint8 *str)
{
	uint8 j=0;
	
	while (str[j]!=0)		
	{
		UART_Transmitte(str[j]);
		j++;
	}
}