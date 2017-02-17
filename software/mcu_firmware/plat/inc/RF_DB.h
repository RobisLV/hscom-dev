//Arturs Orbidans, for Master's thesis
//RF daughterboard's functions

#ifndef PLAT_INC_RF_MB_H_
#define PLAT_INC_RF_MB_H_

#include <msp430.h>
#include <stdint.h>

unsigned char	ADC_init		(unsigned char);
uint16_t		ADC_get_sample	(unsigned char);
unsigned char	ADC_disable		(unsigned char);

unsigned char	DAC_set_value			(unsigned char,unsigned char);
unsigned char	DAC_set_stored_value	(void);

//unsigned char 	DAC_gset_set 		(unsigned char);
//unsigned char 	DAC_pdv_set 		(unsigned char);
//unsigned char 	DAC_pd_set 			(unsigned char);
//unsigned char 	DAC_standby_set 	(unsigned char);

unsigned char	MAX2828_get_phase_lock_statuss	(void);
unsigned char	MAX2828_TX_set					(unsigned char);
unsigned char	MAX2828_RX_set					(unsigned char);
unsigned char	MAX2828_enable_set				(unsigned char);
//unsigned char	MAX2828_TX_set_power				(unsigned char);
//unsigned char MAX2828_set_tegister_values		(unsigned char,unsigned char,unsigned char);
unsigned char	MAX2828_set_tegister_values		(unsigned char, unsigned long int);

unsigned char	MAX2828_set_GPIO_stored			(void);
unsigned char	MAX2828_pwr_set_stored			(void);
unsigned char	MAX2828_set_registers_stored		(void);

unsigned char 	init_pins						(void);					//Init MCU pins
unsigned char 	osc_set 						(unsigned char);
unsigned char	SPI_RCS_init					(void);					//Init SPI realised by eUSCI B0
unsigned char	SPI_RCS_send_byte				(unsigned char);

//Functions to store DAC, MAX2828 settings
//in case of brown out etc.
unsigned char	store_dac						(unsigned char*,unsigned char*);
unsigned char	store_max2828_power_settings	(unsigned char*);
unsigned char	store_max2828_gpio_settings		(unsigned char,unsigned char);
//unsigned char	store_max2828_registers			(unsigned char*,unsigned char*,unsigned char*);
unsigned char	store_max2828_registers			(unsigned char*,unsigned long int*);

//Read stored RCS settings by accessing a single byte
//address specified in storage array
signed	 char	get_stored_settings				(unsigned char);
//Other auxiliary functions
unsigned char	init_timer_b0					(void);

#endif 
