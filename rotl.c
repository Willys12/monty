#include "monty.h"

/**
 * rotl - Rotates the stack to the top.
 * @stack: A pointer to the top of the stack.
 * @line_number: Current line number.
 * Return: Nothing.
 */
void rotl(stack_t **stack, unsigned int line_number)
{
(void)line_number;

if (*stack != NULL && (*stack)->next != NULL)
{
stack_t *temp = *stack;

while ((*temp).next != NULL)
{
temp = (*temp).next;
}

(*temp).next = *stack;
(*stack)->prev = temp;
*stack = (*stack)->next;
(*stack)->prev = NULL;
(*temp).next->next = NULL;
}
}
