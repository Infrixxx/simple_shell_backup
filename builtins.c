#include "shell.h"

/**
 * setenv_builtin - Implement the setenv built-in command.
 * @args: The array of command arguments (should be "setenv VARIABLE VALUE").
 *
 * Return: 1 on success, -1 on failure.
 */
int setenv_builtin(char **args)
{
	if (args[1] == NULL || args[2] == NULL)
	{
		fprintf(stderr, "Usage: setenv VARIABLE VALUE\n");
		return (-1);
	}

	if (setenv(args[1], args[2], 1) != 0)
	{
		perror("setenv");
		return (-1);
	}

	return (1);
}

/**
 * unsetenv_builtin - Implement the unsetenv built-in command.
 * @args: The array of command arguments (should be "unsetenv VARIABLE").
 *
 * Return: 1 on success, -1 on failure.
 */
int unsetenv_builtin(char **args)
{
	if (args[1] == NULL)
	{
		fprintf(stderr, "Usage: unsetenv VARIABLE\n");
		return (-1);
	}

	if (unsetenv(args[1]) != 0)
	{
		perror("unsetenv");
		return (-1);
	}

	return (1);
}
