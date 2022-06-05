#include "shell.h"

void ctrl_c(int n)
{
	(void)n;
	_puts("\n$ ");
}
