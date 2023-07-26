#include "main.h"

/**
 * _strcat - concatenates two strings
 * @dest: destination string
 * @src: source string
 * Return: pointer to the concatenated string
 */
char *_strcat(char *dest, char *src)
{
	int i, j;

	i = 0;
	j = 0;
	while (dest[i] != '\0')
		i++;

	while (src[j] != '\0')
	{
		dest[i] = src[j];
		j++;
		i++;
	}

	dest[i] = '\0';

	return (dest);
}

/**
 * _strcpy - copies a string
 * @dest: destination string
 * @src: source string
 * Return: pointer to the copied string
 */
char *_strcpy(char *dest, char *src)
{
	int i = 0;

	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

/**
 * p_free - frees a pointer
 * @p: pointer to be freed
 * Return: void
 */
void p_free(char *p)
{
	if (p != NULL)
		free(p);
	p = NULL;
}

/**
 * ffree - frees a double pointer
 * @p: double pointer to be freed
 * Return: void
 */
void ffree(char **p)
{
	int i = 0;

	if (p == NULL)
	return;

	while (p[i] != NULL)
	{
		free(p[i]);
		i++;
	}

	free(p);
}
