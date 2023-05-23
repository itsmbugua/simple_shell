#include "main.h"
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

/**
 * remove_new_line - function to remove new,
 * line character from string.
 *
 * @s: pointer to string
 *
 * Return: a pointer to a string
 */

char *remove_new_line(char *s)
{
	char *new;
	int x, len;

	if (s == NULL)
	{
		return (NULL);
	}
	len = strlen(s); /** length of string */
	/** allocoate memory of size strlen(s) */
	new = malloc((len) * sizeof(char));
	/** check fo malloc failure */
	if (new == NULL)
	{
		return (NULL);
	}
	new[len] = '\0'; /** adding a null pointer to new */

	/** add data from string s to new */
	for (x = 0; x < len; x++)
	{
		if (s[x] != '\n')
		{
			new[x] = s[x];
		}
	}

	return (new);
}
