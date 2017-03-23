/*
 * max2828.c
 *
 *  Created on: 2017. gada 2. marts
 *      Author: Roberts
 */
#include "max2828.h"

#define reg_count   13 // number of configurable registers in max2828
#define reg_bits    14 // number of bits in max2828 conf. register
uint16_t userdef_settings[conf_block_size];
// Registers defined by user
// uint16_t user_reg[reg_count] = {0};

// Default register values of max2828
uint16_t default_reg[reg_count]=
{
    0b01000101000000, // R0
    0b00000011001010, // R1
    0b01000000000111, // R2
    0b11000011101000, // R3
    0b00110011001100, // R4
    0b01111101100011, // R5
    0b01110000000000, // R6
    0b00000000101010, // R7
    0b00000000100101, // R8
    0b00001000000000, // R9
    0b00001111000000, // R10
    0b00000001111111, // R11
    0b00000000000000  // R12
};

//Array in MCU's non-volatile FRAM memory to sotre RCS settings
#pragma PERSISTENT(default_settings)
#pragma NOINIT(userdef_settings)
uint16_t default_settings[conf_block_size] = {
        0b01000101000000, // R0
        0b00000011001010, // R1
        0b01000000000111, // R2
        0b11000011101000, // R3
        0b00110011001100, // R4
        0b01111101100011, // R5
        0b01110000000000, // R6
        0b00000000101010, // R7
        0b00000000100101, // R8
        0b00001000000000, // R9
        0b00001111000000, // R10
        0b00000001111111, // R11
        0b00000000000000, // R12
        0x00,
        0x00,
        0x00,
        0x00
};

unsigned char MAX2828_get_phase_lock_statuss(void)
{
    if (TXRX_LOCK_DET_PORT & TXRX_LOCK_DET_PIN) return 1;
    return 0;
}

unsigned char MAX2828_TX_set(unsigned char val)
{
    if (val == 1)
    {
        *TXRX_TX_EN_PORT |= TXRX_TX_EN_PIN;
        store_max2828_gpio_settings(1,1);
        return 0b01001101;
    } else
    if (val == 0)
    {
        *TXRX_TX_EN_PORT &= ~TXRX_TX_EN_PIN;
        store_max2828_gpio_settings(1,0);
        return 0b01001011;
    } else
    return 0;
}

//unsigned char MAX2828_RX_set(unsigned char val)
//{
//  if (val == 1)
//  {
//      TXRX_RX_EN_PORT |= TXRX_RX_EN_PIN;
//      //store_max2828_gpio_settings(1,1);
//      return 0b01001101;
//  } else
//  if (val == 0)
//  {
//      TXRX_RX_EN_PORT &= ~TXRX_RX_EN_PIN;
//      //store_max2828_gpio_settings(1,0);
//      return 0b01001011;
//  } else
//  return 0;
//}

unsigned char MAX2828_enable_set(unsigned char val)
{
    if (val == 1)
    {
        *TXRX_SHDN_PORT |= TXRX_SHDN_PIN;
        store_max2828_gpio_settings(2,1);
        return 0b01001001;
    } else
    if (val == 0)
    {
        *TXRX_SHDN_PORT &= ~TXRX_SHDN_PIN;
        store_max2828_gpio_settings(2,0);
        return 0b01001011;
    } else
    return 0;
}
/*
unsigned char MAX2828_TX_set_power(unsigned char value)
{
    unsigned char status_code = 0;
    if (value>127){
        status_code = 0b01000110;
    }
    else{
        if (value &0x1) MAX2828_pwr_set_port1 |= MAX2828_pwr_set_pin1; else MAX2828_pwr_set_port1 &= ~MAX2828_pwr_set_pin1;
        value = value>>1;
        if (value &0x1) MAX2828_pwr_set_port2 |= MAX2828_pwr_set_pin2; else MAX2828_pwr_set_port2 &= ~MAX2828_pwr_set_pin2;
        value = value>>1;
        if (value &0x1) MAX2828_pwr_set_port3 |= MAX2828_pwr_set_pin3; else MAX2828_pwr_set_port3 &= ~MAX2828_pwr_set_pin3;
        value = value>>1;
        if (value &0x1) MAX2828_pwr_set_port4 |= MAX2828_pwr_set_pin4; else MAX2828_pwr_set_port4 &= ~MAX2828_pwr_set_pin4;
        value = value>>1;
        if (value &0x1) MAX2828_pwr_set_port5 |= MAX2828_pwr_set_pin5; else MAX2828_pwr_set_port5 &= ~MAX2828_pwr_set_pin5;
        value = value>>1;
        if (value &0x1) MAX2828_pwr_set_port6 |= MAX2828_pwr_set_pin6; else MAX2828_pwr_set_port6 &= ~MAX2828_pwr_set_pin6;
        value = value>>1;
        if (value &0x1) MAX2828_pwr_set_port7 |= MAX2828_pwr_set_pin7; else MAX2828_pwr_set_port7 &= ~MAX2828_pwr_set_pin7;
        store_max2828_power_settings(&value);
        status_code = 0b01000111;
    }
    return status_code;
}
*/
//unsigned char MAX2828_set_tegister_values(unsigned char adress, unsigned char data_msb,unsigned char data_lsb)
unsigned char MAX2828_set_tegister_values(unsigned char adress, unsigned long int data)
{
    int i=0;
    unsigned char temp[18]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
//  if (adress>12 || data_msb>63) return 0b01011110;
    if (adress>12 || data>16383) return 0b01011110;
    data = data << 4;
    data |= adress;
    for (i=17;i>=0;i--){
            temp[17-i]=(data >> i) & 1;
    }
    *INT_SPI_TXRX_SS_PORT &= ~INT_SPI_TXRX_SS_PIN;
//  TA1CCR1 = 19;
//  unsigned char byte1 = (data_msb&0b110000)>>4;
//  unsigned char byte2 = ((data_msb&0b1111)<<4) | ((data_lsb&0b11110000)>>4);
//  unsigned char byte3 = ((data_lsb&0b1111)<<4) | (adress&0b1111);
    for (i=0;i<18;i++){
        if(temp[i]) *INT_SPI_MOSI_PORT |= INT_SPI_MOSI_PIN;
        else *INT_SPI_MOSI_PORT &= ~INT_SPI_MOSI_PIN;
        *INT_SPI_SCK_PORT ^= INT_SPI_SCK_PIN;
        if(temp[i]) *INT_SPI_MOSI_PORT |= INT_SPI_MOSI_PIN;
        else *INT_SPI_MOSI_PORT &= ~INT_SPI_MOSI_PIN;
        *INT_SPI_SCK_PORT ^= INT_SPI_SCK_PIN;
    }

//  SPI_RCS_send_byte(byte1);
//  SPI_RCS_send_byte(byte2);
//  SPI_RCS_send_byte(byte3);

    *INT_SPI_TXRX_SS_PORT |= INT_SPI_TXRX_SS_PIN;
//  TA1CCR1 = 0;
    *INT_SPI_MOSI_PORT &= ~INT_SPI_MOSI_PIN;

//  store_max2828_registers (&adress,&data_msb,&data_lsb);
    store_max2828_registers (&adress,&data);
    return 0b01011111;
}

unsigned char MAX2828_set_GPIO_stored (void)
{
    unsigned char temp = get_stored_settings(index_max2828_gpio);
    MAX2828_TX_set(temp&0x1);
    MAX2828_enable_set(temp&0b10>>1);
    return 1;
}
/*
unsigned char MAX2828_pwr_set_stored (void)
{
    MAX2828_TX_set_power(get_stored_settings(index_max2828_pwr));
    return 1;
}
*/
unsigned char MAX2828_set_registers_stored (void)
{
    unsigned char i = 0;
    for (i=0;i<13; i++)
    {
//  MAX2828_set_tegister_values(i,
//          get_stored_settings(index_max2828_reg1+i*2),
//          get_stored_settings(index_max2828_reg2+i*2));
    MAX2828_set_tegister_values(i, get_stored_settings(index_max2828_reg1+i*2));
    }
    return 1;
}

unsigned char store_max2828_power_settings (unsigned char* data)
{
    default_settings[index_max2828_pwr] = *data;
    return 1;
}

unsigned char store_max2828_gpio_settings (unsigned char bit_no, unsigned char state)
{
    //Clears or sets specified bit in register
    if (state) default_settings[index_max2828_gpio] |= (1<<bit_no); else default_settings[3] &= ~(1<<bit_no);
    return 1;
}

//unsigned char store_max2828_registers (unsigned char* register_no, unsigned char* data_msb, unsigned char* data_lsb)
unsigned char store_max2828_registers (unsigned char* register_no, unsigned long int* data)
{
    unsigned int offset = *register_no;
    default_settings[index_max2828_reg1+offset] =  *data;
    return 1;
}

/*********_END_OF_FILE_********/
