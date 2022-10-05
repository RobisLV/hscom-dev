#include <msp430.h>
#include <stdint.h>
#include "macros.h"

#ifndef DRIVER_INCLUDE_CLOCK_H_
#define DRIVER_INCLUDE_CLOCK_H_

typedef volatile enum {
    CS_PWD_SET,         /* Set the password */
    CS_PWD_CLEAR,       /* Clear password   */
    CS_DCO_FSEL_1M,	    /*	1MHz            */
    CS_DCO_FSEL_2M67,	/*	2.67MHz	        */
    CS_DCO_FSEL_3M5,	/*	3.5MHz	        */
    CS_DCO_FSEL_4M,	    /*	4MHz	        */
    CS_DCO_FSEL_5M33,	/* 	5.33MHz	        */
    CS_DCO_FSEL_7M,	    /*	7MHz	        */
    CS_DCO_FSEL_8M,	    /* 	8MHz	        */
    CS_DCO_FSEL_16M,	/*	16MHz	        */
    CS_DCO_FSEL_21M,	/*	21MHz	        */
    CS_DCO_FSEL_24M,	/*	24MHz	        */
    CS_LFXT_CLK,		/* Low frequency clock 	*/
    CS_VLO_CLK,		    /* Internal Very-Low-Power Low-Frequency Oscillator	*/
    CS_LFMOD_CLK,		/* Module Oscillator 	*/
    CS_DCO_CLK,		    /* Digitally Controlled Oscillator			*/
    CS_HFXT_CLK,		/* High frequency crystal oscilator clock	*/
    CS_DIV_1,           /* Clock dividet set to 1                   */
    CS_DIV_2,           /* Clock dividet set to 2                   */
    CS_DIV_4,           /* Clock dividet set to 4                   */
    CS_DIV_8,           /* Clock dividet set to 8                   */
    CS_DIV_16,          /* Clock dividet set to 16                  */
    CS_DIV_32,          /* Clock dividet set to 32                  */
    CS_LFXT_ON,
    CS_LFXT_OFF,
    CS_SMCLK_ON,
    CS_SMCLK_OFF,
    CS_VLO_ON,
    CS_VLO_OFF,
    CS_HFXT_ON,
    CS_HFXT_OFF,
    CS_HFXT_FSEL_0_4M,      /* 0 to 4 MHz		*/
    CS_HFXT_FSEL_4_8M,	    /* 4 to 8 MHz		*/
    CS_HFXT_FSEL_8_16M,	    /* 8 to 16 MHz		*/
    CS_HFXT_FSEL_16_24M,    /* 16 to 24 MHz	    */
    CS_HFXT_DRIVE_LOWEST,
    CS_HFXT_DRIVE_LOW,
    CS_HFXT_DRIVE_HIGH,
    CS_HFXT_DRIVE_HIGHEST,
    CS_LFXT_DRIVE_LOWEST,
    CS_LFXT_DRIVE_LOW,
    CS_LFXT_DRIVE_HIGH,
    CS_LFXT_DRIVE_HIGHEST,
    CS_LFXT_BYPASS_ON,
    CS_LFXT_BYPASS_OFF,
    CS_HFXT_BYPASS_ON,
    CS_HFXT_BYPASS_OFF,
    CS_LFXT_FAULT_CNT_ON,
    CS_LFXT_FAULT_CNT_OFF,
    CS_HFXT_FAULT_CNT_ON,
    CS_HFXT_FAULT_CNT_OFF,
    CS_MODCLK_REQ_ENABLE,
    CS_SMCLK_REQ_ENABLE,
    CS_MCLK_REQ_ENABLE,
    CS_ACLK_REQ_ENABLE,
    CS_MODCLK_REQ_DISABLE,
    CS_SMCLK_REQ_DISABLE,
    CS_MCLK_REQ_DISABLE,
    CS_ACLK_REQ_DISABLE,
} cs_setting;

/***************************************************
 * Clock system functions
 **************************************************/
uint16_t CS_password            (cs_setting clock_password);
uint16_t CS_DCO_freq_set        (cs_setting clock_frequency);
uint16_t CS_HFXT_freq_set       (cs_setting clock_frequency);
uint16_t CS_ACLK_source_set     (cs_setting clock_source);
uint16_t CS_MCLK_source_set     (cs_setting clock_source);
uint16_t CS_SMCLK_source_set    (cs_setting clock_source);
uint16_t CS_ACLK_divider_set    (cs_setting clock_divider);
uint16_t CS_MCLK_divider_set    (cs_setting clock_divider);
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
