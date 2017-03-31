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

uint8_t rx_buffer = 0;
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
	//uint16_t j=0;
	//uint16_t bytes_to_read = 64;
    P2DIR |= BIT2;
    //uint8_t test_byte_array[5] = {0x0B,0x00,0x00,0x00,0xFF};
    __bis_SR_register(GIE);       // Enter LPM0, enable interrupts
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
    	//dp_display_text(test_byte_array);
    	// read 64 bytes starting from 0th address
    	flash_read(0, 8);
    	uart_a0_send_byte(SPI_A1_byte_read());
    	uart_a0_send_byte(SPI_A1_byte_read());
    	uart_a0_send_byte(SPI_A1_byte_read());

    	//SPI_A1_data_write(test_byte_array, 5);
    }
}

#pragma vector=USCI_A1_VECTOR
__interrupt void USCI_A1_ISR(void)
{
    switch(__even_in_range(UCA1IV,4)){
        case 0:
            break;                             // Vector 0 - no interrupt
        case 2:                                   // Vector 2 - RXIFG
            /*
            Interrupt Source: Data received;
            Interrupt Flag: UCRXIFG;
            Interrupt Priority: Highest
            */
          //while (!(UCA1IFG & UCRXIFG)){}             // USCI_B1 TX buffer ready?
              rx_buffer = UCA1RXBUF;
              break;
        case 4:
            /*
            Interrupt Source: Transmit buffer empty;
            Interrupt Flag: UCTXIFG;
            Interrupt Priority: Lowest;
            */
            //rx_buffer = UCB1RXBUF;
            break;
    }
}
