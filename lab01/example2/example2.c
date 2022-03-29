/**
 * @title Example 2
 *
 * @brief The program illustrates an example of elusive bug.
 * The task of the program is to dynamically allocate array of 10 elements using malloc and to place the address of that memory in array1.
 * After that the array is filled with values 0 to 9, then the values of array's elements are printed on screen,
 * and the dynamically allocated memory is released  with free. Now everything is repeated with array2 but with values {0, 10, 20, 30... 90}.
 *
 * Compile and then run the program a few times. See if you always get the same result.
 * Analyze the code and try to find the bug.
 * If you always get the correct result, try to swap lines 42 (free) and 44 (malloc).
 * This change does not change the program but now you might start seeing the effect of the elusive bug.
 * When you find the bug - fix it.
 *
 * Hint: Run the debugger, check values that array1 and array2 get after malloc. Check this for version of the code before and after swap of lines 42 and 44.
 *
 * @author Jovan Slavujevic
 */

#include <stdlib.h>
#include <stdio.h>

static const int array_size = 10;

int main()
{
    int *array1;
    int *array2;

    // alloc array1
    array1 = malloc(array_size * sizeof(int));

    // assign values to array1
    for (int i = 0; i < array_size; i++)
    {
        array1[i] = i;
    }

    // print value from array1
    for (int i = 0; i < array_size; i++)
    {
        printf("%d ", array1[i]);
    }

    // newline
    printf("\n");


    // alloc array2
    array2 = malloc(array_size * sizeof(int));

    // free array1
    free(array1);

    // assign values to arrayX
    for (int i = 0; i < array_size; i++)
    {
        // FIX: repalced array1 by array
        array2[i] = 10 * i;
    }

    // print values from array2
    for (int i = 0; i < array_size; i++)
    {
        printf("%d ", array2[i]);
    }

    // print newline
    printf("\n");

    // free array2
    free(array2);

    return 0;
}
