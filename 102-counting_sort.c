#include "sort.h"
/**
 * counting_sort - function to sort integers array ascendingly.
 * @array: The array of integers to be sorted
 * @size: The size of array
 *
 * Return: void
 */
void counting_sort(int *array, size_t size)
{
	int i, max_val;
	int *fre_array = NULL, *result = NULL;
	size_t j, tmp, val = 0, n, m;

	if (size < 2)
		return;

	max_val = array[0];
	result = malloc(sizeof(int) * size);
	if (result == NULL)
		return;
	for (j = 0; j < size; j++)
	{
		result[j] = array[j];
		if (array[j] > max_val)
			max_val = array[j];
	}
	fre_array = malloc(sizeof(size_t) * (max_val + 1));
	if (fre_array == NULL)
	{
		free(result);
		return;
	}
	for (i = 0; i <= max_val; i++)
		fre_array[i] = 0;
	for (j = 0; j < size; j++)
		fre_array[array[j]] += 1;
	for (i = 0; i <= max_val; i++)
	{
		tmp = fre_array[i];
		fre_array[i] = val;
		val += tmp;
	}
	for (j = 0; j < size; j++)
	{
		array[fre_array[result[j]]] = result[j];
		fre_array[result[j]] += 1;
	}

	print_array(fre_array, max_val + 1);
	for (m = 0; m < size; m++)
	{
		result[fre_array[array[m]] - 1] = array[m];
		fre_array[array[m]]--;
	}
	for (n = 0; n < size; n++)
		array[n] = result[n];
	free(fre_array);
	free(result);
}
