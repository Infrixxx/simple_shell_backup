#include "shell.h"
/**
 * main - Entry point for the Simple Shell program.
 * Return:EXIT_SUCCESS (0) to indicate successful termination.
 */

int main(void)
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

return (EXIT_SUCCESS);
}
