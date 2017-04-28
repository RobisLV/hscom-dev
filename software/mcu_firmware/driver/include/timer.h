/*
 * timer.h
 *
 *  Created on: 2017. gada 20. apr.
 *      Author: Roberts
 */

#ifndef DRIVER_INCLUDE_TIMER_H_
#define DRIVER_INCLUDE_TIMER_H_

#include <msp430.h>
#include <stdint.h>
#include "macros.h"
#include "gpio.h"
#include "pinmap.h"

typedef volatile enum {
    TIMER_CLK_SOURCE_TACLK,
    TIMER_CLK_SOURCE_ACLK,
    TIMER_CLK_SOURCE_SMCLK,
    TIMER_CLK_SOURCE_INCLK,
    TIMER_CLK_DIV_1,
    TIMER_CLK_DIV_2,
    TIMER_CLK_DIV_4,
    TIMER_CLK_DIV_8,
    TIMER_MODE_STOP,            //  Stop mode: Timer is halted
    TIMER_MODE_COUNT_UP,        //  Up mode: Timer counts up to TAxCCR0
    TIMER_MODE_COUNT_UP_CONT,   //  Continuous mode: Timer counts up to 0FFFFh
    TIMER_MODE_COUNT_UP_DOWN,   //  Up/down mode: Timer counts up to TAxCCR0 then down to 0000h
    TIMER_INT_ENABLE,
    TIMER_INT_DISABLE,
    TIMER_CAPTURE_DISABLE,
    TIMER_CAPTURE_RISING_EDGE,
    TIMER_CAPTURE_FALLING_EDGE,
    TIMER_CAPTURE_BOTH_EDGE,
    TIMER_INPUT_CCIA,
    TIMER_INPUT_CCIB,
    TIMER_INPUT_GND,
    TIMER_INPUT_VCC,
    TIMER_SOURCE_ASYNC,
    TIMER_SOURCE_SYNC,
    TIMER_CAPTURE,
    TIMER_COMPARE,
    TIMER_OUTPUT_OUT_BIT,
    TIMER_OUTPUT_SET,
    TIMER_OUTPUT_TOGGLE_RESET,
    TIMER_OUTPUT_SET_RESET,
    TIMER_OUTPUT_TOGGLE,
    TIMER_OUTPUT_RESET,
    TIMER_OUTPUT_TOGGLE_SET,
    TIMER_OUTPUT_RESET_SET,
    TIMER_OUTPUT_HIGH,
    TIMER_OUTPUT_LOW,
    TIMER_EXTENDED_DIV_1,
    TIMER_EXTENDED_DIV_2,
    TIMER_EXTENDED_DIV_3,
    TIMER_EXTENDED_DIV_4,
    TIMER_EXTENDED_DIV_5,
    TIMER_EXTENDED_DIV_6,
    TIMER_EXTENDED_DIV_7,
    TIMER_EXTENDED_DIV_8,
} TimerSetting_t;

/* TA0 TA1 each has 3 CC registers
 * TA2 TA3 each has 2 CC registers
 * TB0 has 7 CC registers
 */
typedef volatile enum {
    TIMER_A0,
    TIMER_A1,
    TIMER_A2,
    TIMER_A3,
} TimerInstance_t;
/***************************************************
*   Timer A0 functions
 **************************************************/
uint16_t timer_A0_clock_source          (TimerSetting_t timer_source);
uint16_t timer_A0_clock_divider         (TimerSetting_t timer_clock_divider);
uint16_t timer_A0_mode                  (TimerSetting_t timer_mode);
uint16_t timer_A0_clear                 (void);
uint16_t timer_A0_interrupt             (TimerSetting_t timer_interrupt);
uint16_t timer_A0_interrupt_read        (void);
uint16_t timer_A0_read                  (void);
uint16_t timer_A0_sync_source           (TimerSetting_t timer_sync_source);
uint16_t timer_A0_output_mode           (TimerSetting_t timer_output_mode);
uint16_t timer_A0_output_write          (TimerSetting_t timer_output);
uint16_t timer_A0_capture_overflow_read (void);
uint16_t timer_A0_clock_divider_exp     (TimerSetting_t timer_clock_divider);

/* functions for using capture/compare registers    */
uint16_t timer_A0_CC_select             (TimerSetting_t timer_capture_mode);
uint16_t timer_A0_CC_mode               (TimerSetting_t timer_capture_mode);
uint16_t timer_A0_CC_input              (TimerSetting_t timer_compare_input);
uint16_t timer_A0_CC_interrupt          (TimerSetting_t timer_interrupt);
uint16_t timer_A0_CC_input_read         (void);
uint16_t timer_A0_CC_interrupt_read     (void);
uint16_t timer_A0_CC_value_write        (uint16_t timer_cc_value);

#endif /* DRIVER_INCLUDE_TIMER_H_ */
