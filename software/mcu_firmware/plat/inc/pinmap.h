#include <msp430.h>
#include <stdint.h>
#ifndef PLAT_INC_PINMAP_H_
#define PLAT_INC_PINMAP_H_

/***** Microcontroller (MCU) ******/
// Status LED (D1)
#define MCU_LED_STATUS_PIN	BIT2
#define MCU_LED_STATUS_PORT	P2OUT
#define MCU_LED_STATUS_DIR	P2DIR

// RS485 connection to bus communication line
#define MCU_RS485_RO_PIN	BIT1
#define MCU_RS485_RE_PIN	BIT0
#define MCU_RS485_DI_PIN	BIT4
#define MCU_RS485_DE_PIN	BIT5

#define MCU_RS485_RO_PORT	P2OUT
#define MCU_RS485_RE_PORT	P2OUT
#define MCU_RS485_DI_PORT	P1OUT
#define MCU_RS485_DE_PORT	P1OUT

#define MCU_RS485_RO_DIR	P2DIR
#define MCU_RS485_RE_DIR	P2DIR
#define MCU_RS485_DI_DIR	P1DIR
#define MCU_RS485_DE_DIR	P1DIR

/***** IGLOO2 M2GL060 (FPGA) ******/
// Hard reset input pin
#define FPGA_RST_PIN	BIT5
#define FPGA_RST_PORT	P3OUT
#define FPGA_RST_DIR	P3DIR

// MCU<->JTAG in/out pins
#define FPGA_JTAG_TDO_PIN	BIT6
#define FPGA_JTAG_TDI_PIN	BIT7
#define FPGA_JTAG_TCK_PIN	BIT7
#define FPGA_JTAG_TMS_PIN	BIT6
#define FPGA_JTAG_TRST_PIN	BIT3

#define FPGA_JTAG_TDO_PORT	P4IN
#define FPGA_JTAG_TDI_PORT	P1OUT
#define FPGA_JTAG_TCK_PORT	P4OUT
#define FPGA_JTAG_TMS_PORT	P1OUT
#define FPGA_JTAG_TRST_PIN	P1OUT

#define FPGA_JTAG_TDO_DIR	P4DIR
#define FPGA_JTAG_TDI_DIR	P1DIR
#define FPGA_JTAG_TCK_DIR	P4DIR
#define FPGA_JTAG_TMS_DIR	P1DIR
#define FPGA_JTAG_TRST_PIN	P1DIR

//***** 5V and 3.3V current measument analog input pins *****/
#define PWR_5V_ISENSE_PIN	BIT0
#define PWR_3V3_ISENSE_PIN	BIT1

#define PWR_5V_ISENSE_PORT	P3IN
#define PWR_3V3_ISENSE_PORT	P3IN

#define PWR_5V_ISENSE_DIR	P3DIR
#define PWR_3V3_ISENSE_DIR	P3DIR

/***** Power Amplifier (PA) ******/
// Enable control digital input pin
#define PA_EN_PIN		BIT0
#define PA_EN_PORT		P1OUT
#define PA_EN_DIR		P1DIR

// Output power detector analog output pin
#define PA_DET_PIN		BIT2
#define PA_DET_PORT		P1OUT
#define PA_DET_DIR		P1DIR

// Antenna switch control digital input pins
#define PA_SW_C0_PIN		BIT5
#define PA_SW_C1_PIN		BIT7

#define PA_SW_C0_PORT		P4OUT
#define PA_SW_C1_PORT		P1OUT

#define PA_SW_C0_DIR		P4DIR
#define PA_SW_C1_DIR		P2DIR

// Transmit enable digital input pin
#define PA_TX_EN_PIN	BIT7
#define PA_TX_EN_PORT	P3IN
#define PA_TX_EN_DIR	P3DIR

// Hi/L linearity control digital input pin
#define PA_HL_LIN_PIN	BIT1
#define PA_HL_LIN_PORT	P1OUT
#define PA_HL_LIN_DIR	P1DIR

/***** MAX2828 transceiver (TXRX) *****/
// Oscialtor enable/disable pin
#define TXRX_OSC_EN_PIN		BIT1
#define TXRX_OSC_EN_PORT	P4OUT
#define TXRX_OSC_EN_DIR		P4DIR

// Shutdown control input pin
#define TXRX_SHDN_PIN		BIT2
#define TXRX_SHDN_PORT		P4OUT
#define TXRX_SHDN_DIR		P4DIR

// Receive enable input pin
#define TXRX_RX_EN_PIN		BIT3
#define TXRX_RX_EN_PORT		P4OUT
#define TXRX_RX_EN_DIR		P4DIR

// Receivers high pass filer corner frequency selection input pin
#define TXRX_RX_HP_PIN		BIT4
#define TXRX_RX_HP_PORT		P4OUT
#define TXRX_RX_HP_DIR		P4DIR

// Received Signal Strength Indicator analog output pin
#define TXRX_RSSI_PIN		BIT2
#define TXRX_RSSI_PORT		P3IN
#define TXRX_RSSI_DIR		P3DIR

// Lock detect status digital output
#define TXRX_LOCK_DET_PIN		BIT0
#define TXRX_LOCK_DET_PORT		P4IN
#define TXRX_LOCK_DET_DIR		P4DIR
#define TXRX_LOCK_DET_PULL 		P4REN

/***** Internal SPI (INT_SPI) ******/
// Data and clock lines
#define INT_SPI_MISO_PIN		BIT6
#define INT_SPI_MOSI_PIN		BIT5
#define INT_SPI_SCK_PIN			BIT4

#define INT_SPI_MISO_PORT		P2OUT
#define INT_SPI_MOSI_PORT		P2OUT
#define INT_SPI_SCK_PORT		P2OUT

#define INT_SPI_MISO_DIR		P2DIR
#define INT_SPI_MOSI_DIR		P2DIR
#define INT_SPI_SCK_DIR			P2DIR

// Slave select lines
#define INT_SPI_FLASH_SS_PIN	BIT3
#define INT_SPI_FPGA_SS_PIN		BIT3
#define INT_SPI_TXRX_SS_PIN		BIT4
#define INT_SPI_AF_SS_PIN		BIT5

#define INT_SPI_FLASH_SS_PORT	P2OUT
#define INT_SPI_FPGA_SS_PORT	P3OUT
#define INT_SPI_TXRX_SS_PORT	P3OUT
#define INT_SPI_AF_SS_PORT		P3OUT

#define INT_SPI_FLASH_SS_DIR	P2DIR
#define INT_SPI_FPGA_SS_DIR		P3DIR
#define INT_SPI_TXRX_SS_DIR		P3DIR
#define INT_SPI_AF_SS_DIR		P3DIR

#define index_dac_msb		0
#define index_dac_lsb		1
#define index_max2828_pwr	2
#define index_max2828_gpio	3
#define index_max2828_reg1	4

#define conf_block_size		17

#endif 
