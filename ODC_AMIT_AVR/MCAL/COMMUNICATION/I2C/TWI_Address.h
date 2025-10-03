/*
 * TWI_Address.h
 *
 * Created: 3/8/2024 5:05:36 PM
 *  Author: Ahmed Mohamed
 */ 


#ifndef TWI_ADDRESS_H_
#define TWI_ADDRESS_H_

#include "CPU_Configuration.h"

#define _TWI_TWAR (*(volatile uint8_t*)(0x22))
#define _TWI_TWBR (*(volatile uint8_t*)(0x20))
#define _TWI_TWCR (*(volatile uint8_t*)(0x56))
#define _TWI_TWDR (*(volatile uint8_t*)(0x23))
#define _TWI_TWSR (*(volatile uint8_t*)(0x21))

#endif /* TWI_ADDRESS_H_ */