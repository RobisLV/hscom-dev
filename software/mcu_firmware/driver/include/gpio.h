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
	LOW,
	HIGH,
	INPUT,
	OUTPUT,
	PULL_ENABLE,
	PULL_DISABLE,
	FUNCTION0,
	FUNCTION1,
	FUNCTION2,
	FUNCTION3,
	INTERRUPT_ENABLE,
	INTERRUPT_EDGE,
	INTERRUPT_FLAG,
} gpio_setting;

uint8_t GPIO_port_read(uint16_t gpio_pin, uint16_t gpio_input_reg);
uint8_t GPIO_port_write(uint16_t gpio_pin, uint16_t gpio_output_reg, gpio_setting gpio_write);
uint8_t GPIO_mode_set(uint16_t gpio_pin, uint16_t gpio_dir_reg, gpio_setting gpio_mode);
uint8_t GPIO_pull_set(uint16_t gpio_pin, uint16_t gpio_pullup_reg, gpio_setting gpio_write);
uint8_t GPIO_function_set(uint16_t gpio_pin, uint16_t gpio_function0_sel, uint16_t gpio_function1_sel, gpio_setting gpio_function);

#endif /* DRIVER_INCLUDE_GPIO_H_ */
