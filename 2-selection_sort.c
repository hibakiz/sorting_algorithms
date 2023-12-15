#include "sort.h"
/**
* selection_sort - sort an array with selection sort algorithm and
* print the array after each swap
* @array: integer array to sort
* @size: the size of the array
* Return: no return
*/

void selection_sort(int *array, size_t size)
{
	size_t i, j = 0, min;

	if (array == NULL || size < 2)
		return;
	for (i = 0; i < size - 1; i++)
	{
		min = i;
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[min])
			{
				min = j;
				continue;
			}
		}
		if (min != i)
		{
			swap_int(&array[i], &array[min]);
			print_array(array, size);
		}
		j++;
	}

}
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
