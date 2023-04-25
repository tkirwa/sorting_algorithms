#include "sort.h"

/**
 * insertion_sort_list - Sorts a doubly linked list of integers in ascending
 *                        order using the Insertion sort algorithm.
 *
 * @list: A pointer to a pointer to the first node of the list
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *node, *cur, *prev;

	if (!list || !*list || !(*list)->next)
		return;

	node = (*list)->next;
	while (node)
	{
		cur = node;
		prev = node->prev;
		node = node->next;

		while (prev && prev->n > cur->n)
		{
			prev->next = cur->next;
			if (cur->next)
				cur->next->prev = prev;

			cur->next = prev;
			cur->prev = prev->prev;

			if (prev->prev)
				prev->prev->next = cur;
			else
				*list = cur;

			prev->prev = cur;
			prev = cur->prev;

			/* print list after swapping elements */
			print_list(*list);
		}
	}
}
