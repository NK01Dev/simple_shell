#include "shell.h"
/**
 * main - Simple Shell main function
 * @ac: Count of arguments
 * @argv: Arguments
 *
 * Return: 0 Always (success)
 */
int main(int ac, char **argv)
{
char *line = NULL;
char **cmnd = NULL;
int stts = 0, indx = 0;
(void)ac;

while (1)
{
line = read_line();
if (line == NULL)
{
if (isatty(STDIN_FILENO))
write(STDOUT_FILENO, "\n", 1);
return (stts);
}
indx++;
cmnd = spreader(line);
if (!cmnd)
continue;

if (is_builtinside(cmnd[0]))
handle_builtinside(cmnd, argv, &stts, indx);
else
stts = _exec(cmnd, argv, indx);
}

return (0);
}

