#include "monty.h"
/*
* main - Entry point.
* @argc: Number of command line arguments.
* @argv: Array of command line arguments.
* Return: 0 on success.
*/
int main(int argc, char *argv[])
{
int n;
char *str = NULL;
size_t len = 0;
ssize_t n_read;
stack_t *stack = NULL;
char *opcode;
char *arg;
if (argc != 2)
{
fprintf(stderr, "USAGE: monty file\n");
exit(EXIT_FAILURE);
}
FILE *file = fopen(argv[1], "r");
if (file == NULL)
{
fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
exit(EXIT_FAILURE);
}
while ((n_read = getline(&str, &len, file)) != -1)
{
opcode = strtok(str, " \t\n");
arg = strtok(NULL, " \t\n");

if (strcmp(opcode, "push") == 0)
{
if (arg == NULL)
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
}
free(str);
fclose(file);
return (0);
}