#include "rot13.h"
#include "caesar.h"
#include <assert.h>
#include <string.h>

#define ROT13 13

void rot13Encrypt(const char* in, char* out)
{
	caesarEncrypt(in, out, ROT13);
}

void rot13Decrypt(const char* in, char* out)
{
	caesarDecrypt(in, out, ROT13);
}
