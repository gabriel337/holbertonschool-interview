#include "sort.h"

/**
 * heap_sort - function that sorts an array of
 * integers in ascending order using the Heap sort algorithm
 * @array: The array
 * @size: size_t, total size of array
 */
void heap_sort(int *array, size_t size)
{
	size_t x;

	if (array == NULL)
		return;

	for (x = size / 2; x > 0; x--)
		max_heap(array, size, x - 1, size);

	for (x = size - 1; x > 0; x--)
	{
		swap(&array[0], &array[x], array, size);
		max_heap(array, x, 0, size);
	}
}

/**
 * max_heap - Find largest from root using a left (2*i + 1) and
 * right (2*i + 2) child and perform a down-heap or heapify-down
 * operation for a map-heap
 * @arr: The array
 * @total: total size of array as integer
 * @x: current index position
 * @size: total size of the length of the array as size_t
 */
void max_heap(int *arr, int total, int x, size_t size)
{
	int L = x;
	int left = 2 * x + 1;
	int right = 2 * x + 2;

	if (left < total && arr[left] > arr[L])
		L = left;
	if (right < total && arr[right] > arr[L])
		L = right;
	if (x != L)
	{
		swap(&arr[x], &arr[L], arr, size);
		max_heap(arr, total, L, size);
	}
}

/**
 * swap - Function to swap elements from current positions
 * @a: first element int
 * @b: second element int
 * @array: The array of nums
 * @total: total length of array
 */
void swap(int *a, int *b, int *array, size_t total)
{
	int temp = *a;
	*a = *b;
	*b = temp;
	print_array(array, total);
}
