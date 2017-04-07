/*
 * flash.c
 *
 *  Created on: 2017. gada 29. marts
 *      Author: Roberts
 */
#include "flash.h"

uint16_t flash_read(uint32_t memory_address,uint16_t byte_count){
    // declare an array that will hold the flash command

    //uint8_t flash_command[5] = {0};
    uint8_t count = 0;
    // compose a valid flash read command
    /*
    flash_command[0] = FLASH_OPCODE_READ;
    flash_command[1] = (uint8_t)memory_address;
    flash_command[2] = (uint8_t)(memory_address >>8);
    flash_command[3] = (uint8_t)(memory_address >>16);
    flash_command[4] = 0xFF;    // dummy byte
*/
    // push "read" command to the SPI TX buffer
    for(count = 0;count < 5; count++){
        //ring_buffer_push(&SPI_A1_TX_buffer, flash_command[count]);
    }
    // trigger eUSCI A1 interrupt starting the SPI transmission
    //UCA1IFG = UCA1IFG | UCTXIFG;
    SPI_A1_TX_interrupt(SPI_INT_ENABLE);
    // send 0's in order to keep CLK running
    for(;byte_count > 0; byte_count--){
        // keep clocking untill all bytes are received
        //ring_buffer_push(&SPI_A1_TX_buffer, 0x00);
    }
    return EXIT_SUCCESS;
}
