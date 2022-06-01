#include "shell.h"

int main(void)
{
    _puts("Riddim");
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
int _putchar(char c)
{
    return (write(STDOUT_FILENO,&c,1));
}
void _puts(char *c)
{
    int i = 0;
    while(*(c+i))
    {
        _putchar(*(c+i));
        i++;
    }
}
