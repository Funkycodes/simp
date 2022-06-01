#include "shell.h"
/**
 * _strlen - computes string length
 * @src: string
 * Return: string length
 */
int _strlen(char *src)
{
    int i = 0;
    while (*src)
    {
        i++;
        src++;
    }
    return (i);
}
/**
 * _strcat - concatenate a string to another
 * @dest: destination string
 * @src: source string
 * Return: void
 */
void _strcat(char *dest, char *src)
{
    int len = _strlen(dest);

    while (*src)
    {
        *(dest + len) = *src;
        src++;
        len++;
    }
}
/**
 * _strcpy - copies one string into another, overwriting it
 * @dest: destination string
 * @src: source string
 * Return: void
 */
void _strcpy(char *dest, char *src)
{
    int i = 0;
    int len = _strlen(dest);
    while((i < len))
    {
        *(dest+i) = 0;
        i++;
    }
    for(i = 0; i<_strlen(src);i++)
    {
        *(dest + i) = *(src + i);
    }
}
/**
 * _strcmp - compares two strings for equality
 * @a: parameter
 * @b: parameter
 * Return: 1(true) if they are the same, otherwise it returns 0(false)
 */
int _strcmp(char *a, char *b)
{
    int i = 0;
    if(_strlen(a) != _strlen(b))
        return 0;
    while(i < _strlen(a))
    {
        if(a[i] != b[i])
            return 0;
        i++;
    }
    return 1;
}
