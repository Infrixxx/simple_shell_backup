#include "shell.h"

/**
 * replace_variables - Replace variables in the command with their values.
 * @command: The command to process.
 *
 * Return: The command with variables replaced, or NULL on failure.
 */
char *replace_variables(char *command, int last_status_code)
{
	if (!command)
		return (NULL);

	char *result = malloc(strlen(command) + 1);
	if (!result)
		return (NULL);

	char *p = command, *r = result, *value, variable[BUFFER_SIZE];

	while (*p)
	{
		if (*p == '#')
		{
			while (*p && *p != '\n')
				p++;
		}
		else if (*p == '$')
		{
			p++;
			char *v = variable;
			while (*p && isalnum(*p))
				*v++ = *p++;
			*v = '\0';

			if (strcmp(variable, "?") == 0)
				value = custom_itoa(last_status_code);
			else if (strcmp(variable, "$") == 0)
				value = custom_itoa(getpid());
			else
				value = getenv(variable);
			if (value)
				while (*value)
					*r++ = *value++;
		}
		else
			*r++ = *p++;
	}
	*r = '\0';
	return (result);
}i

/**
 * custom_itoa - Convert an integer to a string.
 * @num: The integer to convert.
 *
 * Return: The converted string, or NULL on failure.
 */
char *custom_itoa(int num)
{
	int len = snprintf(NULL, 0, "%d", num);

	if (len <= 0)
		return (NULL);

	char *str = malloc(len + 1);

	if (str == NULL)
		return (NULL);

	snprintf(str, len + 1, "%d", num);
	return (str);
}

/**
 * custom_strlen - Get the length of a NULL-terminated array of strings.
 * @arr: The array of strings.
 *
 * Return: The length of the array.
 */
int custom_strlen(char **arr)
{
	int length = 0;

	while (arr[length] != NULL)
	{
		length++;
	}
	return (length);
}
