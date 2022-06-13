#include "shell.h"

int _builtins(char **args, list_t **env)
{
	int i = 0;
	char *builtins[] = {"cd", "exit", "env","setenv", "unsetenv",NULL};

	while(builtins[i])
	{
		if(_strcmp(args[0], builtins[i]))
		{
			break;
		}
		i++;
	}
	switch(i)
	{
		case 1:
			free_double_ptr(args);
			return (0);
			break;
		case 0:
			_cd(args[1], env);
			free_double_ptr(args);
			return (1);
			break;
		case 2:
			print_list(*env);
			free_double_ptr(args);
			return (1);
			break;
		case 3:
			set_env(env, args[1], args[2]);
			free_double_ptr(args);
			return(1);
		case 4:
			unset_env(env, args[1]);
			free_double_ptr(args);
			return(1);
		default:
			return (2);
	}
}
