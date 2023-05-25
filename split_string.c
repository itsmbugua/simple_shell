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
 * @deli: delimeter to use with strtok
 *
 * Return: an array of strings
 */

char **separate_string(char *s, char *deli)
{
	char *portion, *tmp;
	char **cmd_array; /** array of string arrays */
	int x = 0, len = 0;

	tmp = strdup(s);
	cmd_array = malloc(sizeof(char *));
	if (cmd_array == NULL)
	{
		return (NULL);
	}
	portion = strtok(tmp, deli); /** split string using space */
	while (portion != NULL)
	{
		/** reallocate memory to cmd_array */
		cmd_array = realloc(cmd_array, (x + 1) * sizeof(char *));
		len = strlen(portion);
		cmd_array[x] = malloc((len + 1)  * sizeof(char));
		if (cmd_array[x] == NULL)
		{
			return (NULL);
		}
		cmd_array[x] = strdup(portion);
		cmd_array[x][len] = '\0';
		portion = strtok(NULL, deli); /** update value of portion */
		x++;
	}
	cmd_array[x] = NULL;
	free(tmp); /** free tmp */
	return (cmd_array);
}

/**
 * count_strings - calcute the number of strings,
 * after splitting a string.
 *
 * @s: pointer to string
 * @deli: delimeter to use with strtok
 *
 * Return: string count
 */

int count_strings(char *s, char *deli)
{
	char *portion;
	int count = 0;

	portion = strtok(s, deli);
	while (portion != NULL)
	{
		portion = strtok(NULL, deli); /** update value of portion */
		count++;
	}

	return (count);
}
