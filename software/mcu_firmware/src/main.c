/*
 * main.c
 *
 *  Created on:     2017. gada 5. februârî
 *  Author:         Roberts Trops
 *  Description:    This is software for High-speed Communication Subsystem (hardware version 1.0).
 */
#include "main.h"

/*  Main routine    */
uint16_t main(void){
    MSP430_Init();
    uint8_t flash_memory[16] = {0};
    //uint8_t spi_rx_byte = 0;
    uint8_t i;
    while(1){
    	GPIO_port_write(MCU_LED_STATUS_PIN, MCU_LED_STATUS_PORT, GPIO_HIGH);
    	_delay_cycles(200000);
    	GPIO_port_write(MCU_LED_STATUS_PIN, MCU_LED_STATUS_PORT, GPIO_LOW);
    	_delay_cycles(200000);
    	dp_display_text("HSCOM V1.0 Command Interface");
    	flash_read(0x00,flash_memory, 16);

    	_delay_cycles(200000);
    	for(i = 16; i > 0; i--){
    	    uart_a0_send_byte(flash_memory[i-1]);
    	}
    }
}
