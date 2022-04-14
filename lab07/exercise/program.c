/**
 * @title Task 1
 *
 * @brief Program in the file program.c takes given array and sorts it in nonincreasing order,
 * and then prints out elements as long as they are larger from a value defined by the symbol TRESHOLD.
 * Along with element values, the program prints out indexes, which the elements had in the initial array, prior to the sorting.
 *
 * Try to understand the program.
 * Check if it runs correctly.
 * Which function does not work correctly?
 * Place a break-point at the start of the function. Step through the function and monitor the values and variables. See where the error is happening and fix it.
 * Check the program again if it runs correctly.
 *
 * @author Jovan Slavujevic
 */

#include <stdint.h>

#include "my_print.h"

/* FIX: removed unsigned type suffix */
#define TRESHOLD 2000000000

/**
 * Sorts arrays "values" and "indexes" (which contains initial indexes)
 * Array is sorted in nonincreasing order using "bubble sort" algorithm
 */
void sort(int_least32_t values[], int_least32_t indexes[], int_least32_t n);

/**
 * Prints values and their initial indexes on the standard output
 * as long as the values are larger than the value defined by TRESHOLD
 */
void print(const int_least32_t values[], const int_least32_t indexes[], int_least32_t n);

/**
 * Print and init before processing
 */
void init(const int_least32_t values[], int_least32_t indexes[], int_least32_t n);

/**
 * Main function
 */
void main(void);

void main(void)
{
    int_least32_t values_array[10] = {2123874386, -2047433648, 2147287536, 2147000000, -2000021030, 2107487649, 2137433633, 2113426428, 2012345678, 2147182248};
    int_least32_t indexes_array[10] = { 0 };
    int_least32_t elements_in_array = 10;

    init(values_array, indexes_array, elements_in_array);

    sort(values_array, indexes_array, elements_in_array);

    print(values_array, indexes_array, elements_in_array);
}

void init(const int_least32_t values[], int_least32_t indexes[], int_least32_t n)
{
    int_least32_t init_it;
    for (init_it = 0; init_it < n; init_it++)
    {
        my_printf("%d. element: %d", init_it, values[init_it]);
        indexes[init_it] = init_it;
        my_printf("\n");
    }
}

void sort(int_least32_t values[], int_least32_t indexes[], int_least32_t n)
{
    int_least32_t sort_it;
    int_least32_t sort_it_2;
    for (sort_it = 0; sort_it < (n - 1); sort_it++)
    {
        for (sort_it_2 = sort_it + 1; sort_it_2 < n; sort_it_2++)
        {
            /* FIX: replaced comparing of substraction by comparing between numbers */
            if (values[sort_it] < values[sort_it_2])
            {
                int_least32_t tmp;
                tmp = values[sort_it];
                values[sort_it] = values[sort_it_2];
                values[sort_it_2] = tmp;

                tmp = indexes[sort_it];
                indexes[sort_it] = indexes[sort_it_2];
                indexes[sort_it_2] = tmp;
            }
        }
    }
}

void print(const int_least32_t values[], const int_least32_t indexes[], int_least32_t n)
{
    int_least32_t print_it = 0;
    my_printf("Up to the first treshold: ");

    /* FIX: Added (i<n) in order to stop iteration through fixed array */
    while ((print_it < n) && (values[print_it] > TRESHOLD))
    {
        my_printf("%d(%d) ", values[print_it], indexes[print_it]);
        print_it++;
    }
    my_printf("\n");
}
