/*
 * TIMER2_CTC_Address.h
 *
 * Created: 5/3/2024 5:54:14 PM
 *  Author: Ahmed Mohamed
 */ 


#ifndef TIMER2_CTC_ADDRESS_H_
#define TIMER2_CTC_ADDRESS_H_

#include "CPU_Configuration.h"

#define _T2_CTC_OCR2  (*(volatile uint8_t*)(0x43))
#define _T2_CTC_TIFR  (*(volatile uint8_t*)(0x58))
#define _T2_CTC_TCCR2 (*(volatile uint8_t*)(0x45))
#define _T2_CTC_TCNT2 (*(volatile uint8_t*)(0x44))
#define _T2_CTC_TIMSK (*(volatile uint8_t*)(0x59))

#endif /* TIMER2_CTC_ADDRESS_H_ */