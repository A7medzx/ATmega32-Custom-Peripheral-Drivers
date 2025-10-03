/*
* TIMER2_CTC_Program.c
*
* Created: 5/3/2024 5:54:35 PM
*  Author: Ahmed Mohamed
*/

#include "TIMER2_CTC_Interface.h"

uint32_t _T2_CTC_Count  = 0;
uint8_t  _T2_CTC_iValue = 0;

void Timer2_CTC_WithInterrupt_Initialize (void)
{
	/*
	1- Choose CTC mode
	2- Disconnect pin OC0
	3- Enable interrupt
	4- Enable global interrupt
	*/
	DDRB |= (1<<PB3);
	_T2_CTC_TCCR2 &=~((1<<FOC2)|(1<<WGM21)|(1<<WGM20)|(1<<COM21)|(1<<COM20)|(1<<CS22)|(1<<CS21)|(1<<CS20));
	_T2_CTC_TCCR2 |= (1<<WGM21);
	_T2_CTC_TIMSK |= ((1<<TOIE2));
	//_T2_CTC_TCCR2 &=~((1<<FOC2)|(1<<WGM01)|(1<<WGM00)|(1<<CS01)|(1<<CS02)|(1<<CS00));
	//_T2_CTC_TCCR2 |= ((1<<CS21) | (1<<COM20));
	sei();
}
void Timer2_CTC_WithInterrupt_Start (void)
{
	/*Choose prescalar 1024*/
	_T2_CTC_TCCR2 |=((1<<CS21)|(1<<CS22)|(1<<CS20));
}
void Timer2_CTC_WithInterrupt_Stop (void)
{
	/*Choose prescalar 0*/
	_T2_CTC_TCCR2 &=~((1<<CS21)|(1<<CS22)|(1<<CS20));
}
void Timer2_CTC_WithInterrupt_SetDelay (uint32_t delay, uint8_t ocrValue)
{
	/*
		1- Create counter
		2- Create tick = 1 * Prescaler / frequency
		3- Create Count = delay * 10^k / Tick
		4- Create CTC = Count / 2^8 + 1
		5- Create Initial value = 2^8 - (Count % 2^8)
		6- Set initial value
	*/
	uint8_t Tick = ((1*_T2_CTC_PRESCALER)/_T2_CTC_FREQUENCY);
	uint32_t Count = ((delay * _T2_CTC_MICROSECOND) / Tick);
	_T2_CTC_OCR2 = ocrValue;
	_T2_CTC_Count = (Count / _T2_CTC_OCR2) + 1;
	_T2_CTC_iValue = _T2_CTC_OCR2 - (Count % _T2_CTC_OCR2);
	_T2_CTC_TCNT2 = _T2_CTC_iValue;
}


void Timer2_CTC_WithoutInterrupt_Initialize (void)
{
	/*
	1- Choose CTC mode
	2- Disconnect OC2 pin
	3- Disable interrupt
	*/
	_T2_CTC_TCCR2 &=~((1<<FOC2)|(1<<WGM21)|(1<<WGM20)|(1<<COM21)|(1<<COM20)|(1<<CS22)|(1<<CS21)|(1<<CS20));
	_T2_CTC_TCCR2 |= (1<<WGM21);
	_T2_CTC_TIMSK &=~((1<<TOIE2));
}
void Timer2_CTC_WithoutInterrupt_Start (void)
{
	/* Choose prescalar 1024 */
	_T2_CTC_TCCR2 |=((1<<CS21)|(1<<CS22)|(1<<CS20));
}
void Timer2_CTC_WithoutInterrupt_Stop (void)
{
	/* Choose prescalar 0 */
	_T2_CTC_TCCR2 &=~((1<<CS21)|(1<<CS22)|(1<<CS20));
}
void Timer2_CTC_WithoutInterrupt_SetDelay (uint32_t delay, uint8_t ocrValue)
{
	/*
	1- Create counter
	2- Create tick = 1 * Prescaler / frequency
	3- Create Count = delay * 10^k / Tick
	4- Create CTC = Count / 2^8 + 1
	5- Create Initial value = 2^8 - (Count % 2^8)
	6- Set initial value
	7- Wait until flag raise
	8- Re-Initialize flag
	9- Increment counter
	*/
	uint32_t counter = 0;
	uint8_t Tick = ((1*_T2_CTC_PRESCALER)/_T2_CTC_FREQUENCY);
	uint32_t Count = ((delay * _T2_CTC_MICROSECOND) / Tick);
	_T2_CTC_OCR2 = ocrValue;
	uint32_t CTC = (Count / _T2_CTC_OCR2) + 1;
	uint8_t iValue = _T2_CTC_OCR2 - (Count % _T2_CTC_OCR2);
	_T2_CTC_TCNT2 = iValue;
	while (counter != CTC)
	{
		while (GET_BIT(_T2_CTC_TIFR, OCF2) != 1);
		_T2_CTC_TIFR |= (1<<OCF2);
		counter++;
	}
}

uint8_t Timer2_CTC_CounterValue (void)
{
	return _T2_CTC_TCNT2;
}