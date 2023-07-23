
#include "shell.h"

/**
* execute_command - Execute the given command
* @command: The command to execute
*/
void execute_command(char *command)
{
	char **args = tokenize_command(command);

	if (!args)
	{
		perror("Memory Allocation Error");
		return;
	}

	if (check_executable(args[0]))
	{
		execute_command_with_args(args);
	}

	free(args);
}

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

	char *token = custom_strtok(command, " ");

	while (token != NULL)
	{
		args[i] = token;
		i++;
		token = custom_strtok(NULL, " ");
	}
	args[i] = NULL; /* Set the last element of the args array to NULL */

	return (args);
}

/**
* execute_command_with_args - Execute the command with arguments
* @args: The array of strings containing the command and its arguments
*/
void execute_command_with_args(char **args)
{
	pid_t pid = fork();

	if (pid == 0)
	{
		if (execve(args[0], args, environ) == -1)
		{
			perror("Error");
			exit(EXIT_FAILURE);
		}
	}
	else if (pid < 0)
	{
		perror("Fork Error");
	}
	else
	{
		wait(NULL);
	}
}
