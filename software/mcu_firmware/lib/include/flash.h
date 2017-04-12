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

/******************************************
 *           AT25DF321A OP-CODES
 ******************************************/
#define FLASH_OPCODE_DATA_WRITE     0x02
#define FLASH_OPCODE_ENABLE_WRITE   0x06
#define FLASH_OPCODE_DISABLE_WRITE  0x04
#define FLASH_OPCODE_STATUS_READ    0x05

#define FLASH_OPCODE_DATA_READ      0x0B
#define FLASH_OPCODE_RESET          0xF0
#define FLASH_OPCODE_ID_READ        0x9F
#define FLASH_OPCODE_PWR_DOWN       0xB9
#define FLASH_OPCODE_PWR_UP         0xAB

/******************************************
 *    AT25DF321A status register bits
 ******************************************/
#define FLASH_SREG_READY            0x01    /* Ready/Busy Status                    */
#define FLASH_SREG_WEL              0x02    /* Write Enable Latch Status            */
#define FLASH_SREG_SWP_L            0x04    /* Software Protection Status           */
#define FLASH_SREG_SWP_H            0x08    /* Software Protection Status           */
#define FLASH_SREG_WPP              0x10    /* Write Protect (WP) Pin Status        */
#define FLASH_SREG_EPE              0x20    /* Erase/Program Error                  */
#define FLASH_SREG_RES              0x40    /* Reserved for future use              */
#define FLASH_SREG_SPRL             0x80    /* Sector Protection Registers Locked   */

/************************************************************
* SPI flash control functions
************************************************************/
uint16_t flash_data_read    (uint32_t memory_address,uint8_t *storage_buffer, uint16_t storage_buffer_size);
uint16_t flash_id_read      (uint8_t *storage_buffer, uint16_t storage_buffer_size);
uint16_t flash_data_write   (uint32_t memory_address,uint8_t *data_buffer, uint16_t data_buffer_size);
uint16_t flash_status_read      (void);
uint16_t flash_write_enable     (void);
uint16_t flash_write_disable    (void);
uint16_t flash_erase_all();
uint16_t flash_erase_block();


#endif /* LIB_INCLUDE_FLASH_H_ */
