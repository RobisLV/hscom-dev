/*
 * gpio.c
 *
 *  Created on: 2017. gada 17. febr.
 *      Author: Roberts
 */
#include "gpio.h"

/***************************************************
 *
 **************************************************/
uint16_t GPIO_port_read(uint16_t gpio_pin, uint16_t gpio_input_reg){
	if(gpio_input_reg & gpio_pin){
		return 1;
	}
	return 0;
}

/***************************************************
 *
 **************************************************/
uint16_t GPIO_port_write(uint16_t gpio_pin, volatile uint8_t *gpio_output_reg, gpio_setting gpio_write){
	if(gpio_write == GPIO_LOW){
		*gpio_output_reg&=~gpio_pin;
	}
	else if (gpio_write == GPIO_HIGH){
		*gpio_output_reg|=gpio_pin;
	}
	else{
		return 1;
	}
	return 0;
}

/***************************************************
 *
 **************************************************/
uint16_t GPIO_mode_set(uint16_t gpio_pin, volatile uint8_t *gpio_dir_reg, gpio_setting gpio_mode){
	if(gpio_mode == GPIO_OUTPUT){
		*gpio_dir_reg |= gpio_pin;
	}
	else if(gpio_mode == GPIO_INPUT){
		*gpio_dir_reg &= ~gpio_pin;
	}
	else{
		return 1;
	}
	return 0;
}

/***************************************************
 *
 **************************************************/
uint16_t GPIO_pull_set(uint16_t gpio_pin, volatile uint8_t *gpio_pullup_reg, gpio_setting gpio_pull){
	if(gpio_pull == GPIO_PULL_ENABLE){
		*gpio_pullup_reg |= gpio_pin;
	}
	else if(gpio_pull == GPIO_PULL_DISABLE){
		*gpio_pullup_reg &= ~gpio_pin;
	}
	else{
		return 1;
	}
	return 0;
}

/***************************************************
 *
 **************************************************/
uint16_t GPIO_function_set(uint16_t gpio_pin,volatile uint8_t *gpio_function0_sel, volatile uint8_t *gpio_function1_sel, gpio_setting gpio_function){
	if(gpio_function == GPIO_FUNCTION0){
		*gpio_function0_sel &= ~gpio_pin;
		*gpio_function1_sel &= ~gpio_pin;
	}
	else if(gpio_function == GPIO_FUNCTION1){
		*gpio_function0_sel |= gpio_pin;
		*gpio_function1_sel &= ~gpio_pin;
	}
	else if(gpio_function == GPIO_FUNCTION2){
		*gpio_function0_sel &= ~gpio_pin;
		*gpio_function1_sel |= gpio_pin;
	}
	else if(gpio_function == GPIO_FUNCTION3){
		*gpio_function0_sel |= gpio_pin;
		*gpio_function1_sel |= gpio_pin;
	}
	else{
		return 1;
	}
	return 0;
}

/*********_END_OF_FILE_********/
