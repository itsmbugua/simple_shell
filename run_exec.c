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
 * @parent_pid: parent process id
 *
 * Return: None on failure
 */

void execute_commands(char *command, char **env, pid_t parent_pid)
{
	char **command_arr = NULL;

	if (strcmp(command, "exit") == 0)
	{
		exit_application(getpid(), parent_pid);
	}
	/** work in child processes */
	command_arr = separate_string(command);

	/**
	 * if (find_path(command_arr[0]))
	 * {
	 * command_arr[0] = find_path(command_arr[0]);
	 * }
	*/

	if (execve(command_arr[0], command_arr, env) == -1)
	{
		free(command);
	}
}
