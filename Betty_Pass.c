#include <stdio.h>

/**
 * greet_world - Prints a greeting message to the world
 */
void greet_world(void)
{
	printf("Hello, world!\n");
}

/**
 * main - Entry point of the program
 *
 * Return: 0 on success
 */
int main(void)
{
	int i;

	for (i = 0; i < 10; i++)
	{
		greet_world();
	}

	return (0);
}
