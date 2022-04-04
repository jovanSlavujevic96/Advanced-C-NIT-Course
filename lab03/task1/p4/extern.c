/**
 * @title Example 4:
 *
 * @brief Do the same as in the previous example, but initialize global variables differently in file1.c and file2.c.
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
