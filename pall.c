#include "monty.h"
/*
* pall -
* @stack: A pointer to the top of the element.
* @line_number: Current line number.
* Return: Nothing.
*/
void pall(stack_t **stack)
{
stack_t *temp = *stack;

while (temp != NULL)
{
printf("%d\n", (*temp).n);
temp = (*temp).next;
}
}