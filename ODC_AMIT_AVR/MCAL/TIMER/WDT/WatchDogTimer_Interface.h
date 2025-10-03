/*
 * WatchDogTimer_Interface.h
 *
 * Created: 5/10/2024 5:44:43 PM
 *  Author: Ahmed Mohamed
 */ 


#ifndef WATCHDOGTIMER_INTERFACE_H_
#define WATCHDOGTIMER_INTERFACE_H_

#include "WatchDogTimer_Private.h"

void WDT_Initialize(void);
void WDT_Start(_wdt_prescalar prescalar);
void WDT_Refresh(void);

#endif /* WATCHDOGTIMER_INTERFACE_H_ */