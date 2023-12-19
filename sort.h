#ifndef SORT_H
#define SORT_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/**
 * struct listint_s - Doubly linked list node
 *
 * @n: Integer stored in the node
 * @prev: Pointer to the previous element of the list
 * @next: Pointer to the next element of the list
 */
typedef struct listint_s
{
	const int n;
	struct listint_s *prev;
	struct listint_s *next;
} listint_t;

void print_array(const int *array, size_t size);
void print_list(const listint_t *list);
void bubble_sort(int *array, size_t size);
void swap_int(int *a, int *b);
void insertion_sort_list(listint_t **list);
int list_len(listint_t *l);
void swap(listint_t **list, listint_t *nod1, listint_t *nod2);
void selection_sort(int *array, size_t size);
int lomuto_partition(int *array, int low, int high, size_t size);
void lomuto_sort(int *array, int low_dx, int high_dx, size_t size);
void quick_sort(int *array, size_t size);
void quick_sort_hoare(int *array, size_t size);
void horae_sort(int *array, int low_dx, int high_dx, size_t size);
int Horae_partition(int *array, int low, int high, size_t size);
void counting_sort(int *array, size_t size);
void heapify(int *arr, int n, int i, size_t size);
void heap_sort(int *array, size_t size);

#endif
