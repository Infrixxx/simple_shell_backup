#include "shell.c"

/**
* tokenize_command - Tokenize the command into arguments
* @command: The command to tokenize
*
* Return: A NULL-terminated array of strings containing the arguments.
*         NULL if memory allocation fails.
*/
char **tokenize_command(char *command)
{
	char **args = malloc(BUFFER_SIZE * sizeof(char *));
	int i = 0;

	if (!args)
	{
		return (NULL);
	}

	char *token = strtok(command, " ");

	while (token != NULL)
	{
		args[i] = token;
		i++;
		token = strtok(NULL, " ");
	}
	args[i] = NULL;

	return (args);
}
