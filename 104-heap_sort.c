#include "sort.h"
/**
* heap_sort - the main function to sort usinh heap algorithm
* @array: the array of int to sort
* @size: the array size
* Return: No return
*/
void heap_sort(int *array, size_t size)
{
	int i;

	for (i = size / 2 - 1; i >= 0; i--)
		heapify(array, size, i, size);

	for (i = size - 1; i > 0; i--)
	{
		swap_int(array, array + i);
		print_array(array, size);
		heapify(array, i, 0, size);
	}
}
/**
* heapify - helper function to create the heap and sort the
*array
* @arr: array to sort
* @n: the base size for the heap
* @i: the root for the heap
* @size: the size of the array for the print function
* Return: no return
*/
void heapify(int *arr, int n, int i, size_t size)
{
	int largest = i;
	int left = 2 * (i + 1) - 1;
	int right = 2 * (i + 1);

	if (left < n && arr[left] > arr[largest])
		largest = left;

	if (right < n && arr[right] > arr[largest])
		largest = right;

	if (largest != i)
	{
		swap_int(arr + i, arr + largest);
		print_array(arr, size);
		heapify(arr, n, largest, size);
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
