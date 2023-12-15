#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct list_s
{
	char *str;
	struct list_s *next;
} list_t;

int main(void)
{
	list_t **head = NULL;
	list_t *new_node, *temp = NULL;
	char *token, *path_env, *copy_path;
				
	path_env = getenv("PATH");

	if (path_env == NULL)
	{
		fprintf(stderr, "PATH not found\n");
		return (-1);
	}
	copy_path = strdup(path_env);
			
	token = strtok(copy_path, ":");
						
 	/*temp = *head;*/

	while (token != NULL)
	{
		new_node = malloc(sizeof(list_t));
		
		if (new_node == NULL)
		{
			return (-1);
		}
											
		new_node->str = strdup(token);
		new_node->next = NULL;
										
		if (head == NULL)
		{
			head = &new_node;
			temp = new_node;
		}
		else
		{
			temp->next = new_node;
			temp = new_node;
		}

		printf("token is :%s\n", token);
		printf("%s\n", temp->str);

		token = strtok(NULL, ":");
																				}
																				return (0);
}
