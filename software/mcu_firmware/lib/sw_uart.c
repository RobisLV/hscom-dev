/*
 * sw_uart.c
 *
 *  Created on: 2017. gada 22. febr.
 *      Author: Roberts
 */
#include "stdint.h"
void Transmit(void);

// Function Transmits Character from TXByte
uint16_t SW_UART_enable(void);
uint16_t SW_UART_TX(uint8_t);
uint16_t SW_UART_RX(void);

/*
void Transmit()
{
	while(isReceiving);			// Wait for RX completion
  	CCTL0 = OUT;				// TXD Idle as Mark
  	TACTL = TASSEL_2 + MC_2;		// SMCLK, continuous mode

  	BitCnt = 0xA;				// Load Bit counter, 8 bits + ST/SP
  	CCR0 = TAR;				// Initialize compare register

  	CCR0 += Bit_time;			// Set time till first bit
  	TXByte |= 0x100;			// Add stop bit to TXByte (which is logical 1)
  	TXByte = TXByte << 1;			// Add start bit (which is logical 0)

  	CCTL0 =  CCIS0 + OUTMOD0 + CCIE;	// Set signal, intial value, enable interrupts
  	while ( CCTL0 & CCIE );			// Wait for previous TX completion
}

// Port 1 interrupt service routine
#pragma vector=PORT1_VECTOR
__interrupt void Port_1(void)
{
	isReceiving = true;

	P1IE &= ~RXD;			// Disable RXD interrupt
	P1IFG &= ~RXD;			// Clear RXD IFG (interrupt flag)

  	TACTL = TASSEL_2 + MC_2;	// SMCLK, continuous mode
  	CCR0 = TAR;			// Initialize compare register
  	CCR0 += Bit_time_5;		// Set time till first bit
	CCTL0 = OUTMOD1 + CCIE;		// Dissable TX and enable interrupts

	RXByte = 0;			// Initialize RXByte
	BitCnt = 0x9;			// Load Bit counter, 8 bits + ST
}

// Timer A0 interrupt service routine
#pragma vector=TIMERA0_VECTOR
__interrupt void Timer_A (void)
{
	if(!isReceiving)
	{
		CCR0 += Bit_time;			// Add Offset to CCR0
		if ( BitCnt == 0)			// If all bits TXed
		{
  			TACTL = TASSEL_2;		// SMCLK, timer off (for power consumption)
			CCTL0 &= ~ CCIE ;		// Disable interrupt
		}
		else
		{
			CCTL0 |=  OUTMOD2;		// Set TX bit to 0
			if (TXByte & 0x01)
				CCTL0 &= ~ OUTMOD2;	// If it should be 1, set it to 1
			TXByte = TXByte >> 1;
			BitCnt --;
		}
	}
	else
	{
		CCR0 += Bit_time;				// Add Offset to CCR0
		if ( BitCnt == 0)
		{
  			TACTL = TASSEL_2;			// SMCLK, timer off (for power consumption)
			CCTL0 &= ~ CCIE ;			// Disable interrupt

			isReceiving = false;

			P1IFG &= ~RXD;				// clear RXD IFG (interrupt flag)
			P1IE |= RXD;				// enabled RXD interrupt

			if ( (RXByte & 0x201) == 0x200)		// Validate the start and stop bits are correct
			{
				RXByte = RXByte >> 1;		// Remove start bit
				RXByte &= 0xFF;			// Remove stop bit
				hasReceived = true;
			}
  			__bic_SR_register_on_exit(CPUOFF);	// Enable CPU so the main while loop continues
		}
		else
		{
			if ( (P1IN & RXD) == RXD)		// If bit is set?
				RXByte |= 0x400;		// Set the value in the RXByte
			RXByte = RXByte >> 1;			// Shift the bits down
			BitCnt --;
		}
	}
}
*/
