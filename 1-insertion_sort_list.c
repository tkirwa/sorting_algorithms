#include "sort.h"

/**
 * insertion_sort_list - Sorts a doubly linked list of integers in
 *                        ascending order using the Insertion sort algorithm
 * @list: Address of pointer to the first node of the list to sort
 */
void insertion_sort_list(listint_t **list)
{
    listint_t *current = NULL, *compare = NULL;

    if (list == NULL || (*list) == NULL || (*list)->next == NULL)
        return;

    current = (*list)->next;
    while (current)
    {
        compare = current->prev;
        while (compare && compare->n > current->n)
        {
            if (compare->prev == NULL)
            {
                compare->prev = current;
                current->next = compare;
                current->prev = NULL;
                (*list) = current;
                compare->next = compare->next->next;
                if (compare->next)
                    compare->next->prev = compare;
                print_list(*list);
                continue;
            }
            compare->prev->next = current;
            current->prev = compare->prev;
            compare->prev = current;
            current->next = compare;
            compare->next->prev = current;
            compare->next = compare->next->next;
            if (compare->next)
                compare->next->prev = compare;
            print_list(*list);
        }
        current = current->next;
    }
}
