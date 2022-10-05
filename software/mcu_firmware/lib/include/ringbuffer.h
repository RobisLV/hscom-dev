/*
 * ringbuffer.h
 *
 *  Created on: 2017. gada 3. apr.
 *      Author: Roberts
 */
#ifndef LIB_INCLUDE_RINGBUFFER_H_
#define LIB_INCLUDE_RINGBUFFER_H_

#include <stdint.h>
#include "macros.h"

/* all possible buffer states   */
typedef volatile enum {BUFFER_OK, BUFFER_EMPTY, BUFFER_FULL} RingBufferStatus;

/* Ring buffer structure        */
typedef volatile struct {
    uint8_t * const buffer;     /* constant pointer to a an array           */
    const uint16_t max_length;  /* specifies the length of buffer           */
    uint16_t head;              /* points to the head of buffer (write)     */
    uint16_t tail;              /* points to the tail of buffer (read)      */
} RingBuffer_t;

/************************************************************
* RING BUFFER FUNCTIONS
************************************************************/
RingBufferStatus ring_buffer_push   (RingBuffer_t *ring_buffer, uint8_t data);
RingBufferStatus ring_buffer_pop    (RingBuffer_t *ring_buffer, uint8_t *data);
RingBufferStatus ring_buffer_status (RingBuffer_t *ring_buffer);
RingBufferStatus ring_buffer_reset  (RingBuffer_t *ring_buffer);
RingBufferStatus ring_buffer_peek   (RingBuffer_t *ring_buffer);

#endif /* LIB_INCLUDE_RINGBUFFER_H_ */
