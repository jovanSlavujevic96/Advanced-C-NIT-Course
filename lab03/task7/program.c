/**
 * @title Task 7
 *
 * @brief Copy the solution of task 5 into the folder for task 7.
 *
 * Extend function print so that it determines which even numbers in the array are less than the value defined by the constant variable threshold.
 * Make the function return those numbers and their indexes back to function main, and then function main should print it on the standard output.
 * Modify the program so that there are no global variables (i.e. everything is passed through parameters or return values).
 *
 * @author Jovan Slavujevic
 */

#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>

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

void print(const int_least32_t* const values, const int_least16_t* const indexes, int_least16_t n,
	int_least32_t threshold, int_least32_t* const values_out, int_least16_t* const indexes_out, int_least16_t* const indexes_count)
{
	int_least16_t i = 0;
	printf("Up to the first treshold: ");
	while (values[i] > threshold && i < n)
	{
		printf("%"PRIdLEAST32"(%"PRIdLEAST16") ", values[i], indexes[i]);
		i++;
	}
	printf("\n");

	/***************************************************
	 ******************** EXTENDED *********************
	 **************************************************/
	for (i = 0, *indexes_count = 0; i < n; i++)
	{
		if (indexes[i] % 2) // not even
		{
			continue;
		}
		if (values[i] < threshold)
		{
			values_out[*indexes_count] = values[i];
			indexes_out[*indexes_count] = indexes[i];
			(*indexes_count)++;
		}
	}
}


void main()
{
	// MOVED GLOBAL VARIABLES TO main FUNC
	const int_least8_t TRESHOLD = 20;

	int_least32_t values[4000];
	int_least16_t indexes[4000];

	int_least32_t values_even[2000]; // half of them are even
	int_least16_t indexes_even[2000];
	int_least16_t indexes_count = 0;

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

	print(values, indexes, n, TRESHOLD, values_even, indexes_even, &indexes_count);


	/***************************************************
	 ******************** EXTENDED *********************
	 **************************************************/
	printf("\n");
	printf("Even numbers less than threshold {%"SCNdLEAST32"}\n", TRESHOLD);
	printf("\n");
	for (i = 0; i < indexes_count; i++)
	{
		printf("%"PRIdLEAST32"(%"PRIdLEAST16") ", values_even[i], indexes_even[i]);
	}
	printf("\n");

}
