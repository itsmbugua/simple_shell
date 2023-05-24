#include "main.h"
#include <string.h>
#include <stdbool.h>

/**
 * check_errors - function to check for errors
 *
 * @str: pointer to string
 *
 * Return: 0 if success else return 1
 */

int check_errors(char *str)
{
		/** check if one of the conditions is true */
		if (count_strings(str) == 3)
		{
			return (1);
		}

		return (0);
}
