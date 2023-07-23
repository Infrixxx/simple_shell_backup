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
	if (strcmp(args[0], "exit") == 0)
	{
		free(args);
		exit(EXIT_SUCCESS);
	}
	if (check_executable(args[0]))
	{
		execute_command_with_args(args);
	}
	execute_command_with_args(args);
	free(args);
}
