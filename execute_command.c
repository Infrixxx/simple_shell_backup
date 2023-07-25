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
	if (strchr(command, ';'))
	{
		execute_commands_separated_by_semicolon(command);
	}
	else if (strchr(command, '&'))
	{
		execute_commands_separated_by_logical_and(command);
	}
	else if (strchr(command, '|'))
	{
		execute_commands_separated_by_logical_or(command);
	}
	else
	{
		execute_single_command(args);
	}
	free_arguments(args);
}

/**
 * execute_single_command - execute single command without && ||
 * @args: The command and its arguments as an array
 */
void execute_single_command(char **args)
{
	if (check_executable(args[0]))
	{
		execute_command_with_args(args);
	}
}

/**
 * execute_commands_separated_by_semicolon - Execute commands separated by ;
 * @command: The command to execute
 */
void execute_commands_separated_by_semicolon(char *command)
{
	char *token;
	char *saveptr;

	token = custom_strtok(command, ";", &saveptr);

	while (token != NULL)
	{
		char **args = tokenize_command(token);

		if (args != NULL)
		{
			execute_single_command(args);
			free_arguments(args);
		}

		token = custom_strtok(NULL, ";", &saveptr);
	}
}

/**
 * execute_commands_separated_by_logical_and - Execute commands separated by &&
 * @command: The command to execute
 */
void execute_commands_separated_by_logical_and(char *command)
{
	char *token;
	char *saveptr;

	token = custom_strtok(command, "&", &saveptr);

	while (token != NULL)
	{
		char **args = tokenize_command(token);

		if (args != NULL)
		{
			int status = execute_command_with_args(args);

			free_arguments(args);

			if (status != 0)
			{
				break;
			}
		}

		token = custom_strtok(NULL, "&", &saveptr);
	}
}

/**
 * execute_commands_separated_by_logical_or - Execute commands separated by ||
 * @command: The command to execute
 */
void execute_commands_separated_by_logical_or(char *command)
{
	char *token;
	char *saveptr;

	token = custom_strtok(command, "|", &saveptr);

	while (token != NULL)
	{
		char **args = tokenize_command(token);

		if (args != NULL)
		{
			int status = execute_command_with_args(args);

			free_arguments(args);

			if (status == 0)
			{
				break;
			}
		}

		token = custom_strtok(NULL, "|", &saveptr);
	}
}
