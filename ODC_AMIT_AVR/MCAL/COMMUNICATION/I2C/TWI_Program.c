/*
* TWI_Program.c
*
* Created: 3/8/2024 5:05:45 PM
*  Author: Ahmed Mohamed
*/
#include "TWI_Interface.h"
#include "LCD_Interface.h"
/* -------------------------------------------------------------------------------------------------------------------------------------- */
//Master Receive byte from slave
void TWI_voidPeripheralInitialize (twiSlaveAddress slaveAddress)
{
	_TWI_TWSR &=~((1<<TWPS1) |(1<<TWPS0))            ; // Pre-scalar bits in TWSR will be initialize to value = 0
	_TWI_TWBR |= (0x0C)                              ; // ((((MC_FREQ / I2C_SCL) / Prescaler) - 16 ) / 2); Dcimal = 12
	_TWI_TWAR = (slaveAddress << 1) | (0x01)         ; // Set Slave Address + Enable General Call
	_TWI_TWCR |= ((1<<TWINT) | (1<<TWEA) | (1<<TWEN)); // Reinitialize flag + Enable TWI + Enable Acknowledgment
}
/* -------------------------------------------------------------------------------------------------------------------------------------- */
void TWI_voidMasterSendStartCondition (void)
{
	_TWI_TWCR = ((1<<TWSTA) | (1<<TWINT) | (1<<TWEN)); // Start Condition + Reinitialize flag + Enable TWI
	while (GET_BIT(_TWI_TWCR, TWINT) != 1);            // Waiting Flag
	while((_TWI_TWSR & 0xF8) != START_ACK);            // Wait until receive start acknowledgment, 0x08
}

void TWI_voidMasterSendStopCondition (void)
{	
	_TWI_TWCR |= ((1<<TWINT) | (1<<TWSTO) | (1<<TWEN));// Reinitialize flag + Enable TWI
	while (GET_BIT(_TWI_TWCR, TWINT) != 1);            // Waiting Flag
	while((TWSR & 0xF8) != STOP_ACK);                  // Wait until receive start acknowledgment, 0x40
}

void TWI_voidMasterSendRepeatedStartCondition (void)
{
	_TWI_TWCR = ((1<<TWSTA) | (1<<TWINT) | (1<<TWEN)); // Start Condition + Reinitialize flag + Enable TWI
	while (GET_BIT(_TWI_TWCR, TWINT) != 1);            // Waiting Flag
	while((_TWI_TWSR & 0xF8) != REP_START_ACK);        // Wait until receive repeated start acknowledgment, 0x10
	_TWI_TWCR &=~(1<<TWSTA);
}

void TWI_voidMasterSendSlaveAddressWithWriteOperation (twiSlaveAddress slaveAddress)
{
	if(slaveAddress < 128)
	{
		_TWI_TWDR = (slaveAddress<<1) | (0x00);        // Write Slave address with write operation
		_TWI_TWCR &=~(1<<TWSTA);                       // Clear start condition is constrain according to data-sheet
		_TWI_TWCR |= ((1<<TWINT) | (1<<TWEN));         // Reinitialize flag + Enable TWI
		while (GET_BIT(_TWI_TWCR, TWINT) != 1);        // Waiting Flag
		while((_TWI_TWSR & 0xF8) != SLAVE_ADD_WR_ACK); // Wait until receive write acknowledgment
	}
	else
	{
		return;
	}
}

void TWI_voidMasterSendSlaveAddressWithReadOperation  (twiSlaveAddress slaveAddress)
{
	if(slaveAddress < 128)
	{
		_TWI_TWDR = (slaveAddress<<1) | (0x01); // Write Slave address with read operation
		_TWI_TWCR &=~(1<<TWSTA);                // Clear start condition is constrain according to data-sheet
		_TWI_TWCR |= ((1<<TWINT) | (1<<TWEN));  // Reinitialize flag + Enable TWI
		while (GET_BIT(_TWI_TWCR, TWINT) != 1); // Waiting Flag
		while((_TWI_TWSR & 0xF8) != SLAVE_ADD_RD_ACK); // Wait until receive write acknowledgment
	}
	else
	{
		return;
	}
}

void TWI_voidMasterTransmitDataByteWithACK(uint8_t dataTransmitted)
{
	_TWI_TWDR = dataTransmitted;
	_TWI_TWCR |= ((1<<TWINT) | (1<<TWEN));  // Reinitialize flag + Enable TWI
	while (GET_BIT(_TWI_TWCR, TWINT) != 1); // Waiting Flag
	//LCD_Clear_Screen();
	//LCD_Write_Location(ROW0, COL0);
	//LCD_Write_String((uint8_t*)"Transmit ACK");
	//LCD_Write_Location(ROW1, COL0);
	//LCD_Write_String((uint8_t*)"Status: ");
	//LCD_Write_IntegerNumber(_TWI_TWSR & 0xF8);
	//_delay_ms(500);
	while((_TWI_TWSR & 0xF8) != MASTER_WR_BYTE_ACK); // Wait until receive write acknowledgment
	//LCD_Write_String((uint8_t*)",Done");
}

void TWI_voidMasterTransmitDataByteWithNoACK(uint8_t dataTransmitted)
{
	_TWI_TWDR = dataTransmitted;
	_TWI_TWCR |= ((1<<TWINT) | (1<<TWEN));      // Reinitialize flag + Enable TWI
	while (GET_BIT(_TWI_TWCR, TWINT) != 1);     // Waiting Flag
	//LCD_Clear_Screen();
	//LCD_Write_Location(ROW0, COL0);
	//LCD_Write_String((uint8_t*)"Transmit No ACK");
	//LCD_Write_Location(ROW1, COL0);
	//LCD_Write_String((uint8_t*)"Status: ");
	//LCD_Write_IntegerNumber(_TWI_TWSR & 0xF8);
	//_delay_ms(500);
	while((_TWI_TWSR & 0xF8) != MASTER_WR_BYTE_NOACK); // Wait until receive write acknowledgment
	//LCD_Write_String((uint8_t*)",Done");
}

void TWI_voidMasterReceiveDataByteWithACK(uint8_t* dataReceived)
{
	_TWI_TWCR = (1<<TWEA) | (1<<TWEN) | (1<<TWINT); // Reinitialize flag + Enable TWI + Enable Acknowledgment
	while (GET_BIT(_TWI_TWCR, TWINT) != 1);         // Wait until job finish
	while((TWSR & 0xF8) != MASTER_RD_BYTE_ACK);            // Wait until receive write acknowledgment
	_TWI_TWCR &=~(1<<TWEA);                         // Disable acknowledgment
	*dataReceived = _TWI_TWDR;                      // Read received data
}

void TWI_voidMasterReceiveDataByteWithNoACK(uint8_t* dataReceived)
{
	_TWI_TWCR = (1<<TWEN) | (1<<TWINT);         // Reinitialize flag + Enable TWI + Enable Acknowledgment
	while (GET_BIT(_TWI_TWCR, TWINT) != 1);     // Wait until job finish
	while((_TWI_TWSR & 0xF8) != MASTER_RD_BYTE_NOACK); // Wait until receive write acknowledgment
	*dataReceived = _TWI_TWDR;                  // Read received data
}
/* -------------------------------------------------------------------------------------------------------------------------------------- */
void TWI_voidSlaveTransmitDataByteWithACK(uint8_t dataTransmitted)
{
		_TWI_TWDR = dataTransmitted;
		_TWI_TWCR |= ((1<<TWINT) | (1<<TWEN));  // Reinitialize flag + Enable TWI
		while (GET_BIT(_TWI_TWCR, TWINT) != 1); // Waiting Flag
		while((_TWI_TWSR & 0xF8) != SLAVE_WR_BYTE_ACK); // Wait until receive write acknowledgment
}

void TWI_voidSlaveTransmitDataByteWithNoACK(uint8_t dataTransmitted)
{
	_TWI_TWDR = dataTransmitted;
	_TWI_TWCR |= ((1<<TWINT) | (1<<TWEN));  // Reinitialize flag + Enable TWI
	while (GET_BIT(_TWI_TWCR, TWINT) != 1); // Waiting Flag
	while((_TWI_TWSR & 0xF8) != SLAVE_WR_BYTE_ACK); // Wait until receive write acknowledgment
}

void TWI_voidSlaveReceiveDataByteWithACK(uint8_t* dataReceived)
{
	_TWI_TWCR = (1<<TWEA) | (1<<TWEN) | (1<<TWINT); // Reinitialize flag + Enable TWI + Enable Acknowledgment
	while (GET_BIT(_TWI_TWCR, TWINT) != 1);         // Wait until job finish
	while((TWSR & 0xF8) != SLAVE_RD_BYTE_ACK);            // Wait until receive write acknowledgment
	_TWI_TWCR &=~(1<<TWEA);                         // Disable acknowledgment
	*dataReceived = _TWI_TWDR;                      // Read received data
}

void TWI_voidSlaveReceiveDataByteWithNoACK(uint8_t* dataReceived)
{
	_TWI_TWCR = (1<<TWEA) | (1<<TWEN) | (1<<TWINT); // Reinitialize flag + Enable TWI + Enable Acknowledgment
	while (GET_BIT(_TWI_TWCR, TWINT) != 1);         // Wait until job finish
	while((TWSR & 0xF8) != SLAVE_RD_BYTE_ACK);            // Wait until receive write acknowledgment
	_TWI_TWCR &=~(1<<TWEA);                         // Disable acknowledgment
	*dataReceived = _TWI_TWDR;                      // Read received data
}
/* -------------------------------------------------------------------------------------------------------------------------------------- */
