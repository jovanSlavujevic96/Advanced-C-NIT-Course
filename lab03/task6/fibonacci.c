#include "fibonacci.h"


int_least64_t fibonacci(int_least16_t n)
{
	if (n <= 1)
		return n;
	else
		return (fibonacci(n-1) + fibonacci(n-2));
}

int_least64_t myFibonacci(int_least16_t n)
{
	int_least64_t x1 = 0;
	int_least64_t x2 = 1;
	int_least64_t tmp;

	for (int_least16_t i = 1; i < n; i++)
	{
		tmp = x1 + x2;
		x1 = x2;
		x2 = tmp;
	}

	return x2;
}
