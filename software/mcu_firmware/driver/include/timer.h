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

uint16_t timer_A0_CLK_source    (TimerSetting_t timer_source);
uint16_t timer_A0_CLK_divider   (TimerSetting_t timer_clock_divider);

#endif /* DRIVER_INCLUDE_TIMER_H_ */
