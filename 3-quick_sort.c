#include "sort.h"

/**
 * swap - Swaps two integers
 *
 * @a: First integer to swap
 * @b: Second integer to swap
 */
void swap(int *a, int *b)
{
int temp = *a;
*a = *b;
*b = temp;
}

/**
 * lomuto_partition - Lomuto partition scheme for quick sort
 *
 * @array: Array to sort
 * @low: Starting index of partition to sort
 * @high: Ending index of partition to sort
 *
 * Return: Index of the partition
 */
int lomuto_partition(int *array, int low, int high)
{
int pivot = array[high];
int i = low - 1;
int j;

for (j = low; j <= high - 1; j++)
{
if (array[j] <= pivot)
{
i++;
swap(&array[i], &array[j]);
if (i != j)
print_array(array, high - low + 1);
}
}
swap(&array[i + 1], &array[high]);
if (i + 1 != high)
print_array(array, high - low + 1);
return (i + 1);
}

/**
* quick_sort_helper - Helper function for quick sort
*
* @array: Array to sort
* @low: Starting index of partition to sort
* @high: Ending index of partition to sort
* @size: Size of the array
*/
void quick_sort_helper(int *array, int low, int high, size_t size)
{
if (low < high)
{
int p = lomuto_partition(array, low, high);

quick_sort_helper(array, low, p - 1, size);
quick_sort_helper(array, p + 1, high, size);
}
}

/**
* quick_sort - Sorts an array of integers in ascending order using
*              the Quick sort algorithm with Lomuto partition scheme
*
* @array: Array to sort
* @size: Size of the array
*/
void quick_sort(int *array, size_t size)
{
if (size < 2)
return;
quick_sort_helper(array, 0, size - 1, size);
}
