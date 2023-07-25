#include "shell.h"

/**
 * main - Entry point for the Simple Shell program.
 * @argc: The number of command-line arguments.
 * @argv: An array of pointers to command-line arguments.
 * Return: EXIT_SUCCESS (0) to indicate successful termination.
 */
int main(int argc, char *argv[])
{
	if (argc > 1)
	{
		return (execute_commands_from_file(argv[1]));
	}
	else
	{
		return (execute_interactive_shell());
	}
}

/**
 * execute_commands_from_file - Execute commands from a file.
 * @filename: The name of the file containing commands.
 * Return: 0 on success, 1 on failure.
 */
int execute_commands_from_file(const char *filename)
{
	FILE *file = fopen(filename, "r");

	if (!file)
	{
		perror("Error opening file");
		return (1);
	}

	char line[LINE_BUFFER_SIZE];
	char *pos;

	while (fgets(line, LINE_BUFFER_SIZE, file) != NULL)
	{
		pos = strchr(line, '\n');
		if (pos != NULL)
		{
			*pos = '\0';
		}
		execute_command(line);
	}

	fclose(file);
	return (0);
}

/**
 * execute_interactive_shell - Execute an interactive shell.
 * Return: EXIT_SUCCESS (0) to indicate successful termination.
 */
int execute_interactive_shell(void)
{
	char *command;

	while (1)
	{
		display_prompt();
		command = custom_getline();

		if (!command)
		{
			printf("\n");
			break;
		}
		execute_command(command);
		free(command);
	}

	return (0);
}
