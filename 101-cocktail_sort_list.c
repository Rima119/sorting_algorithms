#include "sort.h"

/**
 * swap_node - swaps nodes in a doubly linked list
 * @head: a pointer to the head of the list
 * @node1: a pointer to the first node of the list
 * @node2: a pointer to the second node of the list
 */
void swap_node(listint_t **head, listint_t *node1, listint_t *node2)
{
	if ((node1->prev) != NULL)
		node1->prev->next = node2;
	else
		*head = node2;
	node1->prev = node2;
	node1->next = node2->next;
	node2->prev = node1->prev;
	node2->next = node1;
	if ((node2->next) != NULL)
		node2->next->prev = node1;
}

/**
 * cocktail_sort_list - sorts a doubly linked list of integers in
 * ascending order using the Cocktail shaker sort algorithm
 * @list: doubly linked list of integers
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *p;
	int swapped;

	if (!list || !*list || !(*list)->next)
		return;
	do {
		swapped = 0;
		for (p = *list; p->next != NULL; p = p->next)
		{
			if (p->n > p->next->n)
			{
				swap_node(list, p, p->next);
				print_list(*list);
				swapped = 1;
				p = p->prev;
			}
		}
		if (swapped)
			break;
		swapped = 0;
		for (p = *list; p->prev != NULL; p = p->prev)
		{
			if (p->n < p->prev->n)
			{
				swap_node(list, p->prev, p);
				swapped = 1;
				print_list(*list);
				p = p->next;
			}
		}
	} while (swapped);
}
