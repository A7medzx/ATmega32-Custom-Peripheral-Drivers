/*
 * WatchDogTimer_Address.h
 *
 * Created: 5/10/2024 5:45:03 PM
 *  Author: Ahmed Mohamed
 */ 


#ifndef WATCHDOGTIMER_ADDRESS_H_
#define WATCHDOGTIMER_ADDRESS_H_

#include "CPU_Configuration.h"

#define _WDT_WDTCR  (*(volatile uint8_t*)(0x41))
#define _WDT_MCUCSR (*(volatile uint8_t*)(0x54))

#endif /* WATCHDOGTIMER_ADDRESS_H_ */