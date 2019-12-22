#include "sort.h"
#define BUCKET_NUM 10

void BubbleSort(int* arr, int lenth)
{
	int temp;

	for (int i = 0; i < (lenth - 1); i++)
	{
		for (int j = 0; j < ((lenth - 1) - i); j++)
		{
			if (arr[j] > arr[j + 1])
			{
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}

void InsertionSort(int* arr, int lenth)
{
	int temp, insertiondata;
	for (int i = 0; i < lenth; i++)
	{
		insertiondata = arr[i];
		for (int j = (i - 1); j >= 0; j--)
		{
			if (insertiondata < arr[j])
			{
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
			else
				break;
		}
	}
}

void SelectionSort(int* arr, int lenth)
{
	int min = 0, temp;
	for (int i = 0; i < lenth; i++)
	{
		min = i;
		for (int j = i + 1; j < lenth; j++)
		{
			if (arr[j] < arr[min])
				min = j;
		}
		temp = arr[i];
		arr[i] = arr[min];
		arr[min] = temp;
	}

}

void HeapSort(int* arr, int lenth, PriorityComp pri)
{
	Heap heap(pri);

	for (int i = 0; i < lenth; i++)
		heap.Insert(new HeapNode(arr[i]));

	for (int i = 0; i < lenth; i++)
		arr[i] = heap.Delete();
}

void MergeTwoArea(int* arr, int left, int mid, int right)
{
	int ridx = mid + 1;
	int lidx = left;
	int idx = left;
	
	int* sortarr = new int[right+1];

	while (ridx <= right && lidx <= mid)
	{
		if (arr[lidx] <= arr[ridx])
			sortarr[idx++] = arr[lidx++];
		else
			sortarr[idx++] = arr[ridx++];
	}

	for (int i = lidx; i <= mid; i++)
		sortarr[idx++] = arr[i];

	for (int i = ridx; i <= right; i++)
		sortarr[idx++] = arr[i];

	for (int i = left; i <= right; i++)
		arr[i] = sortarr[i];

	delete sortarr;
}//This function is used for MergeSort

void MergeSort(int* arr, int left, int right)
{
	int mid;

	if (left < right)
	{
		mid = (left + right) / 2;

		MergeSort(arr,left, mid);
		MergeSort(arr, mid + 1, right);

		MergeTwoArea(arr, left, mid, right);
	}
}

void Swap(int* arr, int idx1, int idx2)
{
	int temp = arr[idx1];
	arr[idx1] = arr[idx2];
	arr[idx2] = temp;
}

int Partition(int* arr, int left, int right)
{
	int pivot = arr[left];
	int low = left + 1;
	int high = right;

	while (low <= high)
	{
		while (arr[low] <= pivot && low <= right)
			low++;

		while (arr[high] >= pivot && high >= left + 1)
			high--;

		if (low <= high)
			Swap(arr, low, high);
	}

	Swap(arr, left, high);

	return high;
}

void QuickSort(int* arr, int left, int right)
{
	int mid;


	if (left <= right)
	{
		mid = (left + right) / 2;
		Swap(arr, left, mid);

		int pivot = Partition(arr, left, right);

		QuickSort(arr, left, pivot - 1);
		QuickSort(arr, pivot + 1, right);
	}
}//The Key operation of QuickSort is to swap pivot and high.
//Need more studying of QuickSort.

void RadixSort(int* arr, int num, int maxlen)
{
	Queue que[BUCKET_NUM];
	int divfac = 1;
	int radix;
	int idx = 0;

	for (int i = 0; i < maxlen; i++)
	{
		for (int j = 0; j < num; j++)
		{
			radix = (arr[j] / divfac) % 10;
			que[radix].Enque(arr[j]);
		}

		for (int k = 0; k < BUCKET_NUM; k++)
		{
			while (!que[k].IsEmpty())
				arr[idx++] = que[k].Deque();
		}
		idx = 0;
		divfac *= 10;
	}
}