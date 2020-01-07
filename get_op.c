#include "monty.h"
/**
 * get_op - function that checks what operation needs to be done
 * @token: first token of the file
 * @stack: pointer to the stack
 * @line: number of line
 */
void get_op(char *token, stack_t **stack, unsigned int line)
{
	int i = 0;

	instruction_t op[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"nop", nop},
		{"add", add},
		{NULL, NULL}
	};

	for (i = 0; op[i].opcode != NULL; i++)
	{
		if (strcmp(token, op[i].opcode) == 0)
		{
			op[i].f(stack, line);
			return;
		}
	}
	dprintf(STDERR_FILENO, "L%d: ", line);
	dprintf(STDERR_FILENO, "unknown instruction %s\n", token);
	_free(stack, line);
	exit(EXIT_FAILURE);
}
