#include "monty.h"
/**
 * add - adds elements
 * @stack: pointer to the stack
 * @line_number: line number
 */
void add(stack_t **stack, unsigned int line_number)
{
  int elem;
  stack_t *new, *tmp;

  new = *stack;

  while (new != NULL)
    {
      new = new->next;
      elem++;
    }

  if (elem < 2)
    {
      dprintf(STDERR_FILENO, "L%i: can't add, stack too short\n", line_number);
      _free(stack, line_number);
      exit(EXIT_FAILURE);
    }
  new = (*stack)->next;
  new->n += (*stack)->n;
  new->prev = NULL;
  tmp = *stack;
  *stack = new;
  free(tmp);
}
