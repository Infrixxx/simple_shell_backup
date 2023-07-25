#include "shell.h"

/**
 * execute_builtin - Execute the given built-in command.
 * @args: The array of command arguments.
 *
 * Return: 1 if the command is a built-in and is executed, 0 otherwise.
 */
int execute_builtin(char **args)
{
	if (args[0] == NULL)
		return (0);

	if (strcmp(args[0], "exit") == 0)
	{
		/* Add your implementation for the exit command here */
		/* ... */
		return (1);
	}
	else if (strcmp(args[0], "cd") == 0)
	{
		return (cd_builtin(args));
	}
	else if (strcmp(args[0], "setenv") == 0)
	{
		return (setenv_builtin(args));
	}
	else if (strcmp(args[0], "unsetenv") == 0)
	{
		return (unsetenv_builtin(args));
	}
	else
	{
		return (0);
	}
}

/**
 * get_home_directory - Get the HOME directory.
 *
 * Return: The HOME directory path or NULL if not found.
 */
static char *get_home_directory(void)
{
	char *home = getenv("HOME");

	if (!home)
	{
		fprintf(stderr, "cd: No HOME environment variable.\n");
		return (NULL);
	}
	return (home);
}

/**
 * get_oldpwd_directory - Get the OLDPWD directory.
 *
 * Return: The OLDPWD directory path or NULL if not found.
 */
static char *get_oldpwd_directory(void)
{
	char *oldpwd = getenv("OLDPWD");

	if (!oldpwd)
	{
		fprintf(stderr, "cd: No OLDPWD environment variable.\n");
		return (NULL);
	}
	return (oldpwd);
}

/**
 * cd_builtin - Implement the cd (change directory) built-in command.
 * @args: The array of command arguments (should be "cd [DIRECTORY]").
 *
 * Return: 1 on success, -1 on failure.
 */
int cd_builtin(char **args)
{
	char *dir = args[1];
	char cwd[LINE_BUFFER_SIZE];

	if (dir == NULL)
		dir = get_home_directory();
	else if (strcmp(dir, "-") == 0)
		dir = get_oldpwd_directory();

	if (!dir)
		return (-1);

	if (chdir(dir) != 0)
	{
		perror("cd");
		return (-1);
	}

	if (getcwd(cwd, sizeof(cwd)) == NULL)
	{
		perror("getcwd");
		return (-1);
	}

	/* Update PWD environment variable */
	if (setenv("PWD", cwd, 1) != 0)
	{
		perror("setenv");
		return (-1);
	}

	return (1);
}
