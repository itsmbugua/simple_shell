#include "main.h"
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/**
 * exit_application - function to kill all processes
 *
 * @status: status code to use.
 * @args: arguments for exit()
*/

void exit_application(int status, char *args[])
{
	int exit_code;

	/** check if args is null */
	if (args == NULL)
	{
		exit(status);
	}
	/** check if exit has arguments*/
	if (args[1] != NULL)
	{
		exit_code = atoi(args[1]);
		exit(exit_code);
	}

	exit(status);
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
