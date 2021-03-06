#include "sort.h"
/**
 * swap - Function to swap two elements inside an array.
 * @a: Value inside the first position.
 * @b: Value inside the second position.
 */
void swap(int *a, int *b)
{
	int t = *a;
	*a = *b;
	*b = t;
}

/**
 * partition - Function that creates two partitions inside
 * the array using the Lomuto partition scheme.
 * @array: Array of integers.
 * @low: Starting index inside the array.
 * @high: Ending index inside the array.
 * @size: Size of the array to sort.
 * Return: Print the array after each time you swap two elements.
 */
int partition(int *array, int low, int high, size_t size)
{
	int pivot = array[high];
	int i = (low - 1);
	int j = 0;

	for (j = low; j <= high; j++)
	{
		if (array[j] <= pivot)
		{
			i++;
			if (i != j)
			{
				swap(&array[i], &array[j]);
				print_array(array, size);
			}
		}
	}
	return (i);
}

/**
 * quickSort - Function that sorts an array of integers in
 * ascending order using the Quick sort algorithm.
 * @array: Array of integers.
 * @low: Starting index inside the array.
 * @high: Ending index inside the array.
 * @size: Size of the string.
 */
void quickSort(int *array, int low, int high, size_t size)
{
	if (low < high)
	{
		int num = partition(array, low, high, size);

		quickSort(array, low, num - 1, size);
		quickSort(array, num + 1, high, size);
	}
}

/**
 * quick_sort - Function that sorts an array of integers in
 * ascending order using the Quick sort algorithm.
 * @array: Array of integers.
 * @size: Size of the string.
 * Return: Print the array after each time you swap two elements.
 */
void quick_sort(int *array, size_t size)
{
	quickSort(array, 0, size - 1, size);
}
