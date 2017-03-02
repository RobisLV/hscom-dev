//Arturs Orbidans, for Master's thesis
//Functions to control ADC (get current sensor output) 

#include "RF_DB.h"

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
//	if (adress>12 || data_msb>63) return 0b01011110;
	if (adress>12 || data>16383) return 0b01011110;
	data = data << 4;
	data |= adress;
	for (i=17;i>=0;i--){
			temp[17-i]=(data >> i) & 1;
	}
	*INT_SPI_TXRX_SS_PORT &= ~INT_SPI_TXRX_SS_PIN;
//	TA1CCR1 = 19;
//	unsigned char byte1 = (data_msb&0b110000)>>4;
//	unsigned char byte2 = ((data_msb&0b1111)<<4) | ((data_lsb&0b11110000)>>4);
//	unsigned char byte3 = ((data_lsb&0b1111)<<4) | (adress&0b1111);
	for (i=0;i<18;i++){
		if(temp[i]) *INT_SPI_MOSI_PORT |= INT_SPI_MOSI_PIN;
		else *INT_SPI_MOSI_PORT &= ~INT_SPI_MOSI_PIN;
		*INT_SPI_SCK_PORT ^= INT_SPI_SCK_PIN;
		if(temp[i]) *INT_SPI_MOSI_PORT |= INT_SPI_MOSI_PIN;
		else *INT_SPI_MOSI_PORT &= ~INT_SPI_MOSI_PIN;
		*INT_SPI_SCK_PORT ^= INT_SPI_SCK_PIN;
	}

//	SPI_RCS_send_byte(byte1);
//	SPI_RCS_send_byte(byte2);
//	SPI_RCS_send_byte(byte3);

	*INT_SPI_TXRX_SS_PORT |= INT_SPI_TXRX_SS_PIN;
//	TA1CCR1 = 0;
	*INT_SPI_MOSI_PORT &= ~INT_SPI_MOSI_PIN;

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

/*****************************************
 * Initialize GPIOs
 ****************************************/
uint8_t GPIO_Init(){
    // Set MCU status LED pin as output
	GPIO_Mode_Set(MCU_LED_STATUS_PIN, MCU_LED_STATUS_DIR, OUTPUT);

	// Initialize SS pins for all SPI peripherals  as outputs
	GPIO_Mode_Set(INT_SPI_FLASH_SS_PIN, INT_SPI_FLASH_SS_DIR, OUTPUT);
	GPIO_Mode_Set(INT_SPI_FPGA_SS_PIN, INT_SPI_FPGA_SS_DIR, OUTPUT);
	GPIO_Mode_Set(INT_SPI_TXRX_SS_PIN, INT_SPI_TXRX_SS_DIR, OUTPUT);
	GPIO_Mode_Set(INT_SPI_AF_SS_PIN, INT_SPI_AF_SS_DIR, OUTPUT);

	GPIO_Mode_Set(INT_SPI_MOSI_PIN, INT_SPI_MOSI_DIR, OUTPUT);
	GPIO_Mode_Set(INT_SPI_SCK_PIN, INT_SPI_SCK_DIR, OUTPUT);

	// Set all SS pins as 1's (default - not active)
	GPIO_Port_Write(INT_SPI_FLASH_SS_PIN, INT_SPI_FLASH_SS_PORT, HIGH);
	GPIO_Port_Write(INT_SPI_FPGA_SS_PIN, INT_SPI_FPGA_SS_PORT, HIGH);
	GPIO_Port_Write(INT_SPI_TXRX_SS_PIN, INT_SPI_TXRX_SS_PORT, HIGH);
	GPIO_Port_Write(INT_SPI_AF_SS_PIN, INT_SPI_AF_SS_PORT, HIGH);

	// Default state of SPI data and clock lines is 0
	GPIO_Port_Write(INT_SPI_MOSI_PIN, INT_SPI_MOSI_PORT, LOW);
	GPIO_Port_Write(INT_SPI_SCK_PIN, INT_SPI_SCK_PORT, LOW);

	// Set MAX2828 lock-detect pin as input
	GPIO_Mode_Set(TXRX_LOCK_DET_PIN, TXRX_LOCK_DET_DIR, INPUT);
	GPIO_Pull_Set(TXRX_LOCK_DET_PIN, TXRX_LOCK_DET_PULL, PULL_DISABLE);

	// Other MAX2828 related pins settings
	GPIO_Mode_Set(TXRX_TX_EN_PIN, TXRX_TX_EN_DIR, OUTPUT);
	GPIO_Mode_Set(TXRX_RX_EN_PIN, TXRX_RX_EN_DIR, OUTPUT);
	GPIO_Mode_Set(TXRX_SHDN_PIN, TXRX_SHDN_DIR, OUTPUT);
	GPIO_Mode_Set(TXRX_OSC_EN_PIN, TXRX_OSC_EN_DIR, OUTPUT);

	// Keep the following pins low
	GPIO_Port_Write(TXRX_TX_EN_PIN, TXRX_TX_EN_PORT, LOW);
	GPIO_Port_Write(TXRX_RX_EN_PIN, TXRX_RX_EN_PORT, LOW);
	GPIO_Port_Write(TXRX_SHDN_PIN, TXRX_SHDN_PORT, LOW);
	GPIO_Port_Write(TXRX_OSC_EN_PIN, TXRX_OSC_EN_PORT, LOW);

	return 0;
}

/*****************************************
 * Initialize Clock System (CS) registers
 ****************************************/
uint16_t Clock_Init(void){
	// Enable writing to CS registers
	CS_Password(PWD_SET);
	// Set DCO frequency
	CS_DCO_Freq_Set(DCO_FSEL_8M);
    // Set LFMOD as auxilary clock source
	CS_ACLK_Source_Set(LFMOD_CLK);
	// Set DCO as master clock source
	CS_MCLK_Source_Set(DCO_CLK);
	// Set DCO as subsystem clock source
	CS_SMCLK_Source_Set(DCO_CLK);
	// Set auxilary clock divider to 1
	CS_ACLK_Divider_Set(DIV_1);
	// Set master clock divider to 1
	CS_MCLK_Divider_Set(DIV_1);
	// Set subsystem clock divider to 1
	CS_SMCLK_Divider_Set(DIV_1);
	// Disable writing to CS registers
	CS_Password(PWD_CLEAR);
	return 0;
}

uint16_t UART_A0_Init(void){
    // Set pin functions that are used by USCI_A0 UART
    GPIO_Function_Set(MCU_RS485_RE_PIN , MCU_RS485_RO_FUNC0, MCU_RS485_RO_FUNC1, FUNCTION2);
    GPIO_Function_Set(MCU_RS485_RO_PIN , MCU_RS485_RO_FUNC0, MCU_RS485_RO_FUNC1, FUNCTION2);
    // Put eUSCI in reset
    UART_Reset(RESET_ENABLE);
    // Select EUSCI clock source
    UART_EUSCI_Clock(SOURCE_SMCLK);
    // Set deglitch time to 200ns
    UART_Deglitch_Time(DEGLITCH_200NS);
    // Set modulation stage values ???
    UART_Modulation_Stage_1(0x01 << 4);
    UART_Modulation_Stage_2(0x49 << 8);
    // Prescale clock to select baudrate
    UART_Clock_Prescale(52); // TODO: pie 8MHz clk jabut 52 lai dabutu 9600, bet realitate jaliek 13 (/4)
    UART_Oversampling(OVERSAMPLING_ENABLE);
    // Enable RX interrupt
    UART_RX_Interrupt(RX_INTERRUPT_ENABLE);
    // Release eUSCI reset
    UART_Reset(RESET_DISABLE);
    return 0;
}

unsigned char osc_set (unsigned char val)
{
	if (val == 1) *TXRX_OSC_EN_PORT |= TXRX_OSC_EN_PIN; else
		if (val==0 )*TXRX_OSC_EN_PORT &= ~ TXRX_OSC_EN_PIN; else
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

void display_main_menu(void)
{
    dp_display_text("\r\n\r\n\t\t--------Main menu--------");
    dp_display_text("\r\n---MAX2828 related---\t\t---DAC related---");
    dp_display_text("\r\n01 ENABLE CHIP\t\t\t10 SET DAC REGISTER");
    dp_display_text("\r\n02 DISABLE CHIP\t\t\t11 DAC: SET STANDBY HIGH");
    dp_display_text("\r\n03 ENABLE TX\t\t\t12 DAC: SET STANDBY LOW");
    dp_display_text("\r\n04 DISABLE TX\t\t\t13 DAC: SET GSET HIGH");
    dp_display_text("\r\n05 ENABLE RX\t\t\t14 DAC: SET GSET LOW");
    dp_display_text("\r\n06 DISABLE RX\t\t\t15 DAC: SET PDV HIGH");
    dp_display_text("\r\n07 SET TX GAIN\t\t\t16 DAC: SET PDV LOW");
    dp_display_text("\r\n08 SET REGISTERS\t\t17 DAC: SET PD HIGH");
    dp_display_text("\r\n09 GET PHASE LOCK PIN STAT\t18 DAC: SET PD LOW");
    dp_display_text("\r\n\t\t------Other------");
    dp_display_text("\r\n\t\t19 READ ADC");
    dp_display_text("\r\n\t\t20 ENABLE OSC");
    dp_display_text("\r\n\t\t21 DISABLE OSC");
    dp_display_text("\r\n\t\t99 RESTORE PREV SETTINGS");
    dp_display_text("\r\n\t\t00 DISPLAY MAIN MENU\r\n");
}

void display_error(void)
{
	dp_display_text("\r\n--->Error");
}
/*
uint16_t get_number(char mode){
	unsigned char j=0;
    unsigned char input_array[16]={0};
    //for (j=0;j<16;j++) input_array[j]=0;
    unsigned char input_char = 0;
    //j=0;

	while(1)
	{
		_BIS_SR(LPM0_bits + GIE); 				//GOTO sleep
	    input_char = UART_read_buffer();
	    if (input_char != 13) input_array[j] = input_char; else
	    {
	    	input_array[j] = '\0';
	    	break;
	    }
	    j++;
	}
	if (mode == DEC)
		return atoi(input_array);
	else
		return bin_to_int(input_array);
}
*/
//Convert char array representing binary number into uint16_t
uint16_t  bin_to_int(unsigned char *array){
	uint16_t res = 0;
	uint16_t weight = 1;
	char size=0;
	char index = 0;
	while (array[index++]) size++;
	for (index=size; index>0; index-- )
	{
		if (array[index-1]-48) res += weight;
		weight=weight<<1;
	}
	return res;
}

// Function for coping arrays
void cpy_array(uint16_t *dst_array, uint16_t *src_array, uint8_t ARRAY_SIZE){
    int i;
    for (i = 0; i != ARRAY_SIZE; ++i){
            dst_array[i] = src_array[i];
    }
}

void print_bin(uint16_t value, uint8_t bits){
    int i;
    for(i=bits-1; i>=0 ; i--){
        if(((value>>i) & 0x01)==1){
        	dp_display_text("1");
        }
        else{
        	dp_display_text("0");
        }
    }
}
/*
unsigned char UART_read_buffer (void)
{
	if (rx_a0_buffer_index)
	{
	unsigned char temp = UART_RX_BUFFER[0];
	unsigned int i = 0;
	for (i=0; i<UART_RX_BUFFER_SIZE; i++)
		{UART_RX_BUFFER[i] = UART_RX_BUFFER[i+1];};
	rx_a0_buffer_index--;
	return  temp;
	}
	return UART_RX_BUFFER[0];
}
*/
/*
unsigned char UART_receive_byte_handle(unsigned char in_value)
{
	uart_a0_send_byte(in_value); //echo
	//add byte to UART RX buffer
	if ((rx_a0_buffer_index+1)==UART_RX_BUFFER_SIZE) rx_a0_buffer_index = 0;
	UART_RX_BUFFER[rx_a0_buffer_index++] = in_value;
	return 1;
}
*/
/*
void show_menu(uint8_t action_code){
	dp_display_text("\r\nEnter action code & press enter: ");

	action_code = get_number(DEC);
	switch(action_code)
	{
	case menu:
		//Display main menu
		display_main_menu();
		break;
	case enable_chip:
		//Enable chip (power on)
		if (MAX2828_enable_set(1) == 0b01001001)
			dp_display_text("\r\n--->Chip enabled");
		else
			display_error();
		break;
	case disable_chip:
		//Disable chip (power off)
		if (MAX2828_enable_set(0) == 0b01001011)
			dp_display_text("\r\n--->Chip disabled");
		else
			display_error();
		break;
	case enable_tx:
		//Enable TX
		if (MAX2828_TX_set(1) == 0b01001101)
			dp_display_text("\r\n--->TX on");
		else
			dp_display_text("\r\n--->Error");
		break;
	case disable_tx:
		//Disable TX
		if (MAX2828_TX_set(0) == 0b01001011)
			dp_display_text("\r\n--->TX off");
		else
			dp_display_text("\r\n--->Error");
		break;
	//    case enable_rx:
	//        //Enable RX
	//        if (MAX2828_RX_set(1) == 0b01001101)
	//        	dp_display_text("\r\n--->RX on");
	//        else
	//        	display_error();
	//        break;
	//    case disable_rx:
	//        //Disable RX
	//        if (MAX2828_RX_set(0) == 0b01001011)
	//        	dp_display_text("\r\n--->RX off");
	//        else
	//        	display_error();
	//        break;
	case set_pwr:
		dp_display_text("\r\n--->Type TX gain  [0;127] & press enter: ");
		temp = get_number(DEC);

		if (MAX2828_TX_set_power(temp)==0b01000111)
		{
			dp_display_text("\r\n--->TX gain set to: ");
			dp_display_value(temp,DEC);
		}
		else
			display_error();

		break;
	case set_reg:
		dp_display_text("\r\n--->Type MAX2828 register adress [0;12] & press enter: ");
		temp = get_number(DEC);	//Adr
		dp_display_text("\r\n--->Type MAX2828 register 14 bit binary val & press enter: ");
		in_val = get_number(BIN);
		temp2 = in_val>>8;		//MSB
		temp3 = in_val&0xff;	//LSB

		if (MAX2828_set_tegister_values(temp,in_val)==0b01011111)
		{
			dp_display_text("\r\n--->MAX2828 register ");
			dp_display_value(temp,DEC);
			dp_display_text(" is set to value: ");
			dp_display_value(temp2<<8|temp3,DEC);
			dp_display_text(" = ");
			dp_display_value(temp2<<8|temp3,BIN);
		}
		else
			display_error();
		break;

	case get_phase_lck:
		dp_display_text("\r\n--->MAX282 phase lock: ");
		if (MAX2828_get_phase_lock_statuss())
			dp_display_text("Locked");
		else
			dp_display_text("not locked");
		break;

	case stdby_low:
		//DAC STANDBY set to 0

		if (DAC_standby_set(0))
			dp_display_text("\r\n--->DAC STANDBY=0");
		else
			display_error();

		break;
	case stdby_high:
		//DAC STANDBY set to 1

		if (DAC_standby_set(1))
			dp_display_text("\r\n--->DAC STANDBY=1");
		else
			display_error();

		break;
	case reset_settings:
		dp_display_text("\r\nREG\tHEX\tBIN");
		for(k=0;k<reg_count;k++){
			if (MAX2828_set_tegister_values(k,default_reg[k])==0b01011111)
			{
				dp_display_text("\r\nR"); dp_display_value(k,DEC);
				dp_display_text("\t");
				//dp_display_value(default_reg[k],DEC);
				dp_display_text("\t");
				print_bin(default_reg[k],14);
				//dp_display_value(default_reg[k],BIN);
			}
			else{
				display_error();
			}
		}
		dp_display_text("\r\n--->Default register settings restored.");
		dp_display_text("PS This function is not ready! a.o.");
		break;
	case osc_dis:
		//Disable oscillator
		if (osc_set(0))
			dp_display_text("\r\n--->OSC DISABLED");
		else
			display_error();
		break;
	case osc_en:
		//Enable oscillator
		if (osc_set(1))
			dp_display_text("\r\n--->OSC ENABLED");
		else
			display_error();
		break;
	default:
		dp_display_text("\r\n--->Error");
		break;
	}
	action_code = 0;
	temp2 = 0;
	temp3 = 0;
}
*/
