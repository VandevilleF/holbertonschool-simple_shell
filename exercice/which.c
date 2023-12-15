#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
	char *path = getenv("PATH");
	char *dir;
	char *p;
	char filename[1000];
	int found = 0;

	if (argc != 2)
	{
		fprintf(stderr, "Usage: %s filename\n", argv[0]);
		return 1;
	}

	while ((dir = strsep(&path, ":")) != NULL)
	{
		sprintf(filename, "%s/%s", dir, argv[1]);
		if (access(filename, F_OK) == 0)
		{
			printf("%s\n", filename);
			found = 1;
			break;
		}
	}

	if (!found)
	{
		fprintf(stderr, "%s: command not found\n", argv[1]);
		return 1;
	}
	return 0;
}
