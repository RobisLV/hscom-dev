/*
 * spi.h
 *
 *  Created on: 2017. gada 2. marts
 *      Author: Roberts
 */

#ifndef DRIVER_INCLUDE_SPI_H_
#define DRIVER_INCLUDE_SPI_H_

typedef volatile enum {
    /*  CLock phase select      */
    CLK_RISING,
    CLK_FALLING,
    /* Clock polarity select    */
    CLK_ACTIVE_HIGH,
    CLK_ACTIVE_LOW,
    /* Bit order select         */
    MSB_FIRST,
    LSB_FIRST,
    /*  Character length        */
    CHAR_8BIT,
    CHAR_7BIT,
    /*  Master mode select      */
    SLAVE,
    MASTER,
    /*  eUSCI mode select       */
    MODE_3PIN_SPI,
    MODE_4PIN_SPI_ACTIVE_HIGH,
    MODE_4PIN_SPI_ACTIVE_LOW,
    MODE_I2C,
    /*  Syncronus mode select   */
    MODE_ASYNC,
    MODE_SYNC,
    /*  Clock source select     */
    CLK_SOURCE_UCXCLK,
    CLK_SOURCE_SMCLK,
    /*  STE mode select         */
    STE_DISABLE,
    STE_ENABLE,
    /*  Loopback mode select    */
    LOOPBACK_ENABLE,
    LOOPBACK_DISABLE,
    /*  Transmit interrupt select   */
    TX_INTERRUPT_ENABLE,
    TX_INTERRUPT_DISABLE,
    /*  Receive interrupt select    */
    RX_INTERRUPT_ENABLE,
    RX_INTERRUPT_DISABLE,
} spi_setting;

uint16_t SPI_CLK_Phase(spi_setting spi_phase){
    if(){

    }
    else if(){

    }

}


#endif /* DRIVER_INCLUDE_SPI_H_ */
