#include "shell.h"

int get_node(list_t *h, char *var)
{
    int i;
    if (h == NULL || var == NULL)
        return -1;
    for (i = 0; h != NULL; i++)
    {
        if (c_strcmp(h->var, var))
            return i;
        h = h->next;
    }
    return -1;
}

