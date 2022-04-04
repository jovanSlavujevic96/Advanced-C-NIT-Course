#include <stdio.h>

static int global_variable = 2; // static duration variables are initialized by default

void use_it()
{
    global_variable++;
    printf("%d ", global_variable);
}
