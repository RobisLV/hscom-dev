/*
 * spi.c
 *
 *  Created on: 2017. gada 2. marts
 *      Author: Roberts
 */
#include "spi.h"

/***************************************************
 *
 **************************************************/
uint16_t SPI_A0_clock_phase(spi_setting spi_phase){
    if(spi_phase == SPI_CLK_RISING){
        MASK_SET(UCB0CTLW0, UCCKPH);
    }
    else if(spi_phase == SPI_CLK_FALLING){
        MASK_CLEAR(UCB0CTLW0, UCCKPH);
    }
    else{
        return 1;
    }
    return 0;
}

/***************************************************
 *
 **************************************************/
uint16_t SPI_A0_clock_polarity(spi_setting spi_polarity){
    if(spi_polarity == SPI_CLK_ACTIVE_HIGH){
        MASK_SET(UCB0CTLW0, UCCKPL);
    }
    else if(spi_polarity == SPI_CLK_ACTIVE_LOW){
        MASK_CLEAR(UCB0CTLW0, UCCKPL);
    }
    else{
        return 1;
    }
    return 0;
}

/***************************************************
 *
 **************************************************/
uint16_t SPI_A0_bit_order(spi_setting spi_bitorder){
    if(spi_bitorder == SPI_MSB_FIRST){
        MASK_SET(UCB0CTLW0, UCMSB);
    }
    else if(spi_bitorder == SPI_LSB_FIRST){
        MASK_CLEAR(UCB0CTLW0, UCMSB);
    }
    else{
        return 1;
    }
    return 0;
}

/***************************************************
 *
 **************************************************/
uint16_t SPI_A0_char_length(spi_setting spi_charlength){
    if(spi_charlength == SPI_CHAR_7BIT){
        MASK_SET(UCB0CTLW0, UC7BIT);
    }
    else if(spi_charlength == SPI_CHAR_8BIT){
        MASK_CLEAR(UCB0CTLW0, UC7BIT);
    }
    else{
        return 1;
    }
    return 0;
}

/***************************************************
 *
 **************************************************/
uint16_t SPI_A0_mode(spi_setting spi_mode){
    if(spi_mode == SPI_MASTER){
        MASK_SET(UCB0CTLW0, UCMST);
    }
    else if(spi_mode == SPI_SLAVE){
        MASK_SET(UCB0CTLW0, UCMST);
    }
    else{
        return 1;
    }
    return 0;
}

/***************************************************
 *
 **************************************************/
uint16_t SPI_A0_EUSCI_mode(spi_setting spi_eusci_mode){
    // Clear previously set bits
    MASK_CLEAR(UCB0CTLW0, UCMODE0|UCMODE1);
    if(spi_eusci_mode == SPI_MODE_3PIN_SPI){
        MASK_SET(UCB0CTLW0, UCMODE_0);
    }
    else if(spi_eusci_mode == SPI_MODE_4PIN_SPI_ACTIVE_HIGH){
        MASK_SET(UCB0CTLW0, UCMODE_1);
    }
    else if(spi_eusci_mode == SPI_MODE_4PIN_SPI_ACTIVE_LOW){
        MASK_SET(UCB0CTLW0, UCMODE_2);
    }
    else{
        return 1;
    }
    return 0;
}

/***************************************************
 *
 **************************************************/
uint16_t SPI_A0_sync(spi_setting spi_sync){
    if(spi_sync == SPI_MODE_SYNC){
        MASK_SET(UCB0CTLW0, UCSYNC);
    }
    else if(spi_sync == SPI_MODE_ASYNC){
        MASK_CLEAR(UCB0CTLW0, UCSYNC);
    }
    else{
        return 1;
    }
    return 0;
}
/***************************************************
 *
 **************************************************/
uint16_t SPI_A0_clock_source(spi_setting spi_clk){
    // Clear previously set bits
    MASK_CLEAR(UCB0CTLW0, UCSSEL0|UCSSEL1);
    if(spi_clk == SPI_CLK_SOURCE_ACLK){
        MASK_SET(UCB0CTLW0, UCSSEL__ACLK);
    }
    else if(spi_clk == SPI_CLK_SOURCE_SMCLK){
        MASK_SET(UCB0CTLW0, UCSSEL__SMCLK);
    }
    else if(spi_clk == SPI_CLK_SOURCE_UCXCLK){
        MASK_SET(UCB0CTLW0, UCSSEL__UCLK);
    }
    else{
        return 1;
    }
    return 0;
}
/***************************************************
 *
 **************************************************/
uint16_t SPI_A0_STE_pin(spi_setting spi_ste){
    if(spi_ste == SPI_STE_DISABLE){
        MASK_SET(UCB0CTLW0, UCSTEM);
    }
    else if(spi_ste == SPI_STE_ENABLE){
        MASK_CLEAR(UCB0CTLW0, UCSTEM);
    }
    else{
        return 1;
    }
    return 0;
}

/***************************************************
 *
 **************************************************/
uint16_t SPI_A0_soft_reset(spi_setting spi_reset){
    if(spi_reset == SPI_RESET_ENABLE){
        MASK_SET(UCB0CTLW0, UCSWRST);
    }
    else if(spi_reset == SPI_RESET_DISABLE){
        MASK_CLEAR(UCB0CTLW0, UCSWRST);
    }
    else{
        return 1;
    }
    return 0;
}

/***************************************************
 *
 **************************************************/
uint16_t SPI_A0_loopback(spi_setting spi_loopback){
    if(spi_loopback == SPI_LOOPBACK_ENABLE){
        MASK_SET(UCB0STATW, UCLISTEN);
    }
    else if(spi_loopback == SPI_LOOPBACK_DISABLE){
        MASK_CLEAR(UCB0STATW, UCLISTEN);
    }
    else{
        return 1;
    }
    return 0;
}
/***************************************************
 *
 **************************************************/
uint16_t SPI_A0_clock_prescale(uint16_t spi_clk_prescale){
    UCB0BRW = spi_clk_prescale;
    return 0;
}

/***************************************************
 *
 **************************************************/
uint16_t SPI_A0_frame_error_flag_read(void){
    if(MASK_CHECK(UCB0STATW, UCFE)){
        return 1;
    }
    return 0;
}

/***************************************************
 *
 **************************************************/
uint16_t SPI_A0_overrun_error_flag_read(void){
    if(MASK_CHECK(UCB0STATW, UCOE)){
        return 1;
    }
    return 0;
}

/***************************************************
 *
 **************************************************/
uint16_t SPI_A0_busy_flag_read(void){
    if(MASK_CHECK(UCB0STATW, UCBUSY)){
        return 1;
    }
    return 0;
}

/***************************************************
 *
 **************************************************/
uint16_t SPI_A0_RX_buffer_read(void){
    return UCA0RXBUF;
}

/***************************************************
 *
 **************************************************/
uint16_t SPI_A0_TX_buffer_read(uint8_t spi_byte){
    UCA0TXBUF = spi_byte;
    return 0;
}

/***************************************************
 *
 **************************************************/
uint16_t SPI_A0_RX_interrupt(spi_setting spi_interrupt){
    if(spi_interrupt == SPI_INTERRUPT_ENABLE){
        MASK_SET(UCB0IFG, UCRXIE);
    }
    else if(spi_interrupt == SPI_INTERRUPT_DISABLE){
        MASK_CLEAR(UCB0IFG, UCRXIE);
    }
    else{
        return 1;
    }
    return 0;
}

/***************************************************
 *
 **************************************************/
uint16_t SPI_A0_TX_interrupt(spi_setting spi_interrupt){
    if(spi_interrupt == SPI_INTERRUPT_ENABLE){
        MASK_SET(UCB0IFG, UCTXIE);
    }
    else if(spi_interrupt == SPI_INTERRUPT_DISABLE){
        MASK_CLEAR(UCB0IFG, UCTXIE);
    }
    else{
        return 1;
    }
    return 0;
}

/***************************************************
 *
 **************************************************/
uint16_t SPI_A0_RX_interrupt_read(void){
    if(MASK_CHECK(UCB0IFG, UCRXIFG)){
        return 1;
    }
    return 0;
}
/***************************************************
 *
 **************************************************/
uint16_t SPI_A0_TX_interrupt_read(void){
    if(MASK_CHECK(UCB0IFG, UCTXIFG)){
        return 1;
    }
    return 0;
}

/*********_END_OF_FILE_********/
