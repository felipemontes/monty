#include "monty.h"
/**
 *
 *
 *
 */
void get_op(char *token, stack_t **stack, unsigned int line)
{
        int i = 0;

	instruction_t op[] = {
		{"push", push},
		{"pall", pall},
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
	printf("L%d: unknown instruction %s\n", line, token);
	exit(EXIT_FAILURE);
}