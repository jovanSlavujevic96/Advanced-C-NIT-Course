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
			printf("Fibonacci number %"PRIdLEAST16" is %"PRIdLEAST64"\n", x, fibonacci(x));
		}
	}

	return ret_val;
}
