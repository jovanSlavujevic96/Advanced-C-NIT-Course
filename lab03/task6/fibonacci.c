#include "fibonacci.h"


int_least64_t fibonacci(int_least16_t n)
{
	if (n <= 1)
		return n;
	else
		return (fibonacci(n-1) + fibonacci(n-2));
}
