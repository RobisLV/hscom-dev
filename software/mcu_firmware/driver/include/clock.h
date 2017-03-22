#include <msp430.h>
#include <stdint.h>
#include "macros.h"

#ifndef DRIVER_INCLUDE_CLOCK_H_
#define DRIVER_INCLUDE_CLOCK_H_

typedef volatile enum {
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
	LFXT_CLK,		/* Low frequency clock 	*/
	VLO_CLK,		/* Internal Very-Low-Power Low-Frequency Oscillator	*/
	LFMOD_CLK,		/* Module Oscillator 	*/
	DCO_CLK,		/* Digitally Controlled Oscillator			*/
	HFXT_CLK,		/* High frequency crystal oscilator clock	*/
	DIV_1,          /* Clock dividet set to 1                   */
	DIV_2,          /* Clock dividet set to 2                   */
	DIV_4,          /* Clock dividet set to 4                   */
	DIV_8,          /* Clock dividet set to 8                   */
	DIV_16,         /* Clock dividet set to 16                  */
	DIV_32,         /* Clock dividet set to 32                  */
	LFXT_ON,
	LFXT_OFF,
	SMCLK_ON,
	SMCLK_OFF,
	VLO_ON,
	VLO_OFF,
	HFXT_ON,
	HFXT_OFF,
	HFXT_FSEL_0_4M,		/*	0 to 4 MHz		*/
	HFXT_FSEL_4_8M,		/* 	4 to 8 MHz		*/
	HFXT_FSEL_8_16M,	/*	8 to 16 MHz		*/
	HFXT_FSEL_16_24M,	/* 	16 to 24 MHz	*/
	HFXT_DRIVE_LOWEST,
	HFXT_DRIVE_LOW,
	HFXT_DRIVE_HIGH,
	HFXT_DRIVE_HIGHEST,
	LFXT_DRIVE_LOWEST,
	LFXT_DRIVE_LOW,
	LFXT_DRIVE_HIGH,
	LFXT_DRIVE_HIGHEST,
	LFXT_BYPASS_ON,
	LFXT_BYPASS_OFF,
	HFXT_BYPASS_ON,
	HFXT_BYPASS_OFF,
	LFXT_FAULT_CNT_ON,
	LFXT_FAULT_CNT_OFF,
	HFXT_FAULT_CNT_ON,
	HFXT_FAULT_CNT_OFF,
	MODCLK_REQ_ENABLE,
	SMCLK_REQ_ENABLE,
	MCLK_REQ_ENABLE,
	ACLK_REQ_ENABLE,
	MODCLK_REQ_DISABLE,
	SMCLK_REQ_DISABLE,
	MCLK_REQ_DISABLE,
	ACLK_REQ_DISABLE,
} cs_setting;

/********************************
 * Clock System functions
 *******************************/
uint16_t CS_password            (cs_setting clock_password);
uint16_t CS_DCO_freq_set        (cs_setting clock_frequency);
uint16_t CS_HFXT_freq_set       (cs_setting clock_frequency);

uint16_t CS_ACLK_source_set     (cs_setting clock_source);
uint16_t CS_MCLK_source_set     (cs_setting clock_source);
uint16_t CS_SMCLK_source_set    (cs_setting clock_source);

uint16_t CS_ACLK_divider_set    (cs_setting clock_divider);
uint16_t CS_MSCLK_divider_set    (cs_setting clock_divider);
uint16_t CS_SMCLK_divider_set   (cs_setting clock_divider);

uint16_t CS_LFXT                (cs_setting clock_onoff);
uint16_t CS_SMCLK               (cs_setting clock_onoff);
uint16_t CS_VLO                 (cs_setting clock_onoff);
uint16_t CS_HFXT                (cs_setting clock_onoff);

uint16_t CS_LFXT_drive          (cs_setting clock_drive);
uint16_t CS_HFXT_drive          (cs_setting clock_drive);

uint16_t CS_LFXT_bypass         (cs_setting clock_bypass);
uint16_t CS_HFXT_bypass         (cs_setting clock_bypass);

uint16_t CS_HFXT_fault_counter  (cs_setting clock_counter);
uint16_t CS_LFXT_fault_counter  (cs_setting clock_counter);

uint16_t CS_HFXT_fault_flag_read    (void);
uint16_t CS_LFXT_fault_flag_read    (void);

uint16_t CS_MODCLK_request      (cs_setting clock_request);
uint16_t CS_SMCLK_request       (cs_setting clock_request);
uint16_t CS_MCLK_request        (cs_setting clock_request);
uint16_t CS_ACLK_request        (cs_setting clock_request);

#endif
