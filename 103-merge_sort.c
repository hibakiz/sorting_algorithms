#include "sort.h"
void merge_sort_recursive_tdd(int *array, size_t size);
/**
 * merge_sort - This function to sort ints in ascending order
 * @array: The array be sorte
 * @size: The size of the array
 */
void merge_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	merge_sort_recursive_tdd(array, size);
}
/**
 * merge_subarray - Function to merge subarrays into one array
 * @array: The array
 * @lft: left of array
 * @lft_size: The size of subarray
 * @rht: The right part of subarray
 * @rht_size: The size of rht
 */
void merge_subarray(int *array, int *lft, int lft_size, int *rht, int rht_size)
{
	int i = 0, j = 0, k = 0;
	int *m = malloc((lft_size + rht_size) * sizeof(int));

	if (!m)
		exit(EXIT_FAILURE);

	while (i < lft_size && j < rht_size)
	{
		if (lft[i] <= rht[j])
			m[k++] = lft[i++];
		else
			m[k++] = rht[j++];
	}

	while (i < lft_size)
		m[k++] = lft[i++];

	while (j < rht_size)
		m[k++] = rht[j++];

	for (i = 0; i < lft_size + rht_size; i++)
		array[i] = m[i];

	free(m);
}

/**
 * merge_sort_recursive_tdd - This function do merg sort recursevly
 * @array: The array
 * @size: The size
 */
void merge_sort_recursive_tdd(int *array, size_t size)
{
	int mid, *lft, *rht;

	if (size < 2)
		return;

	lft = array;
	mid = size / 2;
	rht = array + mid;

	merge_sort_recursive_tdd(lft, mid);
	merge_sort_recursive_tdd(rht, size - mid);

	printf("Merging...\n");
	printf("[left]: ");
	print_array(lft, mid);
	printf("[right]: ");
	print_array(rht, size - mid);

	merge_subarray(array, lft, mid, rht, size - mid);

	printf("[Done]: ");
	print_array(array, size);
}
