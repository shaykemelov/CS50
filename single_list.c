#include "single_list.h"

single_list* create(int number)
{
	single_list *list = (single_list*)malloc(sizeof(single_list));
	if (list == NULL)
	{
		return NULL;
	}

	list->next = NULL;
	list->number = number;
	return list;
}

single_list* insert(int number, single_list *list)
{
	single_list *node = (single_list*)malloc(sizeof(single_list));
	if (node == NULL)
	{
		return list;
	}

	node->next = list;
	node->number = number;
	return node;
}

single_list* delete(int number, single_list **list)
{
	single_list *prev = *list;
	single_list *current = *list;
	
	int found = 0;
	
	while (current != NULL)
	{
		if (current->number == number)
		{
			found = 1;
			break;
		}
		prev = current;
		current = current->next;
	}
	
	if (found)
	{
		if (prev == current)
		{
			single_list **temp = &current->next;
			free(current);
			return *temp;
		}
		prev->next = current->next;
		free(current);
		current = NULL;
		return prev;
	}
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
