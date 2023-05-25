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
 */

void remove_new_line(char *s)
{
	int len;

	if (s == NULL)
	{
		return;
	}

	len = strlen(s);
	if (len > 0 && s[len - 1] == '\n')
	{
		s[len - 1] = '\0';
	}
}
