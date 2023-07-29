#include "main.h"

/**
 * h_exit - handles the exit builtin
 * @tokens: array of tokens
 * @line: pointer to the line buffer
 * Return: 0 on success, 1 on failure
 */
int h_exit(char **tokens, char *line)
{
	int status = 0;

	if (tokens[1] == NULL)
	{
		free(tokens);
		free(line);
		exit(exit_cmd(1, status));
	}
	if (check_num(tokens[1]) == 0)
	{
		status = _atoi(tokens[1]);
		if (status < 0)
		{
			free(tokens);
			free(line);
			exit(256 + status);
		}
		free(tokens);
		free(line);
		exit(exit_cmd(1, status));
	}
	else
	{
		write(STDERR_FILENO, "Illegal number: ", 16);
		write(STDERR_FILENO, tokens[1], _strlen(tokens[1]));
		write(STDERR_FILENO, "\n", 1);
		exit_cmd(1, 2);
		return (1);
	}
	return (0);
}
