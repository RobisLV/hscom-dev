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
 *         AT25DF321A OP-CODES
 ******************************************/
/*  Program (write) and Erase Commands  */
#define FLASH_OPCODE_ARRAY_READ         0x0B    /* Fclk <= 85MHz            */
//#define FLASH_OPCODE_ARRAY_READ       0x03    /* Fclk <= 50MHz            */
//#define FLASH_OPCODE_ARRAY_READ       0x1B    /* Fclk <= 100MHz           */
#define FLASH_OPCODE_DARRAY_READ        0x3B    /* Dual-Output Read Array   */
#define FLASH_OPCODE_BLOCK_ERASE_4KB    0x20    /* Block Erase (4-KBytes)   */
#define FLASH_OPCODE_BLOCK_ERASE_32KB   0x52    /* Block Erase (32-KBytes)  */
#define FLASH_OPCODE_BLOCK_ERASE_64KB   0xD8    /* Block Erase (64-KBytes)  */
#define FLASH_OPCODE_CHIP_ERASE         0x60    /* Chip Erase               */
//#define FLASH_OPCODE_CHIP_ERASE       0xC7
#define FLASH_OPCODE_DATA_WRITE         0x02    /*Byte/Page Program                */
#define FLASH_OPCODE_DDATA_WRITE        0xA2    /* Dual-Input Byte/Page Program    */
#define FLASH_OPCODE_WRITE_SUSPEND      0xB0    /* Program/Erase Suspend           */
#define FLASH_OPCODE_WRITE_RESUME       0xD0    /* Program/Erase Resume            */

/*  Protection commands                 */
#define FLASH_OPCODE_WRITE_ENABLE       0x06    /* Write Enable                    */
#define FLASH_OPCODE_WRITE_DISABLE      0x04    /* Write Disable                   */
#define FLASH_OPCODE_SECTOR_PROTECT     0x36    /* Protect Sector                  */
#define FLASH_OPCODE_SECTOR_UNPROTECT   0x39    /* Unprotect Sector                */
#define FLASH_OPCODE_SECTOR_PROT_READ   0x3C    /* Read Sector Protection Regs     */

/*  Security Commands                   */
#define FLASH_OPCODE_SECTOR_LOCK        0x33    /* Sector Lockdown                 */
#define FLASH_OPCODE_FREEZ_LOCK_STATE   0x34    /* Freeze Sector Lockdown State    */
#define FLASH_OPCODE_SECTOR_LOCK_READ   0x35    /* Read Sector Lockdown Registers  */
#define FLASH_OPCODE_OTP_WRITE          0x3C    /* Program OTP Security Register   */
#define FLASH_OPCODE_OTP_READ           0x3C    /* Read OTP Security Registe       */

/*  Status Register Commands            */
#define FLASH_OPCODE_STATUS_READ        0x05    /* Read Status Register            */
#define FLASH_OPCODE_STATUS_1_WRITE     0x01    /* Write Status Register Byte 1    */
#define FLASH_OPCODE_STATUS_2_WRITE     0x31    /* Write Status Register Byte 2    */

/*  Miscellaneous Commands              */
#define FLASH_OPCODE_RESET              0xF0    /* Chip reset                      */
#define FLASH_OPCODE_ID_READ            0x9F    /* Read Manufacturer and Device ID */
#define FLASH_OPCODE_PWR_DOWN           0xB9    /* Deep Power-Down                 */
#define FLASH_OPCODE_PWR_UP             0xAB    /* Resume from Deep Power-Down     */

/******************************************
 *    AT25DF321A status register bits
 ******************************************/
/*  Status Register Byte 1              */
#define FLASH_SREG1_READY               0x01    /* Ready/Busy Status                    */
#define FLASH_SREG1_WEL                 0x02    /* Write Enable Latch Status            */
#define FLASH_SREG1_SWP_L               0x04    /* Software Protection Status           */
#define FLASH_SREG1_SWP_H               0x08    /* Software Protection Status           */
#define FLASH_SREG1_WPP                 0x10    /* Write Protect (WP) Pin Status        */
#define FLASH_SREG1_EPE                 0x20    /* Erase/Program Error                  */
//#define FLASH_SREG1_RESERVED          0x40    /* Reserved for future use              */
#define FLASH_SREG1_SPRL                0x80    /* Sector Protection Registers Locked   */

/*  Status Register Byte 2              */
#define FLASH_SREG2_READY               0x01    /* Ready/Busy Status                    */
#define FLASH_SREG2_ES                  0x02    /* Ready/Busy Status                    */
#define FLASH_SREG2_PS                  0x04    /* Ready/Busy Status                    */
#define FLASH_SREG2_SLE                 0x08    /* Ready/Busy Status                    */
#define FLASH_SREG2_RSTE                0x10    /* Reset enable                         */
//#define FLASH_SREG2_RESERVED          0x20    /* Reserved for future use              */
//#define FLASH_SREG2_RESERVED          0x40    /* Reserved for future use              */
//#define FLASH_SREG2_RESERVED          0x80    /* Reserved for future use              */

#define FLASH_SREG1_GLOBAL_PROT         0x7F    /* Global protect all sectors           */
#define FLASH_SREG1_GLOBAL_UNPROT       0x00    /* Global Unprotect all sectors         */
#define FLASH_SREG1_SECTOR_PROT_LOCK    0xFF    /* Sector Protection Registers Locked   */
#define FLASH_SREG1_SECTOR_PROT_UNLOCK  0x00    /* Sector Protection Registers unlocked */

/******************************************
 *    AT25DF321A chip specific defines
 ******************************************/
#define PAGE_SIZE       256         /* Page size in bytes                 */
#define SECTOR_SIZE     64          /* Sector size in bytes               */
#define SECTOR_COUNT    64          /* Number of sectors                  */
#define END_ADDRESS     0x3FFFFF    /* The last address in flash memory   */

/* Status register struture */
volatile struct {
    uint8_t byte_1_write;   /* Status Write register 1  */
    uint8_t byte_1_read;    /* Status read register 1   */
    uint8_t byte_2_write;   /* Status Write register 2  */
    uint8_t byte_2_read;    /* Status read register 2   */
} FlashSREG;

/************************************************************
* SPI flash control functions
************************************************************/
uint16_t flash_data_read        (uint32_t memory_address,uint8_t *storage_buffer, uint16_t storage_buffer_size);
uint16_t flash_id_read          (uint8_t *storage_buffer, uint16_t storage_buffer_size);
uint16_t flash_data_write       (uint32_t memory_address,uint8_t *data_buffer, uint8_t data_buffer_size);
uint16_t flash_status_read      (void);
uint16_t flash_write_enable     (void);
uint16_t flash_write_disable    (void);

uint16_t flash_chip_erase       (void);
uint16_t flash_block_erase_4KB  (uint32_t memory_address);
uint16_t flash_block_erase_32KB (uint32_t memory_address);
uint16_t flash_block_erase_64KB (uint32_t memory_address);

uint16_t flash_sector_global_unprot (void);

/*  Miscellaneous functions              */

#endif /* LIB_INCLUDE_FLASH_H_ */
