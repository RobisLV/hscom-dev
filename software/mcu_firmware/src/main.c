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
	WDTCTL = WDTPW | WDTHOLD;	// Stop watchdog timer
	// Initialize clock system
    CS_init();
    // Initialize GPIOs
    GPIO_init();
    // Initialize UART A0
    UART_A0_init();
    // Disable the GPIO power-on default high-impedance mode to activate previously configured port settings
    PM5CTL0 &= ~LOCKLPM5;
    // Initialize SPI A1
    SPI_A1_init();
	dp_delay(500);
    volatile uint16_t counter = 0;
	uint16_t i=0;
	uint16_t j=0;
	uint16_t bytes_to_read = 64;
    P2DIR |= BIT2;

    while(1){
    	GPIO_port_write(MCU_LED_STATUS_PIN, MCU_LED_STATUS_PORT, GPIO_HIGH);

    	for(i=0; i < 0xFFFF; i++){
    		counter++;
    	};
    	GPIO_port_write(MCU_LED_STATUS_PIN, MCU_LED_STATUS_PORT, GPIO_LOW);
    	for(i=0; i < 0xFFFF; i++){
    		counter++;
    	};
    	dp_display_text("\r\n\r\n\t\t--------Main menu--------");
    	GPIO_port_write(INT_SPI_FLASH_SS_PIN, INT_SPI_FLASH_SS_PORT, GPIO_LOW);
        SPI_A1_byte_write(0x0B);
        SPI_A1_byte_write(0x00);
        SPI_A1_byte_write(0x00);
        SPI_A1_byte_write(0x00);
        SPI_A1_byte_write(0xFF);
    	for(j=0;j<64;j++){
    	    SPI_A1_byte_write(0x00);
    	}
    	GPIO_port_write(INT_SPI_FLASH_SS_PIN, INT_SPI_FLASH_SS_PORT, GPIO_HIGH);
    }
}
