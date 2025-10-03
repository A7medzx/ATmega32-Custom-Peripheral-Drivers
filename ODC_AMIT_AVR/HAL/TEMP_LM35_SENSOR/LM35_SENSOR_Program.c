/*
 * LM35_SENSOR_Program.c
 *
 * Created: 10/4/2024 10:15:58 AM
 *  Author: Ahmed Mohamed
 */ 

#include "LM35_SENSOR_Interface.h"

void LM35_Initialize(lm35_adc_vref vref, lm35_adc_prescaler prescaler)
{
	ADC_Initialize_WithoutInterrupt(vref, prescaler);
}

float LM35_ReadTemperature(adc_channel channel)
{
	uint16_t ADC_Value = ADC_Read(channel);
	
	float temperature = (ADC_Value * LM35_VOLTAGE_REF / LM35_ADC_MAX_VALUE) * LM35_CONVERSION_FACTOR;
	
	return round(temperature);
}

