//Arturs Orbidans, for Master's thesis
//Auxiliary functions for implementing RCS control software
#include <msp430.h>
#include <stdint.h>
#ifndef PLAT_INC_RF_DB_PINMAP_H_
#define PLAT_INC_RF_DB_PINMAP_H_

//Define SS pins for peripherals
#define SPI_CLK_MAX2828_pin		BIT2
#define SPI_DIN_MAX2828_pin		BIT6
#define SPI_SS_MAX2828_pin		BIT0

#define SPI_CLK_MAX2828_port	P1OUT
#define SPI_DIN_MAX2828_port	P1OUT
#define SPI_SS_MAX2828_port		P3OUT

#define SPI_CLK_MAX2828_ddr		P1DIR
#define SPI_DIN_MAX2828_ddr		P1DIR
#define SPI_SS_MAX2828_ddr		P3DIR

#define DAC_standby_pin			BIT2
#define DAC_standby_port		P4OUT
#define DAC_standby_ddr			P4DIR

#define osc_en_pin				BIT5
#define osc_en_port				P1OUT
#define osc_en_ddr				P1DIR

//Define MAX2828 related pins
#define MAX2828_lock_pin		BIT7
#define MAX2828_lock_port		P1IN
#define MAX2828_lock_ddr		P1DIR
#define MAX2828_lock_pullup		P1REN

#define MAX2828_tx_en_pin		BIT4
#define MAX2828_tx_en_port		P1OUT
#define MAX2828_tx_en_ddr		P1DIR

#define MAX2828_shdn_pin		BIT3
#define MAX2828_shdn_port		P1OUT
#define MAX2828_shdn_ddr		P1DIR

#define MAX2828_pwr_set_pin1	BIT6
#define MAX2828_pwr_set_pin2	BIT5
#define MAX2828_pwr_set_pin3	BIT4
#define MAX2828_pwr_set_pin4	BIT2
#define MAX2828_pwr_set_pin5	BIT4
#define MAX2828_pwr_set_pin6	BIT3
#define MAX2828_pwr_set_pin7	BIT2

#define MAX2828_pwr_set_port1	P3OUT
#define MAX2828_pwr_set_port2	P3OUT
#define MAX2828_pwr_set_port3	P3OUT
#define MAX2828_pwr_set_port4	P2OUT
#define MAX2828_pwr_set_port5	P2OUT
#define MAX2828_pwr_set_port6	P4OUT
#define MAX2828_pwr_set_port7	P4OUT

#define MAX2828_pwr_set_ddr1	P3DIR
#define MAX2828_pwr_set_ddr2	P3DIR
#define MAX2828_pwr_set_ddr3	P3DIR
#define MAX2828_pwr_set_ddr4	P2DIR
#define MAX2828_pwr_set_ddr5	P2DIR
#define MAX2828_pwr_set_ddr6	P4DIR
#define MAX2828_pwr_set_ddr7	P4DIR

#define index_dac_msb		0
#define index_dac_lsb		1
#define index_max2828_pwr	2
#define index_max2828_gpio	3
#define index_max2828_reg1	4

#define conf_block_size		17

#endif 
