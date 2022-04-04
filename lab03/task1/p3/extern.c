/**
 * @title Example 3:
 *
 * @brief Do the same as in the previous example, but change the definitions of the global variables so that they have internal linkage
 * (i.e. they are private to their files / translation units).
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
