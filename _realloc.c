#include "shell.h"

void _realloc(char **str,int n)
{
	char *tmp = strdupe(*str);
	free(*str);
	*str = malloc(n);
	_strcpy(*str,tmp);
	free(tmp);
}
