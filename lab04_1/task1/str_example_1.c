/**
 * @author Jovan Slavujevic
 */

#include <stdio.h>

#include <stdint.h>
#include <inttypes.h>

int_least32_t stringLength(const char str[]);
void stringTrim(char str[]);
int_least8_t extractSubstring(const char inStr[], char outStr[], int_least32_t beginning, int_least32_t end);

int main()
{
    // function that calculates length of a given string
    const char* helloWorldString = "HELLO WORLD";
    printf("String length of `%s` is %" PRIdLEAST32 ".\n", helloWorldString, stringLength(helloWorldString));

    // function that removes spaces from the beginning and ending of a given string
    char helloWorldString2[] = "HE  LL O W O R  LD    ";
    stringTrim(helloWorldString2);
    printf("String length of `%s` is %" PRIdLEAST32 ".\n", helloWorldString2, stringLength(helloWorldString2));

    // function that extracts substring form a given string. It should return 1 in case of success, and 0 otherwise
    char helloSubstring[100];
    extractSubstring(helloWorldString, helloSubstring, 0, 5);
    printf("String length of `%s` is %" PRIdLEAST32 ".\n", helloSubstring, stringLength(helloSubstring));

    return 0;
}

int_least32_t stringLength(const char str[])
{
    int_least32_t len = 0;
    for (; *str != '\0'; str++, len++);
    return len;
}

void stringTrim(char str[])
{
    int_least32_t stringlen = stringLength(str);
    int_least32_t i, j;
    for (i = 0; i < stringlen; i++)
    {
        if (str[i] == ' ')
        {
            if (str + i + 1 < str + stringlen)
            {
                for (j = i; j < stringlen; j++)
                {
                    str[j] = str[j + 1];
                }
                i--;
            }
            stringlen--;
        }
    }
    str[stringlen] = '\0';
}

int_least8_t extractSubstring(const char inStr[], char outStr[], int_least32_t beginning, int_least32_t end)
{
    if (stringLength(inStr) > end)
    {
        int_least32_t i;
        for (i = 0; i < end - beginning; i++)
        {
            outStr[i] = inStr[i + beginning];
        }
        outStr[end - beginning] = '\0';
        return 1;
    }
    return 0;
}
