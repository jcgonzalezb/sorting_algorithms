#include "sort.h"

/**
 * bubble_sort - Sorts an array of integers in ascending order
 * using the Bubble sort algorithm.
 * @array: Array of integers.
 * @size: Size of the array to sort.
 *
 * Return: Print the array after each time you swap two elements.
 */
void bubble_sort(int *array, size_t size)
{
	size_t i = 0, j = 0, tmp;

	for (i = 0; i < size; i++)
	{
		for (j = 0; j < size - i - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				tmp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = tmp;
				print_array(array, size);
			}
		}
	}
}
