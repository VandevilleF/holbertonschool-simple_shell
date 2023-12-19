#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

#define BUFSIZE 1024
#define DELIM " \t\r\n\a"

int main(int argc, char **argv)
{
        char *line, **args;
        int status;

        while (1)
	{
                printf("$ ");
                line = NULL;
                size_t bufsize = 0;

                getline(&line, &bufsize, stdin);
                args = malloc(BUFSIZE * sizeof(char *));
                if (!args)
                {
                        fprintf(stderr, "Allocation error\n");
                        exit(EXIT_FAILURE);
                }
                char *arg;
                int i = 0;

                arg = strtok(line, DELIM);
                while (arg != NULL)
                {
                        args[i] = arg;
                        i++;
                        arg = strtok(NULL, DELIM);
                }
                args[i] = NULL;
                pid_t pid = fork();

                if (pid == 0)
                {
                        if (execvp(args[0], args) == -1)
                                perror("Error");
                        exit(EXIT_FAILURE);
                }
                else if (pid < 0)
			perror("Error");
		else
			wait(&status);
                free(line);
                free(args);
        }
        return (0);
}

