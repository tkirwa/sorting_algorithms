#include "sort.h"

/**
 * sift_down - Repair the heap whose root element is at index 'start'
 * @array: Array to sort
 * @start: Index of the root element in the heap
 * @end: Index of the last element in the heap
 *
 * Return: Nothing
 */
void sift_down(int *array, size_t start, size_t end)
{
size_t root = start, child, swap;
int tmp;

while (2 * root + 1 <= end)
{
child = 2 * root + 1;
swap = root;
if (array[swap] < array[child])
swap = child;
if (child + 1 <= end && array[swap] < array[child + 1])
swap = child + 1;
if (swap == root)
return;
tmp = array[root];
array[root] = array[swap];
array[swap] = tmp;
print_array(array, end + 1);
root = swap;
}
}

/**
* heap_sort - Sort an array of integers using heap sort algorithm
* @array: Array to sort
* @size: Size of the array
*
* Return: Nothing
*/
void heap_sort(int *array, size_t size)
{
size_t i;
int tmp;

if (!array || size < 2)
return;
for (i = size / 2 - 1; i < size; i--)
sift_down(array, i, size - 1);
for (i = size - 1; i > 0; i--)
{
tmp = array[0];
array[0] = array[i];
array[i] = tmp;
print_array(array, size);
sift_down(array, 0, i - 1);
}
}
