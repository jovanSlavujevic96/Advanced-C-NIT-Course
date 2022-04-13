#include <stdio.h>
#include <stdlib.h>

#include "circular_buffer.h"

int CircularInit(CircularBuffer* circ_buf, size_t maxlen)
{
    DATA_TYPE** tmp = (DATA_TYPE**)&circ_buf->buffer;
    *tmp = (DATA_TYPE*)malloc(sizeof(DATA_TYPE)*maxlen);
    if (*tmp)
    {
        CircularEmptyBuff(circ_buf);
        circ_buf->maxlen = maxlen; // one field has been wasted because of missing full flag
        return 1;
    }
    return 0;
}

void CircularDeinit(CircularBuffer* circ_buf)
{
    DATA_TYPE** tmp = (DATA_TYPE**)&circ_buf->buffer;
    if (*tmp)
    {
        free(*tmp);
    }
    circ_buf->head = circ_buf->tail = *tmp = NULL;
    circ_buf->maxlen = 0;
}

int CircularIsEmpty(const CircularBuffer* circ_buf)
{
    return (circ_buf->head == circ_buf->tail);
}

int CircularIsFull(const CircularBuffer* circ_buf)
{
    const DATA_TYPE* end = circ_buf->head + 1;
    if (end == circ_buf->buffer + circ_buf->maxlen)
    {
        end = circ_buf->buffer;
    }
    return (end == circ_buf->tail);
}

int CircularPut(CircularBuffer* circ_buf, DATA_TYPE data)
{
    if (CircularIsFull(circ_buf))
    {
        // no place to put element
        return 0;
    }
    *circ_buf->head = data;
    circ_buf->head++;
    if (circ_buf->head == circ_buf->buffer + circ_buf->maxlen)
    {
        circ_buf->head = circ_buf->buffer;
    }
    return 1;
}

int CircularGet(CircularBuffer* circ_buf, DATA_TYPE* out)
{
    if (CircularIsEmpty(circ_buf))
    {
        // no element to get
        return 0;
    }
    *out = *circ_buf->tail;
    circ_buf->tail++;
    if (circ_buf->tail == circ_buf->buffer + circ_buf->maxlen)
    {
        circ_buf->tail = circ_buf->buffer;
    }
    return 1;
}

void CircularEmptyBuff(CircularBuffer* circ_buf)
{
    circ_buf->head = circ_buf->tail = circ_buf->buffer;
}

void CircularDump(const CircularBuffer* circ_buf, void(*print)(const DATA_TYPE* data))
{
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
        printf("%d : ", abs(circ_buf->buffer - it));
        (*print)(it);
        printf("\n");

        it++;
        if (it == circ_buf->buffer + circ_buf->maxlen)
        {
            it = circ_buf->buffer;
        }
    }
}
