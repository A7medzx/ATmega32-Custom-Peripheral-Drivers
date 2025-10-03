/*
 * LED2_Configuration.h
 *
 * Created: 1/13/2024 5:45:23 PM
 *  Author: Ahmed Mohamed
 */ 


#ifndef LED2_CONFIGURATION_H_
#define LED2_CONFIGURATION_H_

#include "CPU_Configuration.h"
#include "DIO_Interface.h"

//Renaming Port
#define LED2_PORT   DIO_PORTC
//Renaming Pin
#define LED2_PIN    DIO_PIN4
//Renaming State
#define LED2_OUTPUT DIO_OUTPUT
//Renaming Status
#define LED2_LOW    DIO_LOW
#define LED2_HIGH   DIO_HIGH




#endif /* LED2_CONFIGURATION_H_ */
