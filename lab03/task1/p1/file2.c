/**
 * @title Example 1:
 *
 * @brief Create this header file: file.h.
 * Declare extern (and global) variable: global_variable in file.h.
 * Create new file: file1.c. Define in it the variable from the previous step. In the same file, create function named increment() that will increment the variable by 1.
 * Create one more file: file2.c.
 * Include file.h in both source code files.
 * In file2.c create function use_it() that will increase extern variable global_variable by 1 and print its value on the standard output.
 * Create function main in one of the .c files and make it call the above two functions (increment and use_it).
 * Compile and run the program. Analyze output and code execution.
 *
 * @author Jovan Slavujevic
 */

#include <stdio.h>

#include "file.h"

void increment();

void use_it()
{
    global_variable++;
    printf("%d ", global_variable);
}

int main(int argc, char** argv)
{
    increment();
    use_it();

    return 0;
}
