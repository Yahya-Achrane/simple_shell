#include "main.h"

/**
 * _strlen - returns the length of a string
 * @str: string to be measured
 * Return: length of string
 */
int _strlen(char *str)
{
	int i = 0;

	while (str[i] != '\0')
		i++;
	return (i);
}

/**
 * _strncmp - compares two strings
 * @str1: first string
 * @str2: second string
 * @n: number of bytes to compare
 * Return: 0 if strings are equal, -1 if not
 */
int _strncmp(char *str1, char *str2, int n)
{
	int i = 0;

	while (str1[i] != '\0' && str2[i] != '\0' && i < n)
	{
		if (str1[i] != str2[i])
			return (-1);
		i++;
	}
	if (i == n)
		return (0);
	return (-1);
}

/**
 * _strdup - duplicates a string
 * @str: string to be duplicated
 * Return: pointer to the duplicated string
 */
char *_strdup(char *str)
{
	int i = 0;
	char *dup = NULL;

	if (str == NULL)
		return (NULL);
	dup = malloc(sizeof(char) * (_strlen(str) + 1));
	if (dup == NULL)
		return (NULL);
	while (str[i] != '\0')
	{
		dup[i] = str[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

/**
 * sig_Handler - handles the SIGINT signal
 * @sig_num: signal number
 * Return: void
 */
void sig_Handler(int sig_num)
{
	(void)sig_num;
	signal(SIGINT, sig_Handler);
	fflush(stdout);
}

/**
 * exit_cmd - gets the last exit code
 * @act: 0 to get, 1 to set
 * @stat: exit code
 * Return: last exit code
 */
int exit_cmd(int act, int stat)
{
	static int last;

	if (act == 1)
		last = stat;
	return (last);
}
