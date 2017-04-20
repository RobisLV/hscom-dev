/*
 * timer.c
 *
 *  Created on: 2017. gada 20. apr.
 *      Author: Roberts
 */
#include "timer.h"

typedef volatile enum {
    TIMER_CLK_SOURCE_TAXCLK,
    TIMER_CLK_SOURCE_ACLK,
    TIMER_CLK_SOURCE_SMCLK,
    TIMER_CLK_SOURCE_INCLK,
    TIMER_CLK_DIV_1,
    TIMER_CLK_DIV_2,
    TIMER_CLK_DIV_4,
    TIMER_CLK_DIV_8,
    TIMER_MODE_STOP,        //  Stop mode: Timer is halted
    TIMER_MODE_COUNT_UP,    //   Up mode: Timer counts up to TAxCCR0
    TIMER_MODE_COUNT_UP_CONT,   // Continuous mode: Timer counts up to 0FFFFh
    TIMER_MODE_COUNT_DOWN,  //  Up/down mode: Timer counts up to TAxCCR0 then down to 0000h
    TIMER_CLEAR,
    TIMER_INT_ENABLE,
    TIMER_CAPTURE_DISABLE,
    TIMER_CAPTURE_RISING_EDGE,
    TIMER_CAPTURE_FALLING_EDGE,
    TIMER_CAPTURE_BOTH_EDGE,
    TIMER_ASYNC,
    TIMER_SYNC,
    TIMER_CAPTURE,
    TIMER_COMPARE,
    TIMER_OUTPUT_OUT_BUT,
    TIMER_OUTPUT_SET,
    TIMER_OUTPUT_TOGGLE_RESET,
    TIMER_OUTPUT_SET_RESET,
    TIMER_OUTPUT_TOGGLE,
    TIMER_OUTPUT_RESET,
    TIMER_OUTPUT_TOGGLE_SET,
    TIMER_OUTPUT_RESET_SET,
    TIMER_EXTENDED_DIV_1,
    TIMER_EXTENDED_DIV_2,
    TIMER_EXTENDED_DIV_3,
    TIMER_EXTENDED_DIV_4,
    TIMER_EXTENDED_DIV_5,
    TIMER_EXTENDED_DIV_6,
    TIMER_EXTENDED_DIV_7,
    TIMER_EXTENDED_DIV_8,
} TimerSetting_t;

uint16_t timer_A0_CLK_source(TimerSetting_t timer_source){
    // clear any previously set bits
    MASK_CLEAR(TA0CTL, TASSEL0|TASSEL1);
    // select timer clock source
    if(timer_source == TIMER_CLK_SOURCE_TAXCLK){
        MASK_CLEAR(TA0CTL, TASSEL0|TASSEL1);
    }
    else if(timer_source == TIMER_CLK_SOURCE_ACLK){
        MASK_SET(TA0CTL, TASSEL0);
    }
    else if(timer_source == TIMER_CLK_SOURCE_SMCLK){
        MASK_SET(TA0CTL, TASSEL1);
    }
    else if(timer_source == TIMER_CLK_SOURCE_INCLK){
        MASK_SET(TA0CTL, TASSEL0|TASSEL1);
    }
    else{
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}

uint16_t timer_A0_CLK_divider(TimerSetting_t timer_clock_divider){
    // clear any previously set bits
    MASK_CLEAR(TA0CTL, TASSEL0|TASSEL1);

    if(timer_clock_divider == TIMER_CLK_DIV_1){
        MASK_CLEAR(TA0CTL, TASSEL0|TASSEL1);
    }
    else if(timer_clock_divider == TIMER_CLK_DIV_2){
        MASK_SET(TA0CTL, TASSEL0);
    }
    else if(timer_clock_divider == TIMER_CLK_DIV_4){
        MASK_SET(TA0CTL, TASSEL1);
    }
    else if(timer_clock_divider == TIMER_CLK_DIV_8){
        MASK_SET(TA0CTL, TASSEL0|TASSEL1);
    }
    else{
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}

if( == ){

}
else{
    return EXIT_FAILURE;
}
return EXIT_SUCCESS;
