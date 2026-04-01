#ifndef I2C_H
#define I2C_H

/*
 * This module implements an I2C interface, satisfying the following:
 * -> start condition
 * -> address frame
 * -> ACK/NAK
 * -> data transfer
 * -> stop condition
 */

//header file below from STMF3disco-BSP
#include "stm32f3xx.h"

#include <stdint.h>

//initialises I2C-1 on pins PB6 (SCL) & PB7 (SDA), sets 100kHz I2C
void I2CInitialise(void);

//sends data to memoryAddress on the target slaveAddress
void I2CWrite(uint8_t slaveAddress, uint8_t memoryAddress, uint8_t data);

//reads byteNumber bytes from slaveAddress into bufferPointer
void I2CRead(uint8_t slaveAddress, uint8_t memoryAddress, uint8_t* bufferPointer, uint16_t byteNumber);

#endif
