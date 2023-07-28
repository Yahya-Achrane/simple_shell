#include "main.h"

/**
 * _echo - handles the echo builtin
 * @tok: array of tok
 * Return: 0 on success, 1 on failure
 */
int _echo(char **tok)
{
	char *value = NULL;
	int i = 1, flag = 0;

	if (tok[1] == NULL)
	{
		write(STDOUT_FILENO, "\n", 1);
		return (0);
	}
	if (_strncmp(tok[1], "$$", 2) == 0)
	{
		_printv(getpid());
		flag = 1;
		i++;
	}
	if (_strncmp(tok[1], "$?", 2) == 0)
	{
		_printv(exit_cmd(0, 0));
		flag = 1;
		i++;
	}
	if (_strncmp(tok[1], "$", 1) == 0)
	{
		value = get_env(tok[1] + 1);
		if (value != NULL)
		{
			write(STDOUT_FILENO, value, _strlen(value));
			write(STDOUT_FILENO, "\n", 1);
		}
		flag = 1;
		i++;
	}
	_printk(tok, i);
	if (flag == 0)
		write(STDOUT_FILENO, "\n", 1);
	return (0);
}
