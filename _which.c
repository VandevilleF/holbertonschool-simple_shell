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

int _which(int ac, char **av)
{
	int i = 0;
	char *token;
	char *path = _getenv("PATH");
	char *path_copy = strdup(path);
	path_array = malloc(sizeof(char *) * 10);
	

	token = strtok(path_copy, ":");
	while (token != NULL)
	{
		/*copier le contenu du token dans le "array"*/
		sprintf(path_array[i], %s/%s, token);
		token = strtok(NULL, ":");
		i++;
	}
	if (access(path_array, F_OK) == 0)
		return (path_array);
}

