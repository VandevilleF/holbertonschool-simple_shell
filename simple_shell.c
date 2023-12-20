#include "main.h"

/**
 * free_tok_array - free array of token
 * @tok_array: array where token are stored
 * Retrun: Nothing
 */

void free_tok_array(char ** tok_array)
{
	int i;

	if (tok_array != NULL)
	{
		for (i = 0; tok_array[i] != NULL; i++)
		free(tok_array[i]);
		free(tok_array);
	}
}

/**
 * main - main
 * @ac: void
 * @av: void
 * @env: environnement variable
 * Return: 0
 */


int main(int ac, char **av, char **env)
{
	char *input = NULL;
	size_t bufsize = 0;
	char **tok_array;
	ssize_t char_read;

	(void)ac, (void)av;

	while (1)
	{
		printf("$ ");
		char_read = getline(&input, &bufsize, stdin);

		if (char_read != 1)
		{
			tok_array = parse_command(input, tok_array);

			if (strcmp(tok_array[0], "exit") == 0)
			{
				free_tok_array(tok_array);
				break;
			}
			execute_command(tok_array[0], tok_array, env);

			free_tok_array(tok_array);
		}
		input = NULL;
	}
	return (0);
}
