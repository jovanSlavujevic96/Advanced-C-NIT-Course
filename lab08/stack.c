#include "stack.h"

/** @brief Helper macros */
#define SUCCESS 1
#define FAILURE 0
#define EMPTY_BUFFER_INDEX (-1)

/** @defgroup HELPERS */
void reverse_iterate(const DATA_TYPE print_buffer[], int_least32_t start, int_least32_t end, PRINT_TYPE print_func);
void get_from_array(const DATA_TYPE get_buffer[], int_least32_t get_index, DATA_TYPE *assign_out);
void put_to_array(DATA_TYPE put_buffer[], int_least32_t insert_index, DATA_TYPE in);

int_least32_t Stack_Create(Stack *to_init_stack, size_t length, PRINT_TYPE print_func, MALLOC_TYPE malloc_func,
                           FREE_TYPE free_func)
{
    int_least32_t Stack_Create_success = FAILURE;

    /* assign proper function pointers */
    to_init_stack->custom_print = print_func;
    to_init_stack->custom_malloc = malloc_func;
    to_init_stack->custom_free = free_func;

    /* dynamic allocation of buffer */
    to_init_stack->buffer = (DATA_TYPE *)to_init_stack->custom_malloc(length * sizeof(DATA_TYPE));

    /* check is allocation successfull */
    if (to_init_stack->buffer)
    {
        /* assign top iterator & capacity */
        to_init_stack->top = EMPTY_BUFFER_INDEX;
        to_init_stack->capacity = (int_least32_t)length;
        Stack_Create_success = SUCCESS;
    }

    /* exit of function */
    return Stack_Create_success;
}

void Stack_Destroy(Stack *to_destroy_stack)
{
    /* check is buffer allocated / exists */
    if (to_destroy_stack->buffer)
    {
        /* dynamic free of buffer */
        to_destroy_stack->custom_free(to_destroy_stack->buffer);
        to_destroy_stack->buffer = (DATA_TYPE *)NULL;
    }

    /* reset capacity */
    to_destroy_stack->capacity = 0;
}

int_least32_t Stack_Insert(Stack *to_instert_stack, DATA_TYPE data)
{
    int_least32_t Stack_Insert_success = FAILURE;

    /* check is stack full */
    if (to_instert_stack->top < (to_instert_stack->capacity - 1))
    {
        /* increase top iterator and fill the stack buffer */
        to_instert_stack->top++;
        put_to_array(to_instert_stack->buffer, to_instert_stack->top, data);
        Stack_Insert_success = SUCCESS;
    }

    /* exit of function */
    return Stack_Insert_success;
}

int_least32_t Stack_Remove(Stack *to_erase_from_stack, DATA_TYPE *out)
{
    int_least32_t Stack_Remove_success = FAILURE;

    /* check is stack empty */
    if (!Stack_IsEmpty(to_erase_from_stack))
    {
        /* check does out storage exist */
        if (out)
        {
            /* fill storage with top buffer */
            get_from_array(to_erase_from_stack->buffer, to_erase_from_stack->top, out);
        }
        /* decrease top iterator */
        to_erase_from_stack->top--;
        Stack_Remove_success = SUCCESS;
    }

    /* exit of function */
    return Stack_Remove_success;
}

int_least32_t Stack_IsEmpty(const Stack *to_check_stack)
{
    /* checks is stack empty */
    return (to_check_stack->top == EMPTY_BUFFER_INDEX);
}

void Stack_Print(const Stack *to_print_stack)
{
    /* check is stack empty */
    if (!Stack_IsEmpty(to_print_stack))
    {
        /* do reverse iteratiorn throguh buffer and print every element by custom print function */
        reverse_iterate(to_print_stack->buffer, to_print_stack->top, EMPTY_BUFFER_INDEX, to_print_stack->custom_print);
    }
}

/**
 * NOTE: Workaround due to MISA 17.4 warning: "Array indexing shall be the only allowed form of pointer arithmetic"
 */
void reverse_iterate(const DATA_TYPE print_buffer[], int_least32_t start, int_least32_t end, PRINT_TYPE print_func)
{
    int_least32_t i = 0;

    /* do reverse iteratiorn throguh buffer and print every element by custom print function */
    for (i = start; i > end; i--)
    {
        (*print_func)(&print_buffer[i]);
    }
}

void get_from_array(const DATA_TYPE get_buffer[], int_least32_t get_index, DATA_TYPE *assign_out)
{
    /* assign value from buffer to output storage */
    *assign_out = get_buffer[get_index];
}

void put_to_array(DATA_TYPE put_buffer[], int_least32_t insert_index, DATA_TYPE in)
{
    /* assignm value to buffer */
    put_buffer[insert_index] = in;
}
