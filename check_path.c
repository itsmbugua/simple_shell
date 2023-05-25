#include "main.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

/**
 * find_path - function to look for a path
 *
 * @s: pointer to string
 *
 * Return: None if path not found else return path
 */

char *find_path(char *s)
{
	char *tmp, *portion;
	struct stat st;
	char *path = getenv("PATH");
	char deli[] = " ";
	char *store;

	/** check first if path exists */
	if (stat(s, &st) == 0)
	{
		return (s);
	}

	store = strdup(path);
	replace_character(store, ':', ' ');
	portion = strtok(store, deli);
	while (portion != NULL)
	{
		/** duplicate string */
		tmp = strdup(portion);
		strcat(tmp, "/");
		strcat(tmp, s); /** concatnate strings */
		if (stat(tmp, &st) == 0)
		{
			return (tmp);
		}
		portion = strtok(NULL, deli);
	}

	return (NULL);
}
/**
 * replace_character - function to replace all occurences of,
 * a character with another character
 *
 * @str: string to replace character
 * @s1: character to replace
 * @s2: character to replace with
 *
 */

void replace_character(char *str, char s1, char s2)
{
	int x;

	x = 0;
	while (str[x] != '\0')
	{
		if (str[x] == s1)
		{
			str[x] = s2;
		}
		x++;
	}
}



