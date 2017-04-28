/*
 * timer.c
 *
 *  Created on: 2017. gada 20. apr.
 *      Author: Roberts
 */
#include "timer.h"

uint16_t timer_A0_clock_source(TimerSetting_t timer_source){
    // clear any previously set bits
    MASK_CLEAR(TA0CTL, TASSEL0|TASSEL1);
    // select timer clock source
    if(timer_source == TIMER_CLK_SOURCE_TACLK){
        MASK_SET(TA0CTL, TASSEL__TACLK);
    }
    else if(timer_source == TIMER_CLK_SOURCE_ACLK){
        MASK_SET(TA0CTL, TASSEL__ACLK);
    }
    else if(timer_source == TIMER_CLK_SOURCE_SMCLK){
        MASK_SET(TA0CTL, TASSEL__SMCLK);
    }
    else if(timer_source == TIMER_CLK_SOURCE_INCLK){
        MASK_SET(TA0CTL, TASSEL__INCLK);
    }
    else{
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}

uint16_t timer_A0_clock_divider(TimerSetting_t timer_clock_divider){
    // clear any previously set bits
    MASK_CLEAR(TA0CTL, ID0|ID1);

    if(timer_clock_divider == TIMER_CLK_DIV_1){
        MASK_SET(TA0CTL, ID_0);
    }
    else if(timer_clock_divider == TIMER_CLK_DIV_2){
        MASK_SET(TA0CTL, ID_1);
    }
    else if(timer_clock_divider == TIMER_CLK_DIV_4){
        MASK_SET(TA0CTL, ID_2);
    }
    else if(timer_clock_divider == TIMER_CLK_DIV_8){
        MASK_SET(TA0CTL, ID_3);
    }
    else{
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}

uint16_t timer_A0_mode(TimerSetting_t timer_mode){
    // clear any previously set bits
    MASK_CLEAR(TA0CTL, MC0|MC1);

    if(timer_mode == TIMER_MODE_STOP){
        MASK_SET(TA0CTL, MC__STOP);
    }
    else if(timer_mode == TIMER_MODE_COUNT_UP){
        MASK_SET(TA0CTL, MC__UP);
    }
    else if(timer_mode == TIMER_MODE_COUNT_UP_CONT){
        MASK_SET(TA0CTL, MC__CONTINUOUS);
    }
    else if(timer_mode == TIMER_MODE_COUNT_UP_DOWN){
        MASK_SET(TA0CTL, MC__UPDOWN);
    }
    else{
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}

uint16_t timer_A0_clear(void){
    MASK_SET(TA0CTL, TACLR);
    return EXIT_SUCCESS;
}

uint16_t timer_A0_interrupt(TimerSetting_t timer_interrupt){
    if(timer_interrupt == TIMER_INT_ENABLE){
        MASK_SET(TA0CTL, TAIE);
    }
    else if(timer_interrupt == TIMER_INT_DISABLE){
        MASK_CLEAR(TA0CTL, TAIE);
    }
    return EXIT_SUCCESS;
}

uint16_t timer_A0_interrupt_read(void){
    if(MASK_CHECK(TA0CTL, TAIFG) == TRUE){
        return 1;
    }
    return 0;
}

uint16_t timer_A0_read(void){
    return TA0R;
}



uint16_t timer_A0_sync_source(TimerSetting_t timer_sync_source){
    if(timer_sync_source == TIMER_SOURCE_ASYNC){
        MASK_CLEAR(TA0CCTL0, SCS);
    }
    else if(timer_sync_source == TIMER_SOURCE_SYNC){
        MASK_SET(TA0CCTL0, SCS);
    }
    else{
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}

uint16_t timer_A0_output_mode(TimerSetting_t timer_output_mode){
    MASK_CLEAR(TA0CCTL0, OUTMOD0|OUTMOD1|OUTMOD2);

    if(timer_output_mode == TIMER_OUTPUT_OUT_BIT){
        MASK_SET(TA0CCTL0, OUTMOD_0);
    }
    else if(timer_output_mode == TIMER_OUTPUT_SET){
        MASK_SET(TA0CCTL0, OUTMOD_1);
    }
    else if(timer_output_mode == TIMER_OUTPUT_TOGGLE_RESET){
        MASK_SET(TA0CCTL0, OUTMOD_2);
    }
    else if(timer_output_mode == TIMER_OUTPUT_SET_RESET){
        MASK_SET(TA0CCTL0, OUTMOD_3);
    }
    else if(timer_output_mode == TIMER_OUTPUT_TOGGLE){
        MASK_SET(TA0CCTL0, OUTMOD_4);
    }
    else if(timer_output_mode == TIMER_OUTPUT_RESET){
        MASK_SET(TA0CCTL0, OUTMOD_5);
    }
    else if(timer_output_mode == TIMER_OUTPUT_TOGGLE_SET){
        MASK_SET(TA0CCTL0, OUTMOD_6);
    }
    else if(timer_output_mode == TIMER_OUTPUT_RESET_SET){
        MASK_SET(TA0CCTL0, OUTMOD_7);
    }
    else{
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}

uint16_t timer_A0_output_write(TimerSetting_t timer_output){
    if(timer_output == TIMER_OUTPUT_HIGH){
        MASK_SET(TA0CCTL0, OUT);
    }
    else if(timer_output == TIMER_OUTPUT_LOW){
        MASK_CLEAR(TA0CCTL0, OUT);
    }
    else{
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}

uint16_t timer_A0_capture_overflow_read(void){
    if(MASK_CHECK(TA0CCTL0, COV)){
        return 1;
    }
    return 0;
}

uint16_t timer_A0_clock_divider_exp(TimerSetting_t timer_clock_divider){
    // clear any previously set bits
    MASK_CLEAR(TA0EX0, TAIDEX0|TAIDEX1|TAIDEX2);

    if(timer_clock_divider == TIMER_EXTENDED_DIV_1){
        MASK_SET(TA0EX0, TAIDEX_0);
    }
    else if(timer_clock_divider == TIMER_EXTENDED_DIV_2){
        MASK_SET(TA0EX0, TAIDEX_1);
    }
    else if(timer_clock_divider == TIMER_EXTENDED_DIV_3){
        MASK_SET(TA0EX0, TAIDEX_2);
    }
    else if(timer_clock_divider == TIMER_EXTENDED_DIV_4){
        MASK_SET(TA0EX0, TAIDEX_3);
    }
    else if(timer_clock_divider == TIMER_EXTENDED_DIV_5){
        MASK_SET(TA0EX0, TAIDEX_4);
    }
    else if(timer_clock_divider == TIMER_EXTENDED_DIV_6){
        MASK_SET(TA0EX0, TAIDEX_5);
    }
    else if(timer_clock_divider == TIMER_EXTENDED_DIV_7){
        MASK_SET(TA0EX0, TAIDEX_6);
    }
    else if(timer_clock_divider == TIMER_EXTENDED_DIV_8){
        MASK_SET(TA0EX0, TAIDEX_7);
    }
    else{
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}

uint16_t timer_A0_CC_select(TimerSetting_t timer_capture_mode){
    if(timer_capture_mode == TIMER_COMPARE){
        MASK_CLEAR(TA0CCTL0, CAP);
    }
    else if(timer_capture_mode == TIMER_CAPTURE){
        MASK_SET(TA0CCTL0, CAP);
    }
    else{
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}

uint16_t timer_A0_CC_mode(TimerSetting_t timer_capture_mode){
    MASK_CLEAR(TA0CCTL0, CM0|CM1);
    if(timer_capture_mode == TIMER_CAPTURE_DISABLE){
        MASK_SET(TA0CCTL0, CM_0);
    }
    else if(timer_capture_mode == TIMER_CAPTURE_RISING_EDGE){
        MASK_SET(TA0CCTL0, CM_1);
    }
    else if(timer_capture_mode == TIMER_CAPTURE_FALLING_EDGE){
        MASK_SET(TA0CCTL0, CM_2);
    }
    else if(timer_capture_mode == TIMER_CAPTURE_BOTH_EDGE){
        MASK_SET(TA0CCTL0, CM_3);
    }
    else{
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}

uint16_t timer_A0_CC_input(TimerSetting_t timer_compare_input){
    MASK_CLEAR(TA0CCTL0, CCIS0|CCIS1);

    if(timer_compare_input == TIMER_INPUT_CCIA){
        MASK_SET(TA0CCTL0, CCIS_0);
    }
    else if(timer_compare_input == TIMER_INPUT_CCIB){
        MASK_SET(TA0CCTL0, CCIS_1);
    }
    else if(timer_compare_input == TIMER_INPUT_GND){
        MASK_SET(TA0CCTL0, CCIS_2);
    }
    else if(timer_compare_input == TIMER_INPUT_VCC){
        MASK_SET(TA0CCTL0, CCIS_3);
    }
    else{
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}

uint16_t timer_A0_CC_interrupt(TimerSetting_t timer_interrupt){
    if(timer_interrupt == TIMER_INT_ENABLE){
        MASK_SET(TA0CCTL0, CCIE);
    }
    else if(timer_interrupt == TIMER_INT_DISABLE){
        MASK_CLEAR(TA0CCTL0, CCIE);
    }
    else{
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}

uint16_t timer_A0_CC_input_read(void){
    if(MASK_CHECK(TA0CCTL0, CCI)){
        return 1;
    }
    return 0;
}

uint16_t timer_A0_CC_interrupt_read(void){
    if(MASK_CHECK(TA0CCTL0, CCIFG)){
        return 1;
    }
    return 0;
}

uint16_t timer_A0_CC_value_write(uint16_t timer_cc_value){
    TA0CCR0 = timer_cc_value;
    return EXIT_SUCCESS;
}

#pragma vector=TIMER0_A0_VECTOR
__interrupt void TIMER0_A0_ISR(void){
    volatile int a = 0;
    GPIO_toggle(MCU_LED_STATUS_PIN, MCU_LED_STATUS_PORT, MCU_LED_STATUS_IN);
    switch(__even_in_range(TA0IV,8)){
        case 0x00:  /* No interrupt pending                             */
            a++;
            break;
        case 0x02:  /* Capture/compare 1; Interrupt Flag: TAxCCR1 CCIFG */
            a++;
            break;
        case 0x04:  /* Capture/compare 2; Interrupt Flag: TAxCCR2 CCIFG */
            break;
        case 0x06:  /* Capture/compare 3; Interrupt Flag: TAxCCR3 CCIFG */
            break;
        case 0x08:  /* Capture/compare 4; Interrupt Flag: TAxCCR4 CCIFG */
            break;
        case 0x0A:  /* Capture/compare 5; Interrupt Flag: TAxCCR5 CCIFG */
            break;
        case 0x0C:  /* Capture/compare 6; Interrupt Flag: TAxCCR6 CCIFG */
            break;
        case 0x0E:  /* Timer overflow; Interrupt Flag: TAxCTL TAIFG     */
            break;
        default:    /* Default case */
            break;
    }
}

/*********_END_OF_FILE_********/
