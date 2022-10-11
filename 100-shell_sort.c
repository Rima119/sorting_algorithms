#include "sort.h"

/**
 * shell_sort - function that sorts an array of integers in ascending order
 * using the Shell sort algorithm, using the Knuth sequence
 * @array: sorted array
 * @size: size of the array
 */
void shell_sort(int *array, size_t size)
{
	size_t gap, a, b;
	int tmp;

	if (array == NULL || size < 2)
		return;
	for (gap = 1; gap < (size / 3);)
		gap = gap * 3 + 1;
	for (; gap > 0; gap = (gap - 1) / 3)
	{
		for (a = gap; a < size; a++)
		{
			tmp = array[a];
			for (b = a; b >= gap && array[b - gap] >= tmp; b -= gap)
				array[b] = array[b - gap];
			array[b] = tmp;
		}
		print_array(array, size);
	}
}
