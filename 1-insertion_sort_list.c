#include "sort.h"

/**
 * insertion_sort_list - function that sorts a doubly linked list of integers
 * @list: array
 * Return: the sorted double linked list
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *temp1, *temp2;
	int size = 0;

	if (list == NULL || *list == NULL)
	{
		return;
	}
	temp1 = (*list)->next;
	while (temp1 != NULL)
	{
		temp2 = temp1;
		temp1 = temp1->next;
		size++;
		while (temp2->prev)
		{
			if (temp2->prev->n > temp2->n)
			{
				/* swap nodes*/
				temp2->prev->next = temp2->next;
				if (temp2->next != NULL)
					temp2->next->prev = temp2->prev;
				temp2->next = temp2->prev;
				temp2->prev = temp2->next->prev;
				if (temp2->prev != NULL)
					temp2->prev->next = temp2;
				else
					*list = temp2;
				temp2->next->prev = temp2;
				print_list(*list);
			}
			else
			{
				break;
			}
		}
	}
}
