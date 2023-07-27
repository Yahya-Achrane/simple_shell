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
    ssize_t var = 0;

    if (buf == NULL || size_buf == NULL)
        return (-1);
    if (*buf == NULL)
    {
        *buf = malloc(sizeof(char) * READ_SIZE);
        if (*buf == NULL)
            return (-1);
        *size_buf = READ_SIZE;
    }
    var = read(fild, *buf, *size_buf);
    if (var == -1)
    {
        free(*buf);
        return (-1);
    }
    return (var);
}