/*
* Timer0_CTC_Program.c
*
* Created: 2/16/2024 5:41:30 PM
 *  Author: Ahmed Mohamed
*/


#include "Timer1_FAST_PWM_Interface.h"

void Timer1_FAST_PWM_Initialize (_t1_fast_pwm_bits bits)
{
	switch (bits)
	{
		case _T1_FAST_PWM_8BITS_256       :  break;
		case _T1_FAST_PWM_9BITS_512       :  break;
		case _T1_FAST_PWM_10BITS_1024     :  break;
		case _T1_FAST_PWM_16BITS_65536_ICR:  break;
		case _T1_FAST_PWM_16BITS_65536_OCR:  break;
		default: /*Error*/                   break;
	}
}
void Timer1_FAST_PWM_Start (_t1_fast_pwm_prescalar prescalar)
{
	switch (prescalar)
	{
		case _T1_FAST_PWM_PRESCALAR_0   :       break;
		case _T1_FAST_PWM_PRESCALAR_1   :       break;
		case _T1_FAST_PWM_PRESCALAR_8   :       break;
		case _T1_FAST_PWM_PRESCALAR_64  :       break;
		case _T1_FAST_PWM_PRESCALAR_256 :       break;
		case _T1_FAST_PWM_PRESCALAR_1024:       break;
		default:        /*Error*/               break;
	}
}
void Timer1_FAST_PWM_Stop (void)
{
	
}
void Timer1_FAST_PWM_SetDuty (_t1_fast_pwm_pin pin, _t1_fast_pwm_bits bits, uint8_t dutycyle)
{
	switch (pin)
	{
		case _T1_FAST_PWM_Pin_Disconnected:
		break;
		case _T1_FAST_PWM_Pin_Inverting:
		switch (bits)
		{
			case _T1_FAST_PWM_8BITS_256       :  break;
			case _T1_FAST_PWM_9BITS_512       :  break;
			case _T1_FAST_PWM_10BITS_1024     :  break;
			case _T1_FAST_PWM_16BITS_65536_ICR:  break;
			case _T1_FAST_PWM_16BITS_65536_OCR:  break;
			default: /*Error*/                   break;
		}
		break;
		case _T1_FAST_PWM_Pin_Non_inverting:
		switch (bits)
		{
			case _T1_FAST_PWM_8BITS_256       :  break;
			case _T1_FAST_PWM_9BITS_512       :  break;
			case _T1_FAST_PWM_10BITS_1024     :  break;
			case _T1_FAST_PWM_16BITS_65536_ICR:  break;
			case _T1_FAST_PWM_16BITS_65536_OCR:  break;
			default: /*Error*/                   break;
		}
		break;
	}
}