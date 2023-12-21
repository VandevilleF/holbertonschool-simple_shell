#include "main.h"

/**
 * parse_command - parse the command line
 * @input: pointer to the command line
 * @tok_array: array of command parse
 * Return: array for the next step 
 */

char **parse_command(char *input, char **tok_array)
{
	char *token;
	int i = 0;

	tok_array = malloc(sizeof(char *) * 20);

	if (tok_array == NULL)
	{
		free(input);
		exit(EXIT_FAILURE);
	}
	token = strtok(input, " \n\t");

	while (token != NULL)
	{
		tok_array[i] = strdup(token);
		token = strtok(NULL, " \n\t");
		i++;
	}
	tok_array[i] = NULL;
	return (tok_array);
}
