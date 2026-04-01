#include "I2C.h"

//initialise I2C pins (PB6 - SCL, PB7 - SDA), 100kHz interface
void I2CInitialise(void){

	//Enable GPIOB & 12C1 clock
	RCC->AHBENR |= RCC_AHBENR_GPIOBEN;
	RCC->APB1ENR |= RCC_APB1ENR_I2CEN;

	//Set SCL & SDA pins to alternate function mode in MODER
	GPIOB->MODER &= ~(GPIO_MODER_MODER6 | GPIO_MODER_MODER7); //clear bits
	GPIOB->MODER |= (GPIO_MODE_MODER6_1 | GPIO_MODER_MODER7_1); //set bits to AF mode

	//set to open drain configuration
	GPIOB->OTYPER |= (GPIO_OTYPER_OT_6 | GPIO_OTYPER_OT_7);

	//set AF4 for SCL & SDA pins
	GPIOB->AFR[0] &= ~((0xF << (6 * 4)) | (0xF << (7 * 4)));
    GPIOB->AFR[0] |= (4 << (6 * 4)) | (4 << (7 * 4));

    //configure to 100kHz interface
    I2C1->CR1 &= ~I2C_CR1_PE; //disable I2C to set 100kHx

    I2C1->TIMINGR = 0x00201D2B; //correct value for 100kHz given 8MHz clock

    I2C1->CR1 |= I2C_CR1_PE; //reenable I2C

}


void I2CWrite(uint8_t slaveAddress, uint8_t memoryAddress, uint8_t data){}



void I2CRead(uint8_t slaveAddress, uint8_t memoryAddress, uint8_t* bufferPointer, uint16_t byteNumber){}

