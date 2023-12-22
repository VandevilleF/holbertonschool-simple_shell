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
 * main - code body function
 * @ac: void
 * @av: void
 * @env: environnement variable
 * Return: status for exit status
 */


int main(int ac, char **av, char **env)
{
	char *input = NULL;
	size_t bufsize = 0;
	char **tok_array;
	ssize_t char_read;
	int status, count = 0;
	(void)ac;

	while (1)
	{
		if (isatty(STDIN_FILENO))/*Dsiplay prompt if is interactive mode*/
			printf("$ ");
		count++;
		/*Read line of input from the user*/
		char_read = getline(&input, &bufsize, stdin);
		if (char_read == -1)/*Check for error or End Of File*/
		{
			if (input)
				free(input);
			break;/*Break out of the while loop*/

		}
		if (char_read > 0)
		{
			tok_array = parse_command(input, tok_array);/*Tokenize the cmd*/
			if (strcmp(tok_array[0], "exit") == 0)/*Check for the "exit" cmd*/
			{
				free(input);
				free_tok_array(tok_array);
				break;
			}
			/*Execute the command*/
			status = execute_command(tok_array[0], tok_array, count, av, env);
			free_tok_array(tok_array);/*Free tok_array*/
		}
		free(input);
		input = NULL;
	}
	return (status);
}
