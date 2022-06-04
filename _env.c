#include "shell.h"

void _env(void)
{
	int j = 0;

	while(environ[j])
	{
		_puts(environ[j]);
		_putchar('\n');
		j++;
	}
}
