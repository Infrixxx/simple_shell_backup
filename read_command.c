#include "shell.h"

/**
* read_command - Read a command from the user
*
* Return: The command entered by the user or NULL on "end of file" (Ctrl+D)
*/

char *read_command(void)
{
	char *buffer = NULL;
	size_t bufsize = 0;
	int characters;

characters = getline(&buffer, &bufsize, stdin);

if (characters == EOF)
{
free(buffer);
return (NULL);
}

buffer[characters - 1] = '\0'; /* Remove the trailing newline */
return (buffer);
}
