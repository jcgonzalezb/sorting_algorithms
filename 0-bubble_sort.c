#include "sort.h"

/**
 * bubble_sort - implementation of the djb2 algorithm
 * @str: string used to generate hash value
 *
 * Return: hash value
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
			}
		}
	}
}
