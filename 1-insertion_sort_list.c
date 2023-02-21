#include "sort.h"

/**
 * swap_nodes - swaps two nodes in a listint_t doubly-linked list.
 * @h: pointer to the head of the doubly-linked list.
 * @n1: pointer to the first node to swap.
 * @n2: the second node to swap.
 */

void swap_nodes(listint_t **h, listint_t **n1, listint_t *n2)
{
	(*n1)->next = n2->next;

	if (n2->next != NULL)
		n2->next->prev = *n1;

	n2->prev = (*n1)->prev;
	n2->next = *n1;

	if ((*n1)->prev != NULL)
		(*n1)->prev->next = n2;
	else
		*h = n2;

	(*n1)->prev = n2;
	*n1 = n2->prev;
}

/**
 * insertion_sort_list - sorts a doubly linked list of integers
 *                       using the insertion sort algorithm.
 * @list: pointer to the head of a doubly-linked list of integers.
 * Description: prints the list after each swap.
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *node, *insert, *temp;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	for (node = (*list)->next; node != NULL; node = temp)
	{
		temp = node->next;
		insert = node->prev;
		while (insert != NULL && node->n < insert->n)
		{
			swap_nodes(list, &insert, node);
			print_list((const listint_t *)*list);
		}
	}
}
