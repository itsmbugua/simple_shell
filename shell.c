#include "main.h"
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <sys/wait.h>
#include <stdlib.h>

#define PROCESS_NUM 5 /** Number of processes */

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
	char *str, exit_app[] = "exit";
	(void)argc; /** we won't use argc */
	(void)argv; /** we won't use argv */

	printf("$ ");
	/** prompting user for input */
	while (1)
	{
		pids[i] = fork();
		if (pids[i] == -1)
		{
			perror("Error creator process \n");
			exit(1);
		}
		/** child process */
		if (pids[i] == 0)
		{
			str = get_string();
			if (strcmp(str, exit_app) == 0)
			{
				exit(1);
			}
			else
			{
				execute_commands(str, env);
			}
			free(str);
			return (0);
		}
		else
		{
			/** wait for child process to fnish */
			wait(NULL);
		}
		i++;
	}
	return (0);
}
