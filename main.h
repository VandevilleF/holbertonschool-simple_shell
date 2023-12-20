#ifndef __protect__
#define __protect__

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

int execute_command(char *command, char **tok_array, char **env);
int main(int ac, char **av, char **env);

#endif
