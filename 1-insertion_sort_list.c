#include "sort.h"

/**
 * insertion_sort_list - function that sorts a doubly linked list of integers
 * in ascending order using the Insertion sort algorithm
 * @list: doubly linked list of integers
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *curr, *node, *swap;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	curr = *list;
	while ((curr = curr->next))
	{
		swap = curr;
		while (swap->prev && swap->n < swap->prev->n)
		{
			node = swap->prev;
			if (node->prev)
				node->prev->next = swap;
			if (swap->next)
				swap->next->prev = node;
			else
				*list = swap;
			node->next = swap->next;
			swap->prev = node->prev;
			swap->next = node;
			node->prev = swap;
			print_list(*list);
		}
	}
}
