/*
 * SPI_Address.h
 *
 * Created: 3/8/2024 5:05:36 PM
 *  Author: Ahmed Mohamed
 */ 


#ifndef SPI_ADDRESS_H_
#define SPI_ADDRESS_H_

#include "CPU_Configuration.h"

#define _SPI_SPCR (*(volatile uint8_t*) (0x2D))
#define _SPI_SPSR (*(volatile uint8_t*) (0x2E))
#define _SPI_SPDR (*(volatile uint8_t*) (0x2F))

#endif /* SPI_ADDRESS_H_ */
