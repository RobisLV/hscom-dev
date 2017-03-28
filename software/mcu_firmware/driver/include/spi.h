/*
 * spi.h
 *
 *  Created on: 2017. gada 2. marts
 *      Author: Roberts
 */
#include <msp430.h>
#include <stdint.h>
#include "macros.h"

#ifndef DRIVER_INCLUDE_SPI_H_
#define DRIVER_INCLUDE_SPI_H_

/*  Configuration settings used in eUSCIA0 SPI mode         */
typedef volatile enum {
    SPI_CLK_LEADING,        /* Clock phase rising edge      */
    SPI_CLK_TRAILING,       /* Clock phase falling edge     */
    SPI_CLK_ACTIVE_HIGH,    /* Clock polarity active high   */
    SPI_CLK_ACTIVE_LOW,     /* Clock polarity active low    */
    SPI_MSB_FIRST,          /* Bit order MSB is sent first  */
    SPI_LSB_FIRST,          /* Bit order LSB is sent first  */
    SPI_CHAR_8BIT,          /* Char length is 8 bits        */
    SPI_CHAR_7BIT,          /* CHar length is 7 bits        */
    SPI_SLAVE,              /* MCU SPI configured as slave  */
    SPI_MASTER,             /* MCU SPI configured as master */
    SPI_MODE_3PIN,          /* SPI set to 3-pin mode        */
    SPI_MODE_4PIN_AH,       /* SPI set to 4-pin mode, active high   */
    SPI_MODE_4PIN_AL,       /* SPI set to 4-pin mode active low     */
    SPI_MODE_ASYNC,         /* Asyncronus mode - UART       */
    SPI_MODE_SYNC,          /* Syncronus mode - SPI         */
    SPI_CLK_SOURCE_UCXCLK,  /* Clock source UCXCLK          */
    SPI_CLK_SOURCE_ACLK,    /* Clock source ACLK            */
    SPI_CLK_SOURCE_SMCLK,   /* Clock source SMCLK           */
    SPI_STE_DISABLE,        /* STE mode enabled             */
    SPI_STE_ENABLE,         /* STE mode disabled            */
    SPI_RESET_ENABLE,       /* Set SPI reset state          */
    SPI_RESET_DISABLE,      /* Set SPI set state            */
    SPI_LOOPBACK_ENABLE,    /* Enable loopback mode         */
    SPI_LOOPBACK_DISABLE,   /* Disable loopback mode        */
    SPI_INT_ENABLE,         /* Enable RX or TX interrupt    */
    SPI_INT_DISABLE        /* Disable RX or TX interrupt   */
} spi_setting;

/***************************************************
*   eUSCI A0 SPI functions
 **************************************************/
uint16_t SPI_A0_clock_phase         (spi_setting spi_phase);
uint16_t SPI_A0_clock_polarity      (spi_setting spi_polarity);
uint16_t SPI_A0_bit_order           (spi_setting spi_bitorder);
uint16_t SPI_A0_char_length         (spi_setting spi_charlength);
uint16_t SPI_A0_mode                (spi_setting spi_mode);
uint16_t SPI_A0_EUSCI_mode          (spi_setting spi_eusci_mode);
uint16_t SPI_A0_sync                (spi_setting spi_sync);
uint16_t SPI_A0_clock_source        (spi_setting spi_clk);
uint16_t SPI_A0_STE_pin             (spi_setting spi_ste);
uint16_t SPI_A0_soft_reset          (spi_setting spi_reset);
uint16_t SPI_A0_loopback            (spi_setting spi_loopback);
uint16_t SPI_A0_clock_prescale      (uint16_t spi_clk_prescale);
/* SPI flag read functions  */
uint16_t SPI_A0_frame_error_flag_read      (void);
uint16_t SPI_A0_overrun_error_flag_read    (void);
uint16_t SPI_A0_busy_flag_read             (void);
/* SPI data write and read functions    */
uint16_t SPI_A0_RX_buffer_read             (void);
uint16_t SPI_A0_TX_buffer_write            (uint8_t spi_byte);
/* Interrupt read and set functions     */
uint16_t SPI_A0_RX_interrupt               (spi_setting spi_interrupt);
uint16_t SPI_A0_TX_interrupt               (spi_setting spi_interrupt);
uint16_t SPI_A0_RX_interrupt_read          (void);
uint16_t SPI_A0_TX_interrupt_read          (void);

/***************************************************
*   eUSCI A1 SPI functions
 **************************************************/
uint16_t SPI_A1_clock_phase         (spi_setting spi_phase);
uint16_t SPI_A1_clock_polarity      (spi_setting spi_polarity);
uint16_t SPI_A1_bit_order           (spi_setting spi_bitorder);
uint16_t SPI_A1_char_length         (spi_setting spi_charlength);
uint16_t SPI_A1_mode                (spi_setting spi_mode);
uint16_t SPI_A1_EUSCI_mode          (spi_setting spi_eusci_mode);
uint16_t SPI_A1_sync                (spi_setting spi_sync);
uint16_t SPI_A1_clock_source        (spi_setting spi_clk);
uint16_t SPI_A1_STE_pin             (spi_setting spi_ste);
uint16_t SPI_A1_soft_reset          (spi_setting spi_reset);
uint16_t SPI_A1_loopback            (spi_setting spi_loopback);
uint16_t SPI_A1_clock_prescale      (uint16_t spi_clk_prescale);
/* SPI flag read functions  */
uint16_t SPI_A1_frame_error_flag_read      (void);
uint16_t SPI_A1_overrun_error_flag_read    (void);
uint16_t SPI_A1_busy_flag_read             (void);
/* SPI data write and read functions    */
uint16_t SPI_A1_RX_buffer_read             (void);
uint16_t SPI_A1_TX_buffer_write            (uint8_t spi_byte);
uint16_t SPI_A1_byte_write                 (uint8_t spi_byte);
/* Interrupt read and set functions     */
uint16_t SPI_A1_RX_interrupt               (spi_setting spi_interrupt);
uint16_t SPI_A1_TX_interrupt               (spi_setting spi_interrupt);
uint16_t SPI_A1_RX_interrupt_read          (void);
uint16_t SPI_A1_TX_interrupt_read          (void);
uint16_t SPI_A1_TX_complete_interrupt      (spi_setting spi_interrupt);

#endif /* DRIVER_INCLUDE_SPI_H_ */
