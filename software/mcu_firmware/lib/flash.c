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
    uint8_t dummy_byte = 0;
    uint8_t i;

    // compose a valid flash read command
    flash_command[0] = FLASH_OPCODE_READ;
    flash_command[1] = (uint8_t)memory_address;
    flash_command[2] = (uint8_t)(memory_address >>8);
    flash_command[3] = (uint8_t)(memory_address >>16);
    flash_command[4] = 0xFF;

    // push "read" command to the SPI TX buffer
    for(i = 0;i < 5; i++){
        SPI_A1_byte_write(flash_command[i]);
    }
    // send 0's in order to keep CLK running
    for(i = 0;i < storage_buffer_size; i++){
        SPI_A1_byte_write(0x00);
    }
    //__delay_cycles(50000);
    while(SPI_A1_busy_flag_read()==TRUE){}
    SPI_A1_byte_read(&dummy_byte);
    SPI_A1_byte_read(&dummy_byte);
    SPI_A1_byte_read(&dummy_byte);
    SPI_A1_byte_read(&dummy_byte);
    SPI_A1_byte_read(&dummy_byte);

    for(i = 0;i < storage_buffer_size; i++){
        SPI_A1_byte_read(&storage_buffer[i]);
    }

    return EXIT_SUCCESS;
}
