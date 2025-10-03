/*
 * Timer0_OVF_Configuration.h
 *
 * Created: 5/3/2024 5:54:24 PM
 *  Author: Ahmed Mohamed
 */ 


#ifndef TIMER1_OVF_CONFIGURATION_H_
#define TIMER1_OVF_CONFIGURATION_H_

#include "Timer1_OVF_Address.h"

typedef enum
{
	T1_OVF_0    = 0,
	T1_OVF_1    = 1,
	T1_OVF_8    = 2,
	T1_OVF_64   = 3,
	T1_OVF_256  = 4,
	T1_OVF_1024 = 5
}timer1OVF_prescalar;

#define _T1_OVF_BITS         65536 //2^16
#define _T1_OVF_PRESCALER    64
#define _T1_OVF_FREQUENCY    16
#define _T1_OVF_MICROSECOND  1000

#endif /* TIMER1_OVF_CONFIGURATION_H_ */