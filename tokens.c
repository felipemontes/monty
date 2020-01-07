#include "monty.h"
/**
 * isnum - checks if the string is a number
 * @str: string
 * Return: 0 or 1
 */
int isnum(char *str)
{
	if (str == NULL)
		return (0);
	if (*str == '-')
		str++;
	while (*str != '\0')
	{
		if (!isdigit(*str))
			return (0);
		str++;
	}
	return (1);
}
/**
 * tokenize - divide the string into tokens
 * @str: first token
 * @stack: pointer to the function
 * @line_num: line num
 */
void tokenize(char *str, stack_t **stack, unsigned int line_num)
{
	char *token;
	char *second;

	token = strtok(str, " ");
	if (token == NULL || *token == ' ')
		return;
	if (strcmp(token, "push") == 0)
	{
		second = token;
		token = strtok(NULL, " ");
		if (!isnum(token))
		{
			dprintf(STDERR_FILENO, "L%d: ", line_num);
			dprintf(STDERR_FILENO, "usage: push integer\n");
			_free(stack, line_num);
			exit(EXIT_FAILURE);
		}
		global = atoi(token);
		get_op(second, stack, line_num);
	}
	else
	{
		get_op(token, stack, line_num);
	}
}
