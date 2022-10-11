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
	int swapped = 0;

	p = *list;
	while (!swapped)
	{
		swapped = 1;
		while (p->next)
		{
			if (p->n > p->next->n)
			{
				swapped = 0;
				swap_node(list, p, p->next);
				print_list(*list);
			}
			else
				p = p->next;
		}
		if (swapped)
			break;
		p = p->prev;
		while (p->prev)
		{
			if (p->n < p->prev->n)
			{
				swapped = 0;
				p = p->prev;
				swap_node(list, p->prev, p);
				print_list(*list);
			}
			else
				p = p->prev;
		}
	}
}
