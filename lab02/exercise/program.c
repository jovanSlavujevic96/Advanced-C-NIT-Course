/**
 * @title Task 3
 *
 * @brief program.c contains a program similar to one from the previous exercise. The program reads size of array and elements from the standard input,
 * then it sorts elements in nondecreasing order, and at the end it prints out elements form the sorted array up to three different thresholds.
 * The program also prints out indexes that elements had in the original array, before sorting.
 *
 * Change the program so that it would compile and run correctly on every platform that supports C99 standard (regardless of type sizes on that platform).
 * Also, make the program use as little data memory as necessary. (Hint: Note that the maximal number of elements is 30000.)
 *
 * The idea is to use types form stdint.h to replace direct usage of all integer types.
 * Also, look out for places where to use format macro constants from inttypes.h.
 *
 * As a result of this task, upload the files program.c that contains the solution.
 *
 * @author Jovan Slavujevic
 */

#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>

enum tresholds_t
{
	TRESHOLDS_FIRST = 10,
	TRESHOLDS_SECOND,
	TRESHOLDS_THIRD = 20
};

void sort(int_least32_t* values, int_least16_t* indexes, int_least16_t n)
{
	int_least16_t i;
	int_least16_t j;
	for (i = 0; i < (n - 1); i++)
	{
		for (j = i + 1; j < n; j++)
		{
			if (values[i] > values[j])
			{
				int_least32_t tmp;
				tmp = values[i];
				values[i] = values[j];
				values[j] = tmp;

				tmp = indexes[i];
				indexes[i] = indexes[j];
				indexes[j] = tmp;
			}
		}
	}
}


void print(int_least32_t* values, int_least16_t* indexes, int_least16_t n)
{
	int_least16_t i = 0;
	printf("Up to the first treshold: ");
	while (values[i] < TRESHOLDS_FIRST && i < n)
	{
		printf("%" PRIdLEAST32 "(%" PRIdLEAST16 ") ", values[i], indexes[i]);
		i++;
	}
	printf("\n");
	printf("Up to the second treshold: ");
	while (values[i] < TRESHOLDS_SECOND && i < n)
	{
		printf("%" PRIdLEAST32 "(%" PRIdLEAST16 ") ", values[i], indexes[i]);
		i++;
	}
	printf("\n");
	printf("Up to the third treshold: ");
	while (values[i] < TRESHOLDS_THIRD && i < n)
	{
		printf("%" PRIdLEAST32 "(%" PRIdLEAST16 ") ", values[i], indexes[i]);
		i++;
	}
}


void main()
{
	int_least32_t values[30000];
	int_least16_t indexes[30000];
	int_least16_t i;
	int_least16_t n;

	printf("Number of elements: ");
	scanf("%" SCNdLEAST16, &n);
	printf("\n");
	for (i = 0; i < n; i++)
	{
		printf("%" PRIdLEAST16 ". element: ", i);
		scanf("%" PRIdLEAST32, &values[i]);
		indexes[i] = i;
		printf("\n");
	}

	sort(values, indexes, n);

	print(values, indexes, n);
}
