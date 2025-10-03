/*
 * Timer0_CTC_Address.h
 *
 * Created: 2/16/2024 5:40:36 PM
 *  Author: Ahmed Mohamed
 */ 


#ifndef TIMER2_FAST_PWM_ADDRESS_H_
#define TIMER2_FAST_PWM_ADDRESS_H_

#include "CPU_Configuration.h"

#define _T2_FAST_PWM_OCR2  (*(volatile uint8_t*)(0x43))
#define _T2_FAST_PWM_TIFR  (*(volatile uint8_t*)(0x58))
#define _T2_FAST_PWM_TCCR2 (*(volatile uint8_t*)(0x45))
#define _T2_FAST_PWM_TCNT2 (*(volatile uint8_t*)(0x44))
#define _T2_FAST_PWM_TIMSK (*(volatile uint8_t*)(0x59))

#endif /* TIMER0_FAST_PWM_ADDRESS_H_ */