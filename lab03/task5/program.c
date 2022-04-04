/**
 * @title Task 5
 *
 * @brief In file program.c there is a similar program to what we had in the previous two exercises.
 * Add const qualifier where it makes sense. Remove usage of #define directive.
 * Clean up code in terms of linkage and storage duration of variables and functions.
 *
 * @author Jovan Slavujevic
 */

#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>

// Removed usage of #define directive
const int_least8_t TRESHOLD = 20;

int_least32_t values[4000];
int_least16_t indexes[4000];

// CONSTANT POINTER
// Added const qualifier to the pointer because it won't change the pointing address
void sort(int_least32_t* const values, int_least16_t* const indexes, int_least16_t n)
{
	int_least16_t i;
	int_least16_t j;
	for (i = 0; i < (n - 1); i++)
	{
		for (j = i + 1; j < n; j++)
		{
			if (values[i] < values[j])
			{
				int_least32_t tmp;
				int_least16_t tmp1;

				tmp = values[i];
				values[i] = values[j];
				values[j] = tmp;

				tmp1 = indexes[i];
				indexes[i] = indexes[j];
				indexes[j] = tmp1;
			}
		}
	}
}

// CONSTANT POINTER TO CONSTANT
// Added const qualifier to the pointer because it won't change the pointing address
// Added const qualifier to the pointee because it won't change it
void print(const int_least32_t* const values, const int_least16_t* const indexes, int_least16_t n)
{
	int_least16_t i = 0;
	printf("Up to the first treshold: ");
	while (values[i] > TRESHOLD && i < n)
	{
		printf("%"PRIdLEAST32"(%"PRIdLEAST16") ", values[i], indexes[i]);
		i++;
	}
	printf("\n");
}


void main()
{
	int_least16_t i;
	int_least16_t n;

	printf("Number of elements: ");
	scanf("%"SCNdLEAST16"", &n);
	printf("\n");
	for (i = 0; i < n; i++)
	{
		printf("%"PRIdLEAST16". element: ", i);
		scanf("%"SCNdLEAST32"", &values[i]);
		indexes[i] = i;
		printf("\n");
	}

	sort(values, indexes, n);

	print(values, indexes, n);
}
