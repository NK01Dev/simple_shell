#include "shell.h"

char **spreader(char *line)
{
    char *kelma = NULL, *temporary = NULL;
    char **cmnd = NULL;
    int cptr = 0, i = 0;
    if (!line)
        return (NULL);
    temporary = _strdup(line);

    kelma = strtok(temporary, DELIM);
    if (kelma == NULL)
    {
        free(line), line = NULL;
        free(temporary), temporary = NULL;
        return (NULL);
    }

    while (kelma)
    {
        cptr++;
        kelma = strtok(NULL, DELIM);
    }
    free(temporary), temporary = NULL;
    cmnd = malloc(sizeof(char *) * (cptr + 1));
    if (!cmnd)
    {
        free(line);
        return (NULL);
    }

    kelma = strtok(line, DELIM);
    while (kelma)
    {
        cmnd[i] = _strdup(kelma);
        kelma = strtok(NULL, DELIM);
        i++;
    }
    free(line), line = NULL;
    cmnd[i] = NULL;
    return (cmnd);
}

