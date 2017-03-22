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
uint16_t CS_password(cs_setting clock_password){
	if(clock_password == CS_PWD_SET){
		CSCTL0 = CSKEY;
	}
	else if(clock_password == CS_PWD_CLEAR){
		CSCTL0_L = 0x00;
	}
	else{
		return 1;
	}
    return 0;
}

/***************************************************
 *
 **************************************************/
uint16_t CS_DCO_freq_set(cs_setting clock_frequency){
    // Load DCO frequency settings in register CSCTL1
	if(clock_frequency == CS_DCO_FSEL_1M){
		CSCTL1 = DCOFSEL_0;
	}
	else if(clock_frequency == CS_DCO_FSEL_2M67){
		CSCTL1 = DCOFSEL_1;
	}
	else if(clock_frequency == CS_DCO_FSEL_3M5){
		CSCTL1 = DCOFSEL_2;
	}
	else if(clock_frequency == CS_DCO_FSEL_4M){
        CSCTL1 = DCOFSEL_3;
	}
	else if(clock_frequency == CS_DCO_FSEL_5M33){
        CSCTL1 = DCOFSEL_4;
	}
	else if(clock_frequency == CS_DCO_FSEL_7M){
        CSCTL1 = DCOFSEL_5;
	}
	else if(clock_frequency == CS_DCO_FSEL_8M){
        CSCTL1 = DCOFSEL_6;
	}
	else if(clock_frequency == CS_DCO_FSEL_16M){
        CSCTL1 = DCORSEL | DCOFSEL_4;
	}
	else if(clock_frequency == CS_DCO_FSEL_21M){
	    CSCTL1 = DCORSEL | DCOFSEL_5;
	}
	else if(clock_frequency == CS_DCO_FSEL_24M){
	    CSCTL1 = DCORSEL | DCOFSEL_6;
	}
	else{
		return 1;
	}
	return 0;
}

/***************************************************
 *	High frequency crystal on/off
 **************************************************/
uint16_t CS_HFXT_freq_set(cs_setting clock_frequency){
    // Clear any previously set frequency select bits
    MASK_CLEAR(CSCTL4, HFFREQ0|HFFREQ1);
    // Set HFXT frequency
	if(clock_frequency == CS_HFXT_FSEL_0_4M){
		MASK_SET(CSCTL4, HFFREQ_0);
	}
	else if(clock_frequency == CS_HFXT_FSEL_4_8M){
		MASK_SET(CSCTL4, HFFREQ_1);
	}
	else if(clock_frequency == CS_HFXT_FSEL_8_16M){
		MASK_SET(CSCTL4, HFFREQ_2);
	}
	else if(clock_frequency == CS_HFXT_FSEL_16_24M){
		MASK_SET(CSCTL4, HFFREQ_3);
	}
	else{
		return 1;
	}
	return 0;
}

/***************************************************
 *	Auxilary clock source set
 **************************************************/
uint16_t CS_ACLK_source_set(cs_setting clock_source){
    // Clear any previously set source select bits
    MASK_CLEAR(CSCTL2, SELA0|SELA1|SELA2);
    // Select Aux clock source
	if(clock_source == CS_LFXT_CLK){
		MASK_SET(CSCTL2, SELA__LFXTCLK);
	}
	else if(clock_source == CS_VLO_CLK){
		MASK_SET(CSCTL2, SELA__VLOCLK);
	}
	else if(clock_source == CS_LFMOD_CLK){
		MASK_SET(CSCTL2, SELA__LFMODCLK);
	}
	else{
		return 1;
	}
	return 0;
}

/***************************************************
 *	Master clock source set
 **************************************************/
uint16_t CS_MCLK_source_set(cs_setting clock_source){
    // Clear any previously set source select bits
    MASK_CLEAR(CSCTL2, SELM0|SELM1|SELM2);
    // Select Master clock source
	if(clock_source == CS_LFXT_CLK){
		MASK_SET(CSCTL2, SELM__LFXTCLK);
	}
	else if(clock_source == CS_VLO_CLK){
		MASK_SET(CSCTL2, SELM__VLOCLK);
	}
	else if(clock_source == CS_LFMOD_CLK){
		MASK_SET(CSCTL2, SELM__LFMODCLK);
	}
	else if(clock_source == CS_DCO_CLK){
		MASK_SET(CSCTL2, SELM__DCOCLK);
	}
	else if(clock_source == CS_LFMOD_CLK){
		MASK_SET(CSCTL2, SELM__MODCLK);
	}
	else if(clock_source == CS_HFXT_CLK){
		MASK_SET(CSCTL2, SELM__HFXTCLK);
	}
	else{
		return 1;
	}
	return 0;
}

/***************************************************
 *  Subsystem clock source set
 **************************************************/
uint16_t CS_SMCLK_source_set(cs_setting clock_source){
    // Clear any previously set source select bits
    MASK_CLEAR(CSCTL2, SELS0|SELS1|SELS2);
    // Select Subsystem clock source
    if(clock_source == CS_LFXT_CLK){
        MASK_SET(CSCTL2, SELS__LFXTCLK);
    }
    else if(clock_source == CS_VLO_CLK){
        MASK_SET(CSCTL2, SELS__VLOCLK);
    }
    else if(clock_source == CS_LFMOD_CLK){
        MASK_SET(CSCTL2, SELS__LFMODCLK);
    }
    else if(clock_source == CS_DCO_CLK){
        MASK_SET(CSCTL2, SELS__DCOCLK);
    }
    else if(clock_source == CS_LFMOD_CLK){
        MASK_SET(CSCTL2, SELS__MODCLK);
    }
    else if(clock_source == CS_HFXT_CLK){
        MASK_SET(CSCTL2, SELS__HFXTCLK);
    }
    else{
        return 1;
    }
    return 0;
}

/***************************************************
 *	Auxilary clock divider set
 **************************************************/
uint16_t CS_ACLK_divider_set(cs_setting clock_divider){
    // Clear any previously set divider select bits
    MASK_CLEAR(CSCTL3, DIVA0|DIVA1|DIVA2);
    // Select ACLK divider
	if(clock_divider == CS_DIV_1){
		MASK_SET(CSCTL3, DIVA__1);
	}
	else if(clock_divider == CS_DIV_2){
		MASK_SET(CSCTL3, DIVA__2);
	}
	else if(clock_divider == CS_DIV_4){
		MASK_SET(CSCTL3, DIVA__4);
	}
	else if(clock_divider == CS_DIV_8){
		MASK_SET(CSCTL3, DIVA__8);
	}
	else if(clock_divider == CS_DIV_16){
		MASK_SET(CSCTL3, DIVA__16);
	}
	else if(clock_divider == CS_DIV_32){
		MASK_SET(CSCTL3, DIVA__32);
	}
	else{
		return 1;
	}
	return 0;
}

/***************************************************
 *	Master clock divider set
 **************************************************/
uint16_t CS_MCLK_divider_set(cs_setting clock_divider){
    // Clear any previously set divider select bits
    MASK_CLEAR(CSCTL3, DIVM0|DIVM1|DIVM2);
    // Select MCLK divider
	if(clock_divider == CS_DIV_1){
		MASK_SET(CSCTL3, DIVM__1);
	}
	else if(clock_divider == CS_DIV_2){
		MASK_SET(CSCTL3, DIVM__2);
	}
	else if(clock_divider == CS_DIV_4){
		MASK_SET(CSCTL3, DIVM__4);
	}
	else if(clock_divider == CS_DIV_8){
		MASK_SET(CSCTL3, DIVM__8);
	}
	else if(clock_divider == CS_DIV_16){
		MASK_SET(CSCTL3, DIVM__16);
	}
	else if(clock_divider == CS_DIV_32){
		MASK_SET(CSCTL3, DIVM__32);
	}
	else{
		return 1;
	}
	return 0;
}

/***************************************************
 *  Subsystem clock divider set
 **************************************************/
uint16_t CS_SMCLK_divider_set(cs_setting clock_divider){
    // Clear any previously set divider select bits
    MASK_CLEAR(CSCTL3, DIVS0|DIVS1|DIVS2);
    // Select SMCLK divider
    if(clock_divider == CS_DIV_1){
        MASK_SET(CSCTL3, DIVS__1);
    }
    else if(clock_divider == CS_DIV_2){
        MASK_SET(CSCTL3, DIVS__2);
    }
    else if(clock_divider == CS_DIV_4){
        MASK_SET(CSCTL3, DIVS__4);
    }
    else if(clock_divider == CS_DIV_8){
        MASK_SET(CSCTL3, DIVS__8);
    }
    else if(clock_divider == CS_DIV_16){
        MASK_SET(CSCTL3, DIVS__16);
    }
    else if(clock_divider == CS_DIV_32){
        MASK_SET(CSCTL3, DIVS__32);
    }
    else{
        return 1;
    }
    return 0;
}

/***************************************************
 *	Low frequency crystal on/off
 **************************************************/
uint16_t CS_LFXT(cs_setting clock_onoff){
	if(clock_onoff == CS_LFXT_OFF){
		MASK_SET(CSCTL4, LFXTOFF);
	}
	else if(clock_onoff == CS_LFXT_ON){
		MASK_CLEAR(CSCTL4, LFXTOFF);
	}
	else{
		return 1;
	}
	return 0;
}

/***************************************************
 *	 on/off
 **************************************************/
uint16_t CS_SMCLK(cs_setting clock_onoff){
	if(clock_onoff == CS_SMCLK_OFF){
		MASK_SET(CSCTL4, SMCLKOFF);
	}
	else if(clock_onoff == CS_SMCLK_ON){
		MASK_CLEAR(CSCTL4, SMCLKOFF);
	}
	else{
		return 1;
	}
	return 0;
}

/***************************************************
 *	on/off
 **************************************************/
uint16_t CS_VLO(cs_setting clock_onoff){
	if(clock_onoff == CS_VLO_OFF){
		MASK_SET(CSCTL4, VLOOFF);
	}
	else if(clock_onoff == CS_VLO_ON){
		MASK_CLEAR(CSCTL4, VLOOFF);
	}
	else{
		return 1;
	}
	return 0;
}

/***************************************************
 *	High frequency crystal on/off
 **************************************************/
uint16_t CS_HFXT(cs_setting HFXT_status){
	if(HFXT_status == CS_HFXT_OFF){
		MASK_SET(CSCTL4, HFXTOFF);
	}
	else if(HFXT_status == CS_HFXT_ON){
		MASK_CLEAR(CSCTL4, HFXTOFF);
	}
	else{
		return 1;
	}
	return 0;
}

/***************************************************
 *	Low frequency crystal drive strength
 **************************************************/
uint16_t CS_LFXT_drive(cs_setting clock_drive){
    // Clear any previously set crystal drive strength select bits
    MASK_CLEAR(CSCTL4, LFXTDRIVE0|LFXTDRIVE1);
    // Select crystal drive strength
	if(clock_drive == CS_LFXT_DRIVE_LOWEST){
		MASK_SET(CSCTL4, LFXTDRIVE_0);
	}
	else if(clock_drive == CS_LFXT_DRIVE_LOW){
		MASK_SET(CSCTL4, LFXTDRIVE_1);
	}
	else if(clock_drive == CS_LFXT_DRIVE_HIGH){
		MASK_SET(CSCTL4, LFXTDRIVE_2);
	}
	else if(clock_drive == CS_LFXT_DRIVE_HIGHEST){
		MASK_SET(CSCTL4, LFXTDRIVE_3);
	}
	else{
		return 1;
	}
	return 0;
}
/***************************************************
 *	High frequency crystal drive strength
 **************************************************/
uint16_t CS_HFXT_drive(cs_setting clock_drive){
    // Clear any previously set crystal drive strength select bits
    MASK_CLEAR(CSCTL4, HFXTDRIVE0|HFXTDRIVE1);
    // Select crystal drive strength
	if(clock_drive == CS_HFXT_DRIVE_LOWEST){
		MASK_SET(CSCTL4, HFXTDRIVE_0);
	}
	else if(clock_drive == CS_HFXT_DRIVE_LOW){
		MASK_SET(CSCTL4, HFXTDRIVE_1);
	}
	else if(clock_drive == CS_HFXT_DRIVE_HIGH){
		MASK_SET(CSCTL4, HFXTDRIVE_2);
	}
	else if(clock_drive == CS_HFXT_DRIVE_HIGHEST){
		MASK_SET(CSCTL4, HFXTDRIVE_3);
	}
	else{
		return 1;
	}
	return 0;
}

/*****************************************
 * Low frequency crystal clock bypass
 ****************************************/
uint16_t CS_LFXT_bypass(cs_setting clock_bypass){
	if(clock_bypass == CS_LFXT_BYPASS_ON){
		MASK_SET(CSCTL4, LFXTBYPASS);
	}
	else if(clock_bypass == CS_LFXT_BYPASS_OFF){
		MASK_CLEAR(CSCTL4, LFXTBYPASS);
	}
	else{
		return 1;
	}
	return 0;
}

/*****************************************
 * Hgih frequency crystal clock bypass
 ****************************************/
uint16_t CS_HFXT_bypass(cs_setting clock_bypass){
	if(clock_bypass == CS_HFXT_BYPASS_ON){
		MASK_SET(CSCTL4, HFXTBYPASS);
	}
	else if(clock_bypass == CS_HFXT_BYPASS_OFF){
		MASK_CLEAR(CSCTL4, HFXTBYPASS);
	}
	else{
		return 1;
	}
	return 0;
}

/*****************************************
 * Hgih frequency crystal clock fault counter
 ****************************************/
uint16_t CS_HFXT_fault_counter(cs_setting clock_counter){
	if(clock_counter == CS_HFXT_FAULT_CNT_ON){
		MASK_SET(CSCTL5, ENSTFCNT2);
	}
	else if(clock_counter == CS_HFXT_FAULT_CNT_OFF){
		MASK_CLEAR(CSCTL5, ENSTFCNT2);
	}
	else{
		return 1;
	}
	return 0;
}

/*****************************************
 * Low frequency crystal clock fault counter
 ****************************************/
uint16_t CS_LFXT_fault_counter(cs_setting clock_counter){
	if(clock_counter == CS_LFXT_FAULT_CNT_ON){
		MASK_SET(CSCTL5, ENSTFCNT1);
	}
	else if(clock_counter == CS_LFXT_FAULT_CNT_OFF){
		MASK_CLEAR(CSCTL5, ENSTFCNT1);
	}
	else{
		return 1;
	}
	return 0;
}

/*****************************************
 * High frequency crystal clock fault flag
 ****************************************/
uint16_t CS_HFXT_fault_flag_read(void){
	if(CSCTL5 & HFXTOFFG){
		return 1;
	}
	return 0;
}

/*****************************************
 * Low frequency crystal clock fault flag
 ****************************************/
uint16_t CS_LFXT_fault_flag_read(void){
	if(CSCTL5 & LFXTOFFG){
		return 1;
	}
	return 0;
}

/*****************************************
 * Module clock request enable
 ****************************************/
uint16_t CS_MODCLK_request(cs_setting clock_request){
	if(clock_request == CS_MODCLK_REQ_ENABLE){
		MASK_SET(CSCTL6, MODCLKREQEN);
	}
	else if(clock_request == CS_MODCLK_REQ_DISABLE){
		MASK_CLEAR(CSCTL6, MODCLKREQEN);
	}
	else{
		return 1;
	}
	return 0;
}

/*****************************************
 * clock request enable
 ****************************************/
uint16_t CS_SMCLK_request(cs_setting clock_request){
	if(clock_request == CS_SMCLK_REQ_ENABLE){
		MASK_SET(CSCTL6, SMCLKREQEN);
	}
	else if(clock_request == CS_SMCLK_REQ_DISABLE){
		MASK_CLEAR(CSCTL6, SMCLKREQEN);
	}
	else{
		return 1;
	}
	return 0;
}

/*****************************************
 * clock request enable
 ****************************************/
uint16_t CS_MCLK_request(cs_setting clock_request){
	if(clock_request == CS_MCLK_REQ_ENABLE){
		MASK_SET(CSCTL6, MCLKREQEN);
	}
	else if(clock_request == CS_MCLK_REQ_DISABLE){
		MASK_CLEAR(CSCTL6, MCLKREQEN);
	}
	else{
		return 1;
	}
	return 0;
}

/*****************************************
 * clock request enable
 ****************************************/
uint16_t CS_ACLK_request(cs_setting clock_request){
	if(clock_request == CS_ACLK_REQ_ENABLE){
		MASK_SET(CSCTL6, ACLKREQEN);
	}
	else if(clock_request == CS_ACLK_REQ_DISABLE){
		MASK_CLEAR(CSCTL6, ACLKREQEN);
	}
	else{
		return 1;
	}
	return 0;
}

/*********_END_OF_FILE_********/


