/*
 * Timer0_CTC_Interface.h
 *
 * Created: 2/16/2024 5:40:57 PM
 *  Author: Ahmed Mohamed
 */ 


#ifndef TIMER1_FAST_PWM_INTERFACE_H_
#define TIMER1_FAST_PWM_INTERFACE_H_

#include "Timer1_FAST_PWM_Private.h"

void Timer1_FAST_PWM_Initialize (_t1_fast_pwm_bits bits);
void Timer1_FAST_PWM_Start (_t1_fast_pwm_prescalar prescalar);
void Timer1_FAST_PWM_Stop (void);
void Timer1_FAST_PWM_SetDuty (_t1_fast_pwm_pin pin, _t1_fast_pwm_bits bits, uint8_t dutycyle);

#endif /* TIMER1_FAST_PWM_INTERFACE_H_ */