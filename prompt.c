#include "shell.h"
int main(void)
{
    char *h;
    _puts("$ ");
    h = _getline();
    _puts(h);
    _putchar('\n');
    exit(EXIT_SUCCESS);
}