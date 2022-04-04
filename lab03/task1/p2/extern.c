/**
 * @title Example 2:
 *
 * @brief Create two new files: file1.c and file2.c, and define in both of them a global variable of the same name.
 * In file1.c create a function that sets its global variable to some value.
 * In file2.c create a function that prints the value of its global variable on the standard output.
 * Create file extern.c, and in it create function main and from it call functions defined in file1.c and file2.c, in that order.
 * Compile the program.
 *
 * @author Jovan Slavujevic
 */

void increment();
void use_it();

int main(int argc, char** argv)
{
    increment();
    use_it();

    return 0;
}
