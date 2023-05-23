#include "main.h"
#include <unistd.h>
#include <stdio.h>

/**
 * get_string - function to help with getting string from terminal
 *
 * Return: a pointer to a string
 */

char *get_string(void)
{
	char *buffer;
	size_t buffersize = 0;

	if (getline(&buffer, &buffersize, stdin) == -1)
	{
		return (NULL);
	}
	if (buffer == NULL)
	{
		return (NULL);
	}
	/** remove new line character */
	buffer = remove_new_line(buffer);

	return (buffer);
}
