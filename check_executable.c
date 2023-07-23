#include "shell.h"

/**
 * check_executable - Check if the given command is an executable
 * @command: The command to check
 *
 * Return: 1 if executable is found, 0 otherwise
 */

int check_executable(char *command)
{
	if (access(command, X_OK) == 0)
		return (1);
	{
		printf("%s: No such file or directory\n", command);
		return (0);
	}
}
