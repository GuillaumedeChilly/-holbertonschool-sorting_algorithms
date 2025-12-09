#include "sort.h"

/**
 * lomuto_partition - partitions the array using Lomuto scheme
 * @array: array to partition
 * @low: starting index of the partition
 * @high: ending index (pivot index) of the partition
 * @size: full size of the array (for printing)
 *
 * Return: index of the pivot after partition
 */
static int lomuto_partition(int *array, int low, int high, size_t size)
{
	int pivot, tmp;
	int i, j;

	pivot = array[high];
	i = low;

	for (j = low; j < high; j++)
	{
		if (array[j] < pivot)
		{
			if (i != j)
			{
				tmp = array[i];
				array[i] = array[j];
				array[j] = tmp;
				print_array(array, size);
			}
			i++;
		}
	}

	if (array[i] != array[high])
	{
		tmp = array[i];
		array[i] = array[high];
		array[high] = tmp;
		print_array(array, size);
	}

	return (i);
}

/**
 * quick_sort_rec - recursive helper for quick_sort
 * @array: array to sort
 * @low: starting index of the partition
 * @high: ending index of the partition
 * @size: full size of the array
 */
static void quick_sort_rec(int *array, int low, int high, size_t size)
{
	int p;

	if (low < high)
	{
		p = lomuto_partition(array, low, high, size);
		quick_sort_rec(array, low, p - 1, size);
		quick_sort_rec(array, p + 1, high, size);
	}
}

/**
 * quick_sort - sorts an array of integers in ascending order
 * using the Quick sort algorithm (Lomuto partition)
 * @array: array to sort
 * @size: size of the array
 */
void quick_sort(int *array, size_t size)
{
	if (!array || size < 2)
		return;

	quick_sort_rec(array, 0, (int)size - 1, size);
}
