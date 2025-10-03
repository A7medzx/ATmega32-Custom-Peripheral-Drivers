/*
* TIMER2_OVF_Configuration.h
*
* Created: 5/3/2024 5:54:24 PM
*  Author: Ahmed Mohamed
*/


#ifndef TIMER2_OVF_CONFIGURATION_H_
#define TIMER2_OVF_CONFIGURATION_H_

#include "TIMER2_OVF_Address.h"

typedef enum
{
	T2_OVF_0    = 0,
	T2_OVF_1    = 1,
	T2_OVF_8    = 2,
	T2_OVF_64   = 3,
	T2_OVF_256  = 4,
	T2_OVF_1024 = 5
}timer2OVF_prescalar;

#define _T2_OVF_BITS         256
#define _T2_OVF_PRESCALER    1024
#define _T2_OVF_FREQUENCY    16
#define _T2_OVF_MICROSECOND  1000

#endif /* TIMER2_OVF_CONFIGURATION_H_ */