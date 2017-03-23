/*
 * uart.c
 *
 *  Created on: 2017. gada 22. febr.
 *      Author: Roberts
 */
#include "uart.h"

/***************************************************
 *
 **************************************************/
uint16_t UART_A0_parity(uart_setting uart_parity){
    if(uart_parity == UART_PARITY_ENABLE){
        MASK_SET(UCA0CTLW0, UCPEN);
    }
    else if(uart_parity == UART_PARITY_DISABLE){
        MASK_CLEAR(UCA0CTLW0, UCPEN);
    }
    else{
        return 1;
    }
    return 0;
}

/***************************************************
 *
 **************************************************/
uint16_t UART_A0_parity_mode(uart_setting uart_parity){
    if(uart_parity == UART_PARITY_ODD){
        MASK_SET(UCA0CTLW0, UCPAR);
    }
    else if(uart_parity == UART_PARITY_EVEN){
        MASK_CLEAR(UCA0CTLW0, UCPAR);
    }
    else{
        return 1;
    }
    return 0;
}

/***************************************************
 *
 **************************************************/
uint16_t UART_A0_bit_order(uart_setting uart_first_bits){
    if(uart_first_bits == UART_MSB_FIRST){
        MASK_SET(UCA0CTLW0, UCMSB);
    }
    else if(uart_first_bits == UART_LSB_FIRST){
        MASK_CLEAR(UCA0CTLW0, UCMSB);
    }
    else{
        return 1;
    }
    return 0;
}

/***************************************************
 *
 **************************************************/
uint16_t UART_A0_char_length(uart_setting uart_char_length){
    if(uart_char_length == UART_CHAR_8BIT){
        MASK_SET(UCA0CTLW0, UC7BIT);
    }
    else if(uart_char_length == UART_CHAR_7BIT){
        MASK_CLEAR(UCA0CTLW0, UC7BIT);
    }
    else{
        return 1;
    }
    return 0;
}

/***************************************************
 *
 **************************************************/
uint16_t UART_A0_stop_bits(uart_setting uart_stop_bits){
    if(uart_stop_bits==UART_STOP_2BIT){
        MASK_SET(UCA0CTLW0, UCSPB);
    }
    else if(uart_stop_bits==UART_STOP_1BIT){
        MASK_CLEAR(UCA0CTLW0, UCSPB);
    }
    else{
        return 1;
    }
    return 0;
}

/***************************************************
 *
 **************************************************/
uint16_t UART_A0_EUSCI_mode(uart_setting uart_eusci_mode){
    // Clear any previusly set bits
    MASK_CLEAR(UCA0CTLW0, UCMODE0|UCMODE1);

    if(uart_eusci_mode == UART_EUSCI_MODE_0){
        MASK_SET(UCA0CTLW0, UCMODE_0);
    }
    else if(uart_eusci_mode == UART_EUSCI_MODE_1){
        MASK_SET(UCA0CTLW0, UCMODE_1);
    }
    else if(uart_eusci_mode == UART_EUSCI_MODE_2){
        MASK_SET(UCA0CTLW0, UCMODE_2);
    }
    else if(uart_eusci_mode == UART_EUSCI_MODE_3){
        MASK_SET(UCA0CTLW0, UCMODE_3);
    }
    else{
        return 1;
    }
    return 0;
}

/***************************************************
 *
 **************************************************/
uint16_t UART_A0_sync_mode(uart_setting uart_eusci_sync){
    if(uart_eusci_sync == UART_MODE_ASYNC){
        MASK_SET(UCA0CTLW0, UCSYNC);
    }
    else if(uart_eusci_sync == UART_MODE_SYNC){
        MASK_CLEAR(UCA0CTLW0, UCSYNC);
    }
    else{
        return 1;
    }
    return 0;
}

/***************************************************
 *
 **************************************************/
uint16_t UART_A0_EUSCI_clock(uart_setting uart_eusci_clock){
    // Clear any previously set bits
    MASK_CLEAR(UCA0CTLW0, UCSSEL0|UCSSEL1);
    if(uart_eusci_clock == UART_SOURCE_ACLK){
        MASK_SET(UCA0CTLW0, UCSSEL__ACLK);
    }
    else if(uart_eusci_clock == UART_SOURCE_SMCLK){
        MASK_SET(UCA0CTLW0, UCSSEL__SMCLK);
    }
    else if(uart_eusci_clock == UART_SOURCE_UCLK){
        MASK_SET(UCA0CTLW0, UCSSEL__UCLK);
    }
    else{
        return 1;
    }
    return 0;
}

/***************************************************
 *
 **************************************************/
uint16_t UART_A0_error_interrupt(uart_setting uart_error){
    if(uart_error == UART_ERROR_INT_ENABLE){
        MASK_SET(UCA0CTLW0, UCRXEIE);
    }
    else if(uart_error == UART_ERROR_INT_DISABLE){
        MASK_CLEAR(UCA0CTLW0, UCRXEIE);
    }
    else{
        return 1;
    }
    return 0;
}

/***************************************************
 *
 **************************************************/
uint16_t UART_A0_break_interrupt(uart_setting uart_break){
    if(uart_break == UART_BREAK_INT_ENABLE){
        MASK_SET(UCA0CTLW0, UCBRKIE);
    }
    else if(uart_break == UART_BREAK_INT_DISABLE){
        MASK_CLEAR(UCA0CTLW0, UCBRKIE);
    }
    else{
        return 1;
    }
    return 0;
}

/***************************************************
 *
 **************************************************/
uint16_t UART_A0_EUSCI_sleep(uart_setting uart_sleep){
    if(uart_sleep == UART_SLEEP_ENABLE){
        MASK_SET(UCA0CTLW0, UCDORM);
    }
    else if(uart_sleep == UART_SLEEP_DISABLE){
        MASK_CLEAR(UCA0CTLW0, UCDORM);
    }
    else{
        return 1;
    }
    return 0;
}

/***************************************************
 *
 **************************************************/
uint16_t UART_A0_transmit_address(uart_setting uart_adress){
    if(uart_adress == UART_TX_ADDRESS){
        MASK_SET(UCA0CTLW0, UCTXADDR);
    }
    else if(uart_adress == UART_TX_DATA){
        MASK_CLEAR(UCA0CTLW0, UCTXADDR);
    }
    else{
        return 1;
    }
    return 0;
}

/***************************************************
 *
 **************************************************/
uint16_t UART_A0_frame_break(uart_setting uart_break){
    if(uart_break == UART_TX_BREAK){
        MASK_SET(UCA0CTLW0, UCTXBRK);
    }
    else if(uart_break == UART_TX_NO_BREAK){
        MASK_CLEAR(UCA0CTLW0, UCTXBRK);
    }
    else{
        return 1;
    }
    return 0;
}

/***************************************************
 *
 **************************************************/
uint16_t UART_A0_reset(uart_setting uart_reset){
    if(uart_reset == UART_RESET_ENABLE){
        MASK_SET(UCA0CTLW0, UCSWRST);
    }
    else if(uart_reset == UART_RESET_DISABLE){
        MASK_CLEAR(UCA0CTLW0, UCSWRST);
    }
    else{
        return 1;
    }
    return 0;
}

/***************************************************
 *
 **************************************************/
uint16_t UART_A0_deglitch_time(uart_setting uart_deglitch){
    MASK_CLEAR(UCA0CTLW1, UCGLIT0|UCGLIT1);
    if(uart_deglitch == UART_DEGLITCH_2NS){
        MASK_SET(UCA0CTLW1, UCGLIT_0);
    }
    else if(uart_deglitch == UART_DEGLITCH_50NS){
        MASK_SET(UCA0CTLW1, UCGLIT_1);
    }
    else if(uart_deglitch == UART_DEGLITCH_100NS){
        MASK_SET(UCA0CTLW1, UCGLIT_2);
    }
    else if(uart_deglitch == UART_DEGLITCH_200NS){
        MASK_SET(UCA0CTLW1, UCGLIT_3);
    }
    else{
        return 1;
    }
    return 0;
}

/***************************************************
 *
 **************************************************/
uint16_t UART_A0_clock_prescale(uint16_t uart_prescale){
    UCA0BRW = uart_prescale;
    return 0;
}

/***************************************************
 *
 **************************************************/
uint16_t UART_A0_modulation_stage_1(uint16_t uart_modulation){
    MASK_SET(UCA0MCTLW, uart_modulation&(0x00F0));
    return 0;
}

/***************************************************
 *
 **************************************************/
uint16_t UART_A0_modulation_stage_2(uint16_t uart_modulation){
    MASK_SET(UCA0MCTLW, uart_modulation&(0xFF00));
    return 0;
}

/***************************************************
 *
 **************************************************/
uint16_t UART_A0_oversampling(uart_setting uart_modulation){
    if(uart_modulation == UART_OVERSAMPLE_ENABLE){
        MASK_SET(UCA0MCTLW, UCOS16);
    }
    else if(uart_modulation == UART_OVERSAMPLE_DISABLE){
        MASK_CLEAR(UCA0MCTLW, UCOS16);
    }
    else{
        return 1;
    }
    return 0;
}

/***************************************************
 *
 **************************************************/
uint16_t UART_A0_loopback(uart_setting uart_loopback){
    if(uart_loopback == UART_LOOPBACK_ENABLED){
        MASK_SET(UCA0STATW, UCLISTEN);
    }
    else if(uart_loopback == UART_LOOPBACK_DISABLED){
        MASK_CLEAR(UCA0STATW, UCLISTEN);
    }
    else{
        return 1;
    }
    return 0;
}

/***************************************************
 *
 **************************************************/
uint16_t UART_A0_error_flag_read(void){
    if(MASK_CHECK(UCA0STATW, UCFE)){
        return 1;
    }
    return 0;
}

/***************************************************
 *
 **************************************************/
uint16_t UART_A0_buffer_overrun_flag_read(void){
    if(MASK_CHECK(UCA0STATW, UCOE)){
        return 1;
    }
    return 0;
}

/***************************************************
 *
 **************************************************/
uint16_t UART_A0_parity_error_flag_read(void){
    if(MASK_CHECK(UCA0STATW, UCPE)){
        return 1;
    }
    return 0;
}

/***************************************************
 *
 **************************************************/
uint16_t UART_A0_break_flag_read(void){
    if(MASK_CHECK(UCA0STATW, UCBRK)){
        return 1;
    }
    return 0;
}

/***************************************************
 *
 **************************************************/
uint16_t UART_A0_RX_error_flag_read(void){
    if(MASK_CHECK(UCA0STATW, UCRXERR)){
        return 1;
    }
    return 0;
}

/***************************************************
 *
 **************************************************/
uint16_t UART_A0_TX_address_flag_read(void){
    if(MASK_CHECK(UCA0STATW, UCADDR)){
        return 1;
    }
    return 0;
}

/***************************************************
 *
 **************************************************/
uint16_t UART_A0_EUSCI_busy_flag_read(void){
    if(MASK_CHECK(UCA0STATW, UCBUSY)){
        return 1;
    }
    return 0;
}

/***************************************************
 *
 **************************************************/
uint16_t UART_A0_RX_buffer_read(void){
    return UCA0TXBUF;
}

/***************************************************
 *
 **************************************************/
uint16_t UART_A0_TX_buffer_write(uint8_t uart_byte){
    UCA0TXBUF = uart_byte;
    return 0;
}

/***************************************************
 *
 **************************************************/
uint16_t UART_A0_byte_write(uint8_t uart_byte){
    UCA0TXBUF = uart_byte;
    while (!(UCA0IFG & UCTXCPTIFG)){};
    UCA0IFG ^= UCTXCPTIFG;
    return 0;
}

/***************************************************
 *
 **************************************************/
uint16_t UART_A0_break_sync_length(uart_setting uart_delimiter_length){
    if(uart_delimiter_length == UART_DELIMITER_1BIT){
        MASK_CLEAR(UCA0ABCTL, UCDELIM0|UCDELIM1);
    }
    else if(uart_delimiter_length == UART_DELIMITER_2BIT){
        MASK_CLEAR(UCA0ABCTL, UCDELIM1);
        MASK_SET(UCA0ABCTL, UCDELIM0);
    }
    else if(uart_delimiter_length == UART_DELIMITER_3BIT){
        MASK_CLEAR(UCA0ABCTL, UCDELIM0);
        MASK_SET(UCA0ABCTL, UCDELIM1);
    }
    else if(uart_delimiter_length == UART_DELIMITER_4BIT){
        MASK_SET(UCA0ABCTL, UCDELIM0|UCDELIM1);
    }
    else{
        return 1;
    }
    return 0;
}

/***************************************************
 *
 **************************************************/
uint16_t UART_A0_sync_timeout(void){
    if(MASK_CHECK(UCA0ABCTL, UCSTOE)){
        return 1;
    }
    return 0;
}

/***************************************************
 *
 **************************************************/
uint16_t UART_A0_break_timeout(void){
    if(MASK_CHECK(UCA0ABCTL, UCBTOE)){
        return 1;
    }
    return 0;
}

/***************************************************
 *
 **************************************************/
uint16_t UART_A0_autobaud(uart_setting uart_autobaud){
    if(uart_autobaud == UART_BAUD_DET_ENABLE){
        MASK_SET(UCA0ABCTL, UCABDEN);
    }
    else if(uart_autobaud == UART_BAUD_DET_DISABLE){
        MASK_CLEAR(UCA0ABCTL, UCABDEN);
    }
    else{
        return 1;
    }
    return 0;
}

/***************************************************
 *
 **************************************************/
// IRDA functions not yet implemented!!!

/***************************************************
 *
 **************************************************/
// UCBxIE I2C Control not yet implemented!!!

/***************************************************
 *
 **************************************************/

/***************************************************
 *
 **************************************************/
uint16_t UART_A0_RX_interrupt(uart_setting uart_rx_int){
    if(uart_rx_int == UART_INTERRUPT_ENABLE){
        MASK_SET(UCA0IE, UCRXIE);
    }
    else if(uart_rx_int == UART_INTERRUPT_DISABLE){
        MASK_CLEAR(UCA0IE, UCRXIE);
    }
    else{
        return 1;
    }
    return 0;
}

/***************************************************
 *
 **************************************************/
uint16_t UART_A0_TX_interrupt(uart_setting uart_tx_int){
    if(uart_tx_int == UART_INTERRUPT_ENABLE){
        MASK_SET(UCA0IE, UCTXIE);
    }
    else if(uart_tx_int == UART_INTERRUPT_DISABLE){
        MASK_CLEAR(UCA0IE, UCTXIE);
    }
    else{
        return 1;
    }
    return 0;
}

/***************************************************
 *
 **************************************************/
/*
#pragma vector=USCI_A0_VECTOR
__interrupt void USCI_A0_ISR(void)
{
      switch(__even_in_range(UCA0IV, USCI_UART_UCTXCPTIFG))
      {
        case USCI_NONE: break;
        case USCI_UART_UCRXIFG:
          UART_receive_byte_handle(UCA0RXBUF);
          __bic_SR_register_on_exit(LPM0_bits); //wakeup
          break;
        case USCI_UART_UCTXIFG: break;
        case USCI_UART_UCSTTIFG: break;
        case USCI_UART_UCTXCPTIFG: break;
      }
}
*/

/*********_END_OF_FILE_********/
