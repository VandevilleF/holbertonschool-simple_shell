#include "main.h"

/**
 *
 *
 *
 */


int main(int ac, char *av, char **env)
{
	char *input = NULL;
	size_t bufsize = 0;
	char *token, **tok_array;
	int j, i = 0;
	(void)ac, (void)av;

	while (1)
	{
		printf("$ ");

		ssize_t char_read = getline(&input, &bufsize, stdin);

		if (char_read == -1)
		{
			perror("Error reading line");
			return (-1);
		}

		token = strtok(input, " \n");
		while ( token != NULL)
		{
			token = strtok(NULL, " \n");
			i++;
		}
		tok_array = malloc(sizeof(char *) * i);
		
		i = 0;

		while (token != NULL)
		{
			tok_array[i] = strdup(token);
			token = strtok(NULL, " \n");
			i++;
		}
		tok_array[i] = NULL; /*Add NULL at the end*/


		execute_command(tok_array[0], tok_array, env);

		for (j = 0; j < i; j++)
			free(tok_array[j]);
		i = 0;
	}
	free(input);
	return (0);
}
