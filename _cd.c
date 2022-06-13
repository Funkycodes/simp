#include "shell.h"
int _cd(char *dir, list_t **env)
{
	char *ch;
	char pwd[80], *opwd;
	int i = 0;

	getcwd(pwd, sizeof(pwd));
	if(dir == NULL)
	{
		set_env(env, "OLDPWD", pwd);
		opwd = get_env(*env, "HOME");
		chdir(opwd);
		free(opwd);
		return (i);
	}
	switch (dir[0])
	{
		case '-':
			ch = get_env(*env, "OLDPWD");
			if (ch == NULL)
				_strcpy(ch, ".");
			else
			{
				chdir(ch);
				set_env(env, "OLDPWD", pwd);
				getcwd(pwd, sizeof(pwd));
				_puts(pwd);
				_putchar('\n');
				return (i);
			}
			break;
		case '~':
			ch = getenv("HOME");
			break;
		default:
			ch = dir;
			break;
	}

	set_env(env, "OLDPWD", pwd);
	i = chdir(ch);
	free(ch);
	return (i);
}
