#include "shell.h"
void freeTable(char **array)
{
    int i;
    if (!array)
        return;
    for (i = 0; array[i]; i++)
    {
        free(array[i]);
        array[i] = NULL;
    }
    free(array), array = NULL;
}
void p_error(char *name, char *cmnd, int indx)
{
    char *index, mssg[] = ": not found \n";
    index = _itoa(indx);
    write(STDERR_FILENO, name, _strlen(name));
    write(STDERR_FILENO, ":", 2);
    write(STDERR_FILENO, index, _strlen(index));
    write(STDERR_FILENO, ":", 2);
    write(STDERR_FILENO, cmnd, _strlen(cmnd));
    write(STDERR_FILENO, mssg, _strlen(mssg));
    free(index);
}
char *_itoa(int n)
{
    char buffer[20];
    int i = 0;
    if (n == 0)
        buffer[i++] = '0';
    else
    {
        while (n > 0)
        {
            buffer[i++] = (n % 10) + '0';
            n /= 10;
        }
    }
    buffer[i] = '\0';
    reverse_string(buffer, i);
    return (_strdup(buffer));
}
void reverse_string(char *str, int len)
{
    char tmp;
    int start = 0;
    int end = len - 1;
    while (start < end)
    {
        tmp = str[start];
        str[start] = str[end];
        str[end] = tmp;
        start++;
        end--;
    }
}
