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
//#include "dpuser.h"

#define bin_mode		1

//Menu command numbers:
#define enable_chip 	1
#define disable_chip	2
#define enable_tx		3
#define disable_tx		4
#define set_pwr			7
#define set_reg			8
#define get_phase_lck	9
#define stdby_high		11
#define stdby_low		12
#define osc_en			20
#define osc_dis			21
#define reset_settings	99
#define menu			0
//#define UART_RX_BUFFER_SIZE		16
/*
typedef enum selection{
	enable_chip,
	enable_tx,
	disable_tx
	set_pwr,
	set_reg,
	get_phase_lck
	get_phase_lck,
};*/

#define reg_count   13 // number of configurable registers in max2828
#define reg_bits    14 // number of bits in max2828 conf. register

//Define UART RX buffer and its size
//static	unsigned char rx_a0_buffer_index 	= 0;
//#pragma NOINIT(UART_RX_BUFFER)
//unsigned char UART_RX_BUFFER[UART_RX_BUFFER_SIZE];

// Default register values of max2828
/*
uint16_t default_reg[reg_count]=
{
    0b01000101000000, // R0
    0b00000011001010, // R1
    0b01000000000111, // R2
    0b11000011101000, // R3
    0b00110011001100, // R4
    0b01111101100011, // R5
    0b01110000000000, // R6
    0b00000000101010, // R7
    0b00000000100101, // R8
    0b00001000000000, // R9
    0b00001111000000, // R10
    0b00000001111111, // R11
    0b00000000000000  // R12
};
*/
// Registers defined by user
// uint16_t user_reg[reg_count] = {0};

int main(void){
	WDTCTL = WDTPW | WDTHOLD;	// Stop watchdog timer

	//SET master clock to 8 MHz
    Clock_Init();
    // Disable the GPIO power-on default high-impedance mode to activate
    // previously configured port settings
    PM5CTL0 &= ~LOCKLPM5;
    GPIO_Init();
	dp_delay(500);
	//uart_a0_init();
	UART_A0_Init();
	//Board specific assigment
    //PJDIR &= ~BIT5;
    volatile uint16_t counter = 0;
    //
	uint16_t i=0;
    P2DIR |= BIT2;
    while(1){
    	//counter1++;
    	GPIO_Port_Write(MCU_LED_STATUS_PIN, MCU_LED_STATUS_PORT, HIGH);

    	for(i=0; i < 0xFFFF; i++){
    		counter++;
    	};
    	GPIO_Port_Write(MCU_LED_STATUS_PIN, MCU_LED_STATUS_PORT, LOW);
    	for(i=0; i < 0xFFFF; i++){
    		counter++;
    	};
    	dp_display_text("\r\n\r\n\t\t--------Main menu--------");
    }
}
/*
#pragma vector=USCI_A0_VECTOR
__interrupt void USCI_A0_ISR(void)
{
	  switch(__even_in_range(UCA0IV, USCI_UART_UCTXCPTIFG))
	  {
	    case USCI_NONE: break;
	    case USCI_UART_UCRXIFG:
	      UART_receive_byte_handle(UCA0RXBUF);
	      __bic_SR_register_on_exit(LPM0_bits); //wakeup
	      break;
	    case USCI_UART_UCTXIFG: break;
	    case USCI_UART_UCSTTIFG: break;
	    case USCI_UART_UCTXCPTIFG: break;
	  }
}
*/
