#include "sort.h"

/**
 * merge - Function to merge two subarrays of array.
 * @array: Value inside the first position.
 * @size: Value inside the second position.
 * @l: Left index of the array.
 * @r: Right index of the sub-array of arr to be sorted.
 * @m: Middle position between two subarrays.
 */
void merge(int *array, int l, int m, int r, size_t size)
{
	int i, j, k;
	int n1 = m - l + 1;
	int n2 = r - m;
	int L[n1], R[n2];

	for (i = 0; i < n1; i++)
		L[i] = array[l + i];
	for (j = 0; j < n2; j++)
		R[j] = array[m + 1 + j];

	i = 0;
	j = 0;
	k = l;
	while (i < n1 && j < n2)
	{
		if (L[i] <= R[j])
		{
			array[k] = L[i];
			i++;
		}
		else
		{
			array[k] = R[j];
			j++;
		}
	print_array(array, size);
	k++;
	}
	while (i < n1)
	{
		array[k] = L[i];
		i++;
		k++;
	}
	while (j < n2)
	{
		array[k] = R[j];
		j++;
		k++;
	}
}

/**
 * mergeSort - Function to array of integers in ascending
 * order using the Merge sort algorithm.
 * @array: Value inside the first position.
 * @size: Value inside the second position.
 * @l: Left index of the array.
 * @r: Right index of the sub-array of arr to be sorted.
 */
void mergeSort(int *array, int l, int r, size_t size)
{
	if (l < r)
	{
		int m = l + (r - l) / 2;

		mergeSort(array, l, m, size);
		mergeSort(array, m + 1, r, size);

		merge(array, l, m, r, size);
	}
}

/**
 * merge_sort - Function to array of integers in ascending
 * order using the Merge sort algorithm.
 * @array: Value inside the first position.
 * @size: Value inside the second position.
 */
void merge_sort(int *array, size_t size)
{
	mergeSort(array, 0, size - 1, size);
}
