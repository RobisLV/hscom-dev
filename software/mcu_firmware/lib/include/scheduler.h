/*
 * scheduler.h
 *
 *  Created on: 2017. gada 20. apr.
 *      Author: Roberts
 */

#ifndef LIB_INCLUDE_SCHEDULER_H_
#define LIB_INCLUDE_SCHEDULER_H_

#include <msp430.h>
#include <stdint.h>
#include "macros.h"

/* Scheduler struture   */
typedef volatile struct {
    uint16_t tick_period;           /* Rate at which the task should tick   */
    uint16_t elapsed_time;          /* Time since task's last tick          */
    void (*tick_function)(void);    /* Function to call for task's tick     */
} SchedulerTask_t;

#endif /* LIB_INCLUDE_SCHEDULER_H_ */
