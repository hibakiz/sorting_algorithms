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
 * Horae_partition - Implements Horae partition scheme
 * @array: Array to be sorted
 * @low: Starting index of the partition
 * @high: Ending index of the partition
 * @size: Size of the array
 * Return: Index of the pivot element
 */
int Horae_partition(int *array, int low, int high, size_t size)
{
	int pvot = array[high];
	int val1, val2;

	for (val1 = low, val2 = high; 1; val1++, val2--)

	{
		while (array[val1] < pvot)
			val1++;

		while (array[val2] > pvot)
			val2--;

		if (val1 >= val2)
			return (val1);
		swap_int(&array[val1], &array[val2]);
		print_array(array, size);
	}
}

/**
 * Horae_sort - Function to sort partition recursevly
 * @array: address to array
 * @low_dx: low index in array
 * @high_dx: Last index in array
 * @size: The size of array
 */
void horae_sort(int *array, int low_dx, int high_dx, size_t size)
{
	if (low_dx < high_dx)
	{
		int pvot_index = Horae_partition(array, low_dx, high_dx, size);

		horae_sort(array, low_dx, pvot_index - 1, size);
		horae_sort(array, pvot_index, high_dx, size);
	}
}

/**
 * quick_sort_hoare - Function validate sorts array of integers ascendingly
 * @array: The array to be sorted
 * @size: The size
 */
void quick_sort_hoare(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	horae_sort(array, 0, size - 1, size);
}
