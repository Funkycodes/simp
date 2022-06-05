#include "shell.h"

int c_strcmp(char *var, char *value)
{
    int n = _strlen(value);
    int i = 0;

    while (i < n)
    {
        if (var[i] != value[i])
            return 0;
        i++;
    }
    return 1;
}

void createnvlist(list_t **h)
{
    int i = 0;
    while (environ[i] != NULL)
    {
        add_node_end(h, environ[i]);
        i++;
    }
}

