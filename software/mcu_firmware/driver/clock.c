/*
 * clock.c
 *
 *  Created on: 2017. gada 17. febr.
 *      Author: Roberts
 */
#include "clock.h"
#include <msp430.h>
#include <stdint.h>

void Clock_Init(void){
    CSCTL0_H	= CSKEY>>8;			//CSKEY password
	CSCTL1		= DCOFSEL_6;  		//Set DCO 8 MHZ
	CSCTL2		= SELM_3 | SELS_3 | SELA_2;
	CSCTL3		= DIVM__1| DIVS__1;
	CSCTL0_H	= 0;
}
