#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(void)
{
	char *line;
	char *argv[2];
	int status;

	while (1)
	{
		printf("$ ");
		line = NULL;
		size_t len = 0;
		if (getline(&line, &len, stdin) == -1)
		{
			break;
		}
		argv[0] = line;
		argv[1] = NULL;
		if (fork() == 0)
		{
			if (execve(argv[0], argv, NULL) == -1)
			{
				printf("Command not found\n");
			}
			exit(EXIT_FAILURE);
		}
		else
		{
			wait(&status);
		}
	}
	return (EXIT_SUCCESS);
}
