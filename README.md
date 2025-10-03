# ATmega32 Custom Peripheral Drivers 🤖

This repository contains a comprehensive library of custom-built, low-level drivers for the **ATmega32 microcontroller**, written entirely in Embedded C. The drivers are developed from scratch using direct register manipulation, focusing on a deep understanding of the microcontroller's architecture.

The project is organized using a layered architecture (**APP**, **MCAL**, and **HAL**) to ensure modularity and ease of use in embedded systems projects.

-----

## Showcase Project: Automated Temperature Control System 🌡️

To demonstrate the practical application of these drivers, a complete temperature control system was developed as a final project.

  * **Functionality**: The system uses an **LM35 temperature sensor** to read the ambient temperature. The result is continuously displayed on an LCD screen.
  * **High Temperature**: If the temperature rises to **20.0°C or higher**, a driver-controlled **relay** is activated to turn on an air conditioner (AC).
  * **Low Temperature**: If the temperature drops below **20.0°C**, another **relay** is activated to turn on a heater.

### Core Implementation (`main.c`)

The application logic, which I developed for the final project, resides in `main.c`. It integrates the ADC, LCD, and LM35 Sensor drivers to create a functional and automated environmental control system.

```c
#include "main.h"
#include <avr/io.h>
#include <util/delay.h>
#include "LCD_Interface.h"
#include "ADC_Interface.h"
#include "E:\AMIT\ODC_AMIT_AVR_LAST\ODC_AMIT_AVR\ODC_AMIT_AVR\HAL\TEMP_LM35_SENSOR\LM35_SENSOR_Interface.h"

#define TEMP_THRESHOLD 20.0
#define AC_PORT     PORTD
#define AC_PIN      PD0
#define HEATER_PORT PORTD
#define HEATER_PIN  PD1

void Control_AC_Heater(float temperature);

int main(void)
{
    LM35_Initialize(LM35_ADC_Avcc, LM35_ADC_PRE64);
    LCD_Initialize();

    DDRD |= (1 << AC_PIN) | (1 << HEATER_PIN);
    PORTD &= ~((1 << AC_PIN) | (1 << HEATER_PIN));

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
```

-----

## Layered Architecture

The project's structure is divided into three main layers:

### 1\. APP (Application Layer)

This top layer contains the main application logic (`main.c` and `main.h`) where the business logic of the project resides.

### 2\. MCAL (Microcontroller Abstraction Layer)

This layer contains drivers for the ATmega32's internal peripherals.

  * **ADC**, **I2C**, **SPI**, **UART**, **DIO**, **INTERRUPT**, **TIMER**, **WDT**

### 3\. HAL (Hardware Abstraction Layer)

This layer contains drivers for external components that interface with the microcontroller.

  * **LCD**, **SEVENSEGMENT**, **BUZZER**, **KEYPAD**, **RELAY**, **LED**, **TEMP\_LM35\_SENSOR**

-----

## File Structure

Each driver module within the HAL and MCAL layers follows a standardized file structure for consistency and maintainability:

  * `deviceName_interface.h`: Public functions and configurations for the user.
  * `deviceName_program.c`: The core implementation of the driver's logic.
  * `deviceName_private.h`: Private macros, functions, and register definitions.
  * `deviceName_configuration.h`: Pre-build configurations for the driver.

-----

## Acknowledgment and Credits 🙏

A very special thank you to my instructor, **Eng. Karim ElNahal**, whose guidance and teaching were fundamental to the development of this project.

**Important Note on Contributions**: The foundational drivers in the HAL and MCAL layers were developed based on the coursework and instruction provided by Eng. Karim. The final application layer (`main.c`, `main.h`), along with the configuration of most libraries and the integration of all components for the final project, was mostly my own work. This repository represents a combination of the excellent foundational coursework and my own subsequent development efforts.

---
## License

This project is licensed under the [MIT License](https://opensource.org/licenses/MIT).
---
- **Author**: Ahmed M. Saad  
- **Email**: [ahmedm.saad005@gmail.com](mailto:ahmedm.saad005@gmail.com)
