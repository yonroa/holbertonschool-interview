#include "sort.h"

/**
 * heap_sort - sorts an array of integers in ascending order
 * using the Heap sort algorithm
 * @array: Array to be sorted
 * @size: Size of the array
*/
void heap_sort(int *array, size_t size)
{
	int i, j;

	if (!size || !array)
		return;

	if (size < 2)
		return;

	for (i = (size / 2) - 1; i >= 0; i--)
		sift_down(array, size, i, size);

	for (j = size - 1; j > 0; j--)
	{
		if (array[0] >= array[j])
		{
			swap(&array[0], &array[j]);
			print_array(array, size);
		}
		sift_down(array, j, 0, size);
	}
}

/**
 * sift_down - function sift_down to heap order
 * @array: Array to be sorted
 * @size: Size of the array
 * @index: Limit of the sorting of the array
 * @origin: Original size to print the array
*/
void sift_down(int *array, size_t size, int index, size_t origin)
{
	int largest = index;
	size_t left = 2 * index + 1;
	size_t right = 2 * index + 2;

	if (left < size && array[left] > array[largest])
		largest = left;

	if (right < size && array[right] > array[largest])
		largest = right;

	if (largest != index)
	{
		swap(&array[index], &array[largest]);
		print_array(array, origin);
		sift_down(array, size, largest, origin);
	}
}

/**
 * swap - swap two numbers in the array
 * @a: first number
 * @b: second number
*/
void swap(int *a, int *b)
{
	int t = *a;
	*a = *b;
	*b = t;
}
