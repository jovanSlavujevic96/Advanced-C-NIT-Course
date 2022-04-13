/**
 * @title Task 1
 *
 * @brief Implement circular buffer that uses two pointers (not indexes) and without additional variable for tracking size
 * (therefore, with one empty field when full). Type size, as well as type of its data should be adjustable through
 * preprocessing directives. Then, set the data type to be int, and size 10. Implement the buffer in a separate module
 * (circular_buffer.h and circular_buffer.c). The buffer itself should be contained in structure named CircularBuffer.
 *
 * These functions represent the interface to the buffer (and they should be implemented in its module):
 *
 * CircularInit – Initializes given buffer (specified by function argument). Has to be called before the first use.
 * CircularIsFull – Checks whether a given buffer (specified by function argument) is full. Returns zero if it is not, and 1 if it is.
 * CircularIsEmpty – Similar to the previous function. Returns 1 if the buffer is empty, and zero if it not.
 * CircularPut – Adds element to the buffer (specified by function argument). Does not check for overflow!
 * CircularGet – Removes element form the buffer (specified by function argument), and returns its value. Does not check for underflow!
 * CircularEmptyBuff – Empties buffer completely. Resetting the buffer, in essence.
 * CircularDump – Prints out buffer content to the standard output. (Note that type of buffer elements can vary).
 *
 * All of the above functions should have pointer to CircularBuffer as the first argument (const version if appropriate).
 *
 * Create main.c, include circular_buffer.h and play with the buffer. Create more than one circular buffers.
 * Check the correctness of all the functions all the relevant situations that you can think of.
 *
 * Hint: Maybe try first to implement simple CircularBuffer with elements of int type and size 10. When you finish,
 * try to see how you can adjust those two with preprocessing directives.
 *
 * Additional (advanced) task 1: Make static library from circular_buffer module.
 *
 * Additional (advanced) task 2: The task specifies that buffer size should be the same for all the circular buffers that we make.
 * However, it is possible to change the implementation so that you can set the size of a circular buffer through CircularInit function.
 * What needs to be changed? What are implications to module interface (i.e. the other functions that work with circular buffer)?
 *
 * @author Jovan Slavujevic
 */

#include <stdio.h>
#include <inttypes.h>

#include "circular_buffer.h"

void print_data(const DATA_TYPE* data)
{
    printf("%" PRIdLEAST32, *data);
}

int main()
{
    int i;
    CircularBuffer buf;

    CircularInit(&buf, DATA_SIZE);
    for (i = 0; i < DATA_SIZE; ++i)
    {
        CircularPut(&buf, i);
    }

    CircularGet(&buf, &i);
    CircularGet(&buf, &i);

    printf("DUMP 1\n");
    CircularDump(&buf, &print_data);

    CircularPut(&buf, 502);

    printf("DUMP 2\n");
    CircularDump(&buf, &print_data);

    CircularGet(&buf, &i);
    CircularGet(&buf, &i);
    CircularPut(&buf, 404);

    printf("DUMP 3\n");
    CircularDump(&buf, &print_data);

    CircularDeinit(&buf);

    return 0;
}
