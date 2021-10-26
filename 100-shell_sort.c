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
	int j = 0;
	int interval = 1;
	int max = size;
	int temp = 0;
	int first = array[0];

	if (!array || size < 2 || !size)
		return;

	while (interval < max / 3)
	{
		interval = interval * 3 + 1;
	}
	while (interval > 0)
	{
		for (i = interval; i < max; i++)
		{
			temp = array[i];

			for (j = i; j > (interval - 1) && array[j - interval] >= temp; j -= interval)
			{
				array[j] = array[j - interval];
			}
			array[j] = temp;
		}
		interval = interval / 3;
		if (first != array[j])
			print_array(array, size);
	}
}
