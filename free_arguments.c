#include "shell.h"
/**
 * free_arguments - Free the memory allocated for an array of strings.
 * @args: The array of strings to free.
 */
void free_arguments(char **args)
{
	if (!args)
		return;

	for (int i = 0; args[i]; i++)
	{
		free(args[i]);
	}
	free(args);
}
