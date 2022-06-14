#include "shell.h"
/**
 * c_strcmp - compares strings to see if value is at he beginneing of var
 * @var: string
 * @value: string
 * Return: 1 if true.
 */
int c_strcmp(char *var, char *value)
{
	int n = _strlen(value);
	int i = 0;

	while (i < n)
	{
		if (var[i] != value[i])
			return (0);
		i++;
	}
	return (1);
}
/**
 * createnvlist - creates environment linked list
 * @h: linked list head node
 */
void createnvlist(list_t **h)
{
	int i = 0;

	while (environ[i] != NULL)
	{
		add_node_end(h, environ[i]);
		i++;
	}
}

