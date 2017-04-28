/*
 * spi.c
 *
 *  Created on: 2017. gada 2. marts
 *      Author: Roberts
 */
#include "spi.h"

/***************************************************
*   Define and initialize eUSCI A1 SPI buffers
 **************************************************/
#ifdef USE_INTERRUPTS_EUSCI_A1
    // create Rx and TX arrays for storing data
    static uint8_t RX_data[RX_data_length] = {0};
    static uint8_t TX_data[TX_data_length] = {0};

    // initialzie Rx buffer structure
    static RingBuffer_t SPI_A1_RX_buffer = {
        .buffer = RX_data,
        .max_length = RX_data_length,
        .head = 0,
        .tail = 0,
    };
    // initialzie TX buffer structure
    static RingBuffer_t SPI_A1_TX_buffer = {
        .buffer = TX_data,
        .max_length = TX_data_length,
        .head = 0,
        .tail = 0,
    };
#endif

/***************************************************
*   eUSCI A0 SPI function implementations
 **************************************************/
/* Selects if the data are captured on leading or trailing clock edge   */
uint16_t SPI_A0_clock_phase(SpiSetting_t spi_phase){
    if(spi_phase == SPI_CLK_LEADING){
        MASK_SET(UCA0CTLW0, UCCKPH);
    }
    else if(spi_phase == SPI_CLK_TRAILING){
        MASK_CLEAR(UCA0CTLW0, UCCKPH);
    }
    else{
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}

uint16_t SPI_A0_clock_polarity(SpiSetting_t spi_polarity){
    if(spi_polarity == SPI_CLK_ACTIVE_HIGH){
        MASK_SET(UCA0CTLW0, UCCKPL);
    }
    else if(spi_polarity == SPI_CLK_ACTIVE_LOW){
        MASK_CLEAR(UCA0CTLW0, UCCKPL);
    }
    else{
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}

uint16_t SPI_A0_bit_order(SpiSetting_t spi_bitorder){
    if(spi_bitorder == SPI_MSB_FIRST){
        MASK_SET(UCA0CTLW0, UCMSB);
    }
    else if(spi_bitorder == SPI_LSB_FIRST){
        MASK_CLEAR(UCA0CTLW0, UCMSB);
    }
    else{
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}

uint16_t SPI_A0_char_length(SpiSetting_t spi_charlength){
    if(spi_charlength == SPI_CHAR_7BIT){
        MASK_SET(UCA0CTLW0, UC7BIT);
    }
    else if(spi_charlength == SPI_CHAR_8BIT){
        MASK_CLEAR(UCA0CTLW0, UC7BIT);
    }
    else{
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}

uint16_t SPI_A0_mode(SpiSetting_t spi_mode){
    if(spi_mode == SPI_MASTER){
        MASK_SET(UCA0CTLW0, UCMST);
    }
    else if(spi_mode == SPI_SLAVE){
        MASK_SET(UCA0CTLW0, UCMST);
    }
    else{
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}

uint16_t SPI_A0_EUSCI_mode(SpiSetting_t spi_eusci_mode){
    // Clear previously set bits
    MASK_CLEAR(UCA0CTLW0, UCMODE0|UCMODE1);
    if(spi_eusci_mode == SPI_MODE_3PIN){
        MASK_SET(UCA0CTLW0, UCMODE_0);
    }
    else if(spi_eusci_mode == SPI_MODE_4PIN_AH){
        MASK_SET(UCA0CTLW0, UCMODE_1);
    }
    else if(spi_eusci_mode == SPI_MODE_4PIN_AL){
        MASK_SET(UCA0CTLW0, UCMODE_2);
    }
    else{
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}

uint16_t SPI_A0_sync(SpiSetting_t spi_sync){
    if(spi_sync == SPI_MODE_SYNC){
        MASK_SET(UCA0CTLW0, UCSYNC);
    }
    else if(spi_sync == SPI_MODE_ASYNC){
        MASK_CLEAR(UCA0CTLW0, UCSYNC);
    }
    else{
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}
uint16_t SPI_A0_clock_source(SpiSetting_t spi_clk){
    // Clear previously set bits
    MASK_CLEAR(UCA0CTLW0, UCSSEL0|UCSSEL1);
    if(spi_clk == SPI_CLK_SOURCE_ACLK){
        MASK_SET(UCA0CTLW0, UCSSEL__ACLK);
    }
    else if(spi_clk == SPI_CLK_SOURCE_SMCLK){
        MASK_SET(UCA0CTLW0, UCSSEL__SMCLK);
    }
    else if(spi_clk == SPI_CLK_SOURCE_UCXCLK){
        MASK_SET(UCA0CTLW0, UCSSEL__UCLK);
    }
    else{
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}
uint16_t SPI_A0_STE_pin(SpiSetting_t spi_ste){
    if(spi_ste == SPI_STE_DISABLE){
        MASK_SET(UCA0CTLW0, UCSTEM);
    }
    else if(spi_ste == SPI_STE_ENABLE){
        MASK_CLEAR(UCA0CTLW0, UCSTEM);
    }
    else{
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}

uint16_t SPI_A0_soft_reset(SpiSetting_t spi_reset){
    if(spi_reset == SPI_RESET_ENABLE){
        MASK_SET(UCA0CTLW0, UCSWRST);
    }
    else if(spi_reset == SPI_RESET_DISABLE){
        MASK_CLEAR(UCA0CTLW0, UCSWRST);
    }
    else{
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}

uint16_t SPI_A0_loopback(SpiSetting_t spi_loopback){
    if(spi_loopback == SPI_LOOPBACK_ENABLE){
        MASK_SET(UCA0STATW, UCLISTEN);
    }
    else if(spi_loopback == SPI_LOOPBACK_DISABLE){
        MASK_CLEAR(UCA0STATW, UCLISTEN);
    }
    else{
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}
uint16_t SPI_A0_clock_prescale(uint16_t spi_clk_prescale){
    UCA0BRW = spi_clk_prescale;
    return EXIT_SUCCESS;
}

uint16_t SPI_A0_frame_error_flag_read(void){
    if(MASK_CHECK(UCA0STATW, UCFE)){
        return 1;
    }
    return 0;
}

uint16_t SPI_A0_overrun_error_flag_read(void){
    if(MASK_CHECK(UCA0STATW, UCOE)){
        return 1;
    }
    return 0;
}

uint16_t SPI_A0_busy_flag_read(void){
    if(MASK_CHECK(UCA0STATW, UCBUSY)){
        return 1;
    }
    return 0;
}





uint16_t SPI_A0_RX_buffer_read(void){
    return UCA0RXBUF;
}

uint16_t SPI_A0_TX_buffer_write(uint8_t spi_byte){
    UCA0TXBUF = spi_byte;
    return EXIT_SUCCESS;
}


uint16_t SPI_A0_byte_read(void){
    // wait if data transmission is in progress
    while (!(UCA0IFG & UCTXIFG)){};
    SPI_A0_RX_buffer_read();
    // load one dummy byte into transmit register
    UCA0TXBUF = 0x00;
    while (!(UCA0IFG & UCTXIFG)){};
    // return the receive buffer contents
    while (!(UCA0IFG & UCRXIFG)){};
    return UCA0RXBUF;
}

uint16_t SPI_A0_byte_write(uint8_t tx_data){
    // wait if data transmission is in progress
    while (!(UCA0IFG & UCTXIFG)){};
    // load one byte of data into transmit register
    UCA0TXBUF = tx_data;
    // wait for the data transmission to complete
    while (!(UCA0IFG & UCTXIFG)){};
    return EXIT_SUCCESS;
}

uint16_t SPI_A0_data_write(uint8_t *tx_data, uint8_t data_length){
    // check if data length is sane
    if(data_length > 0){
        while(data_length){
            // wait if data transmission is in progress
            //while (!(UCA1IFG & UCRXIFG)){};
            // load one byte of data into transmit register
            UCA0TXBUF = *tx_data;
            // wait for the data transmission to complete
            //while (!(UCA1IFG & UCRXIFG)){};

            data_length--;
            tx_data++;
        }
        return EXIT_SUCCESS;
    }
    else{
        return EXIT_FAILURE;
    }
}


uint16_t SPI_A0_RX_interrupt(SpiSetting_t spi_interrupt){
    if(spi_interrupt == SPI_INT_ENABLE){
        MASK_SET(UCA0IE, UCRXIE);
    }
    else if(spi_interrupt == SPI_INT_DISABLE){
        MASK_CLEAR(UCA0IE, UCRXIE);
    }
    else{
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}

uint16_t SPI_A0_TX_interrupt(SpiSetting_t spi_interrupt){
    if(spi_interrupt == SPI_INT_ENABLE){
        MASK_SET(UCA0IE, UCTXIE);
    }
    else if(spi_interrupt == SPI_INT_DISABLE){
        MASK_CLEAR(UCA0IE, UCTXIE);
    }
    else{
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}

uint16_t SPI_A0_RX_interrupt_read(void){
    if(MASK_CHECK(UCA0IFG, UCRXIFG)){
        return 1;
    }
    return 0;
}
uint16_t SPI_A0_TX_interrupt_read(void){
    if(MASK_CHECK(UCA0IFG, UCTXIFG)){
        return 1;
    }
    return 0;
}

/***************************************************
*   eUSCI A1 SPI function implementations
 **************************************************/
uint16_t SPI_A1_clock_phase(SpiSetting_t spi_phase){
/* selects if the data are captured on leading or trailing clock edge   */
    if(spi_phase == SPI_CLK_LEADING){
        MASK_SET(UCA1CTLW0, UCCKPH);
    }
    else if(spi_phase == SPI_CLK_TRAILING){
        MASK_CLEAR(UCA1CTLW0, UCCKPH);
    }
    else{
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}

uint16_t SPI_A1_clock_polarity(SpiSetting_t spi_polarity){
    if(spi_polarity == SPI_CLK_ACTIVE_HIGH){
        MASK_SET(UCA1CTLW0, UCCKPL);
    }
    else if(spi_polarity == SPI_CLK_ACTIVE_LOW){
        MASK_CLEAR(UCA1CTLW0, UCCKPL);
    }
    else{
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}

uint16_t SPI_A1_bit_order(SpiSetting_t spi_bitorder){
    if(spi_bitorder == SPI_MSB_FIRST){
        MASK_SET(UCA1CTLW0, UCMSB);
    }
    else if(spi_bitorder == SPI_LSB_FIRST){
        MASK_CLEAR(UCA1CTLW0, UCMSB);
    }
    else{
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}

uint16_t SPI_A1_char_length(SpiSetting_t spi_charlength){
    if(spi_charlength == SPI_CHAR_7BIT){
        MASK_SET(UCA1CTLW0, UC7BIT);
    }
    else if(spi_charlength == SPI_CHAR_8BIT){
        MASK_CLEAR(UCA1CTLW0, UC7BIT);
    }
    else{
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}

uint16_t SPI_A1_mode(SpiSetting_t spi_mode){
    if(spi_mode == SPI_MASTER){
        MASK_SET(UCA1CTLW0, UCMST);
    }
    else if(spi_mode == SPI_SLAVE){
        MASK_SET(UCA1CTLW0, UCMST);
    }
    else{
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}

uint16_t SPI_A1_EUSCI_mode(SpiSetting_t spi_eusci_mode){
    // Clear previously set bits
    MASK_CLEAR(UCA1CTLW0, UCMODE0|UCMODE1);
    if(spi_eusci_mode == SPI_MODE_3PIN){
        MASK_SET(UCA1CTLW0, UCMODE_0);
    }
    else if(spi_eusci_mode == SPI_MODE_4PIN_AH){
        MASK_SET(UCA1CTLW0, UCMODE_1);
    }
    else if(spi_eusci_mode == SPI_MODE_4PIN_AL){
        MASK_SET(UCA1CTLW0, UCMODE_2);
    }
    else{
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}

uint16_t SPI_A1_sync(SpiSetting_t spi_sync){
    if(spi_sync == SPI_MODE_SYNC){
        MASK_SET(UCA1CTLW0, UCSYNC);
    }
    else if(spi_sync == SPI_MODE_ASYNC){
        MASK_CLEAR(UCA1CTLW0, UCSYNC);
    }
    else{
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}
uint16_t SPI_A1_clock_source(SpiSetting_t spi_clk){
    // Clear previously set bits
    MASK_CLEAR(UCA1CTLW0, UCSSEL0|UCSSEL1);
    if(spi_clk == SPI_CLK_SOURCE_ACLK){
        MASK_SET(UCA1CTLW0, UCSSEL__ACLK);
    }
    else if(spi_clk == SPI_CLK_SOURCE_SMCLK){
        MASK_SET(UCA1CTLW0, UCSSEL__SMCLK);
    }
    else if(spi_clk == SPI_CLK_SOURCE_UCXCLK){
        MASK_SET(UCA1CTLW0, UCSSEL__UCLK);
    }
    else{
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}
uint16_t SPI_A1_STE_pin(SpiSetting_t spi_ste){
    if(spi_ste == SPI_STE_ENABLE){
        MASK_SET(UCA1CTLW0, UCSTEM);
    }
    else if(spi_ste == SPI_STE_DISABLE){
        MASK_CLEAR(UCA1CTLW0, UCSTEM);
    }
    else{
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}

uint16_t SPI_A1_soft_reset(SpiSetting_t spi_reset){
    if(spi_reset == SPI_RESET_ENABLE){
        MASK_SET(UCA1CTLW0, UCSWRST);
    }
    else if(spi_reset == SPI_RESET_DISABLE){
        MASK_CLEAR(UCA1CTLW0, UCSWRST);
    }
    else{
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}

uint16_t SPI_A1_loopback(SpiSetting_t spi_loopback){
    if(spi_loopback == SPI_LOOPBACK_ENABLE){
        MASK_SET(UCA1STATW, UCLISTEN);
    }
    else if(spi_loopback == SPI_LOOPBACK_DISABLE){
        MASK_CLEAR(UCA1STATW, UCLISTEN);
    }
    else{
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}

uint16_t SPI_A1_clock_prescale(uint16_t spi_clk_prescale){
    UCA1BRW = spi_clk_prescale;
    return EXIT_SUCCESS;
}

uint16_t SPI_A1_frame_error_flag_read(void){
    if(MASK_CHECK(UCA1STATW, UCFE)){
        return 1;
    }
    return 0;
}

uint16_t SPI_A1_overrun_error_flag_read(void){
    if(MASK_CHECK(UCA1STATW, UCOE)){
        return 1;
    }
    return 0;
}

uint16_t SPI_A1_busy_flag_read(void){
    if(MASK_CHECK(UCA1STATW, UCBUSY)){
        return TRUE;
    }
    return FALSE;
}

uint16_t SPI_A1_RX_buffer_read(void){
    return UCA1RXBUF;
}

#ifdef USE_INTERRUPTS_EUSCI_A1

    uint16_t SPI_A1_byte_write(uint8_t tx_data){
        // declare a ring buffer status variable
        RingBufferStatus tx_status;
        // push TX data in ring buffer and save the status
        tx_status = ring_buffer_push(&SPI_A1_TX_buffer, tx_data);
        // check if TX operation was successful
        if(tx_status == BUFFER_FULL){
            // if the buffer was full, return failure
            return EXIT_FAILURE;
        }
        // enable the TX intterupt and return with success
        SPI_A1_TX_interrupt(SPI_INT_ENABLE);
        return EXIT_SUCCESS;
    }

    uint16_t SPI_A1_byte_read(uint8_t *rx_data){
        // declare a ring buffer status variable
        RingBufferStatus rx_status;
        rx_status = ring_buffer_pop(&SPI_A1_RX_buffer, rx_data);
        if(rx_status == BUFFER_EMPTY){
            return EXIT_FAILURE;
        }
        return EXIT_SUCCESS;
    }

    uint16_t SPI_A1_TX_buffer_reset(void){
        ring_buffer_reset(&SPI_A1_TX_buffer);
        return EXIT_SUCCESS;
    }

    uint16_t SPI_A1_RX_buffer_reset(void){
        ring_buffer_reset(&SPI_A1_RX_buffer);
        return EXIT_SUCCESS;
    }
// used if interrupts are not used
#else
    // !!! This function should be used without TX/RX interrupts !!!
    uint16_t SPI_A1_byte_read(void){
        // wait if data transmission is in progress
        while (!(UCA1IFG & UCTXIFG)){};
        SPI_A1_RX_buffer_read();
        // load one dummy byte into transmit register
        UCA1TXBUF = 0x00;
        while (!(UCA1IFG & UCTXIFG)){};
        // return the receive buffer contents
        while (!(UCA1IFG & UCRXIFG)){};
        return UCA1RXBUF;
    }

    uint16_t SPI_A1_byte_write(uint8_t tx_data){
        // wait if data transmission is in progress
        while (!(UCA1IFG & UCTXIFG)){};
        // load one byte of data into transmit register
        UCA1TXBUF = tx_data;
        // wait for the data transmission to complete
        while (!(UCA1IFG & UCTXIFG)){};
        return EXIT_SUCCESS;
    }

    uint16_t SPI_A1_data_write(uint8_t *tx_data, uint8_t data_length){
        // check if data length is sane
        if(data_length > 0){
            while(data_length){
                // wait if data transmission is in progress
                //while (!(UCA1IFG & UCRXIFG)){};
                // load one byte of data into transmit register
                UCA1TXBUF = *tx_data;
                // wait for the data transmission to complete
                //while (!(UCA1IFG & UCRXIFG)){};

                data_length--;
                tx_data++;
            }
            return EXIT_SUCCESS;
        }
        else{
            return EXIT_FAILURE;
        }
    }
#endif

uint16_t SPI_A1_RX_interrupt(SpiSetting_t spi_interrupt){
    if(spi_interrupt == SPI_INT_ENABLE){
        MASK_SET(UCA1IE, UCRXIE);
    }
    else if(spi_interrupt == SPI_INT_DISABLE){
        MASK_CLEAR(UCA1IE, UCRXIE);
    }
    else{
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}

uint16_t SPI_A1_TX_interrupt(SpiSetting_t spi_interrupt){
    if(spi_interrupt == SPI_INT_ENABLE){
        MASK_SET(UCA1IE, UCTXIE);
    }
    else if(spi_interrupt == SPI_INT_DISABLE){
        MASK_CLEAR(UCA1IE, UCTXIE);
    }
    else{
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}

uint16_t SPI_A1_RX_interrupt_read(void){
    if(MASK_CHECK(UCA1IFG, UCRXIFG)){
        return 1;
    }
    return 0;
}
uint16_t SPI_A1_TX_interrupt_read(void){
    if(MASK_CHECK(UCA1IFG, UCTXIFG)){
        return 1;
    }
    return 0;
}


#ifdef USE_INTERRUPTS_EUSCI_A1
    #pragma vector=USCI_A1_VECTOR
    __interrupt void USCI_A1_ISR(void){
        RingBufferStatus spi_buffer_status;
        switch(__even_in_range(UCA1IV,4)){
            case 0x00:  /* No interrupt pending                 */
                break;
            case 0x02:  /* Data received, source: UCRXIFG flag  */
                // push the received SPI byte in to buffer
                ring_buffer_push(&SPI_A1_RX_buffer, UCA1RXBUF);
                break;
            case 0x04:  /* Transmit buffer empty, source: UCTXIFG flag  */
                ring_buffer_pop(&SPI_A1_TX_buffer, (uint8_t *)&UCA1TXBUF_L);
                spi_buffer_status = ring_buffer_status(&SPI_A1_TX_buffer);
                if(spi_buffer_status == BUFFER_EMPTY){
                    SPI_A1_TX_interrupt(SPI_INT_DISABLE);
                }
                break;
            default:    /* Default case */
                break;
        }
    }
#endif

/*********_END_OF_FILE_********/
