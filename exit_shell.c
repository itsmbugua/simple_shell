#include "main.h"
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/**
 * exit_application - function to kill all processes
 *
 * @command: exit status.
 * @status: status code to use.
 */

void exit_application(int status, char *command)
{
	char **args, *deli = " ";
	int exit_code = status;

	args = separate_string(command, deli);
	if (args[1] != NULL)
		exit_code = atoi(args[1]);
	exit(exit_code);
}

/**
 * sleep_and_exit - function to sleep and exit abruptly
 */

void sleep_and_exit(void)
{
	char command[] = "/bin/sleep";
	char *args[] = { "sleep", "0.1", NULL};
	char *env[] = { NULL };

	if (execve(command, args, env) == -1)
	{
		return;
	}
}
