#include <stdio.h>

int global_variable;

void use_it()
{
    global_variable++;
    printf("%d ", global_variable);
}
