#include <stdio.h>
#include "algorithms.h"
#include "single_list.h"

void display_list(single_list*);

int main(int argc, char *argv[]) 
{
	single_list *list = create(3);
	list = insert(5, list);
	list = insert(78, list);
	
	printf("List before deletion:\n");
	display_list(list);
	printf("List after deletion:\n");
	delete(5, &list);
	delete(3, &list);
	delete(78, &list);
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
