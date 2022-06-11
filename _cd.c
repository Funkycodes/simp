#include "shell.h"
int _cd(char *dir)
{
    char *ch;
    char pwd[1023];
    int i = 0;
    switch (dir[0])
    {
    case '-':
        ch = getenv("OLDPWD");
	if (ch == NULL)
		_strcpy(ch,".");
	else
	{
		chdir(ch);
		getcwd(pwd,sizeof(pwd));
		_puts(pwd);
		_putchar('\n');
		return i;
	}
        break;
    case '~':
        ch = getenv("HOME");
        break;
    default:
        ch = dir;
        break;
    }
    if(ch==NULL)
    {
        ch = getenv("HOME");
    }
    if((i = chdir(ch)) == -1)
	    perror("chdir failed");
    return (i);
}
