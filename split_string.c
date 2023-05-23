#include "main.h"
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <stdlib.h>

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
	char *deli = " "; /** delimiter of using a space */
	int x = 0, count = 0, len = strlen(s);

	tmp = malloc(len * sizeof(char));
	if (tmp == NULL)
	{
		return (NULL);
	}
	tmp[len] = '\0';
	strcpy(tmp, s); /** copy string */
	portion = strtok(s, deli);
	while (portion != NULL)/** get number of strings */
	{
		portion = strtok(NULL, " "); /** update value of portion */
		count++; /** increament count */
	}
	cmd_array = malloc((count + 1) * sizeof(char *));
	if (cmd_array == NULL)
	{
		return (NULL);
	}
	cmd_array[count + 1] = '\0'; /** add null pointer to cmd_array */
	portion = strtok(tmp, deli); /** split string using space */
	while (portion != NULL)
	{
		cmd_array[x] = malloc(strlen(portion) * sizeof(char));
		if (cmd_array[x] == NULL)
		{
			return (NULL);
		}
		strcpy(cmd_array[x], portion); /** copy string */
		portion = strtok(NULL, " "); /** update value of portion */
		x++;
	}
	free(tmp); /** free tmp */
	return (cmd_array);
}
