#include "sort.h"
/**
 * quick_sort - function that sorts a doubly linked list of integers
 * @array: array
 * @size: array
 * Return: the value
 */
void quick_sort(int *array, size_t size)
{
	quickSort(array, 0, size - 1, size);
}
/**
 * swap - function that sorts a doubly linked list of integers
 * @a: array
 * @b: array
 * Return: the value
 */
void swap(int *a, int *b)
{
	int t = *a;
	*a = *b;
	*b = t;
}
/**
 * partition - function that sorts a doubly linked list of integers
 * @array: array
 * @low: array
 * @high: array
 * @size: array
 * Return: the value
 */
int partition(int array[], int low, int high, size_t size)
{
	int pivot = array[high];
	int i = (low - 1);

	for (int j = low; j <= high - 1; j++)
	{
		if (array[j] < pivot)
		{
			i++;
			swap(&array[i], &array[j]);
			if (i != j)
				print_array(array, size);
		}
	}
	swap(&array[i + 1], &array[high]);
	if (i + 1 != high)
		print_array(array, size);
	return (i + 1);
}
/**
 * quickSort - function that sorts a doubly linked list of integers
 * @array: array
 * @low: array
 * @high: array
 * @size: array
 * Return: the value
 */
void quickSort(int array[], int low, int high, size_t size)
{
	if (low < high)
	{
		int pi = partition(array, low, high, size);

		quickSort(array, low, pi - 1, size);
		quickSort(array, pi + 1, high, size);
	}
}
