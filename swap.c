#include "monty.h"

/**
 * swap - Swaps the top two elements of the stack.
 * @stack: A pointer to the top of the stack.
 * @line_number: Current line number.
 */
void swap(stack_t **stack, unsigned int line_number)
{
stack_t *begin, *follow;
if (*stack == NULL || (*stack)->next == NULL)
{
fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
exit(EXIT_FAILURE);
}

begin  = *stack;
follow = (*stack)->next;

(*begin).next = (*follow).next;
(*begin).prev = follow;
(*follow).prev = NULL;
(*follow).next = begin;

*stack = follow;
}

