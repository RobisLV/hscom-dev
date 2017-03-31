/*
 * flash.h
 *
 *  Created on: 2017. gada 29. marts
 *      Author: Roberts
 */
// general libraries
#include <msp430.h>
#include <stdint.h>
#include "macros.h"
// task specific libraries
#include "spi.h"

#ifndef LIB_INCLUDE_FLASH_H_
#define LIB_INCLUDE_FLASH_H_

#define FLASH_OPCODE_READ   0x0B

uint16_t flash_read(uint32_t memory_address,uint16_t number_of_bytes);
uint16_t flash_erase_all();
uint16_t flash_erase_block();


#endif /* LIB_INCLUDE_FLASH_H_ */
