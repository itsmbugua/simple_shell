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
*/

void exit_application(int status)
{
	pid_t child_pid, parent_pid;

	parent_pid = getppid();
	child_pid = getpid();

	kill(parent_pid, SIGTERM);
	kill(child_pid, SIGTERM);

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
