/**
 * @author Jovan Slavujevic
 */

#pragma once

#include <stddef.h>
#include <stdint.h>

/**
 * @brief The data type to be used for the stack element should be adjustable through preprocessing directives.
 * NOTE: Preprocessing directive replaced by typedef because of MISRA warning.
 */
typedef int DATA_TYPE;

typedef void (*PRINT_TYPE)(const DATA_TYPE *data);
typedef void *(*MALLOC_TYPE)(size_t size);
typedef void (*FREE_TYPE)(void *ptr);

/**
 * @brief Stack structure
 */
typedef struct
{
    DATA_TYPE *buffer;
    int_least32_t top;
    int_least32_t capacity;

    PRINT_TYPE custom_print;
    MALLOC_TYPE custom_malloc;
    FREE_TYPE custom_free;
} Stack;

/**
 * @brief Initializes passed stack - allocates it's buffer by passed length
 *
 * @param to_init_stack - stack structure instance to be initialized. Can't be NULL
 * @param length - desired length for stack buffer
 * @param print_func - function pointer which prints passed element from stack. Can't be NULL.
 * @param malloc_func - function pointer which allocates passed array. Can't be NULL.
 * @param free_func - function pointer which frees passed array. Can't be NULL.
 *
 * @return success of alloc
 * @retval 1 - alloc succeed
 * @retval 0 - alloc failed
 */
int_least32_t Stack_Create(Stack *to_init_stack, size_t length, PRINT_TYPE print_func, MALLOC_TYPE malloc_func,
                           FREE_TYPE free_func);

/**
 * @brief Deinitializes passed stack - frees it's buffer if buffer is not NULL, otherwise ignores it
 *
 * @param to_destroy_stack - stack structure instance to be dinitialzied. Can't be NULL
 */
void Stack_Destroy(Stack *to_destroy_stack);

/**
 * @brief Inserts data into the stack.
 *
 * @param to_instert_stack - stack structure instance which stores the data. Can't be NULL.
 * @param data - data to be inserted.
 *
 * @return success of insert action
 * @retval 1 - data successfully inserted
 * @retval 0 - stack is full
 */
int_least32_t Stack_Insert(Stack *to_instert_stack, DATA_TYPE data);

/**
 * @brief Removes data from the stack and returns it.
 *
 * @param to_erase_from_stack - stack structure instance which stores the data. Can't be NULL.
 * @param data - storage for removed data. Can be NULL.
 *
 * @return success of remove action
 * @retval 1 - data successfully removed
 * @retval 0 - stack is empty
 */
int_least32_t Stack_Remove(Stack *to_erase_from_stack, DATA_TYPE *out);

/**
 * @brief checks wheter the stack is empty
 *
 * @param to_check_stack - stack structure instance which stores the data. Can't be NULL.
 *
 * @return is stack empty ?
 * @retval 1 - stack is empty
 * @retval 0 - stack is not empty
 */
int_least32_t Stack_IsEmpty(const Stack *to_check_stack);

/**
 * @brief prints stack elements from top to bottom
 *
 * @param to_print_stack - stack structure instance which stores the data. Can't be NULL.
 */
void Stack_Print(const Stack *to_print_stack);
