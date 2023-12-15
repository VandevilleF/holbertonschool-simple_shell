#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main (void)
{
	char *input = NULL;
	size_t bufsize = 0;
	char *sep = " ,.:!-*";
	char *token;

	printf("$ ");

	/*Use getline for read the line*/
	ssize_t char_read = getline(&input, &bufsize, stdin);

	if (char_read == -1)
	{
		perror("Error reading line");
		exit(1);
	}

	/*Use strtok to obtain the first word*/
	token = strtok(input, sep);

	/*Browse all words*/
	while (token != NULL)
	{
		printf("%s\n", token);
		/*Use strtok to obtain the following words*/
		token = strtok(NULL, sep);
	}
	free(input);
	return (0);
}
