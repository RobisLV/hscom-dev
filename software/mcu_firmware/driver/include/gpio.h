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
}gpio_setting;

uint16_t    GPIO_Port_Read     (uint16_t gpio_pin, uint16_t gpio_input_reg);
uint16_t    GPIO_Port_Write    (uint16_t gpio_pin, volatile uint8_t *gpio_output_reg, gpio_setting gpio_write);
uint16_t    GPIO_Mode_Set      (uint16_t gpio_pin, volatile uint8_t *gpio_dir_reg, gpio_setting gpio_mode);
uint16_t    GPIO_Pull_Set      (uint16_t gpio_pin, volatile uint8_t *gpio_pullup_reg, gpio_setting gpio_write);
uint16_t    GPIO_Function_Set  (uint16_t gpio_pin, volatile uint8_t *gpio_function0_sel, volatile uint8_t *gpio_function1_sel, gpio_setting gpio_function);

#endif /* DRIVER_INCLUDE_GPIO_H_ */
