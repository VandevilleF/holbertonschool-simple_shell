#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
	char *token, *path_env, *copy_path;

	path_env = getenv("PATH");

	if (path_env == NULL)
	{
		fprintf(stderr, "PATH not found\n");
		return (-1);
	}
	copy_path = strdup(path_env);
	token = strtok(copy_path, ":");

	while (token != NULL)
	{
		printf("%s\n", token);
		token = strtok(NULL, ":");
	}
	return (0);
}
