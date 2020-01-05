#include "monty.h"
/**
 * _free - frees memorie
 * @stack: pointer to the stack
 * @line_number: line number
 */
void _free(stack_t **stack, unsigned int line_number)
{
	if (stack == NULL)
		return;
	while (*stack != NULL)
		pop(stack, line_number);
}

void _freed(stack_t *head)
{
	if (head != NULL)
	{
		_freed(head->next);
		free(head);
	}
}
