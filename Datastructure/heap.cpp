#include "heap.h"

HeapNode::HeapNode()
{

}

HeapNode::HeapNode(int data)
{
	this->data = data;
	this->priority = 0;
}

Heap::Heap(PriorityComp* action)
{
	comp = action;
	for (int i = 0; i < 100; i++)
		arr[i] = nullptr;
	numofdata = 1;
}

bool Heap::IsEmpty()
{
	if (numofdata == 1)
		return true;
	return false;
}

void Heap::Insert(HeapNode* hn)
{
	HeapNode* temp;
	int idx = numofdata;
	int parentidx = GetParentIDX(idx);
	arr[idx] = hn;

	numofdata++;

	while (comp(arr[idx]->data, arr[parentidx]->data) > 0)
	{
		temp = arr[parentidx];
		arr[parentidx] = arr[idx];
		arr[idx] = temp;
		idx = parentidx;
		parentidx = GetParentIDX(idx);

		if (parentidx <= 0)
			break;
	}
}//Change complete

int Heap::Delete()
{
	if (IsEmpty())
		return 0;

	HeapNode* temp;
	int idx = 1, deleteData, childidx;

	deleteData = arr[idx]->data;

	delete arr[idx];

	numofdata--;

	arr[idx] = arr[numofdata];
	arr[numofdata] = nullptr;
	childidx = idx;

	while (childidx = GetHighPriorChild(idx))
	{
		if (comp(arr[idx]->data, arr[childidx]->data) > 0)
			break;
		
		temp = arr[idx];
		arr[idx] = arr[childidx];
		arr[childidx] = temp;

		idx = childidx;
	}

	return deleteData;
}//Change complete

int Heap::GetParentIDX(int idx)
{
	if (IsEmpty())
		return 1;
	idx = idx / 2;
	return idx;
}

int Heap::GetLeftChildIDX(int idx)
{
	idx = idx * 2;
	return idx;
}

int Heap::GetRightChildIDX(int idx)
{
	idx = (idx * 2) + 1;
	return idx;
}

int Heap::GetHighPriorChild(int idx)
{
	if (GetLeftChildIDX(idx) >= numofdata)
		return 0;
	else if (GetLeftChildIDX(idx) == (numofdata - 1))
		return GetLeftChildIDX(idx);
	else
	{
		if (comp(arr[GetLeftChildIDX(idx)]->data, arr[GetRightChildIDX(idx)]->data) > 0)
			return GetLeftChildIDX(idx);
		else
			return GetRightChildIDX(idx);
	}
}//Change complete

void Heap::print()
{
	for (int i = 1; i < numofdata; i++)
		cout << arr[i]->data << endl;
}