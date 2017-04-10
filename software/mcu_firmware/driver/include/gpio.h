/*
 * gpio.h
 *
 *  Created on: 2017. gada 17. febr.
 *      Author: Roberts
 */
#include <msp430.h>
#include <stdint.h>
#include "macros.h"

#ifndef DRIVER_INCLUDE_GPIO_H_
#define DRIVER_INCLUDE_GPIO_H_

typedef volatile enum{
	GPIO_LOW,           /* set GPIO high            */
	GPIO_HIGH,          /* set GPIO low             */
	GPIO_INPUT,         /* set GPIO as input        */
	GPIO_OUTPUT,        /* set GPIO as output       */
	GPIO_PULL_ENABLE,   /* enable GPIO pull-up      */
	GPIO_PULL_DISABLE,  /* disable GPIO pull-up     */
	GPIO_FUNCTION0,     /* select GPIO function 0   */
	GPIO_FUNCTION1,     /* select GPIO function 1   */
	GPIO_FUNCTION2,     /* select GPIO function 2   */
	GPIO_FUNCTION3,     /* select GPIO function 3   */
	GPIO_INT_ENABLE,    /* enable GPIO interrupt    */
	GPIO_INT_DISABLE,   /* Disable GPIO interrupt   */
	GPIO_INT_EDGE,      /* enable GPIO  */
}gpio_setting;

/***************************************************
 * GPIO functions
 **************************************************/
uint16_t    GPIO_read     (uint16_t gpio_pin, uint8_t gpio_input_reg);
uint16_t    GPIO_write    (uint16_t gpio_pin, volatile uint8_t *gpio_output_reg, gpio_setting gpio_write);
uint16_t    GPIO_toggle   (uint16_t gpio_pin, uint8_t gpio_input_reg);

uint16_t    GPIO_mode_set      (uint16_t gpio_pin, volatile uint8_t *gpio_dir_reg, gpio_setting gpio_mode);
uint16_t    GPIO_pull_set      (uint16_t gpio_pin, volatile uint8_t *gpio_pullup_reg, gpio_setting gpio_write);
uint16_t    GPIO_function_set  (uint16_t gpio_pin, volatile uint8_t *gpio_function0_sel, volatile uint8_t *gpio_function1_sel, gpio_setting gpio_function);
uint16_t    GPIO_interrupt_set (void);

#endif /* DRIVER_INCLUDE_GPIO_H_ */
