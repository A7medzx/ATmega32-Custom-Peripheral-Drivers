/*
* Timer0_OVF_Configuration.h
*
* Created: 5/3/2024 5:54:24 PM
*  Author: Ahmed Mohamed
*/


#ifndef TIMER0_OVF_CONFIGURATION_H_
#define TIMER0_OVF_CONFIGURATION_H_

#include "Timer0_OVF_Address.h"

typedef enum
{
	T0_OVF_0    = 0,
	T0_OVF_1    = 1,
	T0_OVF_8    = 2,
	T0_OVF_64   = 3,
	T0_OVF_256  = 4,
	T0_OVF_1024 = 5
}timer0OVF_prescalar;

#define _T0_OVF_BITS         256
#define _T0_OVF_PRESCALER    1024
#define _T0_OVF_FREQUENCY    16
#define _T0_OVF_MICROSECOND  1000

#endif /* TIMER0_OVF_CONFIGURATION_H_ */