/*
 * uart.h
 *
 *  Created on: 2017. gada 22. febr.
 *      Author: Roberts
 */
#include <msp430.h>
#include <stdint.h>
#include "macros.h"

#ifndef DRIVER_INCLUDE_UART_H_
#define DRIVER_INCLUDE_UART_H_

#define UART_RX_Buffer_Size     16  /*  Size of received data buffer size   */

typedef enum uart_setting{
	PARITY_ENABLE,	/*	Enable parity					*/
	PARITY_DISABLE,	/*	Disable parity					*/
	PARITY_ODD,		/*	Odd parity						*/
	PARITY_EVEN,	/*	Even parity						*/
	MSB_FIRST,		/*	Most significant bit first		*/
	LSB_FIRST,		/*	Least significant bit first		*/
	CHAR_8BIT,		/*	8-bit char						*/
	CHAR_7BIT,		/*	7-bit char						*/
	STOP_1BIT,		/*	1 stop bits						*/
	STOP_2BIT,		/*	2 stop bits						*/
	EUSCI_MODE_0,	/*	UART mode						*/
	EUSCI_MODE_1,	/*	Idle-line multiprocessor mode	*/
	EUSCI_MODE_2,	/*	Address-bit multiprocessor mode	*/
	EUSCI_MODE_3,	/*	UART mode with auto-baud detect	*/
	MODE_ASYNC,		/*	Asynchronous mode enable		*/
	MODE_SYNC,		/*	Synchronous mode enable			*/
	SOURCE_UCLK,	/*	eUSCI clock source				*/
	SOURCE_ACLK,	/*	eUSCI clock source				*/
	SOURCE_SMCLK,	/*	eUSCI clock source				*/
	ERROR_INT_ENABLE,	/*	Receive erroneous-character interrupt enable	*/
	ERROR_INT_DISABLE,	/*	Receive erroneous-character interrupt enable	*/
	BREAK_INT_ENABLE,	/*	Receive break character interrupt enable		*/
	BREAK_INT_DISABLE,	/*	Receive break character interrupt enable		*/
	SLEEP_ENABLE,		/*	Dormant. Puts eUSCI_A into sleep mode			*/
	SLEEP_DISABLE,		/*	Dormant. Puts eUSCI_A into sleep mode			*/
	TX_ADDRESS,			/*	Transmit address	*/
	TX_DATA,			/*	Transmit data		*/
	TX_BREAK,		/*	Transmits a break with the next write to the transmit buffer	*/
	TX_NO_BREAK,		/*	Transmits a break with the next write to the transmit buffer	*/
	RESET_ENABLE,		/*	Software reset enable, logic held in reset state 				*/
	RESET_DISABLE,		/*	Reset released for operation	*/
	DEGLITCH_2NS,       /*  Deglitch time set to 2ns        */
	DEGLITCH_50NS,      /*  Deglitch time set to 50ns       */
	DEGLITCH_100NS,     /*  Deglitch time set to 100ns      */
	DEGLITCH_200NS,     /*  Deglitch time set to 200ns      */

	OVERSAMPLING_ENABLE,
	OVERSAMPLING_DISABLE,
	LOOPBACK_ENABLED,
	LOOPBACK_DISABLED,
	DELIMITER_1BIT,
	DELIMITER_2BIT,
	DELIMITER_3BIT,
	DELIMITER_4BIT,
	BAUD_DET_ENABLE,
	BAUD_DET_DISABLE,
	RX_INTERRUPT_ENABLE,
	RX_INTERRUPT_DISABLE,
	TX_INTERRUPT_ENABLE,
	TX_INTERRUPT_DISABLE
}uart_setting;

// Buffer for storing received UART data
//uint16_t UART_RX_Buffer[UART_RX_Buffer_Size] = {0};

uint16_t UART_Parity        (uart_setting uart_parity);
uint16_t UART_Parity_Mode   (uart_setting uart_parity);
uint16_t UART_Bit_Order     (uart_setting uart_first_bits);
uint16_t UART_Char_Length   (uart_setting uart_char_length);
uint16_t UART_Stop_Bits     (uart_setting uart_stop_bits);

uint16_t UART_EUSCI_Mode    (uart_setting uart_eusci_mode);
uint16_t UART_EUSCI_Sync    (uart_setting uart_eusci_sync);
uint16_t UART_EUSCI_Clock   (uart_setting uart_eusci_clock);

uint16_t UART_Error_Interrupt   (uart_setting uart_error);
uint16_t UART_Break_Interrupt   (uart_setting uart_break);

uint16_t UART_EUSCI_Sleep       (uart_setting uart_sleep);
uint16_t UART_TX_Address        (uart_setting uart_adress);
uint16_t UART_Frame_Break       (uart_setting uart_break);
uint16_t UART_Reset             (uart_setting uart_reset);

uint16_t UART_Deglitch_Time     (uart_setting uart_deglitch);
uint16_t UART_Clock_Prescale    (uint16_t uart_prescale);

uint16_t UART_Modulation_Stage_1    (uint16_t uart_modulation);
uint16_t UART_Modulation_Stage_2    (uint16_t uart_modulation);
uint16_t UART_Oversampling          (uart_setting uart_modulation);
uint16_t UART_Loopback              (uart_setting uart_loopback);

uint16_t UART_Error_Flag_Read           (void);
uint16_t UART_Buffer_Overrun_Flag_Read  (void);
uint16_t UART_Parity_Error_Flag_Read    (void);
uint16_t UART_Break_Flag_Read           (void);
uint16_t UART_RX_Error_Flag_Read        (void);
uint16_t UART_RX_Address_Flag_Read      (void);
uint16_t UART_EUSCI_Bussy_Flag_Read     (void);

uint16_t UART_RX_Buffer_Read            (void);
uint16_t UART_TX_Buffer_Write           (uint16_t data);
uint16_t UART_Byte_Write                (uint8_t byte);

uint16_t UART_Break_Sync_Length     (uart_setting uart_delimiter_length);
uint16_t UART_Sync_Timeout          (void);
uint16_t UART_Break_Timeout         (void);
uint16_t UART_Autobaud              (uart_setting uart_autobaud);

uint16_t UART_RX_Interrupt   (uart_setting uart_rx_int);
uint16_t UART_TX_Interrupt   (uart_setting uart_rx_int);
#endif /* DRIVER_INCLUDE_UART_H_ */
