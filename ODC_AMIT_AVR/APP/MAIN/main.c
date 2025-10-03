/*
* ODC_AMIT_AVR.c
*
* Created: 9/29/2024 11:49:04 AM
* Author: Ahmed Mohamed
*/

#include "main.h"
#include <avr/io.h>
#include <util/delay.h>
#include "LCD_Interface.h"      
#include "ADC_Interface.h"      
#include "E:\AMIT\ODC_AMIT_AVR_LAST\ODC_AMIT_AVR\ODC_AMIT_AVR\HAL\TEMP_LM35_SENSOR\LM35_SENSOR_Interface.h" 

#define TEMP_THRESHOLD 20.0  
#define AC_PORT    PORTD
#define AC_PIN     PD0
#define HEATER_PORT PORTD
#define HEATER_PIN PD1
void Control_AC_Heater(float temperature);
int main(void)
{
	/* Replace with your application code */
	
	    LM35_Initialize(LM35_ADC_Avcc, LM35_ADC_PRE64);
		LCD_Initialize();
		
		 DDRD |= (1 << AC_PIN) | (1 << HEATER_PIN);
		 PORTD &= ~(1 << AC_PIN); 
		 PORTD &= ~(1 << HEATER_PIN);
		 
		 
		float temperature = 0;
	while (1)
	{
		temperature = LM35_ReadTemperature(ADC_channel_0);
		Control_AC_Heater(temperature);
		_delay_ms(1000);
	}
}

void Control_AC_Heater(float temperature)
 {
	
	if (temperature >= TEMP_THRESHOLD) {
		PORTD |= (1 << AC_PIN);
		PORTD &= ~(1 << HEATER_PIN);
		LCD_Clear_Screen();
		LCD_Write_Location(ROW0,COL0);
		LCD_Write_String("Temp: ");
		LCD_Write_FloatNumber(temperature);
		LCD_Write_String(" C");
		LCD_Write_Location(ROW1,COL0);
		LCD_Write_String("AC ON");
		} else {
		PORTD |= (1 << HEATER_PIN);
		PORTD &= ~(1 << AC_PIN);
		LCD_Clear_Screen();
		LCD_Write_Location(ROW0,COL0);
		LCD_Write_String("Temp: ");
		LCD_Write_FloatNumber(temperature);
		LCD_Write_String(" C");
		LCD_Write_Location(ROW1,COL0);
		LCD_Write_String("HEATER ON");
	}
}