#pragma once
#include <iostream>
#include "heap.h"
#include "Queue.h"

void BubbleSort(int* arr, int lenth);

void InsertionSort(int* arr, int lenth);

void SelectionSort(int* arr, int lenth);

void HeapSort(int* arr, int lenth, PriorityComp pri);

void MergeSort(int* arr, int left, int right);

void QuickSort(int* arr, int left, int right);

void RadixSort(int* arr, int num, int maxlen);