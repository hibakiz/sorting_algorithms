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
	size_t i, j = 0;
	int flag;

	do {
		flag = 0;
		for (i = 0; i < size - 1; i++)
		{
			if (array[j] < array[i])
			{
				swap_int(&array[j], &array[i]);
				flag = 1;
				print_array(array, size);
			}

		}
		j++;
	} while (flag);

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
