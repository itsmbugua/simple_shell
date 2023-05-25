#include "main.h"
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

#define PROCESS_NUM 5 /** Number of processes */
#define OUTPUT 2 /** standard output */

/**
 * main - run command in separate processes
 *
 * @argc: number of command line arguments.
 * @argv: array of command line arguments.
 * @envp: current environment.
 *
 * Return: always 0 if success.
 */

int main(int argc, char *argv[], char *envp[])
{
	pid_t pids[PROCESS_NUM]; /** array with process ids */
	int i = 0;
	char *str, *store, **tmp, deli[] = " ";
	(void)argc; /** we won't use argc */
	(void)argv; /** we won't use argv */

	while (1) /** prompting user for input */
	{
		printf("$ ");
		str = get_string(str);
		if (str == NULL)
			sleep_and_exit();
		if (check_for_space(str) == 0)
			continue;
		store = strdup(str);
		tmp = separate_string(store, deli);
		if (verify_command(tmp[0]) == 0 || strcmp(tmp[0], "exit") == 0)
		{
			if (strcmp(tmp[0], "exit") == 0)
				exit_application(0, str);
			pids[i] = fork();
			if (pids[i] == 0)
			{
				if (execute_commands(str, envp) == -1)
					print_error(argv, str);/**executed if execute_commands fails*/
				return (0);
			}
			else /** wait for child process to finish */
				wait(NULL);
			i++;
		}
		else
			print_error(argv, str);
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
	int i;

	/** clear anything printed before the variables */
	for (i = 0; i < 80; i++)
	{
		printf("\b");
	}

	dprintf(OUTPUT, "\b%s : 1: %s: not found\n", s[0], command);
}

/**
 * check_for_space - function to check if a string ,
 * contains only spaces.
 *
 * @s: pointer to string array
 *
 * Return: 0 if all characters are spaces.
 */

int check_for_space(char *s)
{
	int x;

	/** looping and checking all string characters */
	for (x = 0; s[x] != '\0'; x++)
	{
		if (s[x] != ' ')
		{
			return (1);
		}
	}

	return (0);
}


/**
 * verify_command - function to verify a command exists
 *
 * @command: pointer to string
 *
 * Return: 0 if success else returns 1
 */

int verify_command(char *command)
{
	FILE *fp;
	char *cmd;
	int result = 1;

	cmd = strdup(command);
	strcat(cmd, " -v %s > /dev/null 2>&1");
	fp = popen(cmd, "r");
	/** check the exit code and the return */
	if (fp != NULL)
	{
		result = 0;
	}

	fclose(fp);
	return (result);
}
