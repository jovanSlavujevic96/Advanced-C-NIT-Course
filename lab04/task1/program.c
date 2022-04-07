/**
 * @title Taks 1
 *
 * @brief This is continuation on the program in program.c file from the previous exercises.This time the program is changed in the following ways. Instead of two arrays – one for values,
 * and one for initial indexes – now there is only one array of structures with separate fields for value and index. Additionally, now a user can select the threshold, as well as algorithm
 * which will be used for sorting: bubble sort or quick sort.
 *
 * Here are the tasks:
 * 1) From within function quick_sort, for which the empty body is given, call standard library function qsort. Here is the description of qsort function, copied directly from C99 standard.
 * qsort Synopsis
 *
 * #include <stdlib.h>
 * void qsort(void* base, size_t nmemb, size_t size, int (*compar)(const void*, const void*));
 *
 * Description
 * The qsort function sorts an array of nmemb objects, the initial element of which is pointed to by base. The size of each object is specified by size.
 *
 * The contents of the array are sorted into ascending order according to a comparison function pointed to by compar, which is called with two arguments that point to the objects being compared.
 * The function shall return an integer less than, equal to, or greater than zero if the first argument is considered to be respectively less than, equal to, or greater than the second.
 *
 * If two elements compare as equal, their order in the resulting sorted array is unspecified.
 *
 * The qsort function returns no value.
 *
 * 2) Remove switch statements from code, and implement their functionality (which is selection of the threshold and sorting function) in a different way (Hint: look-up/jump tables).
 *
 * 3) Enter the following 10 element array: 41, 55, 27, 33, 33, 33, 27, 79, 15, 50. Select the first threshold (with the index 1). Compare results with both sorting algorithms. Analyze what you observe.
 *
 * @author Jovan Slavujevic
 */

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <inttypes.h>


static const int_least32_t treshold1 = 20;
static const int_least32_t treshold2 = 30;
static const int_least32_t treshold3 = 40;


typedef struct _s
{
	int_least32_t value;
	int_least16_t index;
} val_ind_struct_t;

static val_ind_struct_t struct_array[4000];


static void bubble_sort(val_ind_struct_t* str_array, int_least16_t n)
{
	int_least16_t i;
	int_least16_t j;
	for (i = 0; i < (n - 1); i++)
	{
		for (j = i + 1; j < n; j++)
		{
			if (str_array[i].value < str_array[j].value)
			{
				val_ind_struct_t tmp;

				tmp = str_array[i];
				str_array[i] = str_array[j];
				str_array[j] = tmp;
			}
		}
	}
}


static int comparator(const void* l, const void* r)
{
	int ret = 0;
	const val_ind_struct_t* left  = (val_ind_struct_t*)l;
	const val_ind_struct_t* right = (val_ind_struct_t*)r;

	if (left->value < right->value)
	{
		ret = 1;
	}
	else if (left->value < right->value)
	{
		ret = -1;
	}
	return ret;
}

static void quick_sort(val_ind_struct_t* str_array, int_least16_t n)
{
	// sort using qsort standard function
	qsort(struct_array, n, sizeof(val_ind_struct_t), comparator);
}


static void print(const val_ind_struct_t* str_array, int_least16_t n, int_fast8_t tr_index)
{
	int_least16_t i = 0;
	printf("Up to the %"PRIdFAST8". treshold: ", tr_index);

	const int_least32_t tresholds[] = {treshold1, treshold2, treshold3}; // look-up table

	while (str_array[i].value > tresholds[tr_index-1] && i < n)
	{
		printf("%"PRIdLEAST32"(%"PRIdLEAST16") ", str_array[i].value, str_array[i].index);
		i++;
	}
	printf("\n");
}


void main()
{
	int_least16_t i;
	int_least16_t n;
	int_fast8_t treshold_index;
	int_fast8_t sort_index;

	void (*sort_func_table[])(val_ind_struct_t*, int_least16_t) = {bubble_sort, quick_sort}; // jump table

	printf("Number of elements: ");
	scanf("%"SCNdLEAST16, &n);
	printf("\n");

	for (i = 0; i < n; i++)
	{
		printf("%"PRIdLEAST16". element: ", i);
		scanf("%"SCNdLEAST32, &(struct_array[i].value));
		struct_array[i].index = i;
		printf("\n");
	}

	printf("Trashold you want to use (1, 2, or 3): ");
	scanf("%"SCNdFAST8, &treshold_index);
	printf("\n");

	printf("Sorting algorithm you want to use (1- bubble, 2- quick): ");
	scanf("%"SCNdFAST8, &sort_index);
	printf("\n");

	sort_func_table[sort_index-1](struct_array, n);

	print(struct_array, n, treshold_index);
}
