#include "shell.h"
int delimnum(char *str, char delim)
{
	int i, len;

	len = i = 0;
	while (*(str + i) != '\0')
	{
		if (str[i] == delim)
			len++;
		i++;
	}
	return (len);
}
char **path_strtok(char *str, char *delim)
{
	char **toks = NULL, d_ch;
	int buffsize, i, j, k, len, m;

	len = i = j = k = m = 0;
	d_ch = delim[0];
	if (str == NULL)
		return (NULL);
	buffsize = delimnum(str, d_ch);
	toks = malloc(sizeof(char *) * (buffsize + 2));
	if (toks == NULL)
		return (NULL);
	while (str[len] != '\0')
		len++;
	while (i < len)
	{

		toks[j] = malloc(t_length(str, i, d_ch) + 1);
		k = 0;
		while (str[i] != d_ch && str[i] != '\0')
		{
			toks[j][k] = str[i];
			i++;
			k++;
		}
		toks[j][k] = '\0';
		j++;
		i++;
	}
	toks[j] = NULL;
	return (toks);
}
/**
 * _which - fleshes out command by appending it to a matching PATH directory
 * @str: first command user typed into shell (e.g. "ls" if user typed "ls -l")
 * @env: environmental variable
 * Return: a copy of fleshed out command (e.g. "/bin/ls" if originally "ls")
 */
char *_which(char *str, list_t *env)
{
	char *pth, *cat = NULL, **toks;
	int i = 0;

	/* get and tokenize PATH directories, then free original string */
	pth = get_env(env, "PATH");
	toks = path_strtok(pth, ":");
	free(pth);

	/* append "/cmd" to each token to see it's legit */
	i = 0;
	while (toks[i] != NULL)
	{
		if (toks[i][0] == '\0')
			cat = getcwd(cat, 0);
		else
			cat = strdupe(toks[i]);
		cat = _strcat(cat, "/");
		cat = _strcat(cat, str);
		if (access(cat, F_OK) == 0)
		{
			return (cat);
		}
		free(cat); /* free concatenated string if cmd is never found */
		i++;
	}
	return (str); /* return string if not found; won't pass execve */
}

