#include "main.h"

/**
 * execute_command - excute command line from input
 * @command: command line
 * @tok_array: pointer to array of pointers
 * @env: environnement variable
 * Return:status
 */

int execute_command(char *command, char **tok_array, int count, char **av, char **env)
{
	pid_t pid;
	int wstatus = 0;

	pid = fork();

	if (pid == -1)
	{
		perror("Error creating child process");
		exit(-1);
	}

	if (pid == 0)
	{
		if (execve(command, tok_array, env) == -1)
		{
			fprintf(stderr, "%s: %d: %s: not found\n", av[0], count, tok_array[0]);
			exit(EXIT_FAILURE);
		}
	}

	else
		wait(&wstatus);

	return (wstatus);
}
