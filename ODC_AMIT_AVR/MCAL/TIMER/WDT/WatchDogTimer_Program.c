/*
 * WatchDogTimer_Program.c
 *
 * Created: 5/10/2024 5:45:22 PM
 *  Author: Ahmed Mohamed
 */ 

#include "WatchDogTimer_Interface.h"

void WDT_Initialize(void)
{
	_WDT_WDTCR |= ((1<<WDTOE) | (1<<WDE));
}
void WDT_Start(_wdt_prescalar prescalar)
{
	switch (prescalar)
	{
		case _WDT_PRESCALAR_16K_16_ms:                                                    break;
		case _WDT_PRESCALAR_32K_32_ms:     _WDT_WDTCR |= ((1<<WDP0));                     break;
		case _WDT_PRESCALAR_64K_65_ms:     _WDT_WDTCR |= ((1<<WDP1));                     break;
		case _WDT_PRESCALAR_128K_130_ms:   _WDT_WDTCR |= ((1<<WDP1)|(1<<WDP0));           break;
		case _WDT_PRESCALAR_256K_260_ms:   _WDT_WDTCR |= ((1<<WDP2));                     break;
		case _WDT_PRESCALAR_512K_520_ms:   _WDT_WDTCR |= ((1<<WDP2)|(1<<WDP0));           break;
		case _WDT_PRESCALAR_1024K_1000_ms: _WDT_WDTCR |= ((1<<WDP2)|(1<<WDP1));           break;
		case _WDT_PRESCALAR_2048K_2100_ms: _WDT_WDTCR |= ((1<<WDP2)|(1<<WDP1)|(1<<WDP0)); break;
		default: /*Error*/ break; 
	}
}
void WDT_Refresh(void)
{
	/*
		C-Language -> Inline assembly langauage
	*/
	asm("WDR");
}
