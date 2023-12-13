#include <stdio.h>

extern char **environ;

int main(int ac, char **av, char **env)
{
	printf("Address of env is : %p\n", env);
	printf("Address of environ is : %p\n", environ);
/* L'adresse de env et environ peut être la même car environ pointe vers la même zone mémoire que env. */
	return (0);
}
