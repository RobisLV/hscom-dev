#include <msp430.h>
#include <stdint.h>
#include "macros.h"

#ifndef DRIVER_INCLUDE_CLOCK_H_
#define DRIVER_INCLUDE_CLOCK_H_

typedef enum clock_setting{
	/*	Clock System password options	*/
	PWD_SET,
	PWD_CLEAR,
	/* 	DCO Clock frequency selection	*/
	DCO_FSEL_1M,	/*	1MHz	*/
	DCO_FSEL_2M67,	/*	2.67MHz	*/
	DCO_FSEL_3M5,	/*	3.5MHz	*/
	DCO_FSEL_4M,	/*	4MHz	*/
	DCO_FSEL_5M33,	/* 	5.33MHz	*/
	DCO_FSEL_7M,	/*	7MHz	*/
	DCO_FSEL_8M,	/* 	8MHz	*/
	DCO_FSEL_16M,	/*	16MHz	*/
	DCO_FSEL_21M,	/*	21MHz	*/
	DCO_FSEL_24M,	/*	24MHz	*/
	/*	Clock source selection			*/
	LFXT_CLK,		/* Low frequency clock 	*/
	VLO_CLK,		/* Internal Very-Low-Power Low-Frequency Oscillator	*/
	LFMOD_CLK,		/* Module Oscillator 	*/
	DCO_CLK,		/* Digitally Controlled Oscillator			*/
	HFXT_CLK,		/* High frequency crystal oscilator clock	*/
	/*	Clock divider selection	*/
	DIV_1,
	DIV_2,
	DIV_4,
	DIV_8,
	DIV_16,
	DIV_32,
	/* 							*/
	LFXT_ON,
	LFXT_OFF,
	SMCLK_ON,
	SMCLK_OFF,

} cs_setting;

/********************************
 * Clock System functions
 *******************************/
uint8_t CS_key_write(void);
uint8_t CS_DCO_freq_set(cs_setting clock_frequency);

uint8_t CS_ACLK_source_set(cs_setting clock_source);
uint8_t CS_MCLK_source_set(cs_setting clock_source);
uint8_t CS_SMCLK_source_set(cs_setting clock_source);

uint8_t CS_ACLK_divider_set(cs_setting clock_divider);
uint8_t CS_MCLK_divider_set(cs_setting clock_divider);
uint8_t CS_SMCLK_divider_set(cs_setting clock_divider);

uint8_t CS_LFXT_onoff(cs_setting LFXT_status);
uint8_t CS_SMCLK_onoff(cs_setting SMCLK_status);

void Clock_Init(void);

#endif
