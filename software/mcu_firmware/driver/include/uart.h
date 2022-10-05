/*
 * uart.h
 *
 *  Created on: 2017. gada 22. febr.
 *      Author: Roberts
 *      Description: This file contains function defs used for configuring and controlling
 *      the eUSCI A0 and A1 peripherals in UART mode.
 */
#include <msp430.h>
#include <stdint.h>
#include "macros.h"

#ifndef DRIVER_INCLUDE_UART_H_
#define DRIVER_INCLUDE_UART_H_

#define EUSCI_A0_RX_buffer_size     16  /* eUSCI A0 receive buffer size         */
#define EUSCI_A0_TX_buffer_size     16  /* eUSCI A0 transmit buffer size        */
#define EUSCI_A1_RX_buffer_size     16  /* eUSCI A1 receive buffer size         */
#define EUSCI_A1_TX_buffer_size     16  /* eUSCI A1 transmit buffer size        */
#define EUSCI_B0_RX_buffer_size     16  /* eUSCI B0 receive buffer size         */
#define EUSCI_B0_TX_buffer_size     16  /* eUSCI B0 transmit buffer size        */

// Buffer for storing received UART data
//uint16_t UART_RX_Buffer[UART_RX_Buffer_Size] = {0};

//static    unsigned char rx_a0_buffer_index    = 0;
//#pragma NOINIT(UART_RX_BUFFER)
//unsigned char UART_RX_BUFFER[UART_RX_BUFFER_SIZE];

typedef volatile enum {
	UART_PARITY_ENABLE,	        /* Enable parity					*/
	UART_PARITY_DISABLE,	    /* Disable parity					*/
	UART_PARITY_ODD,		    /* Odd parity						*/
	UART_PARITY_EVEN,	        /* Even parity						*/
	UART_MSB_FIRST,		        /* Most significant bit first		*/
	UART_LSB_FIRST,		        /* Least significant bit first		*/
	UART_CHAR_8BIT,		        /* 8-bit char						*/
	UART_CHAR_7BIT,		        /* 7-bit char						*/
	UART_STOP_1BIT,		        /* 1 stop bits						*/
	UART_STOP_2BIT,		        /* 2 stop bits						*/
	UART_EUSCI_MODE_0,	        /* UART mode						*/
	UART_EUSCI_MODE_1,	        /* Idle-line multiprocessor mode	*/
	UART_EUSCI_MODE_2,	        /* Address-bit multiprocessor mode	*/
	UART_EUSCI_MODE_3,	        /* UART mode with auto-baud detect	*/
	UART_MODE_ASYNC,		    /* Asynchronous mode enable		    */
	UART_MODE_SYNC,		        /* Synchronous mode enable			*/
	UART_SOURCE_UCLK,	        /* eUSCI clock source				*/
	UART_SOURCE_ACLK,	        /* eUSCI clock source				*/
	UART_SOURCE_SMCLK,	        /* eUSCI clock source				*/
	UART_ERROR_INT_ENABLE,	    /* Receive erroneous-character interrupt enable	*/
	UART_ERROR_INT_DISABLE,	    /* Receive erroneous-character interrupt enable	*/
	UART_BREAK_INT_ENABLE,	    /* Receive break character interrupt enable		*/
	UART_BREAK_INT_DISABLE,	    /* Receive break character interrupt enable		*/
	UART_SLEEP_ENABLE,		    /* Dormant. Puts eUSCI_A into sleep mod 		*/
	UART_SLEEP_DISABLE,		    /* Dormant. Puts eUSCI_A into sleep mode		*/
	UART_TX_ADDRESS,	        /* Transmit address	                */
	UART_TX_DATA,			    /* Transmit data		            */
	UART_TX_BREAK,		        /* Transmits a break with the next write to the transmit buffer	*/
	UART_TX_NO_BREAK,		    /* Transmits a break with the next write to the transmit buffer	*/
	UART_RESET_ENABLE,		    /* Software reset enable, logic held in reset state 			*/
	UART_RESET_DISABLE,		    /* Reset released for operation	    */
	UART_DEGLITCH_2NS,          /* Deglitch time set to 2ns         */
	UART_DEGLITCH_50NS,         /* Deglitch time set to 50ns        */
	UART_DEGLITCH_100NS,        /* Deglitch time set to 100ns       */
	UART_DEGLITCH_200NS,        /* Deglitch time set to 200ns       */
	UART_OVERSAMPLE_ENABLE,     /* Enable oversampling              */
	UART_OVERSAMPLE_DISABLE,    /* Disable oversampling             */
	UART_LOOPBACK_ENABLED,      /* Enable loopback mode             */
	UART_LOOPBACK_DISABLED,     /* Disable loopback mode            */
	UART_DELIMITER_1BIT,        /* Delimiter set to 1 bits          */
	UART_DELIMITER_2BIT,        /* Delimiter set to 2 bits          */
	UART_DELIMITER_3BIT,        /* Delimiter set to 3 bits          */
	UART_DELIMITER_4BIT,        /* Delimiter set to 4 bits          */
	UART_BAUD_DET_ENABLE,       /* Enable baudrate detection        */
	UART_BAUD_DET_DISABLE,      /* Disable baudrate detection       */
	UART_INTERRUPT_ENABLE,      /* Rx/Tx interrupt enable           */
	UART_INTERRUPT_DISABLE      /* Rx/Tx interrupt disable          */
}uart_setting;

/***************************************************
 * eUSCI A0 UART functions
 **************************************************/
uint16_t UART_A0_parity                (uart_setting uart_parity);
uint16_t UART_A0_parity_mode           (uart_setting uart_parity);
uint16_t UART_A0_bit_order             (uart_setting uart_first_bits);
uint16_t UART_A0_char_length           (uart_setting uart_char_length);
uint16_t UART_A0_stop_bits             (uart_setting uart_stop_bits);
uint16_t UART_A0_EUSCI_mode            (uart_setting uart_eusci_mode);
uint16_t UART_A0_sync_mode             (uart_setting uart_eusci_sync);
uint16_t UART_A0_EUSCI_clock           (uart_setting uart_eusci_clock);
uint16_t UART_A0_error_interrupt       (uart_setting uart_error);
uint16_t UART_A0_break_interrupt       (uart_setting uart_break);
uint16_t UART_A0_EUSCI_sleep           (uart_setting uart_sleep);
uint16_t UART_A0_transmit_address      (uart_setting uart_adress);
uint16_t UART_A0_frame_break           (uart_setting uart_break);
uint16_t UART_A0_reset                 (uart_setting uart_reset);
uint16_t UART_A0_deglitch_time         (uart_setting uart_deglitch);
uint16_t UART_A0_clock_prescale        (uint16_t UART_A0_prescale);
uint16_t UART_A0_modulation_stage_1    (uint16_t UART_A0_modulation);
uint16_t UART_A0_modulation_stage_2    (uint16_t UART_A0_modulation);
uint16_t UART_A0_oversampling          (uart_setting uart_modulation);
uint16_t UART_A0_loopback              (uart_setting uart_loopback);

/* Functions for reading UART flags  */
uint16_t UART_A0_error_flag_read           (void);
uint16_t UART_A0_buffer_overrun_flag_read  (void);
uint16_t UART_A0_parity_error_flag_read    (void);
uint16_t UART_A0_break_flag_read           (void);
uint16_t UART_A0_RX_error_flag_read        (void);
uint16_t UART_A0_TX_address_flag_read      (void);
uint16_t UART_A0_EUSCI_busy_flag_read      (void);

/* Functions for reading and writing data to/from UART */
uint16_t UART_A0_RX_buffer_read            (void);
uint16_t UART_A0_TX_buffer_write           (uint8_t uart_byte);
uint16_t UART_A0_byte_write                (uint8_t uart_byte);
uint16_t UART_A0_array_write               (uint8_t *tx_array, uint8_t tx_array_size);

/* Additionl UART functions */
uint16_t UART_A0_break_sync_length         (uart_setting uart_delimiter_length);
uint16_t UART_A0_sync_timeout              (void);
uint16_t UART_A0_break_timeout             (void);
uint16_t UART_A0_autobaud                  (uart_setting uart_autobaud);

/* Enable disable UART interrupts   */
uint16_t UART_A0_RX_interrupt   (uart_setting uart_rx_int);
uint16_t UART_A0_TX_interrupt   (uart_setting uart_rx_int);

/***************************************************
 * eUSCI A1 UART functions
 **************************************************/
uint16_t UART_A1_parity                (uart_setting uart_parity);
uint16_t UART_A1_parity_mode           (uart_setting uart_parity);
uint16_t UART_A1_bit_order             (uart_setting uart_first_bits);
uint16_t UART_A1_char_length           (uart_setting uart_char_length);
uint16_t UART_A1_stop_bits             (uart_setting uart_stop_bits);
uint16_t UART_A1_EUSCI_mode            (uart_setting uart_eusci_mode);
uint16_t UART_A1_sync_mode             (uart_setting uart_eusci_sync);
uint16_t UART_A1_EUSCI_clock           (uart_setting uart_eusci_clock);
uint16_t UART_A1_error_interrupt       (uart_setting uart_error);
uint16_t UART_A1_break_interrupt       (uart_setting uart_break);
uint16_t UART_A1_EUSCI_sleep           (uart_setting uart_sleep);
uint16_t UART_A1_transmit_address      (uart_setting uart_adress);
uint16_t UART_A1_frame_break           (uart_setting uart_break);
uint16_t UART_A1_reset                 (uart_setting uart_reset);
uint16_t UART_A1_deglitch_time         (uart_setting uart_deglitch);
uint16_t UART_A1_clock_prescale          (uint16_t UART_A1_prescale);
uint16_t UART_A1_modulation_stage_1    (uint16_t UART_A1_modulation);
uint16_t UART_A1_modulation_stage_2    (uint16_t UART_A1_modulation);
uint16_t UART_A1_oversampling          (uart_setting uart_modulation);
uint16_t UART_A1_loopback              (uart_setting uart_loopback);

/* Functions for reading UART flags  */
uint16_t UART_A1_error_flag_read           (void);
uint16_t UART_A1_buffer_overrun_flag_read  (void);
uint16_t UART_A1_parity_error_flag_read    (void);
uint16_t UART_A1_break_flag_read           (void);
uint16_t UART_A1_RX_error_flag_read        (void);
uint16_t UART_A1_TX_address_flag_read      (void);
uint16_t UART_A1_EUSCI_busy_flag_read      (void);

/* Functions for reading and writing data to/from UART */
uint16_t UART_A1_RX_buffer_read            (void);
uint16_t UART_A1_TX_buffer_write           (uint8_t uart_byte);
uint16_t UART_A1_byte_write                (uint8_t uart_byte);

/* Additionl UART functions */
uint16_t UART_A1_break_sync_length         (uart_setting uart_delimiter_length);
uint16_t UART_A1_sync_timeout              (void);
uint16_t UART_A1_break_timeout             (void);
uint16_t UART_A1_autobaud                  (uart_setting uart_autobaud);

/* Enable disable UART interrupts   */
uint16_t UART_A1_RX_interrupt   (uart_setting uart_rx_int);
uint16_t UART_A1_TX_interrupt   (uart_setting uart_rx_int);

#endif /* DRIVER_INCLUDE_UART_H_ */
