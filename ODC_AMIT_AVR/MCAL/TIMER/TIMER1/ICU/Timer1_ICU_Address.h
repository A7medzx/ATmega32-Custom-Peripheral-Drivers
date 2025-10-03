/*
 * Timer0_OVF_Address.h
 *
 * Created: 2/16/2024 5:40:36 PM
 *  Author: Ahmed Mohamed
 */ 


#ifndef TIMER1_ICU_ADDRESS_H_
#define TIMER1_ICU_ADDRESS_H_

#include "CPU_Configuration.h"
#include "DIO_Address.h"

#define _T1_ICU_OCR1AL  (*(volatile uint8_t*)(0x4A))
#define _T1_ICU_OCR1AH  (*(volatile uint8_t*)(0x4B))
#define _T1_ICU_OCR1A   (*(volatile uint16_t*)(0x4A))
			
#define _T1_ICU_OCR1BL  (*(volatile uint8_t*)(0x48))
#define _T1_ICU_OCR1BH  (*(volatile uint8_t*)(0x49))
#define _T1_ICU_OCR1B   (*(volatile uint16_t*)(0x48))
		
#define _T1_ICU_TCNT1L (*(volatile uint8_t*)(0x4C))
#define _T1_ICU_TCNT1H (*(volatile uint8_t*)(0x4D))
#define _T1_ICU_TCNT1  (*(volatile uint16_t*)(0x4C))
			
#define _T1_ICU_ICR1L  (*(volatile uint8_t*)(0x46))
#define _T1_ICU_ICR1H  (*(volatile uint8_t*)(0x47))
#define _T1_ICU_ICR1   (*(volatile uint16_t*)(0x46))
		
#define _T1_ICU_TCCR1A (*(volatile uint8_t*)(0x4F))
#define _T1_ICU_TCCR1B (*(volatile uint8_t*)(0x4E))
			
#define _T1_ICU_TIFR   (*(volatile uint8_t*)(0x58))
#define _T1_ICU_TIMSK  (*(volatile uint8_t*)(0x59))

#endif /* TIMER1_ICU_ADDRESS_H_ */