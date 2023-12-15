#include "monty.h"

void push(stack_t **stack, unsigned int line_number);
void pall(stack_t **stack);
int is_valid_int(const char *str);

/*
* main - Entry point.
* @argc: Number of command line arguments.
* @argv: Array of command line arguments.
* Return: 0 on success.
*/
int main(int argc, char *argv[])
{
int n;
FILE *file = NULL;
unsigned int line_number = 1;
char str[MAX_LINE];
stack_t *stack = NULL;
char *opcode;
char *arg;

if (argc != 2)
{
fprintf(stderr, "USAGE: monty file\n");
exit(EXIT_FAILURE);
}
file = fopen(argv[1], "r");
if (file == NULL)
{
fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
exit(EXIT_FAILURE);
}
while (fgets(str, sizeof(str), file) != NULL)
{
opcode = strtok(str, " \t\n");
arg = strtok(NULL, " \t\n");

if (strcmp(opcode, "push") == 0)
{
if (arg == NULL || !is_valid_int(arg))
{
fprintf(stderr, "L%d: Usage: push integer\n", line_number);
exit(EXIT_FAILURE);
}
n = atoi(arg);
push(&stack, n);
}
else if (strcmp(opcode, "pall") == 0)
{
pall(&stack);
}
else
{
fprintf(stderr, "L%d: unknown instruction %s\n", line_number, opcode);
exit(EXIT_FAILURE);
}
line_number++;
}
fclose(file);
return (0);
}
/*
*is_valid_int - Checks if the string is a valid integer.
* @str: The string to be checked.
* Return: 0 on success otherwise 1.
*/
int is_valid_int(const char *str)
{
if (str == NULL || *str == '\0')
{
return (0);
}
if (*str != '+' && *str != '-' && !isdigit((unsigned char)*str))
{
return (0);
}
while (*++str)
{
if (!isdigit((unsigned char)*str))
{
return (0);
}
}
return (1);
}
