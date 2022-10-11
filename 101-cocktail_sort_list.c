#include "sort.h"

/**
 * swap_node - swaps nodes in a doubly linked list
 * @head: a pointer to the head of the list
 * @node: a pointer to the node
 */
void swap_node(listint_t **head, listint_t **node)
{
	if (((*node)->next->next) != NULL)
		(*node)->next->next->prev = *node;
	(*node)->next->next = *node;
	(*node)->next->prev = (*node)->prev;
	if (((*node)->prev) != NULL)
		(*node)->prev->next = (*node)->next;
	else
		*head = (*node)->next;
	(*node)->prev = (*node)->next;
	*node = (*node)->next;
}

/**
 * cocktail_sort_list - sorts a doubly linked list of integers in
 * ascending order using the Cocktail shaker sort algorithm
 * @list: doubly linked list of integers
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *tmp;
	int swapped = 0;

	if (!list || !*list || !(*list)->next)
		return;
	tmp = *list;
	while (!swapped)
	{
		swapped = 1;
		while (tmp->next)
		{
			if (tmp->n > tmp->next->n)
			{
				swapped = 0;
				swap_node(list, &tmp);
				print_list(*list);
			}
			else
				tmp = tmp->next;
		}
		if (swapped)
			break;
		tmp = tmp->prev;
		while (tmp->prev)
		{
			if (tmp->n < tmp->prev->n)
			{
				swapped = 0;
				tmp = tmp->prev;
				swap_node(list, &tmp);
				print_list(*list);
			}
			else
				tmp = tmp->prev;
		}
	}
}
