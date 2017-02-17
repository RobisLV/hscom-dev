//Arturs Orbidans, for Master's thesis
//Functions to control ADC (get current sensor output) 

#include "RF_DB.h"
#include "pinmap.h"
#include "dpuser.h"
#include "gpio.h"

unsigned char ADC_init(unsigned char pin){
	/*
	//Analogue inputs P1.0 and P1.1 are used
	P1SEL1 |= (BIT0 |BIT1);                          
	P1SEL0 |= (BIT0 |BIT1);
	
	// Configure ADC12
	ADC12CTL0 = ADC12SHT0_2 | ADC12ON;        	// Sampling time, S&H=16, ADC12 on
	ADC12CTL1 = ADC12SHP;                     	// Use sampling timer
	ADC12CTL2 |= ADC12RES_2;                  	// 12-bit conversion results
	if (pin == 0) ADC12MCTL0 |= ADC12INCH_0;	// ADC input select; Vref=AVCC
		else if (pin == 1) ADC12MCTL0 |= ADC12INCH_1;
			else return 0;

	return 1;
	*/

	//Analogue inputs P1.0 and P1.1 are used
	P1SEL1 |= (BIT0 |BIT1);
	P1SEL0 |= (BIT0 |BIT1);

	// Configure ADC12
	ADC12CTL0 = ADC12SHT0_2 | ADC12ON;        	// Sampling time, S&H=16, ADC12 on
	ADC12CTL1 = ADC12SHP;                     	// Use sampling timer
	ADC12CTL2 |= ADC12RES_2;                  	// 12-bit conversion results

	if (pin == 0) ADC12MCTL0 = ADC12INCH_2;	// ADC input select; Vref=AVCC
		else if (pin == 1) ADC12MCTL0 = ADC12INCH_3;
			else return 0;
	return 1;
}

uint16_t ADC_get_sample(unsigned char pin)
{
	/*
	ADC12CTL0 |= ADC12ENC | ADC12SC;
	while (!(ADC12CTL1&ADC12BUSY)) {};
	if (pin == 0) return ADC12MEM0;
		else if (pin == 1) return ADC12MEM1;
			else return 0;
			*/
	ADC12CTL0 |= ADC12ENC | ADC12SC;
	//while (!(ADC12CTL1&ADC12BUSY)) {};
	if (pin==0)
	{
	while (!(ADC12IFGR0&ADC12IFG0)) {};
	}
	else
	{
	while (!(ADC12IFGR0&ADC12IFG0)) {};
	};

	if (pin == 0) return ADC12MEM0;
		else if (pin == 1) return ADC12MEM0;
			else return 0;
}

unsigned char ADC_disable(unsigned char pin)
{
	ADC12CTL0 = 0; 
	return 1;
}

//unsigned char DAC_set_value(unsigned char data_msb, unsigned char data_lsb)
//{
//	static const unsigned char dac_register=0b00001111;
//
//	if (data_msb>15) return 0b00011110;
//	SPI_SS_DAC_port &= ~SPI_SS_DAC_pin;
//	//SPI_RCS_send_byte((dac_register<<4)|((data_msb&0b11110000)>>4));
//	SPI_RCS_send_byte((dac_register<<4)|((data_msb&0b00001111)));
//
//	SPI_RCS_send_byte(data_lsb);
//	SPI_SS_DAC_port |= SPI_SS_DAC_pin;
//
//	store_dac(&data_msb,&data_lsb);
//
//	return 0b00011111;
//}

//unsigned char DAC_set_stored_value(void)
//{
//	DAC_set_value(
//		get_stored_settings(index_dac_msb),
//		get_stored_settings(index_dac_lsb));
//	return 1;
//}


//unsigned char DAC_gset_set (unsigned char val)
//{
//	if (val == 1) DAC_gset_port |= DAC_gset_pin; else
//		if (val == 0 )DAC_gset_port &= ~ DAC_gset_pin; else
//			return 0;
//	return 1;
//}

//unsigned char DAC_pdv_set (unsigned char val)
//{
//	if (val == 1) DAC_pdv_port |= DAC_pdv_pin; else
//		if (val==0 )DAC_pdv_port &= ~ DAC_pdv_pin; else
//			return 0;
//	return 1;
//}

//unsigned char DAC_pd_set (unsigned char val)
//{
//	if (val == 1) DAC_pd_port |= DAC_pd_pin; else
//		if (val==0 )DAC_pd_port &= ~ DAC_pd_pin; else
//			return 0;
//	return 1;
//}

/*
unsigned char DAC_standby_set (unsigned char val)
{
	if (val == 1) DAC_standby_port |= DAC_standby_pin; else
		if (val==0 )DAC_standby_port &= ~ DAC_standby_pin; else
			return 0;
	return 1;
}
*/
unsigned char MAX2828_get_phase_lock_statuss(void)
{
	if (TXRX_LOCK_DET_PORT & TXRX_LOCK_DET_PIN) return 1;
	return 0;
}

unsigned char MAX2828_TX_set(unsigned char val)
{
	if (val == 1)
	{
		TXRX_TX_EN_PORT |= TXRX_TX_EN_PIN;
		store_max2828_gpio_settings(1,1);
		return 0b01001101;
	} else
	if (val == 0)
	{
		TXRX_TX_EN_PORT &= ~TXRX_TX_EN_PIN;
		store_max2828_gpio_settings(1,0);
		return 0b01001011;
	} else
	return 0;
}

//unsigned char MAX2828_RX_set(unsigned char val)
//{
//	if (val == 1)
//	{
//		TXRX_RX_EN_PORT |= TXRX_RX_EN_PIN;
//		//store_max2828_gpio_settings(1,1);
//		return 0b01001101;
//	} else
//	if (val == 0)
//	{
//		TXRX_RX_EN_PORT &= ~TXRX_RX_EN_PIN;
//		//store_max2828_gpio_settings(1,0);
//		return 0b01001011;
//	} else
//	return 0;
//}

unsigned char MAX2828_enable_set(unsigned char val)
{
	if (val == 1)
	{
		TXRX_SHDN_PORT |= TXRX_SHDN_PIN;
		store_max2828_gpio_settings(2,1);
		return 0b01001001;
	} else
	if (val == 0)
	{
		TXRX_SHDN_PORT &= ~TXRX_SHDN_PIN;
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
//	if (adress>12 || data_msb>63) return 0b01011110;
	if (adress>12 || data>16383) return 0b01011110;
	data = data << 4;
	data |= adress;
	for (i=17;i>=0;i--){
			temp[17-i]=(data >> i) & 1;
	}
	INT_SPI_TXRX_SS_PORT &= ~INT_SPI_TXRX_SS_PIN;
//	TA1CCR1 = 19;
//	unsigned char byte1 = (data_msb&0b110000)>>4;
//	unsigned char byte2 = ((data_msb&0b1111)<<4) | ((data_lsb&0b11110000)>>4);
//	unsigned char byte3 = ((data_lsb&0b1111)<<4) | (adress&0b1111);
	for (i=0;i<18;i++){
		if(temp[i]) INT_SPI_MOSI_PORT |= INT_SPI_MOSI_PIN;
		else INT_SPI_MOSI_PORT &= ~INT_SPI_MOSI_PIN;
		INT_SPI_SCK_PORT ^= INT_SPI_SCK_PIN;
		if(temp[i]) INT_SPI_MOSI_PORT |= INT_SPI_MOSI_PIN;
		else INT_SPI_MOSI_PORT &= ~INT_SPI_MOSI_PIN;
		INT_SPI_SCK_PORT ^= INT_SPI_SCK_PIN;
	}

//	SPI_RCS_send_byte(byte1);
//	SPI_RCS_send_byte(byte2);
//	SPI_RCS_send_byte(byte3);

	INT_SPI_TXRX_SS_PORT |= INT_SPI_TXRX_SS_PIN;
//	TA1CCR1 = 0;
	INT_SPI_MOSI_PORT &= ~INT_SPI_MOSI_PIN;

//	store_max2828_registers (&adress,&data_msb,&data_lsb);
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
//	MAX2828_set_tegister_values(i,
//			get_stored_settings(index_max2828_reg1+i*2),
//			get_stored_settings(index_max2828_reg2+i*2));
	MAX2828_set_tegister_values(i, get_stored_settings(index_max2828_reg1+i*2));
	}
	return 1;
}

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
uint16_t userdef_settings[conf_block_size];

struct chip_conf
{
	//uint16_t max2828_reg[13];
	uint16_t max2828_pin;
	uint8_t max2828_pwr;
	uint8_t dac2932_pin;
}ch_conf;

#pragma PERSISTENT(test_struct)
struct chip_conf test_struct =
{
		.max2828_pin = 0x05,
		.max2828_pwr = 0x45
};

uint8_t gpio_init()
{
	// Init SS pins for all SPI peripherals  as outputs
	gpio_mode_set(INT_SPI_FLASH_SS_PIN, INT_SPI_FLASH_SS_DIR, output);
	gpio_mode_set(INT_SPI_FPGA_SS_PIN, INT_SPI_FPGA_SS_DIR, output);
	gpio_mode_set(INT_SPI_TXRX_SS_PIN, INT_SPI_TXRX_SS_DIR, output);
	gpio_mode_set(INT_SPI_AF_SS_PIN, INT_SPI_AF_SS_DIR, output);

	gpio_mode_set(INT_SPI_MOSI_PIN, INT_SPI_MOSI_DIR, output);
	gpio_mode_set(INT_SPI_SCK_PIN, INT_SPI_SCK_DIR, output);

	// Set all SS pins as 1's (default - not active)
	gpio_port_write(INT_SPI_FLASH_SS_PIN, INT_SPI_FLASH_SS_PORT, high);
	gpio_port_write(INT_SPI_FPGA_SS_PIN, INT_SPI_FPGA_SS_PORT, high);
	gpio_port_write(INT_SPI_TXRX_SS_PIN, INT_SPI_TXRX_SS_PORT, high);
	gpio_port_write(INT_SPI_AF_SS_PIN, INT_SPI_AF_SS_PORT, high);

	// Default state of SPI data and clock lines is 0
	gpio_port_write(INT_SPI_MOSI_PIN, INT_SPI_MOSI_PORT, low);
	gpio_port_write(INT_SPI_SCK_PIN, INT_SPI_SCK_PORT, low);

	// Set MAX2828 lock-detect pin as input
	gpio_mode_set(TXRX_LOCK_DET_PIN, TXRX_LOCK_DET_DIR, input);
	gpio_pull_set(TXRX_LOCK_DET_PIN, TXRX_LOCK_DET_PULL, pull_disable);

	// Other MAX2828 related pins settings
	gpio_mode_set(TXRX_TX_EN_PIN, TXRX_TX_EN_DIR, output);
	gpio_mode_set(TXRX_RX_EN_PIN, TXRX_RX_EN_DIR, output);
	gpio_mode_set(TXRX_SHDN_PIN, TXRX_SHDN_DIR, output);
	gpio_mode_set(TXRX_OSC_EN_PIN, TXRX_OSC_EN_DIR, output);

	// Keep the following pins low
	gpio_port_write(TXRX_TX_EN_PIN, TXRX_TX_EN_PORT, low);
	gpio_port_write(TXRX_RX_EN_PIN, TXRX_RX_EN_PORT, low);
	gpio_port_write(TXRX_SHDN_PIN, TXRX_SHDN_PORT, low);
	gpio_port_write(TXRX_OSC_EN_PIN, TXRX_OSC_EN_PORT, low);

	return 0;
}

unsigned char osc_set (unsigned char val)
{
	if (val == 1) TXRX_OSC_EN_PORT |= TXRX_OSC_EN_PIN; else
		if (val==0 )TXRX_OSC_EN_PORT &= ~ TXRX_OSC_EN_PIN; else
			return 0;
	return 1;
}

unsigned char SPI_RCS_init()
{
	P1SEL1 |= BIT6;
	P1SEL0 &= ~BIT6;

	P2SEL1 |= BIT2;
	P2SEL0 &= ~BIT2;
	P1DIR |= BIT6;

	UCB0CTLW0 |=UCSWRST;
	UCB0CTLW0 |= UCSYNC;
	UCB0CTLW0 = UCMST | UCMODE_0 | UCSSEL_2 | UCMSB;
	UCB0BRW = 100;
	UCB0CTLW0 &= ~UCSWRST;

	return 1;
}

unsigned char SPI_RCS_send_byte(unsigned char data)
{
	//Send a byte via SPI when SPI is ready for TX
	while (UCB0STATW & UCBUSY) {};
	UCB0TXBUF = data;
	while (UCB0STATW & UCBUSY) {};

	return 1;
}

unsigned char store_dac(unsigned char* data_msb, unsigned char* data_lsb)
{
	default_settings[index_dac_msb] = *data_msb;
	default_settings[index_dac_lsb] = *data_lsb;
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
	default_settings[index_max2828_reg1+offset]	=  *data;
	return 1;
}

signed char get_stored_settings (unsigned char requested_byte)
{
	if (requested_byte > conf_block_size-1)
		{
			#ifdef ENABLE_DISPLAY
			dp_display_text("Incorrect index!");
			#endif
			return -1;
		}
	return default_settings[requested_byte];
}


//Timer B0 counts up to 10; needed for timing of the pause in
unsigned char init_timer_b0 (void)
{
	TB0R = 0;
	TB0CTL = TBSSEL_1 | MC_1 | ID_3 ; //Clk - ACLK, DIV 8
	TB0CCR0 = 10;
	TB0CCTL0 = CCIE;				 //Enale interrupts
	TB0EX0 = TBIDEX_7;				 //Clk DIV 8

	return 1;
}
