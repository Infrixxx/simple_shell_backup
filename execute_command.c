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

	/* Check if the command is a built-in and execute it */
	if (execute_builtin(args))
	{
		free_arguments(args);
		return;
	}

	if (strcmp(args[0], "exit") == 0)
	{
		int status = 0;

		if (args[1])
		{
			status = custom_atoi(args[1]);
		}

		free_arguments(args);
		exit(status);
	}

	if (check_executable(args[0]))
	{
		execute_command_with_args(args);
	}

	free_arguments(args);
}
