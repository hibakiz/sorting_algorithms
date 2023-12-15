#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * swap_int - Entry point
 *@a: int
 *@b: int
 * Description: 'tsks'
 *
 *
 * Return: Always 0 (Success)
 */
void swap_int(int *a, int *b)
{
	int c;

	c = *a;
	*a = *b;
	*b = c;
}

/**
 * lomuto_partition - Implements Lomuto partition scheme
 * @array: Array to be sorted
 * @low: Starting index of the partition
 * @high: Ending index of the partition
 * @size: Size of the array
 * Return: Index of the pivot element
 */
int lomuto_partition(int *array, int low, int high, size_t size)
{
	int pvot = array[high];
	int val1 = low - 1;
	int val2;

	for (val2 = low; val2 < high; val2++)
	{
		if (array[val2] < pvot)
		{
			val1++;
			if (val1 != val2)
			{
				swap_int(&array[val1], &array[val2]);
				print_array(array, size);
			}
		}
	}
	if ((val1 + 1) != high)
	{
		swap_int(&array[val1 + 1], &array[high]);
		print_array(array, size);
	}

	return (val1 + 1);
}

/**
 * lomuto_sort - Function to sort partition recursevly
 * @array: address to array
 * @low_dx: low index in array
 * @high_dx: Last index in array
 * @size: The size of array
 */
void lomuto_sort(int *array, int low_dx, int high_dx, size_t size)
{
	if (low_dx < high_dx)
	{
		int pvot_index = lomuto_partition(array, low_dx, high_dx, size);

		lomuto_sort(array, low_dx, pvot_index - 1, size);
		lomuto_sort(array, pvot_index + 1, high_dx, size);
	}
}

/**
 * quick_sort - Function that sorts array of integers ascendingly
 * @array: The array to be sorted
 * @size: The size
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	lomuto_sort(array, 0, size - 1, size);
}
