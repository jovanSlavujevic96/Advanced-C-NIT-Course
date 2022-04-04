/**
 * @title Task 2
 *
 * @brief Modify object_lifetime_e1.c example so that variable x become visible from main and foo functions.
 * Remove parameter from function foo. Build and run the code.
 *
 * @author Jovan Slavujevic
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int_least8_t foo(void);

// PUT x variable declaration/definition outside of functions
// it now has static duration & visibility
static int_least8_t x;

int main(int argc, char** argv)
{
	printf("Local variable scope\n");

	x = 42;
	foo();
	printf("After calling foo: x = %d\n", x);

	return EXIT_SUCCESS;
}

int_least8_t foo(void)
{
	x = 101;
	printf("Inside foo: x = %d\n", x);
	return x;
}
