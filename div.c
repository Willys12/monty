#include "monty.h"

/*
 * div_op - Divides the second top element of the stack.
 * @stack: A pointer to the top of the stack.
 * @line_number: Current line number.
 */
void div_func(stack_t **stack, unsigned int line_number)
{
if (*stack == NULL || (*stack)->next == NULL)
{
fprintf(stderr, "L%d: can't div, stack too short\n", line_number);
exit(EXIT_FAILURE);
}

if ((*stack)->n == 0)
{
fprintf(stderr, "L%d: division by zero\n", line_number);
exit(EXIT_FAILURE);
}

(*stack)->next->n /= (*stack)->n;
pop(stack, line_number);
}

