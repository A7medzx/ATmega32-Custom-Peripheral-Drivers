/*
* TIMER1_CTC_Configuration.h
*
* Created: 2/16/2024 5:41:12 PM
 *  Author: Ahmed Mohamed
*/


#ifndef TIMER1_FAST_PWM_CONFIGURATION_H_
#define TIMER1_FAST_PWM_CONFIGURATION_H_

#include "TIMER1_FAST_PWM_Address.h"

#define OC1A_Pin PD4
#define OC1B_Pin PD5

#define _T1_FAST_PWM_BITS         65536
#define _T1_FAST_PWM_PRESCALER    256
#define _T1_FAST_PWM_FREQUENCY    16
#define _T1_FAST_PWM_MICROSECOND  1000

typedef enum
{
	_T1_FAST_PWM_PRESCALAR_0    = 0,
	_T1_FAST_PWM_PRESCALAR_1    = 1,
	_T1_FAST_PWM_PRESCALAR_8    = 2,
	_T1_FAST_PWM_PRESCALAR_64   = 3,
	_T1_FAST_PWM_PRESCALAR_256  = 4,
	_T1_FAST_PWM_PRESCALAR_1024 = 5
}_t1_fast_pwm_prescalar;

typedef enum
{
	_T1_FAST_PWM_Pin_Disconnected   = 0,
	_T1_FAST_PWM_Pin_Inverting      = 1,
	_T1_FAST_PWM_Pin_Non_inverting  = 2
}_t1_fast_pwm_pin;

typedef enum
{
	_T1_FAST_PWM_8BITS_256        = 0,
	_T1_FAST_PWM_9BITS_512        = 1,
	_T1_FAST_PWM_10BITS_1024      = 2,
	_T1_FAST_PWM_16BITS_65536_ICR = 3,
	_T1_FAST_PWM_16BITS_65536_OCR = 4
}_t1_fast_pwm_bits;


#endif /* TIMER1_FAST_PWM_CONFIGURATION_H_ */