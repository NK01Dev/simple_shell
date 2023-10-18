#include "shell.h"
int _exec(char **cmnd, char **argv, int indx)
{
    char *full_cmnd;
    pid_t child;
    int stts;
    full_cmnd = _getpath(cmnd[0]);
    if (!full_cmnd)
    {
        p_error(argv[0], cmnd[0], indx);
        freeTable(cmnd);

        return (127);
    }
    child = fork();
    if (child == 0)
    {
        if (execve(full_cmnd, cmnd, environ) == -1)
        {
            freeTable(cmnd);
        }
    }
    else
    {
        waitpid(child, &stts, 0);
        freeTable(cmnd);
        free(full_cmnd), full_cmnd = NULL;
    }
    return (WEXITSTATUS(stts));
}

