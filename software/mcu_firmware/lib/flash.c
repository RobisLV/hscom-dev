/*
 * flash.c
 *
 *  Created on: 2017. gada 29. marts
 *      Author: Roberts
 */
#include "flash.h"

uint16_t flash_read(uint32_t memory_address,uint16_t number_of_bytes){
    // declare an array that will hold the flash command
    uint8_t flash_command[5] = {0};
    // compose a valid flash read command
    flash_command[0] = FLASH_OPCODE_READ;
    flash_command[1] = (uint8_t)memory_address;
    flash_command[2] = (uint8_t)(memory_address >>8);
    flash_command[3] = (uint8_t)(memory_address >>16);
    flash_command[4] = 0xFF;    // dummy byte
    // send the "read" command
    SPI_A1_data_write(flash_command, 5);
    // send 0's in order to keep CLK running
    for(;number_of_bytes > 0; number_of_bytes--){
        // keep clocking untill all bytes are received
        SPI_A1_byte_write(0x00);
    }
    return EXIT_SUCCESS;
}
