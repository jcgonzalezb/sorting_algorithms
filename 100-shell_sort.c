#include "sort.h"
/**
 * shell_sort - Function that sorts an array of integers in
 * ascending order using the  Shell sort algorithm, using the
 * Knuth sequence.
 * @array: Array of integers.
 * @size: Size of the string.
 * Return: Print the array after each time you swap two elements.
 */
void shell_sort(int *array, size_t size)
{
	int i = 0;
	int interval = 1;
	int max = size;
	int j = 0;

	while (interval <= max / 3)
	{
		interval = interval * 3 + 1;
	}
	while (interval >= 1)
	{
		for (i = interval; i < max; i += 1)
		{
			int temp = array[i];

			for (j = i; j >= interval && array[j - interval] > temp; j -= interval)
			{
				array[j] = array[j - interval];
			}
			array[j] = temp;
		}
		interval = interval / 3;
		print_array(array, size);
	}
}
