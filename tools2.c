#include "shell.h"
/**
 * check_if_positive - check if number is positive
 * @str: the input string
 * Return: 0 or 1
 */

int check_if_positive(char *str)

{

int i;

if (!str)
return (0);
for (i = 0; str[i]; i++)
{

if (str[i] < '0' || str[i] > '9')
return (0);
}
return (1);
}

/**
 * _atoi - convert from assci to int
 * @str: the input string
 * Return: int
 */
int _atoi(char *str)

{

int i, num = 0;

for (i = 0; str[i]; i++)
{

num *= 10;

num += (str[i] - '0');
}

return (num);
}
