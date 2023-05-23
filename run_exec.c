#include "main.h"
#include <unistd.h>
#include <stdio.h>

/**
 * execute_commands - function to run different,
 * functions on different processes.
 *
 * @command: pointer to string containing commands..
 * @env: current environment variables.
 *
 * Return: an array of pipes
 * Description: function to run different,
 * funtions in different processes.
 */

int execute_commands(char *command, char **env)
{
	char **command_arr = NULL;

	/** work in child processes */
	command_arr = separate_string(command);
	if (find_path(command_arr[0]))
	{
		command_arr[0] = find_path(command_arr[0]);
	}

	if (execve(command_arr[0], command_arr, env) == -1)
	{
		return (1);
	}

	free_arr(command_arr);
	return (0);
}
