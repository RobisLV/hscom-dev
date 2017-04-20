/*
 * main.c
 *
 *  Created on:     2017. gada 5. februârî
 *  Author:         Roberts Trops
 *  Description:    This is software for High-speed Communication Subsystem (hardware version 1.0).
 */
#include "main.h"
#define FLASH_MEM_SIZE 32
#define FLASH_ID_SIZE 4
/*  Main routine    */

void toggle_mcu_status_led(){
   GPIO_write(MCU_LED_STATUS_PIN, MCU_LED_STATUS_PORT, GPIO_HIGH);
   _delay_cycles(50000);
   GPIO_write(MCU_LED_STATUS_PIN, MCU_LED_STATUS_PORT, GPIO_LOW);
   _delay_cycles(50000);
}

uint16_t main(void){
    MSP430_Init();
    uint8_t flash_memory[FLASH_MEM_SIZE] = {0};
    uint8_t flash_id[FLASH_ID_SIZE] = {0};
    uint8_t flash_write_data[] = {0xAA,0xE3,0xF1,0xAB};
    uint32_t read_address = 0;
    uint32_t write_address = 0;

    flash_status_read();
    flash_sector_global_unprot();
    flash_status_read();
    flash_write_enable();
    flash_status_read();
    //flash_block_erase_4KB(read_address);
    flash_data_write(0x0F, flash_write_data, 4);
    flash_write_disable();
    flash_status_read();
    while(1){   // START OF LOOP
        toggle_mcu_status_led();

    	dp_display_text("HSCOM V1.0 Command Interface");

    	flash_data_read(read_address,flash_memory, FLASH_MEM_SIZE);

        UART_A0_array_write(flash_memory, FLASH_MEM_SIZE);

        flash_id_read(flash_id, FLASH_ID_SIZE);

        UART_A0_array_write(flash_id, FLASH_ID_SIZE);

        read_address = read_address + FLASH_MEM_SIZE;
        if(read_address > 0xFF){
            read_address = 0;
        }
    }
    // END OF LOOP
}
