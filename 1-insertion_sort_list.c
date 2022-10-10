#include "sort.h"

/**
 * swap_node - function that swaps two nodes in doubly linked list
 * @head: a pointer to the head of the list
 * @node1: a pointer to the first node of the list
 * @node2: a pointer to the second node of the list
 */
void swap_node(listint_t **head, listint_t **node1, listint_t *node2)
{
	(*node1)->next = node2->next;
	if ((node2->next) != NULL)
		node2->next->prev = *node1;
	node2->prev = (*node1)->prev;
	node2->next = *node1;
	if ((*node1)->prev != NULL)
		(*node1)->prev->next = node2;
	else
		*head = node2;
	(*node1)->prev = node2;
	*node1 = node2->prev;
}

/**
 * insertion_sort_list - function that sorts a doubly linked list of integers
 * in ascending order using the Insertion sort algorithm
 * @list: doubly linked list of integers
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *curr, *node, *tmp;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;
	for (curr = (*list)->next; curr != NULL; curr = tmp)
	{
		tmp = curr->next;
		node = curr->prev;
		while (node != NULL && curr->n < node->n)
		{
			swap_node(list, &node, curr);
			print_list((const listint_t *)*list);
		}
	}
}
