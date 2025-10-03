/*
 * TIMER2_OVF_Interface.h
 *
 * Created: 5/3/2024 5:54:06 PM
 *  Author: Ahmed Mohamed
 */ 


#ifndef TIMER2_OVF_INTERFACE_H_
#define TIMER2_OVF_INTERFACE_H_

#include "TIMER2_OVF_Private.h"

void Timer2_OVF_WithInterrupt_Initialize (void);
void Timer2_OVF_WithInterrupt_Start (void);
void Timer2_OVF_WithInterrupt_Stop (void);
void Timer2_OVF_WithInterrupt_SetDelay (uint32_t delay);

void Timer2_OVF_WithoutInterrupt_Initialize (void);
void Timer2_OVF_WithoutInterrupt_Start (void);
void Timer2_OVF_WithoutInterrupt_Stop (void);
void Timer2_OVF_WithoutInterrupt_SetDelay (uint32_t delay);

uint8_t TIMER2_OVF_CounterValue (void);

#endif /* TIMER2_OVF_INTERFACE_H_ */