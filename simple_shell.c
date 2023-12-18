#include "main.h"

/**
 *
 *
 *
 */


int main(void)
{
	char *input = NULL;
	size_t bufsize = 0;
	char *token;
	char *tok_array[120];
	int j, i = 0;
	int condition = 1;

	while (condition)
	{
		printf("$ ");

		ssize_t char_read = getline(&input, &bufsize, stdin);

		if (char_read == -1)
		{
			perror("Error reading line");
			return (-1);
		}

		if (strcmp(input, "exit") == 0)
			condition = 0;

		token = strtok(input, " \n");

		while (token != NULL)
		{
			tok_array[i] = strdup(token);
			token = strtok(NULL, " \n");
			i++;
		}
		tok_array[i] = NULL; /*Add NULL at the end*/

		for (j = 0; j < i; j++)
			free(tok_array[j]);
		i = 0;
	}
	free(input);
	return (0);
}
