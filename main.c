#include "main.h"

/**
 * main - starting point of the program
 * @ac: number of arguments
 * @av: array of arguments
 * @env: array of environment variables
 * Return: 0 on success, 1 on failure
 */
int main(int ac, char **av, char **env)
{
	char *block = NULL;
	size_t ln = 0;
	int read = 0;

	(void)ac;
	signal(SIGINT, sig_Handler);
	while (1)
	{
		if (isatty(STDIN_FILENO))
		{
			fflush(stdin);
			write(STDOUT_FILENO, "$ ", 2);
		}
		read = _getline(&block, &ln, STDIN_FILENO);
		if (read == EOF)
		{
			if (isatty(STDIN_FILENO))
				write(STDOUT_FILENO, "\n", 1);
			break;
		}
		if (block[0] == '\n')
			continue;
		split_string(block);
		if (read > 1)
			block[read - 1] = '\0';
		get_input(block, env, av);
		ln = 0;
		block = NULL;
	}
	free(block);
	return (0);
}
