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
		FILE *file = fopen(argv[1], "r");
		if (!file)
		{
			perror("Error opening file");
			return (1);
		}

		char line[LINE_BUFFER_SIZE];
		while (fgets(line, LINE_BUFFER_SIZE, file) != NULL)
		{
			char *pos;
			if ((pos = strchr(line, '\n')) != NULL)
				*pos = '\0';

			execute_command(line);
		}

		fclose(file);
	}
	else
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
	}

	return (0);
}
