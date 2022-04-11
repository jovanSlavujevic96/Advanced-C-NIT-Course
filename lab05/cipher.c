#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <inttypes.h>
#include "caesar.h"
#include "rot13.h"

static const int_fast16_t CAESAR_SHIFT = 3;

int main(void)
{
	char in[100] = "the QUICK brown FOX jumps over THE lazy DOG";
	char encrypted[100];
	char decrypted[100];

	printf("Caesar cipher (shift %"PRIdFAST16") :\n", CAESAR_SHIFT);

	caesarEncrypt(in, encrypted, CAESAR_SHIFT);
	printf("Original: %s\nencrypted: %s\n", in, encrypted);

	caesarDecrypt(encrypted, decrypted, CAESAR_SHIFT);
	printf("decrypted: %s\n", decrypted);
	printf("\n");

	strcpy(encrypted,"");
	strcpy(decrypted,"");

	printf("ROT13:\n");

	rot13Encrypt(in, encrypted);
	printf("Original: %s\nencrypted: %s\n", in, encrypted);

	rot13Decrypt(encrypted, decrypted);
	printf("decrypted: %s\n", decrypted);
	printf("\n");

	return EXIT_SUCCESS;
}
