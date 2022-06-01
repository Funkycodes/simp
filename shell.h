#ifndef SHELL_H
#define SHELL_H
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
char *strdupe(char *);
int t_arraylength(char*,char);
char **_strtok(char *, char);
int t_length(char *, char ,char);
int _strcmp(char *, char *);
int _strlen(char *);
void _strcat(char *, char *);
void _strcpy(char *, char *);
/*GEtline*/
char _getchar(void);
int _putchar(char c);
char *_getline(void);
void _puts(char *c);
typedef struct env
{
    char *var;/*holds environment variable*/
    struct env *next;/*ptr to next variable*/
} list_t;

/*Functions*/
size_t print_list(const list_t *);
size_t list_len(const list_t *h);
list_t *add_node(list_t **, char *);
list_t *add_node_end(list_t **, char *);
void free_list(list_t *);
#endif
