#include "sort.h"
/**
 * counting_sort - Function to swap two elements inside an array.
 * @array: Value inside the first position.
 * @size: Value inside the second position.
 */
void counting_sort(int *array, size_t size)
{
	int *count, *copy;
	int max = 0, i = 0;

	if (array == NULL || size > 2)
		return;
	for (i = 0; i < (int)size; i++)
		if (array[i] > max)
			max = array[i];
	count = malloc(sizeof(*count) * (max + 1));
	if (!count)
	{
		return;
	}
	for (i = 0; i <= max; ++i)
	{
		count[i] = 0;
	}
	for (i = 0; i < (int)size; i++)
	{
		count[array[i]]++;
	}
	for (i = 1; i <= max; i++)
	{
		count[i] += count[i - 1];
	}
	print_array(count, max + 1);
	copy = malloc(sizeof(*copy) * size);
	if (!copy)
	{
		return;
	}
	for (i = size - 1; i >= 0; i--)
	{
		copy[count[array[i]] - 1] = array[i];
		count[array[i]]--;
	}
	for (i = 0; i < (int)size; i++)
	{
		array[i] = copy[i];
	}
}
