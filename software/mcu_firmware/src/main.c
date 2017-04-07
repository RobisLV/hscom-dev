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

/*  Main routine    */
uint16_t main(void){
    MSP430_Init();
    uint8_t count = 0;
    while(1){
    	GPIO_port_write(MCU_LED_STATUS_PIN, MCU_LED_STATUS_PORT, GPIO_HIGH);
    	_delay_cycles(500000);
    	GPIO_port_write(MCU_LED_STATUS_PIN, MCU_LED_STATUS_PORT, GPIO_LOW);
    	_delay_cycles(500000);
    	dp_display_text("HSCOM V1.0 Command Interface");

        for(count = 0;count < 5; count++){
            //ring_buffer_push(&SPI_A1_TX_buffer, test_byte_array[count]);
        }
    	// trigger eUSCI A1 interrupt
    	UCA1IFG = UCA1IFG | UCTXIFG;
    	//while(ring_buffer_empty(&SPI_A1_RX_buffer) == BUFFER_EMPTY){}
        //while(ring_buffer_pop(&SPI_A1_RX_buffer, &test_byte)==BUFFER_OK){
           // uart_a0_send_byte(test_byte);
        //}
    }
}
