#include "monty.h"
int value;
/**
 * main - interpreter for Monty ByteCodes files
 * @argc: argument count
 * @argv: argument vector
 * Return: 0
 */
int main(int argc, char *argv[])
{
	FILE *fd;
	char *buff = NULL;
	char *tok;
	size_t size = 0;
	stack_t *stack = NULL;
	unsigned int line_num = 1;

	if (argc != 2)
	{
		dprintf(STDERR_FILENO, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	fd = fopen(argv[1], "r");
	if (fd == NULL)
	{
		dprintf(STDERR_FILENO, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while (getline(&buff, &size, fd) != -1)
	{
		if (*buff != '\n')
		{
			tok = strtok(buff, "\n");
			tokenize(tok, &stack, line_num);
		}
		line_num++;
	}
	fclose(fd);
	free(buff);
	_free(&stack, line_num);
	return (0);
}
