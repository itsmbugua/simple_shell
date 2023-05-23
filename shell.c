#include "main.h"
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <sys/wait.h>
#include <stdlib.h>

#define PROCESS_NUM 5 /** Number of processes */
#define OUTPUT 2 /** standard output */

/**
 * main - run command in separate processes
 *
 * @argc: number of command line arguments.
 * @argv: array of command line arguments.
 * @env: current environment.
 *
 * Return: always 0 if success.
 */

int main(int argc, char *argv[], char *env[])
{
	pid_t pids[PROCESS_NUM]; /** array with process ids */
	int i = 0;
	pid_t parent_pid = getpid();
	char *str, **tmp, *store;
	(void)argc; /** we won't use argc */
	(void)argv; /** we won't use argv */

	/** prompting user for input */
	while (1)
	{
		printf("$ ");
		str = get_string();
		store = strdup(str);
		tmp = separate_string(store);
		if (find_path(tmp[0]) != NULL || strcmp(str, "exit") == 0)
		{
			pids[i] = fork();
			if (pids[i] == 0)
			{
				if (strcmp(str, "exit") == 0)
				{
					exit_application(parent_pid, pids[i]);
				}
				execute_commands(str, env);
				free(str);
				return (0);
			}
			else
			{
				/** wait for child process to finish */
				wait(NULL);
			}
		}
		else
		{
			dprintf(OUTPUT, "%s : No such file or directory\n", argv[0]);
		}
		i++;
	}
	return (0);
}
