#include "main.h"
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/**
 * execute_commands - function to run different,
 * functions on different processes.
 *
 * @command: pointer to string containing commands..
 * @env: current environment variables.
 *
 * Return: None on failure
 */

void execute_commands(char *command, char **env)
{
	char **command_arr;
	char deli[] = " ";
	char *path;
	int len = 0;

	if (strcmp(command, "exit") == 0)
	{
		exit_application(0);
	}

	/** work in child processes */
	command_arr = separate_string(command, deli);
	path = find_path(command_arr[0]);
	if (command_arr == NULL)
	{
		return;
	}
	if (path != NULL)
	{
		len = strlen(path);
		free(command_arr[0]);
		command_arr[0] = malloc((len + 1) * sizeof(char));
		strcpy(command_arr[0], path);
	}
	/** check if the 2 value null */
	if (execve(command_arr[0], command_arr, env) == -1)
	{
		return;
	}
}
