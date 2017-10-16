#include <stdio.h>
#include "algorithms.h"
#include "single_list.h"

void display_list(single_list*);

int main(int argc, char *argv[]) 
{
	single_list *list = create(3);
	if (list == NULL)
	{
		return 1;
	}
	list = insert(5, list);
	list = insert(78, list);
	
	printf("List before deletion:\n");
	display_list(list);
	list = delete(4, &list);
	//list = delete(5, &list);
	//list = delete(3, &list);
	list = delete(78, &list);
	printf("List after deletion:\n");
	display_list(list);
	destroy(&list);	
	display_list(list);
	return 0;
}

void display_list(single_list *list)
{
	single_list *ptr = list;
	while (ptr != NULL)
	{
		printf("%i\n", ptr->number);
		ptr = ptr->next;
	}
}
