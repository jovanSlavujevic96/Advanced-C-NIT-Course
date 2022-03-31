/**
 * @title Task 2
 *
 * @brief The aim of this task is to illustrate binary representation of integer numbers.
 * task2.c has implementation of function printBinary that prints 8 bit integer value on screen in binary format (bit by bit). The functions work in the following way:
 *
 * Initialization of bit-mask that has 1 for the most significant bit.
 * Test for a bit value is performed by AND operation between that number and mask.Operation result represent bit value that is going to be printed on screen.
 * After that mask is shifted once to right.
 * The above three steps are repeated while mask value is different than zero.
 * Functon printSignedChar contains an example of printBinary usage. Passed number is being printed in different formats (hexadecimal,
 * decimal, interpreted as unsigned value and in binary format). With this assignment b = a passed number is converted to 32bit value.
 * That 32bit value is then also printed in the same formats (except binary).
 *
 * You task (after analyzing the given code) is to add code - on places that are marked by comment - which prints 32bit integer value in binary format
 * using function printBinary. The idea for solution is to use pointer to 8bit value and print out 32bit value piece by piece (byte by byte, in this case).
 * When printing the result pay attention to byte order.
 *
 * As a result of this task upload the files task2.c that contains the solution.
 *
 * @author Jovan Slavujevic
 */

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdint.h>
#include <stdbool.h>

#define IS_BIG_ENDIAN (!*(unsigned char *)&(uint16_t){1})


void printBinary(uint8_t* number);
void printSignedChar(int8_t num);

/**
 * @brief prints number in form of byte array
 *
 * @param start - pointer to starting position of array
 * @param end - pointer to ending postition of array
 */
void printBinaries(uint8_t* start, uint8_t* end);


int main()
{
	printf("================================\n");
	printf("Exercise2\n");
	printf("================================\n");

	int32_t intNumber= 1;

	//---------------------------------------------------------
	// This is where you should print 32bit integer intNumber
	//---------------------------------------------------------
	printf("intNumber = 0x%x\t(signed) intNumber = %d\t(unsigned) intNumber = %u\n", (uint8_t)intNumber, intNumber, (uint8_t)intNumber);
	printf("(binary)\t");

	printBinaries((uint8_t*)&intNumber, ((uint8_t*)&intNumber)+4);

	printf("\n");

	printSignedChar(-2);

	return 1;
}


void printBinary(uint8_t* number)
{
	uint8_t small = *number;
	uint8_t mask = 0x80;
	int i = 0;

	for (i = 0; i < 8; i++)
	{
		uint8_t tmp = 0;
		tmp = (small & mask) != 0;
		printf("%d", tmp);
		mask = mask >> 1;
	}
}


void printSignedChar(int8_t num)
{
	int i = 0;
	int32_t b = 0;
	int8_t a = num;

	b = a;

	printf("a = 0x%x\t(signed) a = %d\t(unsigned) a = %u\n", (uint8_t)a, a, (uint8_t)a);
	printf("(binary)\t");
	printBinary((uint8_t*)&a);

	printf("\n\n");

	uint8_t* part = (uint8_t*)&b;

	printf("b = 0x%x\t(signed) b = %d\t(unsigned) b = %u\n", b, b, (uint32_t)b);
	printf("(binary)\t");

	//---------------------------------------------------------
	//This is where you should print 32bit integer b
	//---------------------------------------------------------
	printBinaries(part, part+4);

	// printf("Not implemented\n");
}

void printBinaries(uint8_t* start, uint8_t* end)
{
	uint8_t* iterator;
	intptr_t step;

	if (IS_BIG_ENDIAN)
	{
		step = 1;
	}
	else
	{
		iterator = start - 1;
		start = end - 1;
		end = iterator;

		step = -1;
	}

	for (iterator = start; iterator != end; iterator += step)
	{
		printBinary(iterator);
	}

	printf("\n");
}

