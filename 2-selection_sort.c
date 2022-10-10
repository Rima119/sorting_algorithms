#include "sort.h"

/**
 * swap_node - function that swaps two nodes
 * @node1: a pointer to the first node of the list
 * @node2: a pointer to the second node of the list
 */
void swap_node(int *node1, int *node2)
{
	int a = *node1;
	*node1 = *node2;
	*node2 = a;
}

/**
 * selection_sort - function that sorts an array of integers
 * in ascending order using the Selection sort algorithm
 * @array: the sorted array
 * @size: size of the array
 */
void selection_sort(int *array, size_t size)
{
	unsigned int a, b, c;

	if (array == NULL || size <= 0)
		return;

	for (a = 0; a < size - 1; a++)
	{
		b = a;
		for (c = a + 1; c < size; c++)
		{
			if (array[c] < array[b])
				b = c;
		}
		if (b != a)
		{
			swap_node(&array[b], &array[a]);
			print_array(array, size);
		}
	}
}
