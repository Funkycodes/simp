#include "shell.h"
int _cd(char *dir)
{
    char *ch;
    int i;
    switch (dir[0])
    {
    case '-':
        ch = getenv("OLDPWD");
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
    i = chdir(ch);
    return (i);
}