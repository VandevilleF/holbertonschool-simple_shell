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
	char *token, **tok_array;
	int i;
	ssize_t char_read;

	(void)ac, (void)av;

	while (1)
	{
		printf("$ ");
		char_read = getline(&input, &bufsize, stdin);

		if (char_read != 1)
		{
			tok_array = malloc(sizeof(char *) * 20);

			if (tok_array == NULL)
			{
				free(input);
				exit(EXIT_FAILURE);
			}
			token = strtok(input, " \n\t");

			i = 0;

			while (token != NULL)
			{
				tok_array[i] = strdup(token);
				token = strtok(NULL, " \n\t");
				i++;
			}
			tok_array[i] = NULL; /*Add NULL at the end*/

			if (strcmp(tok_array[0], "exit") == 0)
			{
				free_tok_array(tok_array);
				free(input);
				break;
			}
			execute_command(tok_array[0], tok_array, env);

			free_tok_array(tok_array);
		}
		free(input);
		input = NULL;
	}
	return (0);
}
