#include "sort.h"

/**
 * bubble_sort - function that sorts an array of integers
 * in ascending order using the Bubble sort algorithm
 * @array: the sorted array
 * @size: size of the array
 */
void bubble_sort(int *array, size_t size)
{
	size_t a, b, c;

	if (size < 2 || array == NULL)
		return;
	for (a = 0; a < size; a++)
	{
		for (b = 0; b < size - 1; b++)
		{
			if (array[b] > array[b + 1])
			{
				c = array[b];
				array[b] = array[b + 1];
				array[b + 1] = c;
				print_array(array, size);
			}
		}
	}
}
