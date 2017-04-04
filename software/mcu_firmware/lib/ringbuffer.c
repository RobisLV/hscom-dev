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
uint16_t ring_buffer_push(RingBuffer_t *ring_buffer, uint8_t data){
    // next_address is where head will point to after this write
    uint16_t next_address = ring_buffer->head + 1;
    // check if circular buffer is full
    if (next_address == ring_buffer->tail){
        // return error if it is
        return EXIT_FAILURE;
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
    return EXIT_SUCCESS;
}

uint16_t ring_buffer_pop(RingBuffer_t *ring_buffer, uint8_t *data){
    // next is where tail will point to after this read.
    uint16_t next_address = ring_buffer->tail + 1;
    // check if buffer is empty (head and tail pointing to the same address)
    if (ring_buffer->head == ring_buffer->tail){
       // return failure to indicate that buffer is empty
        return EXIT_FAILURE;
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
    return EXIT_SUCCESS;
}

uint16_t ring_buffer_empty(RingBuffer_t *ring_buffer){
    if (ring_buffer->head == ring_buffer->tail){
       // return failure to indicate that buffer is empty
        return 1;
    }
    return 0;
}

uint16_t ring_buffer_full(RingBuffer_t *ring_buffer){
    // next_address is where head will point to after this write
    uint16_t next_address = ring_buffer->head + 1;
    // check if circular buffer is full
    if (next_address == ring_buffer->tail){
        // return error if it is
        return 1;
    }
    return 0;
}
