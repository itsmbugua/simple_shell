#include "main.h"
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

/**
 * get_string - function to help with getting string from terminal
 *
 * @buffer: string array
 *
 * Return: a pointer to a string
 */

char *get_string(char *buffer)
{
	size_t buffersize = 0;
	ssize_t chars;

	chars = getline(&buffer, &buffersize, stdin);
	/** check for errors */
	if (chars == -1)
	{
		free(buffer);
		return (NULL);
	}

	/** remove new line character */
	remove_new_line(buffer);
	if (buffer[0] == '\0')
	{
		return (NULL);
	}
	return (buffer);
}
