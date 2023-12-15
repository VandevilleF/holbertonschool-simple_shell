#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int ac, char *av[])
{
	int count_words = 0, i = 0;
 	char *token, *buffer;
	char *sep = " ,.:!/*";
	char **array_word;

	if (ac != 2)
	{
		fprintf(stderr, "No arguments for %s", av[0]);
		exit(-1);
	}
	buffer = strdup(av[1]);
	if (buffer == NULL)
	{
		perror("Allocation of memory error");
		exit(-1);
	}
	token = strtok(buffer, sep);

	while (token != NULL)
	{
		count_words++;
		token = strtok(NULL, sep);
	}
	array_word = malloc(sizeof(char*) * count_words);

	free(buffer);

	buffer = strdup(av[1]);

	token = strtok(buffer, sep);

	while (token != NULL)
	{
		array_word[i] = strdup(token);
		i++;
		token = strtok(NULL, sep);
	}
	for (i = 0; i < count_words; i++)
	{
		printf("Word n°%d : %s\n", i, array_word[i]);
		free(array_word[i]);
	}
	free(array_word);
	free(buffer);

	return (0);
}
