#include "shell.h"

int _builtins(char **args)
{
	int i = 0;
	char *builtins[] = {"cd","exit","env",NULL};

	while(builtins[i])
	{
		if(_strcmp(args[0],builtins[i]))
		{
			break;
		}
		i++;
	}
	switch(i)
	{
		case 1:
			return (0);
			break;
		case 0:
			_cd(args[1]);
			return (1);
			break;
		case 2:
			_env();
			return (1);
			break;
		default:
			return 2;
	}
}
