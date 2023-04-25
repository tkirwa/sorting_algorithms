#include "sort.h"

/**
 * merge - Merges two subarrays of array[]
 * @array: Pointer to array
 * @left: Leftmost index of the first subarray
 * @middle: Rightmost index of the first subarray and leftmost index of the second subarray
 * @right: Rightmost index of the second subarray
 *
 * Return: void
 */
void merge(int *array, int left, int middle, int right)
{
int i, j, k;
int n1 = middle - left + 1;
int n2 = right - middle;
int *L, *R;

L = malloc(n1 * sizeof(int));
if (L == NULL)
return;
R = malloc(n2 * sizeof(int));
if (R == NULL)
{
free(L);
return;
}

for (i = 0; i < n1; i++)
L[i] = array[left + i];
for (j = 0; j < n2; j++)
R[j] = array[middle + 1 + j];

i = 0;
j = 0;
k = left;
while (i < n1 && j < n2)
{
if (L[i] <= R[j])
{
array[k] = L[i];
i++;
}
else
{
array[k] = R[j];
j++;
}
k++;
}

while (i < n1)
{
array[k] = L[i];
i++;
k++;
}

while (j < n2)
{
array[k] = R[j];
j++;
k++;
}

free(L);
free(R);
}

/**
 * merge_sort - Sorts an array of integers in ascending order using
 * the Merge sort algorithm
 * @array: Pointer to array
 * @size: Size of the array
 *
 * Return: void
 */
void merge_sort(int *array, size_t size)
{
if (size < 2)
return;

int middle = size / 2;

merge_sort(array, middle);
merge_sort(array + middle, size - middle);
merge(array, 0, middle - 1, size - 1);
}
