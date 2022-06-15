#include "shell.h"

/**
 * c_ignore - custom ignores spaces and newlines
 * (e.g. echo "ls\n ls" | ./a.out)
 * @str: envrionmental variables
 * Return: new string
 */
char *c_ignore(char *str)
{
	while (*str == ' ' || *str == '\n')
		str++;
	return (str);
}

/**
 * non_interactive - handles when user pipes commands into shell via pipeline
 * (e.g. echo "ls/nls -al/n" | ./a.out)
 * @env: envrionmental variables
 */
void non_interactive(list_t *env)
{
	size_t n = 0;
	int command_line_no = 0, exit_stat = 0;
	char *command = NULL, **n_line;

	while ((command = _getline()) != NULL)
	{
		if (command_line_no > 0)
			_puts("$ ");
	n_line = _strtok(command, ' '); /* tokenize each command string */
	n = 0;
		command_line_no++;
		exit_stat = _builtins(n_line, &env);
		if (exit_stat == 1)
		{
			n++;
			continue;
		}
		exit_stat = _execute(n_line, env, command_line_no);
		n++;
	}
	free_list(env);
	exit(exit_stat);
}

