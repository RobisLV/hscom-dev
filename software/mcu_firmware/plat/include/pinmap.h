#include <msp430.h>
#include <stdint.h>
#ifndef PLAT_INCLUDE_PINMAP_H_
#define PLAT_INCLUDE_PINMAP_H_

/***** Microcontroller (MCU) ******/
// Status LED (D1)
#define MCU_LED_STATUS_PIN	BIT2
#define MCU_LED_STATUS_PORT	ADDRESS_OF(P2OUT)
#define MCU_LED_STATUS_DIR	ADDRESS_OF(P2DIR)

// RS485 connection to bus communication line
#define MCU_RS485_RO_PIN	BIT1
#define MCU_RS485_RE_PIN	BIT0
#define MCU_RS485_DI_PIN	BIT4
#define MCU_RS485_DE_PIN	BIT5

#define MCU_RS485_RO_PORT	ADDRESS_OF(P2OUT)
#define MCU_RS485_RE_PORT	ADDRESS_OF(P2OUT)
#define MCU_RS485_DI_PORT	ADDRESS_OF(P1OUT)
#define MCU_RS485_DE_PORT	ADDRESS_OF(P1OUT)

#define MCU_RS485_RO_DIR	ADDRESS_OF(P2DIR)
#define MCU_RS485_RE_DIR	ADDRESS_OF(P2DIR)
#define MCU_RS485_DI_DIR	ADDRESS_OF(P1DIR)
#define MCU_RS485_DE_DIR	ADDRESS_OF(P1DIR)

#define MCU_RS485_RO_FUNC1   ADDRESS_OF(P2SEL1)
#define MCU_RS485_RO_FUNC0   ADDRESS_OF(P2SEL0)
#define MCU_RS485_RE_FUNC1   ADDRESS_OF(P2SEL1)
#define MCU_RS485_RE_FUNC0   ADDRESS_OF(P2SEL0)
/***** IGLOO2 M2GL060 (FPGA) ******/
// Hard reset input pin
#define FPGA_RST_PIN	BIT5
#define FPGA_RST_PORT	ADDRESS_OF(P3OUT)
#define FPGA_RST_DIR	ADDRESS_OF(P3DIR)

// MCU<->JTAG in/out pins
#define FPGA_JTAG_TDO_PIN	BIT6
#define FPGA_JTAG_TDI_PIN	BIT7
#define FPGA_JTAG_TCK_PIN	BIT7
#define FPGA_JTAG_TMS_PIN	BIT6
#define FPGA_JTAG_TRST_PIN	BIT3

#define FPGA_JTAG_TDO_PORT	P4IN
#define FPGA_JTAG_TDI_PORT	ADDRESS_OF(P1OUT)
#define FPGA_JTAG_TCK_PORT	ADDRESS_OF(P4OUT)
#define FPGA_JTAG_TMS_PORT	ADDRESS_OF(P1OUT)
#define FPGA_JTAG_TRST_PORT	ADDRESS_OF(P1OUT)

#define FPGA_JTAG_TDO_DIR	ADDRESS_OF(P4DIR)
#define FPGA_JTAG_TDI_DIR	ADDRESS_OF(P1DIR)
#define FPGA_JTAG_TCK_DIR	ADDRESS_OF(P4DIR)
#define FPGA_JTAG_TMS_DIR	ADDRESS_OF(P1DIR)
#define FPGA_JTAG_TRST_DIR	ADDRESS_OF(P1DIR)

//***** 5V and 3.3V current measument analog input pins *****/
#define PWR_5V_ISENSE_PIN	BIT0
#define PWR_3V3_ISENSE_PIN	BIT1

#define PWR_5V_ISENSE_PORT	P3IN
#define PWR_3V3_ISENSE_PORT	P3IN

#define PWR_5V_ISENSE_DIR	ADDRESS_OF(P3DIR)
#define PWR_3V3_ISENSE_DIR	ADDRESS_OF(P3DIR)

/***** Power Amplifier (PA) ******/
// Enable control digital input pin
#define PA_EN_PIN		BIT0
#define PA_EN_PORT		ADDRESS_OF(P1OUT)
#define PA_EN_DIR		ADDRESS_OF(P1DIR)

// Output power detector analog output pin
#define PA_DET_PIN		BIT2
#define PA_DET_PORT		ADDRESS_OF(P1OUT)
#define PA_DET_DIR		ADDRESS_OF(P1DIR)

// Antenna switch control digital input pins
#define PA_SW_C0_PIN	BIT5
#define PA_SW_C1_PIN	BIT7

#define PA_SW_C0_PORT	ADDRESS_OF(P4OUT)
#define PA_SW_C1_PORT	ADDRESS_OF(P1OUT)

#define PA_SW_C0_DIR	ADDRESS_OF(P4DIR)
#define PA_SW_C1_DIR	ADDRESS_OF(P2DIR)

// Transmit enable digital input pin
#define PA_TX_EN_PIN	BIT7
#define PA_TX_EN_PORT	P3IN
#define PA_TX_EN_DIR	ADDRESS_OF(P3DIR)

// Hi/L linearity control digital input pin
#define PA_HL_LIN_PIN	BIT1
#define PA_HL_LIN_PORT	ADDRESS_OF(P1OUT)
#define PA_HL_LIN_DIR	ADDRESS_OF(P1DIR)

/***** MAX2828 transceiver (TXRX) *****/
// Oscialtor enable/disable pin
#define TXRX_OSC_EN_PIN		BIT1
#define TXRX_OSC_EN_PORT	ADDRESS_OF(P4OUT)
#define TXRX_OSC_EN_DIR		ADDRESS_OF(P4DIR)

// Shutdown control input pin
#define TXRX_SHDN_PIN		BIT2
#define TXRX_SHDN_PORT		ADDRESS_OF(P4OUT)
#define TXRX_SHDN_DIR		ADDRESS_OF(P4DIR)

// Transmit enable input pin
#define TXRX_TX_EN_PIN		BIT7
#define TXRX_TX_EN_PORT		ADDRESS_OF(P3OUT)
#define TXRX_TX_EN_DIR		ADDRESS_OF(P3DIR)

// Receive enable input pin
#define TXRX_RX_EN_PIN		BIT3
#define TXRX_RX_EN_PORT		ADDRESS_OF(P4OUT)
#define TXRX_RX_EN_DIR		ADDRESS_OF(P4DIR)

// Receivers high pass filer corner frequency selection input pin
#define TXRX_RX_HP_PIN		BIT4
#define TXRX_RX_HP_PORT		ADDRESS_OF(P4OUT)
#define TXRX_RX_HP_DIR		ADDRESS_OF(P4DIR)

// Received Signal Strength Indicator analog output pin
#define TXRX_RSSI_PIN		BIT2
#define TXRX_RSSI_PORT		P3IN
#define TXRX_RSSI_DIR		ADDRESS_OF(P3DIR)

// Lock detect status digital output
#define TXRX_LOCK_DET_PIN		BIT0
#define TXRX_LOCK_DET_PORT		P4IN
#define TXRX_LOCK_DET_DIR		ADDRESS_OF(P4DIR)
#define TXRX_LOCK_DET_PULL 		ADDRESS_OF(P4REN)

/***** Internal SPI (INT_SPI) ******/
// Data and clock lines
#define INT_SPI_MISO_PIN		BIT6
#define INT_SPI_MOSI_PIN		BIT5
#define INT_SPI_SCK_PIN			BIT4

#define INT_SPI_MISO_PORT		ADDRESS_OF(P2OUT)
#define INT_SPI_MOSI_PORT		ADDRESS_OF(P2OUT)
#define INT_SPI_SCK_PORT		ADDRESS_OF(P2OUT)

#define INT_SPI_MISO_DIR		ADDRESS_OF(P2DIR)
#define INT_SPI_MOSI_DIR		ADDRESS_OF(P2DIR)
#define INT_SPI_SCK_DIR			ADDRESS_OF(P2DIR)

// Slave select lines
#define INT_SPI_FLASH_SS_PIN	BIT3
#define INT_SPI_FPGA_SS_PIN		BIT3
#define INT_SPI_TXRX_SS_PIN		BIT4
#define INT_SPI_AF_SS_PIN		BIT5

#define INT_SPI_FLASH_SS_PORT	ADDRESS_OF(P2OUT)
#define INT_SPI_FPGA_SS_PORT	ADDRESS_OF(P3OUT)
#define INT_SPI_TXRX_SS_PORT	ADDRESS_OF(P3OUT)
#define INT_SPI_AF_SS_PORT		ADDRESS_OF(P3OUT)

#define INT_SPI_FLASH_SS_DIR	ADDRESS_OF(P2DIR)
#define INT_SPI_FPGA_SS_DIR		ADDRESS_OF(P3DIR)
#define INT_SPI_TXRX_SS_DIR		ADDRESS_OF(P3DIR)
#define INT_SPI_AF_SS_DIR		ADDRESS_OF(P3DIR)

#endif 
