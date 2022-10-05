/*
 * max2828.h
 *
 *  Created on: 2017. gada 2. marts
 *      Author: Roberts
 */
#include <msp430.h>
#include <stdint.h>
#include "macros.h"
#include "pinmap.h"

#ifndef LIB_INCLUDE_MAX2828_H_
#define LIB_INCLUDE_MAX2828_H_

#define index_dac_msb       0
#define index_dac_lsb       1
#define index_max2828_pwr   2
#define index_max2828_gpio  3
#define index_max2828_reg1  4
#define conf_block_size     17
/*
typedef volatile struct {
   uint16_t reg1
} max2828_settings;
*/
unsigned char   MAX2828_get_phase_lock_statuss  (void);
unsigned char   MAX2828_TX_set                  (unsigned char);
unsigned char   MAX2828_RX_set                  (unsigned char);
unsigned char   MAX2828_enable_set              (unsigned char);
//unsigned char MAX2828_TX_set_power                (unsigned char);
//unsigned char MAX2828_set_tegister_values     (unsigned char,unsigned char,unsigned char);
unsigned char   MAX2828_set_tegister_values     (unsigned char, unsigned long int);

unsigned char   MAX2828_set_GPIO_stored         (void);
unsigned char   MAX2828_pwr_set_stored          (void);
unsigned char   MAX2828_set_registers_stored    (void);

unsigned char   store_max2828_power_settings    (unsigned char*);
unsigned char   store_max2828_gpio_settings     (unsigned char,unsigned char);
//unsigned char store_max2828_registers         (unsigned char*,unsigned char*,unsigned char*);
unsigned char   store_max2828_registers         (unsigned char*,unsigned long int*);

//Read stored RCS settings by accessing a single byte
//address specified in storage array
signed   char   get_stored_settings             (unsigned char);


#endif /* LIB_INCLUDE_MAX2828_H_ */
