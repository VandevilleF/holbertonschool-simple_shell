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

	/*Allocated memory for an array*/
	tok_array = malloc(sizeof(char *) * 20);

	/*Check if allocated is successful*/
	if (tok_array == NULL)
	{
		free(input);/*Free if allocated is fail*/
		exit(EXIT_FAILURE);
	}
	/*Tokenize the input string with delimiter*/
	token = strtok(input, " \n\t");

	/*Loop for find the end of the string*/
	while (token != NULL)
	{
		/*Store in the array with an allocated memory*/
		tok_array[i] = strdup(token);
		/*Tokenize the next part*/
		token = strtok(NULL, " \n\t");
		i++;
	}
	/*Set the last index to NULL for the end of th array*/
	tok_array[i] = NULL;
	return (tok_array);
}
