#include "sort.h"

/**
 * merge - Function to merge two subarrays of array.
 * @array: Array of integers.
 * @temp: Temporal array for merging.
 * @l: Left index of the array.
 * @r: Right index of the sub-array of array to be sorted.
 * @m: Middle position between two subarrays.
 */
void merge(int *array, int l, int m, int r, int *temp)
{
	int i, j, k, n, le = 0, ri = 0, n1 = m - l + 1, n2 = r - m, L[n1], R[n2];

	printf("Merging...\n");
	i = l, j = m + 1, k = le = 0;
	while (i <= m && j <= r)
	{
		if (array[i] <= array[j])
			temp[k] = L[le] = array[i], k++, i++, le++;
		else
			temp[k] = R[ri] = array[j], k++, j++, ri++;
	}
	while (i <= m)
		temp[k] = L[le] = array[i], k++, i++, le++;
	while (j <= r)
		temp[k] = R[ri] = array[j], k++, j++, ri++;
	printf("[left]: ");
	for (n = 0; n < le; n++)
		(n == 0) ? printf("%d", L[n]) : printf(", %d", L[n]);
	printf("\n[right]: ");
	for (n = 0; n < ri; n++)
		(n == 0) ? printf("%d", R[n]) : printf(", %d", R[n]);
	printf("\n[Done]: ");
	for (i = l; i <= r; i++)
	{
		array[i] = temp[i - l], printf("%d", array[i]);
		if (i != r)
			printf(", ");
		else
			printf("\n");
	}
}

/**
 * mergeSort - Function to array of integers in ascending
 * order using the Merge sort algorithm.
 * @array: Array of integers.
 * @temp: Temporal array for merging.
 * @l: Left index of the array.
 * @r: Right index of the sub-array of arr to be sorted.
 */
void mergeSort(int *array, int l, int r, int *temp)
{
	if (l > r)
		return;
	if (l < r)
	{
		int m = ((r + l - 1) / 2);

		mergeSort(array, l, m, temp);
		mergeSort(array, m + 1, r, temp);
		merge(array, l, m, r, temp);
	}
}

/**
 * merge_sort - Function to array of integers in ascending
 * order using the Merge sort algorithm.
 * @array: Array of integers.
 * @size: Size of the array to sort.
 */
void merge_sort(int *array, size_t size)
{
	int *temp;

	if (array == NULL || size < 2)
		return;

	temp = malloc(sizeof(*temp) * (size + 1));
	if (temp == NULL)
		return;

	mergeSort(array, 0, size - 1, temp);
	free(temp);
}
