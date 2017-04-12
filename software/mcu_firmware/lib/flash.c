/*
 * flash.c
 *
 *  Created on: 2017. gada 29. marts
 *      Author: Roberts
 */
#include "flash.h"

/***************************************************
 * Flash read/write and configure functions
 **************************************************/

uint16_t flash_data_read(uint32_t memory_address,uint8_t *storage_buffer, uint16_t storage_buffer_size){
    uint8_t dummy_byte = 0;
    uint8_t i;
    // wait while TX and RX is complete
    while(SPI_A1_busy_flag_read()==TRUE){}
    // clear the TX/RX SPI buffers
    SPI_A1_TX_buffer_reset();
    SPI_A1_RX_buffer_reset();
    // push "read" command to the SPI TX buffer
    SPI_A1_byte_write(FLASH_OPCODE_DATA_READ);
    SPI_A1_byte_write((uint8_t)memory_address);
    SPI_A1_byte_write((uint8_t)(memory_address >>8));
    SPI_A1_byte_write((uint8_t)(memory_address >>16));
    SPI_A1_byte_write(0xFF); // dummy byte

    // send 0's in order to keep CLK running
    for(i = 0;i < storage_buffer_size; i++){
        SPI_A1_byte_write(0x00);
    }
    // wait while TX and RX is complete
    while(SPI_A1_busy_flag_read()==TRUE){}

    // read and dump the first 5 received bytes (not actually data)
    SPI_A1_byte_read(&dummy_byte);
    SPI_A1_byte_read(&dummy_byte);
    SPI_A1_byte_read(&dummy_byte);
    SPI_A1_byte_read(&dummy_byte);
    SPI_A1_byte_read(&dummy_byte);

    // read bytes and store them in array
    for(i = 0;i < storage_buffer_size; i++){
        SPI_A1_byte_read(&storage_buffer[i]);
    }
    return EXIT_SUCCESS;
}

uint16_t flash_data_write(uint32_t memory_address,uint8_t *data_buffer, uint16_t data_buffer_size){
    uint8_t index;
    // wait while TX and RX is complete
    while(SPI_A1_busy_flag_read()==TRUE){}
    // clear the TX/RX SPI buffers
    SPI_A1_TX_buffer_reset();
    SPI_A1_RX_buffer_reset();
    // write the "flash write" command and address to TX buffer
    SPI_A1_byte_write(FLASH_OPCODE_ENABLE_WRITE);
    SPI_A1_byte_write(FLASH_OPCODE_DATA_WRITE);
    SPI_A1_byte_write((uint8_t)memory_address);
    SPI_A1_byte_write((uint8_t)(memory_address >>8));
    SPI_A1_byte_write((uint8_t)(memory_address >>16));
    // write flash data to TX buffer
    for(index = 0;index < data_buffer_size; index++){
        SPI_A1_byte_write(data_buffer[index]);
    }
    SPI_A1_byte_write(FLASH_OPCODE_DISABLE_WRITE);
    return EXIT_SUCCESS;
}

uint16_t flash_id_read(uint8_t *storage_buffer, uint16_t storage_buffer_size){
    uint8_t index;
    uint8_t dummy_byte = 0;

    // wait while TX and RX is complete
    while(SPI_A1_busy_flag_read()==TRUE){}
    // clear the TX/RX SPI buffers
    SPI_A1_TX_buffer_reset();
    SPI_A1_RX_buffer_reset();

    SPI_A1_byte_write(FLASH_OPCODE_ID_READ);

    if(storage_buffer_size < 4){
        return EXIT_FAILURE;
    }
    SPI_A1_byte_write(dummy_byte);
    SPI_A1_byte_write(dummy_byte);
    SPI_A1_byte_write(dummy_byte);
    SPI_A1_byte_write(dummy_byte);
    while(SPI_A1_busy_flag_read()==TRUE){}
    // read and dump the first byte
    SPI_A1_byte_read(&dummy_byte);
    for(index = 0;index < 4; index++){
        SPI_A1_byte_read(&storage_buffer[index]);
    }
    return EXIT_SUCCESS;
}

uint16_t flash_status_read(void){
    // wait while TX and RX is complete
    while(SPI_A1_busy_flag_read()==TRUE){}
    // clear the TX/RX SPI buffers
    SPI_A1_TX_buffer_reset();
    SPI_A1_RX_buffer_reset();
    SPI_A1_byte_write(FLASH_OPCODE_STATUS_READ);
    SPI_A1_byte_write(0x00);
    SPI_A1_byte_write(0x00);
    return EXIT_SUCCESS;
}

uint16_t flash_write_enable(void){
    // wait while TX and RX is complete
    while(SPI_A1_busy_flag_read()==TRUE){}
    // clear the TX/RX SPI buffers
    SPI_A1_TX_buffer_reset();
    SPI_A1_RX_buffer_reset();
    SPI_A1_byte_write(FLASH_OPCODE_ENABLE_WRITE);
    return EXIT_SUCCESS;
}

uint16_t flash_write_disable(void){
    // wait while TX and RX is complete
    while(SPI_A1_busy_flag_read()==TRUE){}
    // clear the TX/RX SPI buffers
    SPI_A1_TX_buffer_reset();
    SPI_A1_RX_buffer_reset();
    SPI_A1_byte_write(FLASH_OPCODE_DISABLE_WRITE);
    return EXIT_SUCCESS;
}
