//Arturs Orbidans, for Master's thesis
//RF daughterboard's functions

#ifndef PLAT_INCLUDE_RF_MB_H_
#define PLAT_INCLUDE_RF_MB_H_
// Standard libraries
#include <msp430.h>
#include <stdint.h>
#include "pinmap.h"
#include "gpio.h"
#include "clock.h"
#include "uart.h"
#include "dpuser.h"
#include "max2828.h"

unsigned char	ADC_init		(unsigned char);
uint16_t		ADC_get_sample	(unsigned char);
unsigned char	ADC_disable		(unsigned char);

unsigned char	DAC_set_value			(unsigned char,unsigned char);
unsigned char	DAC_set_stored_value	(void);

//unsigned char 	DAC_gset_set 		(unsigned char);
//unsigned char 	DAC_pdv_set 		(unsigned char);
//unsigned char 	DAC_pd_set 			(unsigned char);
//unsigned char 	DAC_standby_set 	(unsigned char);

uint16_t    GPIO_init               (void);
uint16_t    CS_init				    (void);
uint16_t    UART_A0_init            (void);
uint16_t    TMR_B0_init             (void);

unsigned char 	osc_set 						(unsigned char);
unsigned char	SPI_RCS_init					(void);					//Init SPI realised by eUSCI B0
unsigned char	SPI_RCS_send_byte				(unsigned char);

//void 			    display_main_menu				(void);
//void 			    display_error					(void);
//unsigned char 	UART_read_buffer 				(void);
//unsigned char 	UART_receive_byte_handle		(unsigned char in_value);

uint16_t  		bin_to_int						(unsigned char *array);
void 			cpy_array						(uint16_t *dst_array, uint16_t *src_array, uint8_t ARRAY_SIZE);
void 			print_bin						(uint16_t value, uint8_t bits);
//void			show_menu						(void);
#endif 
