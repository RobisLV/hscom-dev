/*
 * gpio.h
 *
 *  Created on: 2017. gada 17. febr.
 *      Author: Roberts
 */
#include <msp430.h>
#include <stdint.h>

#ifndef DRIVER_INCLUDE_GPIO_H_
#define DRIVER_INCLUDE_GPIO_H_

typedef enum gpio_setting{
	low,
	high,
	input,
	output,
	pull_enable,
	pull_disable,
	function0,
	function1,
	function2,
	function3,
	interrupt_enable,
	interrupt_edge,
	interrupt_flag,
} gpio_setting;

uint8_t gpio_port_read(uint16_t gpio_pin, uint16_t gpio_port);
uint8_t gpio_port_write(uint16_t gpio_pin, uint16_t gpio_port, gpio_setting gpio_write);
uint8_t gpio_mode_set(uint16_t gpio_pin, uint16_t gpio_dir, gpio_setting gpio_mode);
uint8_t gpio_pull_set(uint16_t gpio_pin, uint16_t gpio_pullup_reg, gpio_setting gpio_write);
uint8_t gpio_function_set(uint16_t gpio_pin, uint16_t gpio_function0_sel, uint16_t gpio_function1_sel, gpio_setting gpio_function);

#endif /* DRIVER_INCLUDE_GPIO_H_ */
