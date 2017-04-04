/*
Authors:
Arturs Orbidans
Roberts Trops
*/

/* Abbreviation Table
* RF - radio frequency
* DB - daughterboard
* MB - motherboard
* AF
* TXRX
*/
#include <msp430.h>
#include "RF_DB.h"
#define RX_data_length 32
//uint16_t RX_data_length = 32;
uint8_t RX_data[RX_data_length] = {0};
uint8_t const *pointer = RX_data;

RingBuffer_t SPI_A1_RX_buffer = {
    .buffer = RX_data,
    .max_length = RX_data_length,
    .head = 0,
    .tail = 0,
};
/*  Main routine    */
uint16_t main(void){
    MSP430_Init();
    uint8_t test_byte = 0;

    while(1){
    	GPIO_port_write(MCU_LED_STATUS_PIN, MCU_LED_STATUS_PORT, GPIO_HIGH);

    	_delay_cycles(500000);
    	GPIO_port_write(MCU_LED_STATUS_PIN, MCU_LED_STATUS_PORT, GPIO_LOW);
    	_delay_cycles(500000);
    	dp_display_text("HSCOM V1.0 Command Interface");
    	// read 64 bytes starting from 0th address
    	flash_read(0, 16);
    	if(!ring_buffer_empty(&SPI_A1_RX_buffer)){
    	    while(!ring_buffer_empty(&SPI_A1_RX_buffer)){
    	        ring_buffer_pop(&SPI_A1_RX_buffer, &test_byte);
    	        uart_a0_send_byte(test_byte);
    	    }
    	}
    }
}

#pragma vector=USCI_A1_VECTOR
__interrupt void USCI_A1_ISR(void)
{
    switch(__even_in_range(UCA1IV,4)){
        case 0x00:  /* No interrupt pending                 */
            break;
        case 0x02:  /* Data received, source: UCRXIFG flag  */
            // push the received SPI byte in to buffer
            ring_buffer_push(&SPI_A1_RX_buffer, UCA1RXBUF);
            break;
        case 0x04:  /* Transmit buffer empty, source: UCTXIFG flag  */
            break;
        default:    /* Default case */
            break;
    }
}
