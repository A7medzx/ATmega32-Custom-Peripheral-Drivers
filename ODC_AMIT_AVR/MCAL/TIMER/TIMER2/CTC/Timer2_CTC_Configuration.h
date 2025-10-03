/*
* TIMER2_CTC_Configuration.h
*
* Created: 5/3/2024 5:54:24 PM
*  Author: Ahmed Mohamed
*/


#ifndef TIMER2_CTC_CONFIGURATION_H_
#define TIMER2_CTC_CONFIGURATION_H_

#include "TIMER2_CTC_Address.h"

typedef enum
{
	T2_CTC_0    = 0,
	T2_CTC_1    = 1,
	T2_CTC_8    = 2,
	T2_CTC_64   = 3,
	T2_CTC_256  = 4,
	T2_CTC_1024 = 5
}timer2CTC_prescalar;

#define _T2_CTC_BITS         256
#define _T2_CTC_PRESCALER    1024
#define _T2_CTC_FREQUENCY    16
#define _T2_CTC_MICROSECOND  1000

#endif /* TIMER2_CTC_CONFIGURATION_H_ */