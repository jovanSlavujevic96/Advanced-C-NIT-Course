#include "caesar.h"
#include <stdio.h>
#include <ctype.h>
#include <string.h>

static const char LC_FIRST = 'a';
static const char LC_LAST = 'z';
static const char UC_FIRST = 'A';
static const char UC_LAST = 'Z';

static const char key = 26;

static uint8_t isLower(char letter);
static uint8_t isUpper(char letter);
static char encryptChar(char ch, int_fast16_t shift);
static char decryptChar(char ch);

void caesarEncrypt(const char* in, char* out, int_fast16_t shift)
{
	int i = 0;
	int inLength = strlen(in);

	for (i = 0; i < inLength; i++)
	{
		char c = in[i];
		if (isLower(c) || isUpper(c))
		{
			c = tolower(c);
			out[i] = encryptChar(c, shift);
		}
		else
		{
			out[i] = in[i];
		}
	}
	out[i] = '\0';
}

void caesarDecrypt(const char* in, char* out, int_fast16_t shift)
{
	int i = 0;
	int inLength = strlen(in);

	for (i = 0; i < inLength; i++)
	{
		char c = in[i];
		if (isLower(c) || isUpper(c))
		{
			c = tolower(c);
			if ((c = c - 'a' - shift) < 0)
			{
				c += key;
			}
			out[i] = decryptChar(c);
		}
		else
		{
			out[i] = in[i];
		}
	}
	out[i] = '\0';
}

static char encryptChar(char ch, int_fast16_t shift)
{
	return ((ch - 'a') + shift) % key + 'a';
}

static char decryptChar(char ch)
{
	return (ch % key + 'a');
}

static uint8_t isLower(char letter)
{
	if(letter >= LC_FIRST && letter <= LC_LAST) {
		return 1;
	} else {
		return 0;
	}
}

static uint8_t isUpper(char letter)
{
	if(letter >= UC_FIRST && letter <= UC_LAST) {
		return 1;
	} else {
		return 0;
	}
}
