#include "sort.h"
/**
* bubble_sort - sort an array with bubble sort algorithm and
* print the array after each swap
* @array: integer array to sort
* @size: the size of the array
* Return: no return
*/

void bubble_sort(int *array, size_t size)
{
	size_t i;
	int flag;

	if (array == NULL || size < 2)
		return;
	do {
		flag = 0;
		for (i = 0; i < size - 1; i++)
		{
			if (array[i] > array[i + 1])
			{
				swap_int(&array[i], &array[i + 1]);
				flag = 1;
				print_array(array, size);
			}

		}
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
