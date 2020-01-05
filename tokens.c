#include "monty.h"
/**
 *
 *
 *
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
 *
 *
 *
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
			printf("L%d: usage: push integer\n", line_num);
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
