#include "main.h"

/**
 * execute_command - excute command line from input
 * @command: command line
 * @tok_array: pointer to array of pointers
 * @env: environnement variable
 * Return:status for exit status
 */

int execute_command(char *command, char **tok_array, int count, char **av, char **env)
{
	pid_t pid;
	int status = 0;

	/*Create a child process*/
	pid = fork();

	/*Check if fork is successful*/
	if (pid == -1)
	{
		perror("Error creating child process");
		exit(-1);
	}

	/*Fork successful*/
	if (pid == 0)
	{
		/*Execute the command in the child process*/
		if (execve(command, tok_array, env) == -1)
		{
			/*Print message error if command not found*/
			fprintf(stderr, "%s: %d: %s: not found\n", av[0], count, tok_array[0]);
			exit(127);/*Exit status for command not found*/
		}
	}

	else
		/*Wait end of child process*/
		wait(&status);

	return (status);
}
