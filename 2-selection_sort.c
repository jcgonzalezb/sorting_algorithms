#include "sort.h"

/**
 * bubble_sort - implementation of the djb2 algorithm
 * @str: string used to generate hash value
 *
 * Return: hash value
 */
void selection_sort(int *array, size_t size)
{
	size_t min, i, j, temp;

	for (i = 0; i < size - 1; i++)
	{
		min = i;
		for (j = i + 1; j < size; j++)
		{
			if (array[min] > array[j])
			{
				min = j;
			}
		}
		if (min != i)
		{
			temp = array[i];
			array[i] = array[min];
			array[min] = temp;
			print_array(array, size);
		}
	}
}
