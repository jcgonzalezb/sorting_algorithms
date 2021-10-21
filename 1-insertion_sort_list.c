#include "sort.h"

/**
 * insertion_sort_list - function that sorts a doubly linked list of integers
 * @list: array
 * Return: the sorted double linked list
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *temp1;
	int size = 0;
	int i;

	if (list == NULL || *list == NULL)
	{
		return;
	}
	while (list != NULL)
	{
		*list = (*list)->next;
		size++;
	}
	for (i = 0; i < size; i++)
	{
		temp1 = *list;
		while (temp1->next && temp1->n > temp1->next->n)
		{
			temp1->prev->next = temp1->next;
			temp1->next->next->prev = temp1->next->prev;
			temp1->next->prev = temp1->prev;
			temp1->prev = temp1->next;
			temp1->next = temp1->next->next;
			temp1->next->next = temp1;
		}
		temp1 = temp1->next;
		print_list(*list);
	}
}
