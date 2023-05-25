#include "main.h"
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <time.h>

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
	char *str = NULL, *store, **tmp;
	char deli[] = " ";
	(void)argc; /** we won't use argc */
	(void)argv; /** we won't use argv */

	while (1) /** prompting user for input */
	{
		printf("$ ");
		str = get_string(str);
		if (str == NULL)
		{
			sleep_and_exit();
		}
		store = strdup(str);
		tmp = separate_string(store, deli);
		if (find_path(tmp[0]) != NULL || strcmp(str, "exit") == 0)
		{
			pids[i] = fork();
			if (pids[i] == 0)
			{
				execute_commands(str, env);
				print_error(argv, str);/**executed if execute_commands fails*/
				return (0);
			}
			else /** wait for child process to finish */
				wait(NULL);
			i++;
		}
		else
			print_error(argv, str);
		free(str);
		free(store);
		free(tmp);
	}
	return (0);
}

/**
 * print_error - function to print error.
 *
 * @s: string to print with error message.
 * @command: sec
 */

void print_error(char **s, char *command)
{
	dprintf(OUTPUT, "%s : 1: %s: not found\n", s[0], command);
}
