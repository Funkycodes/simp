#include "shell.h"
/**
 * unset_env - unsets/deletes a given env variable
 * @h: environmentel linked list
 * @var: env variable to delete/unset
 * Return: void
 */
void unset_env(list_t **h, char *var)
{
	int idx;

	idx = get_node(*h, var);
	delete_nodeint_at_index(h, idx);
}
/**
 * set_env - modifies or create env variable
 * @h: environmental linked list
 * @var: environmetal variable
 * @val: value to set
 */
void set_env(list_t **h, char *var, char *val)
{
	int idx;
	list_t *node = *h;
	char *nodevar;

	nodevar = _strcat(var, "=");
	nodevar = _strcat(nodevar, val);
	idx = get_node(*h, var);
	if (idx == -1)
	{
		add_node_end(h, nodevar);
	}
	else
	{
		int i = 0;

		while (i <= idx)
		{
			if (c_strcmp(node->var, var))
			{
				node->var = nodevar;
				return;
			}
			node = node->next;
			i++;
		}
	}
}

