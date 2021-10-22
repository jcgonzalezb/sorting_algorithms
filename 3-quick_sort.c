#include "sort.h"
// A utility function to swap two elements
void quick_sort(int *array, size_t size)
{
	quickSort(array, 0, size - 1);
}
void swap(int* a, int* b)
{
	int t = *a;
	*a = *b;
	*b = t;
}
/* This function takes last element as pivot, places
the pivot element at its correct position in sorted
arrayay, and places all smaller (smaller than pivot)
to left of pivot and all greater elements to right
of pivot */
int partition (int array[], int low, int high)
{
	int pivot = array[high]; // pivot
	int i = (low - 1); // Index of smaller element and indicates the right position of pivot found so far

	for (int j = low; j <= high - 1; j++)
	{
		// If current element is smaller than the pivot
		if (array[j] < pivot)
		{
			i++; // increment index of smaller element
			swap(&array[i], &array[j]);
			if (i != j)
				print_array(array, 10);
		}
	}
	swap(&array[i + 1], &array[high]);
	if (i + 1 != high)
		print_array(array, 10);
	return (i + 1);
}
/* The main function that implements QuickSort
array[] --> arrayay to be sorted,
low --> Starting index,
high --> Ending index */
void quickSort(int array[], int low, int high)
{
	if (low < high)
	{
		/* pi is partitioning index, array[p] is now
		at right place */
		int pi = partition(array, low, high);

		// Separately sort elements before
		// partition and after partition
		quickSort(array, low, pi - 1);
		quickSort(array, pi + 1, high);
	}
}