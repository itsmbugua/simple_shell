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
	char **command_arr;

	if (strcmp(command, "exit") == 0)
	{
		exit_application(getpid(), parent_pid);
		exit(EXIT_SUCCESS);
	}

	/** work in child processes */
	command_arr = separate_string(command);

	/** check if the 2 value null */
	if (command_arr[1] && command_arr[2] == NULL)
	{
		return;
	}

	if (execve(command_arr[0], command_arr, env) == 0)
	{
		printf("cool");
		return;
	}
}
