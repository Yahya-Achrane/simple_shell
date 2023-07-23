#include "shell.h"

/**
 * create_tokens - create token from input string
 * @line: input
 * Return: array of strings or tokens
 */
char **create_tokens(char *line)
{
	char **tokens;
	char *token, *line_copy;
	char *delim = " \n";
	int tokens_count = 0;
	int position = 0;

	line_copy = strdup(line);
	token = strtok(line, delim);
	while (token)
	{
		tokens_count++;
		token = strtok(NULL, delim);
	}
	tokens_count++;
	tokens = malloc(sizeof( char *) * tokens_count);
	if (!tokens)
	{
		perror("tokens alloacation");
		return (NULL);
	}
	token = strtok(line_copy, delim);
	while (token)
	{
		tokens[position] = token;
		position++;
		token = strtok(NULL, delim);
	}
	tokens[position] = NULL;
	return (tokens);
}
 

