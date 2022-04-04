/**
 * @title Task 6
 *
 * @brief In this task, you are given the implementation of a recursive function that returns the n-th number from the Fibonacci sequence,
 * where n is passed as input. Function declaration is in fibonacci.h, and definition in fibonacci.c.
 *
 * Fibonacci numbers is a name for a sequence of numbers where each element is a sum of the previous two; except, of course, for the first two elements:
 * Fn = Fn-1 + Fn-2,       F0 = 0 and F1 =1
 *
 * Compile and run the program for different values of Fibonacci sequence index (e.g. for 14, 44, 60).
 * The index is passed to the program as a command-line argument and it should be an integer from this range [0, 32767].
 * Check whether the program works correctly for all input arguments. It does not work correctly in some cases, try to answer why.
 *
 * Implement the same function, but without recursion. Use loops. Test this version with the same arguments as the previous one. Compare results and execution time of two versions.
 *
 * @author Jovan Slavujevic
 */

#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>
#include "fibonacci.h"

static const int EXPECTED_NUM_ARGS = 2;

int main(int argc, char *argv[])
{
	int ret_val = EXIT_SUCCESS;

	// Check if argument number is valid
	if(argc != EXPECTED_NUM_ARGS)
	{
		printf("Error: Missing program argument.\nCall function using following command: \n");
		printf("%s [index_of_fib_number]\n", argv[0]);
		ret_val = EXIT_FAILURE;
	}
	else
	{
		// Convert argument to integer
		int x = atoi(argv[1]);

		// Check if argument range is valid
		if (x < 0 || x > INT_LEAST16_MAX)
		{
			printf("Error: Fibbonaci number index must be in interval [0, %d].\n", INT_LEAST16_MAX);
			ret_val = EXIT_FAILURE;
		}
		else
		{
			// Execute function and print the output
			printf("Fibonacci number %"PRIdLEAST16" is %"PRIdLEAST64"\n", x, myFibonacci(x));
		}
	}

	return ret_val;
}
