#include "main.h"
/**
 * _printv - prints a value
 * @val: value to be printed
 * Return: void
 */

void _printv(int val)
{
    char *str = NULL;

    str = _itoa(val);
    write(STDOUT_FILENO, str, _strlen(str));
    write(STDOUT_FILENO, "\n", 1);
    free(str);
}

/**
 * _printk - print tok
 * @tok: array of tokens
 * @i: index of the token to start printing from
 * Return: void
 */

void _printk(char **tok, int i)
{
    int j;

    j = 0;
    while (tok[i] != NULL)
    {
        j = 0;
        while (tok[i][j] != '\0')
        {
            write(STDOUT_FILENO, &tok[i][j], 1);
            j++;
        }
        if (tok[i + 1] != NULL)
            write(STDOUT_FILENO, " ", 1);
        i++;
    }
}

/**
 * _perror - writes an error message to stderr
 * @tokens: array of tokens
 * @argv: array of arguments
 * Return: void
 */
void _perror(char **tokens, char **argv)
{
    write(STDERR_FILENO, argv[0], _strlen(argv[0]));
    write(STDERR_FILENO, ": ", 2);
    write(STDERR_FILENO, "1", 1);
    write(STDERR_FILENO, ": ", 2);
    write(STDERR_FILENO, tokens[0], _strlen(tokens[0]));
    write(STDERR_FILENO, ": not found\n", 12);
}