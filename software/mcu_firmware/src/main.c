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
    Clock_Init();
    // Initialize GPIOs
    GPIO_Init();
    // Initialize UART A0
    UART_A0_Init();
    // Disable the GPIO power-on default high-impedance mode to activate previously configured port settings
    PM5CTL0 &= ~LOCKLPM5;

	dp_delay(500);
    volatile uint16_t counter = 0;
	uint16_t i=0;
    P2DIR |= BIT2;

    while(1){
    	//counter1++;
    	GPIO_port_write(MCU_LED_STATUS_PIN, MCU_LED_STATUS_PORT, GPIO_HIGH);

    	for(i=0; i < 0xFFFF; i++){
    		counter++;
    	};
    	GPIO_port_write(MCU_LED_STATUS_PIN, MCU_LED_STATUS_PORT, GPIO_LOW);
    	for(i=0; i < 0xFFFF; i++){
    		counter++;
    	};
    	dp_display_text("\r\n\r\n\t\t--------Main menu--------");
    }
}
