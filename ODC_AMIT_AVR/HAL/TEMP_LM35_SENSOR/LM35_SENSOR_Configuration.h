/*
 * LM35_SENSOR_Configuration.h
 *
 * Created: 10/4/2024 10:15:42 AM
 * Author: Ahmed Mohamed
 */ 


#ifndef LM35_SENSOR_CONFIGURATION_H_
#define LM35_SENSOR_CONFIGURATION_H_

#include "CPU_Configuration.h"
#include "LM35_SENSOR_Address.h"


typedef enum
{
	LM35_ADC_Aref     = 0,
	LM35_ADC_Avcc     = 1,
	LM35_ADC_Internal = 2
}lm35_adc_vref;


typedef enum
{
	LM35_ADC_PRE1   = 0,
	LM35_ADC_PRE2   = 1,
	LM35_ADC_PRE4   = 2,
	LM35_ADC_PRE8   = 3,
	LM35_ADC_PRE16  = 4,
	LM35_ADC_PRE32  = 5,
	LM35_ADC_PRE64  = 6,
	LM35_ADC_PRE128 = 7
}lm35_adc_prescaler;


#define LM35_ADC_MAX_VALUE 1024.0
#define LM35_VOLTAGE_REF   5.0
#define LM35_CONVERSION_FACTOR 100.0  

#endif /* LM35_SENSOR_CONFIGURATION_H_ */