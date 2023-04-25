#include "sort.h"

/**
 * radix_sort - sorts an array of integers in ascending order using
 * the Radix sort algorithm
 * @array: Array to be sorted
 * @size: Size of the array
 */
void radix_sort(int *array, size_t size)
{
int i, max_digit = 0, digit_place = 1;
int *tmp = NULL, *count = NULL;

if (array == NULL || size < 2)
return;

tmp = malloc(sizeof(int) * size);
if (tmp == NULL)
return;

for (i = 0; i < (int)size; i++)
if (array[i] > max_digit)
max_digit = array[i];

while (max_digit / digit_place > 0)
{
count = calloc(sizeof(int), 10);
if (count == NULL)
{
free(tmp);
return;
}

for (i = 0; i < (int)size; i++)
count[array[i] / digit_place % 10]++;

for (i = 1; i < 10; i++)
count[i] += count[i - 1];

for (i = (int)size - 1; i >= 0; i--)
tmp[--count[array[i] / digit_place % 10]] = array[i];

for (i = 0; i < (int)size; i++)
array[i] = tmp[i];

print_array(array, size);
digit_place *= 10;
free(count);
}
free(tmp);
}
