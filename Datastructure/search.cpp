#include "search.h"

int InterpolationSearch(int* arr, int first, int last, int target)
{
	if (arr[first] > target || arr[last] < target)
		return -1;

	int pivot = ((double)(target - arr[first]) / (arr[last] - arr[first])
		* (last - first)) + first;

	if (arr[pivot] == target)
		return pivot;
	else if (arr[pivot] > target)
		return InterpolationSearch(arr, first, pivot - 1, target);
	else
		return InterpolationSearch(arr, pivot + 1, last, target);
}

