#include "shell.h"

/**
 * env_builtin - Print the current environment variables.
 */
void env_builtin(void)
{
	int i = 0;

	while (environ[i] != NULL)
	{
		printf("%s\n", environ[i]);
		i++;
	}
}
