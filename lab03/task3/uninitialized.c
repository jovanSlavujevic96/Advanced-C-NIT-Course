/**
 * @title Task 3
 *
 * @brief Illustration of difference of various kinds of uninitialized local variables. Build and run the code from the file uninitialized.c.
 *
 * @author Jovan Slavujevic
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

// static duration variable initialized to zero
int32_t global;

void foo();

int main(void)
{
	printf("================================\n");
	printf("Uninitialized variables\n");
	printf("================================\n");

	foo();


	return EXIT_SUCCESS;
}

void foo()
{
	// automatic duration variable not initialized
	int32_t local;

	// static duration variable initialized to zero
	static int32_t static_local;

	if (local % 2)
	{
		printf("TRUE : global = %d, local = %d, static_local = %d\n", global, local, static_local);
	}
	else
	{
		printf("FALSE : global = %d, local = %d, static_local = %d\n", global, local, static_local);
	}
}