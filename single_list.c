#include "single_list.h"

single_list* create(int number)
{
	single_list *list = (single_list*)malloc(sizeof(single_list));
	if (list != NULL)
	{
		list->next = NULL;
		list->number = number;
		return list;
	}
}

single_list* insert(int number, single_list *list)
{
	single_list *node = (single_list*)malloc(sizeof(single_list));
	if (node != NULL)
	{
		node->next = list;
		node->number = number;
		return node;
	}
}

single_list* delete(int number, single_list **list)
{
	single_list *ptr = *list;
	if (ptr->number == number)
	{
		*list = ptr->next;
		free(ptr);
		ptr = NULL;
		return *list;	
	}
	
	while ((ptr->next != NULL) && (ptr->next->number != number))
	{
		ptr = ptr->next;
	}
	
	single_list *remove = ptr->next;
	ptr->next = remove->next;
	free(remove);
	remove = NULL;
	return *list;
}

int search(int number, single_list *list)
{
	single_list *ptr = list;
	while (ptr != NULL)
	{
		if (ptr->number == number)
		{
			return 1;
		}
		ptr = ptr->next;
	}
	return 0;
}

void destroy(single_list * *list)
{
	if ((*list) == NULL)
	{
		return;
	}
	if ((*list)->next != NULL)
	{
		destroy(&(*list)->next);
	}
	free(*list);
	*list = NULL;
}
