#include "monty.h"
/**
 *
 *
 *
 */
void _free(stack_t **stack, unsigned int line_number)
{
	if (stack == NULL)
		return;
	while (*stack != NULL)
		pop(stack, line_number);
}