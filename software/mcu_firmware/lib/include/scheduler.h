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

/*  All possible states that task may be in */
typedef volatile enum {
    TASK_INACTIVE,  /* Task has not been started yet and cannot run                     */
    TASK_ACTIVE,    /* Task is started, can be run, but other task is currently running */
    TASK_SUSPEND,   /* Task is is suspended and will not run untill allowed             */
    TASK_RUNNING    /* Task is started and currently being run by CPU                   */
} TaskStatus_t;

/* Scheduler task struture   */
typedef volatile struct {
    uint16_t tick_period;           /* Rate at which the task should tick   */
    uint16_t elapsed_time;          /* Time since task's last tick          */
    void (*tick_function)(void);    /* Function to call for task's tick     */
    TaskStatus_t status;            /* Holds the current status of task     */

} SchedulerTask_t;
/*
uint16_t task_init(SchedulerTask_t *task, uint16_t period, TaskStatus_t status){
    task->status = status;
    task->tick_period = period;
    task->elapsed_time = task->tick_period;
    //task->tick_function =
    return EXIT_SUCCESS;
}

void task_status_set(SchedulerTask_t *task, TaskStatus_t status){
    task->status = status;
}
*/
/*
void scheduler(void){
    unsigned char index;

    // run scheduler if no task is currently running
    if(!task_running_flag){
        // set the flag to avoid nested interrupts and stack overflow
        task_running_flag = TRUE;
        // cycle through task array
        for (index=0; index < tasksNum; ++index) {
            if(tasks[i].elapsed_time >= tasks[i].tick_period){ // Ready
                tasks[i].TickFct();         // execute task tick function
                tasks[i].elapsed_time = 0;  // clear elapsed time
            }
            tasks[i].elapsedTime += tasksPeriodGCD;
        }
        task_running_flag = FALSE;
    }
    */
    /*
     * else - Timer ticked before task processing done
     */
#endif /* LIB_INCLUDE_SCHEDULER_H_ */
