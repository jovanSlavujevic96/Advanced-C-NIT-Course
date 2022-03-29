/**
 * @title Example 3
 *
 * @brief The program illustrates reading from uninitialized memory.
 * The program should calculate the sum of first N natural numbers and print result on the screen.
 *
 * Compile and then run the program a few times. See if you always get the same result.
 * If it does always produce the same result, try to add this: int x = 1; at the beginning of function main,
 * just before declaration of variable sum.  After that try compiling and running the program again.
 * Analyze the code and try to find and fix the bug.
 *
 * @author Jovan Slavujevic
 */

#include <stdio.h>

static const int num = 5;

int main()
{
    int x = 1;

    // FIX: assigned inital value for sum
    int sum = 0;

    // for loop -> sums first N numbers
    for (int i = 1; i <= num; i++)
    {
        sum += i;
    }

    // prints sum of first N numbers
    printf("Sum of first %d natural numbers is: %d \n", num, sum);

    return 0;
}
