/**
 * @title Final Assignment
 *
 * @brief You need to do this task by yourself. The solution will be graded and it will be calculated towards your final grade.
 *
 * To set up for this task:
 *
 * In CS50 IDE make a new folder lab08
 * As the result of this whole exercise, upload files main.c, stack.h and stack.c.
 * Implement stack (LIFO data structure).
 *
 * The data type to be used for the stack element should be adjustable through preprocessing directives.
 * The stack should be implemented as a separate module.
 * Implement the following functionality:
 *
 * Create/Initialize stack
 * Destroy stack
 * Inserts new element.
 * Remove a single element from the stack.
 * Check whether the stack is empty.
 * Print stack content on the standard output.
 * In function main create at least 2 instances of the stack and test all the functions using both.
 *
 * Make the program accept a command-line argument that specifies how many elements (generate data as you wish)
 * should be used for testing the first stack instance.
 *
 * Your stack module (not including the main function) should be written in accordance with the MISRA standard.
 *
 * In addition:
 *
 * The main.c file should contain a block of comments at the very beginning in which you will (in free form)
 * provide a brief description of the solution, your name, as well as all important notes related to the program.
 *
 * The code should be written in such a way that it is as portable as possible. So, to work successfully on some other
 * platforms, with some other compilers. If you need to introduce a non-portable code element somewhere, it is important
 * to clearly mention and explain it with an inline comment, as well as in the comment at the beginning of the main.c file.
 *
 * Make the stack module work as generally as possible.
 *
 * If you have to make some assumptions, feel free to make them, but explain them in the comment at the beginning of the main.c file.
 * In this regard, think carefully about the limitations of your program (eg maximum size and amount of input data or data structure, etc.),
 * and write them in the comments in the main.c file.
 *
 * Use asserts wherever you deem necessary.
 *
 * All programs should be written so that they take up as little memory as possible and run as fast as possible.
 * You should always keep in mind that we work with systems that have limited resources. In cases where the tendency to make
 * the program as small and as fast as possible is opposed, choose one of these two criteria and state it in the comments.
 *
 * Analyze whether your stack module is written according to the MISRA C standard. It is perfectly fine if you have not followed
 * some rules in the code, but be sure to comment on it and clearly indicate it in the comment at the beginning of the main.c.
 *
 * Apply to this task everything that you have learned on this course. Consult again all the material if you have any doubts
 * or you have forgotten something.
 *
 * @author Jovan Slavujevic
 */

#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>
#include <assert.h>

#include "stack.h"

#define STACK_2_CAPACITY 10u
#define MAGIC_NUMBER 404

/** @defgroup HELPERS */
static void my_print(const DATA_TYPE *element);
static void stack_test1(Stack *stack, int_least32_t capacity);
static void stack_test2(Stack *stack1, const int_least32_t stack1_capacity, Stack *stack2);

int main(int argc, char **argv)
{
    int_least32_t capacity;
    Stack stack1;
    Stack stack2;

    /* Waits for user to enter capacity */
    printf("Enter desired capacity of stack: ");
    scanf("%" SCNdLEAST32, &capacity);
    printf("You entered: %" PRIdLEAST32 "\n", capacity);

    /* Checks is capacity OK */
    if (capacity <= 0)
    {
        /* EXIT_SUCCESS because it is expected behaviour */
        printf("Passed capacity is inappropriate\n");
        return EXIT_SUCCESS;
    }
    printf("\n");

    /* Creates/Initializes testing stacks -> asserts success */
    assert(Stack_Create(&stack1, capacity, &my_print, &malloc, &free));
    assert(Stack_Create(&stack2, STACK_2_CAPACITY, &my_print, &malloc, &free));

    /* test execution */
    stack_test1(&stack1, capacity);
    stack_test2(&stack1, capacity, &stack2);

    /* Destroys/Deinitializes testing stacks */
    Stack_Destroy(&stack1);
    Stack_Destroy(&stack2);

    /* exit of program */
    printf("Successfull exit\n");
    return EXIT_SUCCESS;
}

static void my_print(const DATA_TYPE *element)
{
    /* custom print */
    printf("element: %" PRIdLEAST32 "\n", *element);
}

static void stack_test1(Stack *stack, int_least32_t capacity)
{
    /* TEST 1 */
    int_least32_t item;
    int_least32_t i;

    /* assert that stack is empty at the beginning */
    assert(Stack_IsEmpty(stack));

    /* fill the stack and make sure that every element is propperly inserted */
    for (i = 0; i < capacity; i++)
    {
        assert(Stack_Insert(stack, i));
    }

    /* print of stack */
    printf("Print stack1.\n");
    Stack_Print(stack);
    printf("\n");

    /* try to insert one more element and make sure that element will not be inserted */
    assert(!Stack_Insert(stack, i));

    /* remove elements from stack and store them to tmp storage, assert it's value */
    for (i = capacity - 1; i > -1; i--)
    {
        assert(Stack_Remove(stack, &item));
        assert(item == i);
    }

    /* make sure that stack is empty */
    assert(Stack_IsEmpty(stack));

    /* print of stack */
    printf("Print stack1.\n");
    Stack_Print(stack);
    printf("\n");

    /* try to remove one more element and make sure that element will not be removed */
    assert(!Stack_Remove(stack, &item));

    /* after clearing iteration try to inesrt another element to stack, get it out and check it's value */
    assert(Stack_Insert(stack, MAGIC_NUMBER));
    assert(Stack_Remove(stack, &item));
    assert(item == MAGIC_NUMBER);

    /* additionaly inesrt same element again and make sure that it will be removed even if passed storage is NULL */
    assert(Stack_Insert(stack, MAGIC_NUMBER));
    assert(Stack_Remove(stack, NULL));
    assert(Stack_IsEmpty(stack));
}

static void stack_test2(Stack *stack1, const int_least32_t stack1_capacity, Stack *stack2)
{
    /* TEST 2 */
    int_least32_t i, j;
    int_least32_t capacity_stack1;
    int_least32_t capacity_stack2;
    int_least32_t item;

    /* clear stacks */
    for (; Stack_Remove(stack1, NULL););
    for (; Stack_Remove(stack2, NULL););

    /* fill them with MAGIC NUMBER untill they stop inserting elements */
    for (capacity_stack1 = 0; Stack_Insert(stack1, MAGIC_NUMBER); capacity_stack1++);
    for (capacity_stack2 = 0; Stack_Insert(stack2, MAGIC_NUMBER); capacity_stack2++);

    /* assert expected capacities */
    assert(stack1_capacity == capacity_stack1);
    assert(STACK_2_CAPACITY == capacity_stack2);

    /* iterate through stacks, remove from  stacks, then move one element from stack2->stack1 */
    for (i = capacity_stack1 - 1, j = capacity_stack2 - 1; i > -1 && j > -1; i--, j--)
    {
        int_least32_t tmp;
        Stack_Remove(stack1, NULL);
        Stack_Remove(stack2, &item);
        Stack_Insert(stack1, item * 2);
        Stack_Remove(stack1, &tmp);
        assert(item * 2 == tmp);
    }

    /* assert that at least one stack will be empty at the end of test */
    assert(Stack_IsEmpty(stack1) || Stack_IsEmpty(stack2));
}