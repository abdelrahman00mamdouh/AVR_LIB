/*
 * SPI_Config.h
 *
 * Created: 5/1/2023 10:16:06 AM
 *  Author: abdel
 */ 

#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_Types.h"
#include "../DIO/DIO.h"

#ifndef SPI_CONFIG_H_
#define SPI_CONFIG_H_


#define  SPCR         *((volatile uint8*)  0x2D)
#define  SPSR         *((volatile uint8*)  0x2E)
#define  SPDR         *((volatile uint8*)  0x2F)

/*SPI Control Register - SPCR*/
#define SPIE     7
#define SPE      6
#define DORD     5
#define MSTR     4
#define CPOL     3
#define CPHA     2
#define SPR1     1
#define SPR0     0


/*SPI Status Register - SPSR*/
#define SPIF      7
#define WCOL      6
#define SPI2X     0



/*SPI Data Register - SPDR*/
#define MSB     7
#define LSB     0


#endif /* SPI_CONFIG_H_ */