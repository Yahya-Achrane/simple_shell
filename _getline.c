#include "main.h"

/**
 * _getline - gets a line from a file descriptor
 * @buf: buf to store line
 * @size_buf: size of buf
 * @fild: file descriptor
 * Return: number of characters read
 */

ssize_t _getline(char **buf, size_t *size_buf, int fild)
{
    ssize_t n_characters;
    char *n_buf;

    if (buf == NULL || size_buf == NULL)
        return (-1);

    if (*buf == NULL)
    {
        *buf = malloc(sizeof(char) * READ_SIZE);
        if (*buf == NULL)
            return (-1);
        *size_buf = READ_SIZE;
    }

    n_characters = read(fild, *buf, *size_buf);

    if (n_characters == -1)
        return (-1);

    if (n_characters == 0)
        return (n_characters);

    if (*(*buf + n_characters - 1) == '\n')
        return (n_characters);

    n_buf = malloc(sizeof(char) * (*size_buf + READ_SIZE));
    if (n_buf == NULL)
        return (-1);

    memcpy(n_buf, *buf, n_characters);

    free(*buf);

    *buf = n_buf;
    *size_buf += READ_SIZE;

    return (n_characters);
}