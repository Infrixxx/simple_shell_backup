#include "shell.h"

/**
 * custom_atoi - Custom implementation of the atoi function.
 * @str: The string to convert to an integer.
 *
 * Return: The converted integer.
 */
int custom_atoi(const char *str)
{
	int result = 0;
	int sign = 1;
	int i = 0;

	if (str[0] == '-')
	{
		sign = -1;
		i++;
	}

	while (str[i] != '\0')
	{
		if (str[i] >= '0' && str[i] <= '9')
		{
			result = result * 10 + (str[i] - '0');
		}
		else
		{
			return (0);
		}
		i++;
	}

	return (sign * result);
}
