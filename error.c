#include "shell.h"
/**
 * not_found - write error ("sh: 1: lss: not found")
 * @str: user's typed command
 * @c_n: nth user's typed command
 * @env: bring in environmental variables linked list to write shell name
 */
void not_found(char *str, int c_n, list_t *env)
{
	char *shell, *num;

	shell = get_env(env, "_"); /* get shell name to write */
	_puts(shell);
	free(shell);
	_puts(": ");
	num = i_to_str(c_n); /* convert cmd line num to string to write */
	_puts(num);
	free(num);
	_puts(": ");
	_puts(str);
	_puts(": ");
	_puts("not found\n");
}
/**
 * cd_error - print error if cd fails
 * @env: environment linked list
 * @i: return from cd
 * @str: name of directory
 * Return: void
 */
void cd_error(list_t *env, int i, char *str)
{
	char *shell;

	shell = get_env(env, "_");
	if (i == -1)
	{
	_puts(shell);
	_puts(": cd: ");
	_puts(str);
	_puts(": No such file or directory\n");
	}
	free(shell);
}
