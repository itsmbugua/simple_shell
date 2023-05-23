#include "main.h"
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

/**
 * separate_string - function to
 *
 * @s: string array
 * Return: an array of strings
 */

char **separate_string(char *s)
{
	char *portion, *tmp;
	char **cmd_array; /** array of string arrays */
	char deli[] = " "; /** delimiter of using a space */
	char *current_path = " .";
	int x = 0, count = 0, len = 0;

	tmp = strdup(s);
	count = count_strings(s);
	if (count == 3)
	{
		/** add current path if we get two arguments */
		strcat(tmp, current_path);
	}
	cmd_array = malloc(sizeof(char *));
	if (cmd_array == NULL)
	{
		return (NULL);
	}
	portion = strtok(tmp, deli); /** split string using space */
	while (portion != NULL)
	{
		/** reallocate meory to cmd_array */
		cmd_array = realloc(cmd_array, (x + 1));
		len = strlen(portion);
		cmd_array[x] = malloc((len + 1)  * sizeof(char));
		if (cmd_array[x] == NULL)
		{
			return (NULL);
		}
		if (cmd_array == NULL)
		{
			return (NULL);
		}
		cmd_array[x] = strdup(portion);
		portion = strtok(NULL, deli); /** update value of portion */
		x++;
	}
	cmd_array[x] = '\0';
	free(tmp); /** free tmp */
	return (cmd_array);
}

/**
 * count_strings - calcute the number of strings,
 * after splitting a string.
 *
 * @s: pointer to string
 *
 * Return: string count
 */
int count_strings(char *s)
{
	char *portion;
	int count = 0;
	char deli[] = " ";

	portion = strtok(s, deli);
	while (portion != NULL)
	{
		portion = strtok(NULL, deli); /** update value of portion */
		count++;
	}

	return (count + 1);
}
