/*
 * Timer0_OVF_Interface.h
 *
 * Created: 2/16/2024 5:40:57 PM
 *  Author: Ahmed Mohamed
 */ 


#ifndef TIMER1_ICU_INTERFACE_H_
#define TIMER1_ICU_INTERFACE_H_

#include "Timer1_ICU_Private.h"

void Timer1_ICU_Initialize (void);
void Timer1_ICU_Start (void);
void Timer1_ICU_Stop (void);
void Timer1_ICU_SetDuty (uint32_t angle);

#endif /* TIMER1_ICU_INTERFACE_H_ */