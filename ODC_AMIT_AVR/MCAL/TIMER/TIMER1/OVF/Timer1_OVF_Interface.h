/*
 * Timer0_OVF_Interface.h
 *
 * Created: 5/3/2024 5:54:06 PM
 *  Author: Ahmed Mohamed
 */ 


#ifndef TIMER1_OVF_INTERFACE_H_
#define TIMER1_OVF_INTERFACE_H_

#include "Timer1_OVF_Private.h"

void Timer1_OVF_WithInterrupt_Initialize (void);
void Timer1_OVF_WithInterrupt_Start (void);
void Timer1_OVF_WithInterrupt_Stop (void);
void Timer1_OVF_WithInterrupt_SetDelay (uint32_t delay);

void Timer1_OVF_WithoutInterrupt_Initialize (void);
void Timer1_OVF_WithoutInterrupt_Start (void);
void Timer1_OVF_WithoutInterrupt_Stop (void);
void Timer1_OVF_WithoutInterrupt_SetDelay (uint32_t delay);

uint16_t Timer1_OVF_CounterValue (void);

#endif /* TIMER1_OVF_INTERFACE_H_ */