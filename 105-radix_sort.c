#include <stdlib.h>
#include "sort.h"

/**
 * radix_sort - sorts an array of integers in ascending order
 * using the LSD radix sort algorithm
 * @array: pointer to array to sort
 * @size: size of the array
 **/
void radix_sort(int *array, size_t size)
{
    int i, exp = 1;
    int *output = malloc(sizeof(int) * size);
    int max_value = 0;

    if (output == NULL)
        return;

    /* Get the maximum value in the array */
    for (i = 0; i < (int)size; i++)
    {
        if (array[i] > max_value)
            max_value = array[i];
    }

    /* LSD radix sort */
    while (max_value / exp > 0)
    {
        int bucket[10] = {0};

        /* Counting sort */
        for (i = 0; i < (int)size; i++)
            bucket[(array[i] / exp) % 10]++;

        for (i = 1; i < 10; i++)
            bucket[i] += bucket[i - 1];

        for (i = size - 1; i >= 0; i--)
        {
            output[bucket[(array[i] / exp) % 10] - 1] = array[i];
            bucket[(array[i] / exp) % 10]--;
        }

        /* Copy sorted elements to original array */
        for (i = 0; i < (int)size; i++)
            array[i] = output[i];

        /* Print array */
        print_array(array, size);
        exp *= 10;
    }

    free(output);
}
