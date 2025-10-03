/*
* Timer0_CTC_Program.c
*
* Created: 2/16/2024 5:41:30 PM
*  Author: Ahmed Mohamed
*/

#include "Timer1_ICU_Interface.h"

void Timer1_ICU_Initialize (void)
{
	/*
	1- Define direction for pin as output
	2- Choose mode from timer1 as fast PWM
	3- Choose non-inverting mode
	*/
	_DIO_DDRD |= (1<<PD5);
	
	_T1_ICU_TCCR1B |= ((1<<WGM13) | (1<<WGM12));
	_T1_ICU_TCCR1A |= (1<<WGM11);
	_T1_ICU_TCCR1A &=~(1<<WGM10);
	
	_T1_ICU_TCCR1A |= (1<<COM1A1);
	_T1_ICU_TCCR1A &=~(1<<COM1A0);
}

void Timer1_ICU_Start (void)
{
	/*
	1- Choose prescalar 256
	2- Set new top value
	*/
	_T1_ICU_TCCR1B |= (1<<CS12);
	_T1_ICU_TCCR1B &=~((1<<CS11) | (1<<CS10));
	_T1_ICU_ICR1 = 1249;
}

void Timer1_ICU_Stop (void)
{
	/*
	1- Stop prescalar
	*/
	_T1_ICU_TCCR1B &=~((1<<CS12) | (1<<CS11) | (1<<CS10));
}

void Timer1_ICU_SetDuty (uint32_t angle)
{
	_T1_ICU_OCR1A = ((_T1_ICU_ICR1 * angle) / 100) - 1;
}
