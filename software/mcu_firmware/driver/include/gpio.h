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
	GPIO_LOW,
	GPIO_HIGH,
	GPIO_INPUT,
	GPIO_OUTPUT,
	GPIO_PULL_ENABLE,
	GPIO_PULL_DISABLE,
	GPIO_FUNCTION0,
	GPIO_FUNCTION1,
	GPIO_FUNCTION2,
	GPIO_FUNCTION3,
	GPIO_INTERRUPT_ENABLE,
	GPIO_INTERRUPT_EDGE,
	GPIO_INTERRUPT_FLAG,
}gpio_setting;

uint16_t    GPIO_port_read     (uint16_t gpio_pin, uint16_t gpio_input_reg);
uint16_t    GPIO_port_write    (uint16_t gpio_pin, volatile uint8_t *gpio_output_reg, gpio_setting gpio_write);
uint16_t    GPIO_mode_set      (uint16_t gpio_pin, volatile uint8_t *gpio_dir_reg, gpio_setting gpio_mode);
uint16_t    GPIO_pull_set      (uint16_t gpio_pin, volatile uint8_t *gpio_pullup_reg, gpio_setting gpio_write);
uint16_t    GPIO_function_set  (uint16_t gpio_pin, volatile uint8_t *gpio_function0_sel, volatile uint8_t *gpio_function1_sel, gpio_setting gpio_function);

#endif /* DRIVER_INCLUDE_GPIO_H_ */
