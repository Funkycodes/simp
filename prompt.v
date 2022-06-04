#include "shell.h"
int main(void)
{
    char *h;
    _puts("$ ");
    h = _getline();
    _puts(h);
    _putchar('\n');
    _putchar(_strlen(h)+'0');
    exit(EXIT_SUCCESS);
}
