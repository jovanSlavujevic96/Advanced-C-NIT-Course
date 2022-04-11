#pragma once

#include <stdint.h>
#include <stdbool.h>

#define DATA_TYPE int
#define DATA_SIZE 10

#define DATA_PRINT PRIdLEAST32

typedef struct
{
    DATA_TYPE* const buffer;
    DATA_TYPE*       head;
    DATA_TYPE*       tail;
    bool             full;
    size_t           maxlen;
} CircularBuffer;

void CircularInit(CircularBuffer* circ_buf, size_t maxlen);
void CircularDeinit(CircularBuffer* circ_buf);
int CircularIsEmpty(const CircularBuffer* circ_buf);
int CircularIsFull(const CircularBuffer* circ_buf);
void CircularPut(CircularBuffer* circ_buf, DATA_TYPE data);
void CircularGet(CircularBuffer* circ_buf, DATA_TYPE* out);
void CircularEmptyBuff(CircularBuffer* circ_buf);
void CircularDump(const CircularBuffer* circ_buf);
