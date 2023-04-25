#include "sort.h"

/**
 * bitonic_sort - sorts an array of integers in ascending order
 *                using the Bitonic sort algorithm
 * @array: the array of integers to sort
 * @size: the size of the array
 */
void bitonic_sort(int *array, size_t size)
{
if (array == NULL || size < 2)
return;

bitonic_sort_recursive(array, size, 1);
}

/**
 * bitonic_sort_recursive - recursive function that implements the
 *                          Bitonic sort algorithm
 * @array: the array of integers to sort
 * @size: the size of the array
 * @direction: the direction of the merge (1 for up, 0 for down)
 */
void bitonic_sort_recursive(int *array, size_t size, int direction)
{
if (size < 2)
return;

bitonic_sort_recursive(array, size / 2, 1);
bitonic_sort_recursive(array + size / 2, size / 2, 0);

bitonic_merge(array, size, direction);
}

/**
 * bitonic_merge - merges two sorted subarrays of the given array
 *                 in the desired order
 * @array: the array of integers to sort
 * @size: the size of the array
 * @direction: the direction of the merge (1 for up, 0 for down)
 */
void bitonic_merge(int *array, size_t size, int direction)
{
if (size > 1)
{
size_t i;
size_t k = size / 2;

for (i = 0; i < k; i++)
{
if ((array[i] > array[i + k]) == direction)
{
swap(&array[i], &array[i + k]);
}
}

bitonic_merge(array, k, direction);
bitonic_merge(array + k, k, direction);
}
}

/**
 * swap - swaps two integers in an array
 * @a: the first integer
 * @b: the second integer
 */
void swap(int *a, int *b)
{
int tmp = *a;
*a = *b;
*b = tmp;

printf("Swapping %d and %d\n", *a, *b);
}
