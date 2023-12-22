#include "main.h"

char *_getenv(const char *name)
{
	extern char **environ;
	int i = 0;
	char *token;

	if (name == NULL)
		return (NULL);

	while (environ[i])
	{
		token = strtok(environ[i], "=");
		if (strcmp(token, name) == 0)
			return (strtok(NULL, "="));
		i++;
	}
	return (NULL);
}

int _which(char *command)
{
	char *token;
	char *path = _getenv("PATH");
	char *path_copy = strdup(path);
	char *full_path = NULL;

	token = strtok(path_copy, ":");
	while (token != NULL)
	{
		full_path = malloc(strlen(token) + strlen(command) + 2);
		printf("%s\n", full_path);
		if (full_path == NULL)
		{
			perror("Error allocate memory");
			exit(EXIT_FAILURE);
		}

		sprintf(full_path, "%s/%s", token, command);

		if (access(full_path, X_OK) == 0)
		{
			free(full_path);
			free(path_copy);
			return (1);
		}
		free(full_path);
		token = strtok(NULL, ":");
	}
	free(path_copy);
	return (0);
}

