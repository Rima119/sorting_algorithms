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
 * partition - function that divides array into two partitions
 * @array: the array
 * @size: size of the array
 * @low: input low index
 * @high: input high index
 * Return: new pivot
 */
int partition(int *array, int low, int high, size_t size)
{
	int pivot = array[high], a = low, b;

	for (b = low; b < high; b++)
	{
		if (array[b] <= pivot)
		{
			swap_node(&array[a], &array[b]);
			if (a != b)
				print_array(array, size);
			a++;
		}
	}
	swap_node(&array[a], &array[high]);
	if (a != b)
		print_array(array, size);
	return (a);
}

/**
 * quickSort - sorts an array of integers
 * in ascending order using the Quick sort algorithm
 * @arr: the sorted array
 * @size: size of the array
 * @low: input low index
 * @high: input high index
 */
void quickSort(int *arr, int low, int high, size_t size)
{
	int p;

	if (low < high)
	{
		p = partition(arr, low, high, size);
		quickSort(arr, low, p - 1, size);
		quickSort(arr, p + 1, high, size);
	}
}

/**
 * quick_sort - function that sorts an array of integers
 * in ascending order using the Quick sort algorithm
 * @array: the sorted array
 * @size: size of the array
 */
void quick_sort(int *array, size_t size)
{
	if (size < 2)
		return;
	quickSort(array, 0, size - 1, size);
}
