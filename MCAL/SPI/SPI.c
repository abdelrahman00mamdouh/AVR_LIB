/*
 * SPI.c
 *
 * Created: 5/1/2023 10:15:41 AM
 *  Author: abdel
 */ 
#include "../SPI/SPI.h"

void (*INT_func)(void)=NULL;

void SPI_MasterInit(void)
{
	
	DIO_Set_Pin_Direction(PORTB,PIN5,OUTPUT);
	DIO_Set_Pin_Direction(PORTB,PIN6,INPUT); 
	DIO_Set_Pin_Direction(PORTB,PIN4,OUTPUT);
	DIO_Set_Pin_Direction(PORTB,PIN7,OUTPUT);

	Set_bit(SPCR,SPE);                            
	Set_bit(SPCR,DORD);                         
	Set_bit(SPCR,MSTR);                         
	Set_bit(SPCR,CPOL);                         
	Set_bit(SPCR,CPHA);                         
	
	Set_bit(SPCR,SPR0);                           
	Clr_bit(SPCR,SPR1);
}

void SPI_SlaveInit(void)
{
	
	DIO_Set_Pin_Direction(PORTB,PIN5,INPUT); 
	DIO_Set_Pin_Direction(PORTB,PIN6,OUTPUT);
	DIO_Set_Pin_Direction(PORTB,PIN4,INPUT); 
	
	Set_bit(SPCR,SPE);                            
	Set_bit(SPCR,DORD);                           
	Clr_bit(SPCR,MSTR);                           
	Set_bit(SPCR,CPOL);                           
	Set_bit(SPCR,CPHA);                           
	
	Set_bit(SPCR,SPR0);                           
	Clr_bit(SPCR,SPR1);
}

uint8 SPI_Transfer(uint8 Data)
{
	SPDR=Data;
	while((Get_bit(SPSR,SPIF))==0){}
	return SPDR;
}

void SPI_InterruptEnable(void)
{
	Set_bit(SPCR,SPIE);
}


void SPI_SetCallBack(void (*func)(void))
{
	INT_func=func;
}


void __vector_12(void){
	if(INT_func != NULL)
	{
		INT_func();
	}
}