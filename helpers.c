#include "shell.h"
/**
 * _strspn - gets the length of a prefix substring
 * @str: string to be searched
 * @set: string containing characters to match
 * Return: number of bytes in the segment of str
 */
int _strspn(char *str, const char *set)
{
    int i = 0, j = 0, count = 0;

    while (str[i] != '\0')
    {
        for (j = 0; set[j] != '\0'; j++)
        {
            if (str[i] == set[j])
            {
                count++;
                break;
            }
        }
        if (set[j] == '\0')
        {
            break;
        }
        i++;
    }

    return count;
}

/**
 * _strpbrk - searches a string for any of a set of bytes
 * @str: string to be searched
 * @set: string containing the characters to match
 * Return: pointer to the byte in str that matches one of the bytes in set
 */

char *_strpbrk(char *str, const char *set)
{
    int i = 0, j = 0;

    while (str[i] != '\0')
    {
        for (j = 0; set[j] != '\0'; j++)
        {
            if (str[i] == set[j])
            {
                return str + i;
            }
        }
        i++;
    }

    return NULL;
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