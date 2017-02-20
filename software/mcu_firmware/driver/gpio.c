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
uint8_t GPIO_port_read(uint16_t gpio_pin, uint16_t gpio_input_reg){
	if(gpio_input_reg & gpio_pin){
		return 1;
	}
	return 0;
}

/***************************************************
 *
 **************************************************/
uint8_t GPIO_port_write(uint16_t gpio_pin, uint16_t gpio_output_reg, gpio_setting gpio_write){
	if(gpio_write == HIGH){
		gpio_output_reg |= gpio_pin;
	}
	else if(gpio_write == LOW){
		gpio_output_reg &= ~gpio_pin;
	}
	else{
		return 1;
	}
	return 0;
}

/***************************************************
 *
 **************************************************/
uint8_t GPIO_mode_set(uint16_t gpio_pin, uint16_t gpio_dir_reg, gpio_setting gpio_mode){
	if(gpio_mode == OUTPUT){
		gpio_dir_reg |= gpio_pin;
	}
	else if(gpio_mode == INPUT){
		gpio_dir_reg &= ~gpio_pin;
	}
	else{
		return 1;
	}
	return 0;
}

/***************************************************
 *
 **************************************************/
uint8_t GPIO_pull_set(uint16_t gpio_pin, uint16_t gpio_pullup_reg, gpio_setting gpio_pull){
	if(gpio_pull == PULL_ENABLE){
		gpio_pullup_reg |= gpio_pin;
	}
	else if(gpio_pull == PULL_DISABLE){
		gpio_pullup_reg &= ~gpio_pin;
	}
	else{
		return 1;
	}
	return 0;
}

/***************************************************
 *
 **************************************************/
uint8_t GPIO_function_set(uint16_t gpio_pin, uint16_t gpio_function0_sel, uint16_t gpio_function1_sel, gpio_setting gpio_function){
	if(gpio_function == FUNCTION0){
		gpio_function0_sel &= ~gpio_pin;
		gpio_function1_sel &= ~gpio_pin;
	}
	else if(gpio_function == FUNCTION1){
		gpio_function0_sel |= gpio_pin;
		gpio_function1_sel &= ~gpio_pin;
	}
	else if(gpio_function == FUNCTION2){
		gpio_function0_sel &= ~gpio_pin;
		gpio_function1_sel |= gpio_pin;
	}
	else if(gpio_function == FUNCTION3){
		gpio_function0_sel |= gpio_pin;
		gpio_function1_sel |= gpio_pin;
	}
	else{
		return 1;
	}
	return 0;
}
