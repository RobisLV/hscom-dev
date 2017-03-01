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
uint16_t UART_Parity(uart_setting uart_parity){
    if(uart_parity == PARITY_ENABLE){
        MASK_SET(UCA0CTLW0, UCPEN);
    }
    else if(uart_parity == PARITY_DISABLE){
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
uint16_t UART_Parity_Mode(uart_setting uart_parity){
    if(uart_parity == PARITY_ODD){
        MASK_SET(UCA0CTLW0, UCPAR);
    }
    else if(uart_parity == PARITY_EVEN){
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
uint16_t UART_Bit_Order(uart_setting uart_first_bits){
    if(uart_first_bits == MSB_FIRST){
        MASK_SET(UCA0CTLW0, UCMSB);
    }
    else if(uart_first_bits == LSB_FIRST){
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
uint16_t UART_Char_Length(uart_setting uart_char_length){
    if(uart_char_length == CHAR_8BIT){
        MASK_SET(UCA0CTLW0, UC7BIT);
    }
    else if(uart_char_length == CHAR_7BIT){
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
uint16_t UART_Stop_Bits(uart_setting uart_stop_bits){
    if(uart_stop_bits==STOP_2BIT){
        MASK_SET(UCA0CTLW0, UCSPB);
    }
    else if(uart_stop_bits==STOP_1BIT){
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
uint16_t UART_EUSCI_Mode(uart_setting uart_eusci_mode){
    // Clear any previusly set bits
    MASK_CLEAR(UCA0CTLW0, UCMODE0|UCMODE1);

    if(uart_eusci_mode == EUSCI_MODE_0){
        MASK_SET(UCA0CTLW0, UCMODE_0);
    }
    else if(uart_eusci_mode == EUSCI_MODE_1){
        MASK_SET(UCA0CTLW0, UCMODE_1);
    }
    else if(uart_eusci_mode == EUSCI_MODE_2){
        MASK_SET(UCA0CTLW0, UCMODE_2);
    }
    else if(uart_eusci_mode == EUSCI_MODE_3){
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
uint16_t UART_EUSCI_Sync(uart_setting uart_eusci_sync){
    if(uart_eusci_sync == MODE_ASYNC){
        MASK_SET(UCA0CTLW0, UCSYNC);
    }
    else if(uart_eusci_sync == MODE_SYNC){
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
uint16_t UART_EUSCI_Clock(uart_setting uart_eusci_clock){
    // Clear any previously set bits
    MASK_CLEAR(UCA0CTLW0, UCSSEL0|UCSSEL1);

    if(uart_eusci_clock == SOURCE_ACLK){
        MASK_SET(UCA0CTLW0, UCSSEL__ACLK);
    }
    else if(uart_eusci_clock == SOURCE_SMCLK){
        MASK_SET(UCA0CTLW0, UCSSEL__SMCLK);
    }
    else if(uart_eusci_clock == SOURCE_UCLK){
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
uint16_t UART_Error_Interrupt(uart_setting uart_error){
    if(uart_error == ERROR_INT_ENABLE){
        MASK_SET(UCA0CTLW0, UCRXEIE);
    }
    else if(uart_error == ERROR_INT_DISABLE){
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
uint16_t UART_Break_Interrupt(uart_setting uart_break){
    if(uart_break == BREAK_INT_ENABLE){
        MASK_SET(UCA0CTLW0, UCBRKIE);
    }
    else if(uart_break == BREAK_INT_DISABLE){
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
uint16_t UART_EUSCI_Sleep(uart_setting uart_sleep){
    if(uart_sleep == SLEEP_ENABLE){
        MASK_SET(UCA0CTLW0, UCDORM);
    }
    else if(uart_sleep == SLEEP_DISABLE){
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
uint16_t UART_TX_Address(uart_setting uart_adress){
    if(uart_adress == TX_ADDRESS){
        MASK_SET(UCA0CTLW0, UCTXADDR);
    }
    else if(uart_adress == TX_DATA){
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
uint16_t UART_Frame_Break(uart_setting uart_break){
    if(uart_break == TX_BREAK){
        MASK_SET(UCA0CTLW0, UCTXBRK);
    }
    else if(uart_break == TX_NO_BREAK){
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
uint16_t UART_Reset(uart_setting uart_reset){
    if(uart_reset == RESET_ENABLE){
        MASK_SET(UCA0CTLW0, UCSWRST);
    }
    else if(uart_reset == RESET_DISABLE){
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
uint16_t UART_Deglitch_Time(uart_setting uart_deglitch){
    MASK_CLEAR(UCA0CTLW1, UCGLIT0|UCGLIT1);
    if(uart_deglitch == DEGLITCH_2NS){
        MASK_SET(UCA0CTLW1, UCGLIT_0);
    }
    else if(uart_deglitch == DEGLITCH_50NS){
        MASK_SET(UCA0CTLW1, UCGLIT_1);
    }
    else if(uart_deglitch == DEGLITCH_100NS){
        MASK_SET(UCA0CTLW1, UCGLIT_2);
    }
    else if(uart_deglitch == DEGLITCH_200NS){
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
uint16_t UART_Clock_Prescale(uint16_t uart_prescale){
    UCA0BRW = uart_prescale;
    return 0;
}

/***************************************************
 *
 **************************************************/
uint16_t UART_Modulation_Stage_1(uint16_t uart_modulation){
    MASK_SET(UCA0MCTLW, uart_modulation&(0x00F0));
    return 0;
}

/***************************************************
 *
 **************************************************/
uint16_t UART_Modulation_Stage_2(uart_setting uart_modulation){
    MASK_SET(UCA0MCTLW, uart_modulation&(0xFF00));
    return 0;
}

/***************************************************
 *
 **************************************************/
uint16_t UART_Oversampling(uart_setting uart_modulation){
    if(uart_modulation == OVERSAMPLING_ENABLE){
        MASK_SET(UCA0MCTLW, UCOS16);
    }
    else if(uart_modulation == OVERSAMPLING_DISABLE){
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
uint16_t UART_Loopback(uart_setting uart_loopback){
    if(uart_loopback == LOOPBACK_ENABLED){
        MASK_SET(UCA0STATW, UCLISTEN);
    }
    else if(uart_loopback == LOOPBACK_DISABLED){
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
uint16_t UART_Error_Flag_Read(void){
    if(MASK_CHECK(UCA0STATW, UCFE)){
        return 1;
    }
    return 0;
}

/***************************************************
 *
 **************************************************/
uint16_t UART_Buffer_Overrun_Flag_Read(void){
    if(MASK_CHECK(UCA0STATW, UCOE)){
        return 1;
    }
    return 0;
}

/***************************************************
 *
 **************************************************/
uint16_t UART_Parity_Error_Flag_Read(void){
    if(MASK_CHECK(UCA0STATW, UCPE)){
        return 1;
    }
    return 0;
}

/***************************************************
 *
 **************************************************/
uint16_t UART_Break_Flag_Read(void){
    if(MASK_CHECK(UCA0STATW, UCBRK)){
        return 1;
    }
    return 0;
}

/***************************************************
 *
 **************************************************/
uint16_t UART_RX_Error_Flag_Read(void){
    if(MASK_CHECK(UCA0STATW, UCRXERR)){
        return 1;
    }
    return 0;
}

/***************************************************
 *
 **************************************************/
uint16_t UART_RX_Address_Flag_Read(void){
    if(MASK_CHECK(UCA0STATW, UCADDR)){
        return 1;
    }
    return 0;
}

/***************************************************
 *
 **************************************************/
uint16_t UART_EUSCI_Bussy_Flag_Read(void){
    if(MASK_CHECK(UCA0STATW, UCBUSY)){
        return 1;
    }
    return 0;
}

/***************************************************
 *
 **************************************************/
uint16_t UART_RX_Buffer_Read(void){
    return UCA0TXBUF;
}

/***************************************************
 *
 **************************************************/
uint16_t UART_TX_Buffer_Write(uint16_t data){
    UCA0TXBUF = (data & 0x00FF);
    return 0;
}

/***************************************************
 *
 **************************************************/

/***************************************************
 *
 **************************************************/
uint16_t UART_Write_Byte(uint8_t byte){
    UCA0TXBUF = byte;
    while (!(UCA0IFG & UCTXCPTIFG)){};
    UCA0IFG ^= UCTXCPTIFG;
    return 0;
}
/*
if(==){
    MASK_SET(, );
}
else if(==){
    MASK_CLEAR(, );
}
else{
    return 1;
}
return 0;
*/
