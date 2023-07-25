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
	args[i] = NULL;

	return (args);
}

/**
 * execute_command_with_args - Execute the command with arguments
 * @args: The array of strings containing the command and its arguments
 */
void execute_command_with_args(char **args)
{
	char *replaced_command = replace_variables(args[0]);

	if (!replaced_command)
	{
		perror("Memory Allocation Error");
		return;
	}

	pid_t pid = fork();

	if (pid == 0)
	{
		execute_child_process(args);
	}
	else if (pid < 0)
	{
		perror("Fork Error");
	}
	else
	{
		wait(NULL);
	}

	free(replaced_command);
}

/**
 * execute_child_process - Execute the child process with replaced arguments
 * @args: The array of strings containing the command and its arguments
 */
void execute_child_process(char **args)
{
	char **replaced_args = malloc((custom_strlen(args) + 1) * sizeof(char *));

	if (!replaced_args)
	{
		perror("Memory Allocation Error");
		exit(EXIT_FAILURE);
	}

	for (int i = 0; args[i] != NULL; i++)
	{
		replaced_args[i] = replace_variables(args[i]);
		if (!replaced_args[i])
		{
			perror("Memory Allocation Error");
			free_arguments(replaced_args);
			exit(EXIT_FAILURE);
		}
	}
	replaced_args[custom_strlen(args)] = NULL;

	if (execvp(replaced_args[0], replaced_args) == -1)
	{
		perror("Error");
		free_arguments(replaced_args);
		exit(EXIT_FAILURE);
	}

	free_arguments(replaced_args);
}
