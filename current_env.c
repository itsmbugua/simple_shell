#include "main.h"
#include <stdio.h>


/**
 * get_current_env - function the gets and prints the,
 * current environment variables.
 *
 * @envp: pointer to pointer for environment variables.
 */

void get_current_env(char **envp)
{
	int x = 0, i;

	/** check for null */
	if (envp == NULL)
	{
		return;
	}

	/** clear anything printed before the variables */
	for (i = 0; i < 80; i++)
	{
		printf("\b");
	}

	/** print environment variables */
	while (envp[x] != NULL)
	{
		printf("%s\n", envp[x]);
		fflush(stdin);
		x++;
	}
}
