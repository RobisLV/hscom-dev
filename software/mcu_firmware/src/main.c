/*
 * main.c
 *
 *  Created on:     2017. gada 5. febru�r�
 *  Author:         Roberts Trops
 *  Description:    This is software for High-speed Communication Subsystem (hardware version 1.0).
 */
#include "main.h"
#define flash_mem_size 16
/*  Main routine    */

void toggle_mcu_status_led(){
   GPIO_write(MCU_LED_STATUS_PIN, MCU_LED_STATUS_PORT, GPIO_HIGH);
   _delay_cycles(50000);
   GPIO_write(MCU_LED_STATUS_PIN, MCU_LED_STATUS_PORT, GPIO_LOW);
   _delay_cycles(50000);
}

uint16_t main(void){
    MSP430_Init();
    uint8_t flash_memory[flash_mem_size] = {0};
    uint8_t i;

    // START OF LOOP
    while(1){
        toggle_mcu_status_led();

    	dp_display_text("HSCOM V1.0 Command Interface");

    	flash_read(0x00,flash_memory, flash_mem_size);

        for(i = 0; i < flash_mem_size; i++){
            uart_a0_send_byte(flash_memory[i]);
            flash_memory[i] = 0;
        }
    }
    // END OF LOOP
}
