/**
 * custom_strtok - Custom implementation of strtok.
 * @str: The string to tokenize.
 * @delimiters: The delimiters used to tokenize the string.
 *
 * Return: A pointer to the next token found in the string, or NULL.
 */
char *custom_strtok(char *str, const char *delimiters)
{
	static char *last_token;
	static int last_len;

	if (str)
	{
		last_token = str;
		last_len = 0;
	}

	if (!last_token || last_len == -1)
		return (NULL);

	char *token_start = last_token;
	char *token_end = NULL;
	int i, j;

	for (i = last_len; str[i]; i++)
	{
		for (j = 0; delimiters[j]; j++)
		{
			if (str[i] == delimiters[j])
			{
				str[i] = '\0';
				token_end = &str[i + 1];
				break;
			}
		}

		if (token_end)
			break;
	}

	last_len = (token_end) ? (int)(token_end - str) : -1;
	last_token = token_end;

	return (token_start);
}
