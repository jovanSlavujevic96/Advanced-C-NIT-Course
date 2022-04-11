#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>

#include "circular_buffer.h"

void CircularInit(CircularBuffer* circ_buf, size_t maxlen)
{
    DATA_TYPE** tmp = (DATA_TYPE**)&circ_buf->buffer;
    *tmp = (DATA_TYPE*)malloc(sizeof(DATA_TYPE)*maxlen);
    circ_buf->head = circ_buf->tail = circ_buf->buffer;
    circ_buf->full = false;
    circ_buf->maxlen = maxlen;
}

void CircularDeinit(CircularBuffer* circ_buf)
{
    DATA_TYPE** tmp = (DATA_TYPE**)&circ_buf->buffer;
    free(*tmp);
    circ_buf->head = circ_buf->tail = *tmp = NULL;
    circ_buf->full = false;
    circ_buf->maxlen = 0;
}

int CircularIsEmpty(const CircularBuffer* circ_buf)
{
    return (!circ_buf->full) && (circ_buf->head == circ_buf->tail);
}

int CircularIsFull(const CircularBuffer* circ_buf)
{
    return circ_buf->full;
}

void CircularPut(CircularBuffer* circ_buf, DATA_TYPE data)
{
    if (CircularIsFull(circ_buf))
    {
        // no place to put element
        return;
    }
    *circ_buf->head = data;
    circ_buf->head++;
    if (circ_buf->head == circ_buf->buffer + circ_buf->maxlen)
    {
        circ_buf->head = circ_buf->buffer;
    }
    circ_buf->full = (circ_buf->head == circ_buf->tail);
}

void CircularGet(CircularBuffer* circ_buf, DATA_TYPE* out)
{
    if (CircularIsEmpty(circ_buf))
    {
        // no element to get
        return;
    }
    *out = *circ_buf->tail;
    circ_buf->tail++;
    if (circ_buf->tail == circ_buf->buffer + circ_buf->maxlen)
    {
        circ_buf->tail = circ_buf->buffer;
    }
    circ_buf->full = false;
}

void CircularEmptyBuff(CircularBuffer* circ_buf)
{
    circ_buf->head = circ_buf->tail = circ_buf->buffer;
    circ_buf->full = false;
}

void CircularDump(const CircularBuffer* circ_buf)
{
    int64_t tmp;
    const DATA_TYPE* it;
    const DATA_TYPE* end;
    if (CircularIsEmpty(circ_buf))
    {
        return;
    }
    if (CircularIsFull(circ_buf))
    {
        if (circ_buf->head - 1 >= circ_buf->buffer)
        {
            end = circ_buf->head - 1;
        }
        else
        {
            end = circ_buf->buffer + circ_buf->maxlen;
        }
    }
    else
    {
        end = circ_buf->head;
    }
    for (it = circ_buf->tail; it != end;)
    {
        tmp = *it;
        printf("%d : %ld\n", abs(circ_buf->buffer - it), tmp);
        it++;
        if (it == circ_buf->buffer + circ_buf->maxlen)
        {
            it = circ_buf->buffer;
        }
    }
}
