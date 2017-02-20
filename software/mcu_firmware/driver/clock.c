/*
 * clock.c
 *
 *  Created on: 2017. gada 17. febr.
 *      Author: Roberts
 */
#include "clock.h"

/***************************************************
 *	Write clock system key password
 **************************************************/
uint8_t CS_key_write(void){
	MASK_SET(CSCTL0, CSKEY);
    return 0;
}

/***************************************************
 *
 **************************************************/
uint8_t CS_DCO_freq_set(cs_setting clock_frequency){
	if(clock_frequency == DCO_FSEL_1M){
		MASK_CLEAR(CSCTL1, DCORSEL);
		MASK_SET(CSCTL1, DCOFSEL0 | DCOFSEL1 | DCOFSEL2);
	}
	else if(clock_frequency == DCO_FSEL_2M67){
		MASK_CLEAR(CSCTL1, DCORSEL);
		MASK_SET(CSCTL1, DCOFSEL0);
		MASK_CLEAR(CSCTL1, DCOFSEL1 | DCOFSEL2);
	}
	else if(clock_frequency == DCO_FSEL_3M5){
		MASK_CLEAR(CSCTL1, DCORSEL);
		MASK_SET(CSCTL1, DCOFSEL1);
		MASK_CLEAR(CSCTL1, DCOFSEL0 | DCOFSEL2);
	}
	else if(clock_frequency == DCO_FSEL_4M){
		MASK_CLEAR(CSCTL1, DCORSEL);
		MASK_SET(CSCTL1, DCOFSEL0 | DCOFSEL1);
		MASK_CLEAR(CSCTL1, DCOFSEL2);
	}
	else if(clock_frequency == DCO_FSEL_5M33){
		MASK_SET(CSCTL1, DCORSEL);
		MASK_SET(CSCTL1, DCOFSEL0);
		MASK_CLEAR(CSCTL1, DCOFSEL1 | DCOFSEL2);
	}
	else if(clock_frequency == DCO_FSEL_7M){
		MASK_SET(CSCTL1, DCORSEL);
		MASK_SET(CSCTL1, DCOFSEL1);
		MASK_CLEAR(CSCTL1, DCOFSEL0 | DCOFSEL2);
	}
	else if(clock_frequency == DCO_FSEL_8M){
		MASK_SET(CSCTL1, DCORSEL);
		MASK_SET(CSCTL1, DCOFSEL0 | DCOFSEL1);
		MASK_CLEAR(CSCTL1, DCOFSEL2);
	}
	else if(clock_frequency == DCO_FSEL_16M){
		MASK_SET(CSCTL1, DCORSEL);
		MASK_SET(CSCTL1, DCOFSEL2);
		MASK_CLEAR(CSCTL1, DCOFSEL0 | DCOFSEL1);
	}
	else if(clock_frequency == DCO_FSEL_21M){
		MASK_SET(CSCTL1, DCORSEL);
		MASK_SET(CSCTL1, DCOFSEL0 | DCOFSEL2);
		MASK_CLEAR(CSCTL1, DCOFSEL1);
	}
	else if(clock_frequency == DCO_FSEL_24M){
		MASK_SET(CSCTL1, DCORSEL);
		MASK_SET(CSCTL1, DCOFSEL1 | DCOFSEL2);
		MASK_CLEAR(CSCTL1, DCOFSEL0);
	}
	else{
		return 1;
	}
	return 0;
}

/***************************************************
 *	Auxilary clock source set
 **************************************************/
uint8_t CS_ACLK_source_set(cs_setting clock_source){
	if(clock_source == LFXT_CLK){
		MASK_SET(CSCTL2, SELA__LFXTCLK);
	}
	else if(clock_source == VLO_CLK){
		MASK_SET(CSCTL2, SELA__VLOCLK);
	}
	else if(clock_source == LFMOD_CLK){
		MASK_SET(CSCTL2, SELA__LFMODCLK);
	}
	else{
		return 1;
	}
	return 0;
}

/***************************************************
 *	Subsystem clock source set
 **************************************************/
uint8_t CS_SCLK_source_set(cs_setting clock_source){
	if(clock_source == LFXT_CLK){
		MASK_SET(CSCTL2, SELS__LFXTCLK);
	}
	else if(clock_source == VLO_CLK){
		MASK_SET(CSCTL2, SELS__VLOCLK);
	}
	else if(clock_source == LFMOD_CLK){
		MASK_SET(CSCTL2, SELS__LFMODCLK);
	}
	else if(clock_source == DCO_CLK){
		MASK_SET(CSCTL2, SELS__DCOCLK);
	}
	else if(clock_source == LFMOD_CLK){
		MASK_SET(CSCTL2, SELS__MODCLK);
	}
	else if(clock_source == HFXT_CLK){
		MASK_SET(CSCTL2, SELS__HFXTCLK);
	}
	else{
		return 1;
	}
	return 0;
}

/***************************************************
 *	Master clock source set
 **************************************************/
uint8_t CS_MCLK_source_set(cs_setting clock_source){
	if(clock_source == LFXT_CLK){
		MASK_SET(CSCTL2, SELM__LFXTCLK);
	}
	else if(clock_source == VLO_CLK){
		MASK_SET(CSCTL2, SELM__VLOCLK);
	}
	else if(clock_source == LFMOD_CLK){
		MASK_SET(CSCTL2, SELM__LFMODCLK);
	}
	else if(clock_source == DCO_CLK){
		MASK_SET(CSCTL2, SELM__DCOCLK);
	}
	else if(clock_source == LFMOD_CLK){
		MASK_SET(CSCTL2, SELM__MODCLK);
	}
	else if(clock_source == HFXT_CLK){
		MASK_SET(CSCTL2, SELM__HFXTCLK);
	}
	else{
		return 1;
	}
	return 0;
}

/***************************************************
 *	Auxilary clock divider set
 **************************************************/
uint8_t CS_ACLK_divider_set(cs_setting clock_divider){
	if(clock_divider == DIV_1){
		MASK_SET(CSCTL3, DIVA__1);
	}
	else if(clock_divider == DIV_2){
		MASK_SET(CSCTL3, DIVA__2);
	}
	else if(clock_divider == DIV_4){
		MASK_SET(CSCTL3, DIVA__4);
	}
	else if(clock_divider == DIV_8){
		MASK_SET(CSCTL3, DIVA__8);
	}
	else if(clock_divider == DIV_16){
		MASK_SET(CSCTL3, DIVA__16);
	}
	else if(clock_divider == DIV_32){
		MASK_SET(CSCTL3, DIVA__32);
	}
	else{
		return 1;
	}
	return 0;
}

/***************************************************
 *	Subsystem clock divider set
 **************************************************/
uint8_t CS_SCLK_divider_set(cs_setting clock_divider){
	if(clock_divider == DIV_1){
		MASK_SET(CSCTL3, DIVS__1);
	}
	else if(clock_divider == DIV_2){
		MASK_SET(CSCTL3, DIVS__2);
	}
	else if(clock_divider == DIV_4){
		MASK_SET(CSCTL3, DIVS__4);
	}
	else if(clock_divider == DIV_8){
		MASK_SET(CSCTL3, DIVS__8);
	}
	else if(clock_divider == DIV_16){
		MASK_SET(CSCTL3, DIVS__16);
	}
	else if(clock_divider == DIV_32){
		MASK_SET(CSCTL3, DIVS__32);
	}
	else{
		return 1;
	}
	return 0;
}

/***************************************************
 *	Master clock divider set
 **************************************************/
uint8_t CS_MCLK_divider_set(cs_setting clock_divider){
	if(clock_divider == DIV_1){
		MASK_SET(CSCTL3, DIVM__1);
	}
	else if(clock_divider == DIV_2){
		MASK_SET(CSCTL3, DIVM__2);
	}
	else if(clock_divider == DIV_4){
		MASK_SET(CSCTL3, DIVM__4);
	}
	else if(clock_divider == DIV_8){
		MASK_SET(CSCTL3, DIVM__8);
	}
	else if(clock_divider == DIV_16){
		MASK_SET(CSCTL3, DIVM__16);
	}
	else if(clock_divider == DIV_32){
		MASK_SET(CSCTL3, DIVM__32);
	}
	else{
		return 1;
	}
	return 0;
}

uint8_t CS_LFXT_onoff(cs_setting LFXT_status){
	if(LFXT_status == LFXT_OFF){
		MASK_SET(CSCTL4, LFXTOFF);
	}
	else if(LFXT_status == LFXT_ON){
		MASK_CLEAR(CSCTL4, LFXTOFF);
	}
	else{
		return 1;
	}
	return 0;
}

uint8_t CS_SMCLK_onoff(cs_setting SMCLK_status){
	if(SMCLK_status == SMCLK_OFF){
		MASK_SET(CSCTL4, SMCLKOFF);
	}
	else if(SMCLK_status == SMCLK_ON){
		MASK_CLEAR(CSCTL4, SMCLKOFF);
	}
	else{
		return 1;
	}
	return 0;
}

/*****************************************
 * Clock select control registers
 ****************************************/
void Clock_Init(void){
    //Set DCO 8 MHZ
	CSCTL2		= SELM_3 | SELS_3 | SELA_2;
	CSCTL3		= DIVM__1| DIVS__1;
	CSCTL0_H	= 0;
}
