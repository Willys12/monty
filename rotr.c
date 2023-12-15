#include "monty.h"

/*
 * rotr - Rotates the stack to the bottom.
 * @stack: A pointer to the top of the stack.
 * @line_number: Current line number.
 */
void rotr(stack_t **stack, unsigned int line_number)
{
if (*stack != NULL && (*stack)->next != NULL)
{

stack_t *temp = *stack;

while ((*temp).next != NULL)
{
temp = (*temp).next;
}

(*temp).prev->next = NULL;
(*temp).prev = NULL;
(*temp).next = *stack;
(*stack)->prev = temp;
*stack = temp;
}
(void)line_number;
}
