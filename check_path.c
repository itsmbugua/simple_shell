#include "main.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>

/**
 * find_path - function to look for a path
 *
 * @s: pointer to string
 *
 * Return: None if path not found else return path
 */

char *find_path(char *s)
{
	char *paths[] = {"/bin/", "/usr/bin/"};
	char *tmp;
	struct stat st;
	int x;

	/** check first if path exists */
	if (stat(s, &st) == 0)
	{
		return (s);
	}

	for (x = 0; x < 2; x++)
	{
		/** duplicate string */
		tmp = strdup(paths[x]);
		strcat(tmp, s); /** concatnate strings */
		if (stat(tmp, &st) == 0)
		{
			return (tmp);
		}
	}

	return (NULL);
}
