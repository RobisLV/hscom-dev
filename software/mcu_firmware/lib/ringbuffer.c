/*
 * ringbuffer.c
 *
 *  Created on: 2017. gada 3. apr.
 *      Author: Roberts
 */
#include "ringbuffer.h"

/***************************************************
 * Ring buffer read/write/check functions
 **************************************************/
RingBufferStatus ring_buffer_push(RingBuffer_t *ring_buffer, uint8_t data){
    // next_address is where head will point to after this write
    uint16_t next_address = ring_buffer->head + 1;
    // check if circular buffer is full
    if (next_address == ring_buffer->tail){
        // return error if it is
        return BUFFER_FULL;
    }
    // check if next address does not exceed boundaries of buffer
    if (next_address >= ring_buffer->max_length){
        // if it does, point it to the 0th address
        next_address = 0;
    }
    // push data into the buffer
    ring_buffer->buffer[ring_buffer->head] = data;
    //
    ring_buffer->head = next_address;
    // return success to indicate successful push
    return BUFFER_OK;
}

RingBufferStatus ring_buffer_pop(RingBuffer_t *ring_buffer, uint8_t *data){
    // next is where tail will point to after this read.
    uint16_t next_address = ring_buffer->tail + 1;
    // check if buffer is empty (head and tail pointing to the same address)
    if (ring_buffer->head == ring_buffer->tail){
       // return failure to indicate that buffer is empty
        return BUFFER_EMPTY;
    }
    // check if next address is
    if(next_address >= ring_buffer->max_length){
        // if it does, point it to the 0th address
        next_address = 0;
    }
    // read/pop form the buffer
    *data = ring_buffer->buffer[ring_buffer->tail];
    // set read pointer
    ring_buffer->tail = next_address;
    // return success to indicate successful push.
    return BUFFER_OK;
}

RingBufferStatus ring_buffer_status(RingBuffer_t *ring_buffer){
    // next_address is where head will point to after this write
    uint16_t next_address = ring_buffer->head + 1;
    if (ring_buffer->head == ring_buffer->tail){
       // return failure to indicate that buffer is empty
        return BUFFER_EMPTY;
    }
    // check if circular buffer is full
    else if (next_address == ring_buffer->tail){
        // return error if it is
        return BUFFER_FULL;
    }
    return BUFFER_OK;
}
