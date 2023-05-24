#include "main.h"
#include <stdlib.h>

/**
 * free_arr - function to free pointer to pointer array
 *
 * @s: array of strings
 */

void free_arr(char **s)
{
	if (s == NULL)
	{
		return;
	}
	while (*s)
	{
		free(*s);
	}
	free(s);
}
