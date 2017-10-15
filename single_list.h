#include <stdlib.h>

typedef struct single_linked_list 
{
	struct single_linked_list *next;
	int number;
}
single_list;

single_list* create(int);
single_list* insert(int, single_list*);
single_list* delete(int, single_list**);
int search(int number, single_list*);
void destroy(single_list**);
