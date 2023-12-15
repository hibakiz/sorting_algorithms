#include "sort.h"

/**
 * list_len - calaculate length of linkedlis
 * @l: pointer to the head of list
 *
 * Return: length of linked list
 */
int list_len(listint_t *l)
{
	int h = 0;

	while (l)
	{
		h++;
		l = l->next;
	}
	return (h);
}

/**
 * swap - function to swaps 2 nodes in a DLL
 * @nod1: Pointer to the first node to swap
 * @nod2: pointer to the second node
 * @list: double pointer ssign to head of DLL.
 *
 * Return: No return
 */
void swap(listint_t **list, listint_t *nod1, listint_t *nod2)
{
	if (nod1->prev != NULL)
		nod1->prev->next = nod2;
	else
		*list = nod2;

	if (nod2->next != NULL)
		nod2->next->prev = nod1;
	nod1->next = nod2->next;
	nod2->prev = nod1->prev;
	nod1->prev = nod2;
	nod2->next = nod1;
}

/**
 * insertion_sort_list - Defines insertion sorts a doubly linked ascendinly.
 * @list: Pointer to a head node of linked list
 *
 * Return: No return
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *key, *i;

	if (list == NULL || *list == NULL || list_len(*list) < 2)
		return;
	key = (*list)->next;
	while (key != NULL)
	{
		i = key->next;
		while (key->prev != NULL && key->prev->n > key->n)
		{
			swap(list, key->prev, key);
			print_list(*list);
		}
		key = i;
	}
}
