/**
 * @title Task 4
 *
 * @brief Illustration of const keyword usage. Compile const_parameter.c. Analyze reported errors.
 *
 * NOTE: It is not required to fix this code so that it compiles. The idea is to see what compiler will and will not allow,
 * depending on const keyword usage.
 *
 * @author Jovan Slavujevic
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void modifyChar(char* ch);
void modifyString1(const char* sp);
void modifyString2(char const* sp);
void modifyString3(char* const sp);
void modifyString4(const char* const sp);

char globalString[20] = "The global string";

int main()
{
	printf("================================\n");
	printf("Const in function parameter list\n");
	printf("================================\n");

	char string1[20] = "text 1";
	char string2[20] = "text 2";
	char string3[20] = "text 3";
	char string4[20] = "text 4";

	modifyString1(string1);
	modifyString2(string2);
	modifyString3(string3);
	modifyString4(string4);

	printf("modifyString1 -> %s\n", string1);
	printf("modifyString2 -> %s\n", string2);
	printf("modifyString3 -> %s\n", string3);
	printf("modifyString4 -> %s\n", string4);

	return 0;
}

// POINTER TO CONSTANT
void modifyString1(const char* sp)
{
	// WARNING : discards const qualifier
	modifyChar(sp + 3);

	// ALLOWED: You can assign new address to the pointer of the const pointee
	sp = globalString;

	// NOT ALLOWED: You cannot change value to the const pointee
//	*(sp + 3) = '\0';
}

void modifyChar(char* ch)
{
	// ALLOWED : everything OK if ch is not NULL
	*ch = '\0';
}

// POINTER TO CONSTANT
void modifyString2(char const* sp)
{
	// WARNING : discards const qualifier
	strcpy(sp, globalString);

	// ALLOWED: You can assign new address to the pointer of the const pointee
	sp = globalString;

	// NOT ALLOWED: You cannot change value to the const pointee
//	*(sp + 3) = '\0';
}

// CONSTANT POINTER
void modifyString3(char* const sp)
{
	// ALLOWED: You can change value to the pointee of the const pointer
	*(sp + 3) = '\0';

	// NOT ALLOWED: You cannot assign new address to the const pointer
//	sp = globalString;
}

// CONSTANT POINTER TO CONSTANT
void modifyString4(const char* const sp)
{
	// NOT ALLOWED: You cannot assign new address to the const pointer
//	sp = globalString;

	// NOT ALLOWED: You cannot change value to the const pointee
//	*(sp + 3) = '\0';
}

