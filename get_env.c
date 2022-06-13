#include "shell.h"

char *get_env(list_t *h, char *var)
{
	int idx = get_node(h, var);
	int i = 0;

	if (idx == -1)
	{
		_puts("'");
		_puts(var);
		_puts("' ");
		_puts("not found");
		return (NULL);
	}
	else
	{
		while (i < idx)
		{
			i++;
			h = h->next;
		}
		return (c_strdup(h->var, _strlen(var)));
	}
}
