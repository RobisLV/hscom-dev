/*
 * flash.h
 *
 *  Created on: 2017. gada 29. marts
 *      Author: Roberts
 */
#ifndef LIB_INCLUDE_FLASH_H_
#define LIB_INCLUDE_FLASH_H_

// general libraries
#include <msp430.h>
#include <stdint.h>
#include "macros.h"
#include "spi.h"

#define FLASH_OPCODE_READ   0x0B

/************************************************************
* SPI flash control functions
************************************************************/
uint16_t flash_read(uint32_t memory_address,uint8_t *storage_buffer, uint16_t storage_buffer_size);
uint16_t flash_erase_all();
uint16_t flash_erase_block();


#endif /* LIB_INCLUDE_FLASH_H_ */
