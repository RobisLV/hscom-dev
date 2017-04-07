/*
 * flash.c
 *
 *  Created on: 2017. gada 29. marts
 *      Author: Roberts
 */
#include "flash.h"

uint16_t flash_read(uint32_t memory_address,uint8_t *storage_buffer, uint16_t storage_buffer_size){
    // declare an array that will hold the flash command
    uint8_t flash_command[5] = {0};
    const uint8_t dummy_byte = 0x00;
    uint8_t i;

    // compose a valid flash read command
    flash_command[0] = FLASH_OPCODE_READ;
    flash_command[1] = (uint8_t)memory_address;
    flash_command[2] = (uint8_t)(memory_address >>8);
    flash_command[3] = (uint8_t)(memory_address >>16);
    flash_command[4] = dummy_byte;

    // push "read" command to the SPI TX buffer
    for(i = 0;i < 5; i++){
        SPI_A1_byte_write(flash_command[i]);
    }

    // send 0's in order to keep CLK running
    while(storage_buffer_size>0){
        SPI_A1_byte_write(dummy_byte);
        if(SPI_A1_byte_read(&storage_buffer[storage_buffer_size])==EXIT_SUCCESS){
            storage_buffer_size--;
        }
    }
    return EXIT_SUCCESS;
}
