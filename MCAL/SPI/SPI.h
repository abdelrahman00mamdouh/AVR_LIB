/*
 * SPI.h
 *
 * Created: 5/1/2023 10:15:55 AM
 *  Author: abdel
 */ 

#include "../SPI/SPI_Config.h"

#ifndef SPI_H_
#define SPI_H_

void SPI_MasterInit(void);
void SPI_SlaveInit(void) ;
uint8 SPI_Transfer(uint8 Data);
void SPI_InterruptEnable(void);
void SPI_SetCallBack(void (*func)(void));



#endif /* SPI_H_ */