#include "monty.h"
int global;
/**
 * push - add a element to the stack
 * @stack: pointer to the stack
 * @line_number: line number
 */
void push(stack_t **stack, unsigned int line_number)
{
	stack_t *new;

	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		dprintf(STDERR_FILENO, "Error: malloc failed");
		_free(stack, line_number);
		exit(EXIT_FAILURE);
	}
	new->n = global;
	new->prev = NULL;
	new->next = *stack;
	if (*stack != NULL)
		(*stack)->prev = new;
	*stack = new;
}
/**
 * pall - prints elements of the stack
 * @stack: pointer to the stack
 * @line_number: line number
 */
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	(void)line_number;

	if (stack == NULL)
	{
		exit(EXIT_FAILURE);
	}
	temp = *stack;
	while (temp != NULL)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
}
/**
 * pop - removes the top element of a stack
 * @stack: pointer to the stack
 * @line_number: line number
 */
void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

	if (stack == NULL || *stack == NULL)
	{
		dprintf(STDERR_FILENO, "L%d: ", line_number);
		dprintf(STDERR_FILENO, "can't pop an empty stack\n");
		exit(EXIT_FAILURE);
	}
	tmp = *stack;
	*stack = (*stack)->next;
	free(tmp);
}
/**
 * pint - prints the top
 * @stack: pointer to the stack
 * @line_number: line number
 */
void pint(stack_t **stack, unsigned int line_number)
{
	if (stack == NULL || *stack == NULL)
	{
		dprintf(STDERR_FILENO,"L%d: can't pint, stack empty\n", line_number);
		_freed(*stack);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);

}
/**
 * nop - does nothing
 * @stack: pointer to the stack
 * @line_number: line number
 */
void nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}
/**
 * swap - swaps elements
 * @stack: pointer to the stack
 * @line_number: line number
 */
void swap(stack_t **stack, unsigned int line_number)
{
	stack_t *new;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
	{
		dprintf(STDERR_FILENO, "L%d: can't swap, stack too short\n",
			line_number);
		_free(stack, line_number);
		exit(EXIT_FAILURE);
	}

	new = (*stack)->next;
	(*stack)->prev = new;
	(*stack)->next = new->next;
	new->prev = NULL;

	if (new->next)
		(new->next)->prev = *stack;
	new->next = *stack;
	*stack = new;
}
