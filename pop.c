#include "monty.h"

/*
 * pop - Removes the top element from the stack.
 * @stack: A pointer to the top of the stack.
 * @line_number: Current line number.
 */
void pop(stack_t **stack, unsigned int line_number)
{
stack_t *temp;

if (*stack == NULL)
{
fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
exit(EXIT_FAILURE);
}

temp = *stack;
*stack = (*stack)->next;

if (*stack != NULL)
{
(*stack)->prev = NULL;
}

free(temp);
}

