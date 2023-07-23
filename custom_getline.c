#include "shell.h"

/**
 * read_input - Read input from the standard input into a buffer.
 * @buffer: The buffer to store the input.
 * @buffer_size: The size of the buffer.
 *
 * Return: Number of characters read, or -1 on failure.
 */
static int read_input(char *buffer, int buffer_size)
{
	int characters_read = read(STDIN_FILENO, buffer, buffer_size);

	if (characters_read <= 0)
		return (-1);

	return (characters_read);
}

/**
 * process_input - Process the input buffer and extract a line.
 * @buffer: The buffer containing the input to process.
 * @buffer_size: The size of the buffer.
 *
 * Return: Pointer to the line read from input, or NULL on failure.
 */
static char *process_input(char *buffer, int buffer_size)
{
	static int buffer_index;
	char *line = NULL;
	int i = 0;

	if (buffer_index == 0 && read_input(buffer, buffer_size) <= 0)
		return (NULL);

	line = malloc(LINE_BUFFER_SIZE * sizeof(char));
	if (!line)
	{
		perror("Memory Allocation Error");
		return (NULL);
	}

	while (buffer_index < buffer_size)
	{
		if (buffer[buffer_index] == '\n')
		{
			line[i] = '\0';
			buffer_index++;
			return (line);
		}

		line[i] = buffer[buffer_index];
		i++;
		buffer_index++;

		if (i >= LINE_BUFFER_SIZE)
		{
			if (!realloc_line(&line, &i))
				return (NULL);
		}
	}

	if (buffer_index >= buffer_size)
		buffer_index = 0;

	return (line);
}

/**
 * realloc_line - Reallocate the line buffer to extend its size.
 * @line: Pointer to the line buffer.
 * @i: Pointer to the current index in the buffer.
 *
 * Return: 1 on success, 0 on failure.
 */
static int realloc_line(char **line, int *i)
{
	char *new_line = realloc(*line, (*i + LINE_BUFFER_SIZE) * sizeof(char));

	if (!new_line)
	{
		perror("Memory Allocation Error");
		free(*line);
		*line = NULL;
		return (0);
	}

	*line = new_line;
	return (1);
}

/**
 * custom_getline - Read a line of input from the standard input.
 *
 * Return: On success, returns a pointer to the line read from input.
 *         On failure or end-of-file, returns NULL.
 */
char *custom_getline(void)
{
	static char buffer[BUFFER_SIZE];
	int characters_read = read_input(buffer, BUFFER_SIZE);

	if (characters_read <= 0)
		return (NULL);

	return (process_input(buffer, characters_read));
}
