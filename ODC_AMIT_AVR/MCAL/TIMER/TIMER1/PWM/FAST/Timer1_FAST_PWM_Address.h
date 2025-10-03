/*
 * TIMER1_CTC_Address.h
 *
 * Created: 2/16/2024 5:40:36 PM
 *  Author: Ahmed Mohamed
 */ 


#ifndef TIMER1_FAST_PWM_ADDRESS_H_
#define TIMER1_FAST_PWM_ADDRESS_H_

#include "CPU_Configuration.h"

#define _T1_FAST_PWM_OCR0  (*(volatile uint8_t*)(0x))
#define _T1_FAST_PWM_TIFR  (*(volatile uint8_t*)(0x))
#define _T1_FAST_PWM_TCCR0 (*(volatile uint8_t*)(0x))
#define _T1_FAST_PWM_TCNT0 (*(volatile uint8_t*)(0x))
#define _T1_FAST_PWM_TIMSK (*(volatile uint8_t*)(0x))

#endif /* TIMER1_FAST_PWM_ADDRESS_H_ */