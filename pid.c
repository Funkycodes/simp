#include "shell.h"

int main()
{
	list_t *env;
	int i;
	char **toks;
	char *line;
	int cmd_no = 0;
	createnvlist(&env);
	while (1)
	{
		cmd_no++;
		if (isatty(STDIN_FILENO))
			_puts("$ ");
		else
			_puts("Non nteractive");
		signal(SIGINT, ctrl_c);
		toks = NULL;
		line = _getline();
		if (line == NULL)
		{
			continue;
		}
		toks = _strtok(line, ' ');
		if ((i = _builtins(toks)) == 1)
			continue;
		else if (i == 0)
			break;
		i = _execute(toks, env, cmd_no);
	}
	return (i);
}

