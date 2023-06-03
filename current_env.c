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
	int x = 0;

	/** check for null */
	if (envp == NULL)
	{
		return;
	}

	/** print environment variables */
	while (envp[x] != NULL)
	{
		printf("%s\n", envp[x]);
		x++;
	}
}
