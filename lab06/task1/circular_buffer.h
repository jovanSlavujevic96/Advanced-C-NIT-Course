#pragma once

#include <stdint.h>

#define DATA_TYPE int
#define DATA_SIZE 10

typedef struct
{
    DATA_TYPE* const buffer;
    DATA_TYPE*       head;
    DATA_TYPE*       tail;
    size_t           maxlen;
} CircularBuffer;

int CircularInit(CircularBuffer* circ_buf, size_t maxlen);
void CircularDeinit(CircularBuffer* circ_buf);
int CircularIsEmpty(const CircularBuffer* circ_buf);
int CircularIsFull(const CircularBuffer* circ_buf);
int CircularPut(CircularBuffer* circ_buf, DATA_TYPE data);
int CircularGet(CircularBuffer* circ_buf, DATA_TYPE* out);
void CircularEmptyBuff(CircularBuffer* circ_buf);
void CircularDump(const CircularBuffer* circ_buf, void (*print)(const DATA_TYPE* data));
