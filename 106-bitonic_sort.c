#include <stdio.h>
#include "sort.h"

/**
 * bitonic_merge - merge bitonic sequence
 * @array: array of integers
 * @low: lowest index
 * @count: number of elements to sort
 * @dir: direction of sorting
 *
 * Return: nothing
 */
void bitonic_merge(int *array, size_t low, size_t count, int dir)
{
    size_t k = count / 2, i = low, j = low + k, temp;

    if (count < 2)
        return;
    printf("Merging [%lu/%lu] (%s):\n", count, count, (dir == 1) ? "UP" : "DOWN");
    print_array(array + low, count);
    bitonic_merge(array, low, k, 1);
    bitonic_merge(array, low + k, k, 0);
    for (; i < low + k; i++)
    {
        if ((array[i] > array[j]) == dir)
        {
            temp = array[i];
            array[i] = array[j];
            array[j] = temp;
            printf("Result [%lu/%lu] (%s):\n", i + 1, count, (dir == 1) ? "UP" : "DOWN");
            print_array(array + low, count);
        }
        j++;
    }
}

/**
 * bitonic_sort - sorts an array of integers in ascending order using
 * the bitonic sort algorithm
 * @array: array of integers
 * @size: size of array
 *
 * Return: nothing
 */
void bitonic_sort(int *array, size_t size)
{
    size_t i, k;

    if (size < 2 || !array)
        return;
    for (k = 2; k <= size; k <<= 1)
    {
        for (i = 0; i < size; i += k)
        {
            bitonic_merge(array, i, k, (i / k) % 2 == 0 ? 1 : 0);
        }
    }
}
