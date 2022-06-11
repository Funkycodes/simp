#include "shell.h"

int main()
{
	int i,stat;
	char **toks;
	char *line;
	char *cmd;
	while(1){
		if(isatty(STDIN_FILENO))
			_puts("$ ");
		else
			_puts("Non nteractive");
		signal(SIGINT, ctrl_c);
	toks = NULL;
	line=_getline();
	cmd = malloc(100);
	if (line == NULL)
	{
		free(cmd);
		continue;
	}
	toks = _strtok(line,' ');
	if((i =_builtins(toks))==1)
		continue;
	else if(i == 0)
		break;
	_strcpy(cmd,"/bin/");
	cmd = _strcat(cmd,toks[0]);
	if(fork() == 0)
	{
		if (execve(cmd, toks,NULL) == -1)
			perror("./shell");
		sleep(3);
	}
	else
	{
		wait(&stat);
	}
	free(*toks);
	free(toks);
	free(cmd);
	free(line);
	}
		return 0;
}
