/*
 * TWI_Interface.h
 *
 * Created: 3/8/2024 5:05:26 PM
 *  Author: Ahmed Mohamed
 */ 


#ifndef TWI_INTERFACE_H_
#define TWI_INTERFACE_H_

#include "TWI_Private.h"
/*
//Another option
void TWI_Initialize(twi_mode mode, uint8_t slaveAddress);
void TWI_Transmit(uint8_t data, twiSlaveAddress slaveAddress, uint8_t operation);
uint8_t TWI_Receive(uint8_t addres);
// Define Mode of Operation
void TWI_Master_Initialize(void);
void TWI_SLave_Initialize(twiSlaveAddress slaveAddress);
//Frame of I2C
//Start Condition Or Repeated Start
void TWI_Start_Condition(void);
void TWI_RepeatedStart_Condition(void);
//Slave Address + Operation
void TWI_Slave_Write_Operation(twiSlaveAddress slaveAddress);
void TWI_Slave_Read_Operation(twiSlaveAddress slaveAddress);
//Data + Operation
void TWI_Transmit_Byte(uint8_t data);
uint8_t TWI_Receive_Byte(void);
//Stop Condition
void TWI_Stop_Condition(void);
*/
/* ------------------------------------------------------------------------------------ */
//Master Transmit & Receive Data 
void TWI_voidPeripheralInitialize                     (twiSlaveAddress slaveAddress);
void TWI_voidMasterSendStartCondition                 (void                        );
void TWI_voidMasterSendStopCondition                  (void                        );
void TWI_voidMasterSendRepeatedStartCondition         (void                        );
void TWI_voidMasterSendSlaveAddressWithWriteOperation (twiSlaveAddress slaveAddress);
void TWI_voidMasterSendSlaveAddressWithReadOperation  (twiSlaveAddress slaveAddress);
void TWI_voidMasterTransmitDataByteWithACK            (uint8_t dataTransmitted     );
void TWI_voidMasterTransmitDataByteWithNoACK          (uint8_t dataTransmitted     );
void TWI_voidMasterReceiveDataByteWithACK             (uint8_t* dataReceived       );
void TWI_voidMasterReceiveDataByteWithNoACK           (uint8_t* dataReceived       );
/* ------------------------------------------------------------------------------------ */
void TWI_voidSlaveTransmitDataByteWithACK             (uint8_t dataTransmitted     );
void TWI_voidSlaveTransmitDataByteWithNoACK           (uint8_t dataTransmitted     );
void TWI_voidSlaveReceiveDataByteWithACK              (uint8_t* dataReceived       );
void TWI_voidSlaveReceiveDataByteWithNoACK            (uint8_t* dataReceived       );
/* ------------------------------------------------------------------------------------ */
#endif /* TWI_INTERFACE_H_ */