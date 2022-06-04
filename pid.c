#include "shell.h"

int main()
{
	extern char **environ;
	int i;
	while(1){
	_puts("$ ");
	char **toks = _strtok(_getline(),' ');
	char *cmd = malloc(100);
	if((i =_builtins(toks))==1)
		continue;
	else if(i == 0)
		break;
	int stat;
	_strcpy(cmd,"/bin/");
	cmd = _strcat(cmd,toks[0]);
	if(fork() == 0)
	{
		execve(cmd, toks,NULL);
		sleep(3);
	}
	else
	{
		wait(&stat);
	}
	free(*toks);
	free(toks);
	free(cmd);
	}
		return 0;
}
