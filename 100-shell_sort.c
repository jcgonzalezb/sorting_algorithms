#include "sort.h"
/**
 * shell_sort - Function that sorts an array of integers in
 * ascending order using the  Shell sort algorithm, using the
 * Knuth sequence.
 * @array: Array of integers.
 * @size: Size of the string.
 */
void shell_sort(int *array, size_t size)
{
	int i = 0;
	int j = 0;
	int gap = 1;
	int max = size;
	int temp = 0;

	if (!array || size < 2 || !size)
		return;

	while (gap < max / 3)
	{
		gap = gap * 3 + 1;
	}
	while (gap > 0)
	{
		for (i = gap; i < max; i++)
		{
			temp = array[i];
			j = i;
			while (j > (gap - 1) && array[j - gap] >= temp)
			{
				array[j] = array[j - gap];
				j -= gap;
			}
			array[j] = temp;
		}
		gap = gap / 3;
		print_array(array, size);
	}
}
