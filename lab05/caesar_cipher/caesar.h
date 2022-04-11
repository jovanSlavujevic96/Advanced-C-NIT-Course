#ifndef CAESAR_H_
#define CAESAR_H_
#include <stdint.h>

void caesarEncrypt(const char* in, char* out, int_fast16_t shift);
void caesarDecrypt(const char* in, char* out, int_fast16_t shift);

#endif /* CAESAR_H_ */
