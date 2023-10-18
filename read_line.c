#include "shell.h"
/**
 * _getline - gets the next line of input from STDIN

 *
 * Return: line
 */

char *read_line(void)
{
    char *line = NULL;
    size_t length = 0;
    ssize_t v;
    if (isatty(STDIN_FILENO))
        write(STDOUT_FILENO, "$ ", 2);
    v = getline(&line, &length, stdin);
    if (v == -1)
    {
        free(line);
        return (NULL);
    }

    return (line);
}
