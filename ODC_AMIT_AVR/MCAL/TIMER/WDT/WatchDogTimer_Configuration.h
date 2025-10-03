/*
* WatchDogTimer_Configuration.h
*
* Created: 5/10/2024 5:45:13 PM
*  Author: Ahmed Mohamed
*/


#ifndef WATCHDOGTIMER_CONFIGURATION_H_
#define WATCHDOGTIMER_CONFIGURATION_H_

#include "WatchDogTimer_Address.h"

typedef enum
{
	_WDT_PRESCALAR_16K_16_ms     = 0,
	_WDT_PRESCALAR_32K_32_ms     = 1,
	_WDT_PRESCALAR_64K_65_ms     = 2,
	_WDT_PRESCALAR_128K_130_ms   = 3,
	_WDT_PRESCALAR_256K_260_ms   = 4,
	_WDT_PRESCALAR_512K_520_ms   = 5,
	_WDT_PRESCALAR_1024K_1000_ms = 6,
	_WDT_PRESCALAR_2048K_2100_ms = 7
}_wdt_prescalar;


#endif /* WATCHDOGTIMER_CONFIGURATION_H_ */