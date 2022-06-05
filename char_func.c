#include "shell.h"

char _getchar(void)
{
    int i;
    char ch[1];
    ch[0] = '\0';
    i = read(STDIN_FILENO, ch, 1);
    if ((i == 0))
    {
	    if (isatty(STDIN_FILENO))
		    _puts("\n");
	    exit(0);
    }
    return ch[0];
}
char *_getline(void)
{
    char *line = malloc(1023);
    char ch;
    int i = 0;
    while (((ch = _getchar()) != '\n') && ((int)ch > 0) && (ch != '\0'))
    {
        *(line + i) = ch;
        i++;
    }
    *(line + i) = '\0';
    if(_strlen(line)==0)
	    return NULL;
    _realloc(&line, _strlen(line) + 1);

    return line;
}
int _putchar(char c)
{
    return (write(STDOUT_FILENO, &c, 1));
}
void _puts(char *c)
{ 
    int i = 0;
    if (c == NULL)
	    return;
    while (*(c + i))
    {
        _putchar(*(c + i));
        i++;
    }
}
