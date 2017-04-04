/*
 * ringbuffer.h
 *
 *  Created on: 2017. gada 3. apr.
 *      Author: Roberts
 */
#include <stdint.h>
#include "macros.h"

#ifndef LIB_INCLUDE_RINGBUFFER_H_
#define LIB_INCLUDE_RINGBUFFER_H_

/* Ring buffer structure    */
typedef struct {
    uint8_t * const buffer;     /* constant pointer to a an array           */
    const uint16_t max_length;  /* specifies the length of buffer           */
    uint16_t head;              /* points to the head of buffer (write)     */
    uint16_t tail;              /* points to the tail of buffer (read)      */
} RingBuffer_t;

uint16_t ring_buffer_push   (RingBuffer_t *ring_buffer, uint8_t data);
uint16_t ring_buffer_pop    (RingBuffer_t *ring_buffer, uint8_t *data);
uint16_t ring_buffer_empty  (RingBuffer_t *ring_buffer);
uint16_t ring_buffer_full   (RingBuffer_t *ring_buffer);

#endif /* LIB_INCLUDE_RINGBUFFER_H_ */
