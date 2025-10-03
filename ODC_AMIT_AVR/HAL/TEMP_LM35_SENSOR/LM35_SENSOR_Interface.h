/*
 * LM35_SENSOR_Interface.h
 *
 * Created: 10/4/2024 10:15:50 AM
 *  Author: Ahmed Mohamed
 */ 


#ifndef LM35_SENSOR_INTERFACE_H_
#define LM35_SENSOR_INTERFACE_H_

#include "LM35_SENSOR_Private.h"

void LM35_Initialize(lm35_adc_vref vref, lm35_adc_prescaler prescaler);

float LM35_ReadTemperature(adc_channel channel);

#endif /* LM35_SENSOR_INTERFACE_H_ */
