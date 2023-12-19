#include "main.h"

/**
 * execute_command - excute command line from input
 * @command: command line
 * @tok_array: pointer to array of pointers
 * @env: environnement variable
 * Return:status
 */

int execute_command(char *command, char **tok_array, char **env)
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
			perror("Error executing command");
			exit(-1);
		}
	}

	else
		wait(&wstatus);

	return (wstatus);
}
