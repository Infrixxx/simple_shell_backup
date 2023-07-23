#include "shell.h"

/**
* execute_command_with_args - Execute the command with arguments
* @args: The array of strings containing the command and its arguments
*/

void execute_command_with_args(char **args)
{
	if (!check_executable(args[0]))
	{
		printf("Command not found: %s\n", args[0]);
		return;
	}

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
