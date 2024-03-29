//Arturs Orbidans, for Master's thesis
//Functions to control ADC (get current sensor output) 

#include <hscom.h>

//Menu command numbers:
#define bin_mode        1
#define enable_chip     1
#define disable_chip    2
#define enable_tx       3
#define disable_tx      4
#define set_pwr         7
#define set_reg         8
#define get_phase_lck   9
#define stdby_high      11
#define stdby_low       12
#define osc_en          20
#define osc_dis         21
#define reset_settings  99
#define menu            0

unsigned char ADC_init(unsigned char pin){
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
uint16_t GPIO_init(void){
    // Set MCU status LED pin as output
	GPIO_mode_set(MCU_LED_STATUS_PIN, MCU_LED_STATUS_DIR, GPIO_OUTPUT);

	// Initialize SS pins for all SPI peripherals  as outputs
	GPIO_mode_set(INT_SPI_FLASH_SS_PIN, INT_SPI_FLASH_SS_DIR, GPIO_OUTPUT);
	GPIO_mode_set(INT_SPI_FPGA_SS_PIN, INT_SPI_FPGA_SS_DIR, GPIO_OUTPUT);
	GPIO_mode_set(INT_SPI_TXRX_SS_PIN, INT_SPI_TXRX_SS_DIR, GPIO_OUTPUT);
	GPIO_mode_set(INT_SPI_AF_SS_PIN, INT_SPI_AF_SS_DIR, GPIO_OUTPUT);

	// Set SPI A1 pins as inputs or outputs respectively
	GPIO_mode_set(INT_SPI_MISO_PIN, INT_SPI_MISO_DIR, GPIO_INPUT);
	GPIO_mode_set(INT_SPI_MOSI_PIN, INT_SPI_MOSI_DIR, GPIO_OUTPUT);
	GPIO_mode_set(INT_SPI_SCK_PIN, INT_SPI_SCK_DIR, GPIO_OUTPUT);

	// Set all SS pins as 1's (default - not active)
	GPIO_write(INT_SPI_FLASH_SS_PIN, INT_SPI_FLASH_SS_PORT, GPIO_HIGH);
	GPIO_write(INT_SPI_FPGA_SS_PIN, INT_SPI_FPGA_SS_PORT, GPIO_HIGH);
	GPIO_write(INT_SPI_TXRX_SS_PIN, INT_SPI_TXRX_SS_PORT, GPIO_HIGH);
	GPIO_write(INT_SPI_AF_SS_PIN, INT_SPI_AF_SS_PORT, GPIO_HIGH);

	// Default state of SPI data and clock lines is 0
	GPIO_write(INT_SPI_MOSI_PIN, INT_SPI_MOSI_PORT, GPIO_LOW);
	GPIO_write(INT_SPI_SCK_PIN, INT_SPI_SCK_PORT, GPIO_LOW);

	// Set MAX2828 lock-detect pin as input
	GPIO_mode_set(TXRX_LOCK_DET_PIN, TXRX_LOCK_DET_DIR, GPIO_INPUT);
	GPIO_pull_set(TXRX_LOCK_DET_PIN, TXRX_LOCK_DET_PULL, GPIO_PULL_DISABLE);

	// Other MAX2828 related pins settings
	GPIO_mode_set(TXRX_TX_EN_PIN, TXRX_TX_EN_DIR, GPIO_OUTPUT);
	GPIO_mode_set(TXRX_RX_EN_PIN, TXRX_RX_EN_DIR, GPIO_OUTPUT);
	GPIO_mode_set(TXRX_SHDN_PIN, TXRX_SHDN_DIR, GPIO_OUTPUT);
	GPIO_mode_set(TXRX_OSC_EN_PIN, TXRX_OSC_EN_DIR, GPIO_OUTPUT);

	// Keep the following pins low
	GPIO_write(TXRX_TX_EN_PIN, TXRX_TX_EN_PORT, GPIO_LOW);
	GPIO_write(TXRX_RX_EN_PIN, TXRX_RX_EN_PORT, GPIO_LOW);
	GPIO_write(TXRX_SHDN_PIN, TXRX_SHDN_PORT, GPIO_LOW);
	GPIO_write(TXRX_OSC_EN_PIN, TXRX_OSC_EN_PORT, GPIO_LOW);

	return EXIT_SUCCESS;
}

/*****************************************
 * Initialize Clock System (CS) registers
 ****************************************/
uint16_t CS_init(void){
	// Enable writing to CS registers
	CS_password(CS_PWD_SET);
	// Set DCO frequency
	CS_DCO_freq_set(CS_DCO_FSEL_8M);
    // Set LFMOD as auxilary clock source
	CS_ACLK_source_set(CS_LFMOD_CLK);
	// Set DCO as master clock source
	CS_MCLK_source_set(CS_DCO_CLK);
	// Set DCO as subsystem clock source
	CS_SMCLK_source_set(CS_DCO_CLK);
	// Set auxilary clock divider to 1
	CS_ACLK_divider_set(CS_DIV_1);
	// Set master clock divider to 1
	CS_MCLK_divider_set(CS_DIV_1);
	// Set subsystem clock divider to 1
	CS_SMCLK_divider_set(CS_DIV_1);
	// Disable writing to CS registers
	CS_password(CS_PWD_CLEAR);
	return EXIT_SUCCESS;
}

uint16_t UART_A0_init(void){
    // Put eUSCI in reset
    UART_A0_reset(UART_RESET_ENABLE);
    // Set pin functions that are used by USCI_A0 UART
    GPIO_function_set(MCU_RS485_RE_PIN , MCU_RS485_RO_FUNC0, MCU_RS485_RO_FUNC1, GPIO_FUNCTION2);
    GPIO_function_set(MCU_RS485_RO_PIN , MCU_RS485_RO_FUNC0, MCU_RS485_RO_FUNC1, GPIO_FUNCTION2);
    // Select EUSCI clock source
    UART_A0_EUSCI_clock(UART_SOURCE_SMCLK);
    // Set deglitch time to 200ns
    UART_A0_deglitch_time(UART_DEGLITCH_100NS);
    // Set modulation stage values ???
    UART_A0_modulation_stage_1(0x01 << 4);
    UART_A0_modulation_stage_2(0x49 << 8);
    // Prescale clock to select baudrate
    UART_A0_clock_prescale(13); // TODO: pie 8MHz clk jabut 52 lai dabutu 9600, bet realitate jaliek 13 (/4)
    UART_A0_oversampling(UART_OVERSAMPLE_ENABLE);
    // Enable RX interrupt
    UART_A0_RX_interrupt(UART_INTERRUPT_ENABLE);
    // Release eUSCI reset
    UART_A0_reset(UART_RESET_DISABLE);
    return EXIT_SUCCESS;
}

uint16_t SPI_A1_init(void){
    // eUSCI A1 SPI is set to 4-pin master mode, STE is automatically generated
    // enable reset to allow configuration of SPI
    SPI_A1_soft_reset(SPI_RESET_ENABLE);
    // set GPIOs in SPI function mode
    GPIO_function_set(INT_SPI_MISO_PIN,INT_SPI_MISO_FUNC0,INT_SPI_MISO_FUNC1,GPIO_FUNCTION2);
    GPIO_function_set(INT_SPI_MOSI_PIN,INT_SPI_MOSI_FUNC0,INT_SPI_MOSI_FUNC1,GPIO_FUNCTION2);
    GPIO_function_set(INT_SPI_SCK_PIN,INT_SPI_SCK_FUNC0,INT_SPI_SCK_FUNC1,GPIO_FUNCTION2);
    GPIO_function_set(INT_SPI_FLASH_SS_PIN,INT_SPI_FLASH_SS_FUNC0,INT_SPI_FLASH_SS_FUNC1,GPIO_FUNCTION2);
    // set eUSCI to synchronus (SPI) mode
    SPI_A1_STE_pin(SPI_STE_ENABLE);
    // set the clock edge used for data capture
    SPI_A1_clock_phase(SPI_CLK_LEADING);
    // put eUSCI in synchronus mode a.k.a. SPI
    SPI_A1_sync(SPI_MODE_SYNC);
    // set eUSCI A1 as master SPI device
    SPI_A1_mode(SPI_MASTER);
    // set SPI to 3-pin mode
    SPI_A1_EUSCI_mode(SPI_MODE_4PIN_AL);
    // select SMCLK as SPI clock source
    SPI_A1_clock_source(SPI_CLK_SOURCE_SMCLK);
    // set the most significant bit first
    SPI_A1_bit_order(SPI_MSB_FIRST);
    // prescale the SPI clock
    SPI_A1_clock_prescale(100);
    // release reset
    SPI_A1_soft_reset(SPI_RESET_DISABLE);
    // enable receive and transmit interrupts
    SPI_A1_RX_interrupt(SPI_INT_ENABLE);
    //SPI_A1_TX_interrupt(SPI_INT_ENABLE);
    return EXIT_SUCCESS;
}

uint16_t timer_A0_init(void){
    timer_A0_clock_source(TIMER_CLK_SOURCE_ACLK);
    // select timer clock divider
    timer_A0_clock_divider(TIMER_CLK_DIV_1);
    // set timer capture/compare value
    timer_A0_CC_value_write(0x4B4C);    // ACLK=5Mhz/128=39062.5Hz
    // enable capture/compare interrupts on TA0
    timer_A0_CC_interrupt(TIMER_INT_ENABLE);
    // set extended clock divider value
    timer_A0_clock_divider_exp(TIMER_EXTENDED_DIV_1);
    // clear timer value
    timer_A0_clear();
    // select the operating mode of timer
    timer_A0_mode(TIMER_MODE_COUNT_UP);
    return EXIT_SUCCESS;
}

uint16_t MSP430_Init(void){
    // Stop watchdog timer
    WDTCTL = WDTPW | WDTHOLD;
    // initialize clock system
    CS_init();
    // initialize GPIOs
    GPIO_init();
    // initialize UART of eUSCI A0
    UART_A0_init();
    // initialize SPI of eUSCI A1
    SPI_A1_init();
    // Disable the GPIO power-on default high-impedance mode to activate previously configured port settings
    PM5CTL0 &= ~LOCKLPM5;
    // initialize timer A0
    timer_A0_init();
    // global interrupt enable
    __bis_SR_register(GIE);
    dp_delay(500);
    // return success
    return EXIT_SUCCESS;
}

void MCU_LED_status_toggle(void){
   GPIO_toggle(MCU_LED_STATUS_PIN, MCU_LED_STATUS_PORT, MCU_LED_STATUS_IN);
   _delay_cycles(50000);
}

unsigned char osc_set (unsigned char val)
{
	if (val == 1) *TXRX_OSC_EN_PORT |= TXRX_OSC_EN_PIN; else
		if (val==0 )*TXRX_OSC_EN_PORT &= ~ TXRX_OSC_EN_PIN; else
			return 0;
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
