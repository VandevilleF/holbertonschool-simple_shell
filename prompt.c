#include <stdio.h>
#include <stdlib.h>

int main()
{
	char *buffer;
	size_t bufsize = 32;
	size_t char_read;
    
	printf("$ ");
	buffer = malloc(bufsize * sizeof(char));

	if( buffer == NULL)
	{
		perror("Unable to allocate buffer");
		exit(1);
	}

	char_read = getline(&buffer,&bufsize,stdin);

	if (char_read == (size_t) - 1)
	{
		perror("Unable to allocate buffer");
		exit(1);
	}

	printf("%s",buffer);
	free(buffer);
	return(0);
}
