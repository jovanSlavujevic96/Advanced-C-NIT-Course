/**
 * @title Example 1
 *
 * @brief The program illustrates one example of easy to reproduce the catchable bug.
 * Program should enable a user to enter A and B, and then prints out the sum of those numbers on the screen.
 *
 * Analyze code in example1.c.
 * Find and fix the bug.
 *
 * Hint: pay attention to the result of function  sum.
 *
 * @author Jovan Slavujevic
 */

#include <stdio.h>

int sum(int x, int y)
{
    // FIX: put `+` instead of `*`
    int z = x + y;
    return z;
}

int main()
{
    int A;
    int B;

    //  Enter A
    printf("Enter A: ");
    scanf("%d", &A);
    printf("\n");

    //  Enter B
    printf("Enter B: ");
    scanf("%d", &B);
    printf("\n");

    // sum of entered numbers
    printf("Sum of A and B is %d \n", sum(A, B));

    return 0;
}
