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

#include <stdio.h>

// FIX: removed unsigned type suffix
#define TRESHOLD 2000000000

// Sorts arrays "values" and "indexes" (which contains initial indexes)
// Array is sorted in nonincreasing order using "bubble sort" algorithm
void sort(int *values, int *indexes, int n)
{
    int i;
    int j;
    for (i = 0; i < (n - 1); i++)
    {
        for (j = i + 1; j < n; j++)
        {
            // FIX: replaced comparing of substraction by comparing between numbers
            if (values[i] < values[j])
            {
                int tmp;
                tmp = values[i];
                values[i] = values[j];
                values[j] = tmp;

                tmp = indexes[i];
                indexes[i] = indexes[j];
                indexes[j] = tmp;
            }
        }
    }
}


// Prints values and their initial indexes on the standard output
// as long as the values are larger than the value defined by TRESHOLD
void print(int *values, int *indexes, int n)
{
    int i = 0;
    printf("Up to the first treshold: ");
    while (values[i] > TRESHOLD)
    {
        printf("%d(%d) ", values[i], indexes[i]);
        i++;
    }
    printf("\n");
}


void main()
{
    int values[10] = {2123874386, -2047433648, 2147287536, 2147000000, -2000021030, 2107487649, 2137433633, 2113426428, 2012345678, 2147182248};
    int indexes[10];
    int n = 10;
    int i;

    for (i = 0; i < n; i++)
    {
        printf("%d. element: %d", i, values[i]);
        indexes[i] = i;
        printf("\n");
    }

    sort(values, indexes, n);

    print(values, indexes, n);
}
