#include "shell.h"

int main(void)
{
    char **p = _strtok(_getline(),' ');
    char cmd[30];
    _strcpy(cmd,"/bin/");
    _strcat(cmd,p[0]);
    execv(cmd,p);
    return 0;
}
char _getchar(void)
{
    char ch[2];
    read(STDIN_FILENO,ch,1);
    return ch[0];
}
char *_getline(void)
{
    char *line = malloc(1023);
    char ch;
    int i = 0;
    while((ch = _getchar()) != '\n')
    {
        *(line+i) = ch;
        i++;
    }
    *(line+i) = '\0';
    line=realloc(line, _strlen(line)+1);

    return  line;
}

